#include "Board.h"

static uint8_t seqNumber = 0;

void RF_Config_init(void)
{
    EasyLink_Params easyLink_params;
    EasyLink_Params_init(&easyLink_params);
    easyLink_params.ui32ModType = EasyLink_Phy_Custom;

    if (EasyLink_init(&easyLink_params) != EasyLink_Status_Success){
        while(1);
    }

    EasyLink_Status pwrStatus = EasyLink_setRfPower(RFEASYLINKTX_RF_POWER);
    if(pwrStatus != EasyLink_Status_Success)
    {
        while(1);
    }
}

void RF_Send_Manager(uint32_t temperatureValue, int32_t VoltageValue)
{
    EasyLink_TxPacket txPacket =  { {0}, 0, 0, {0} };
    uint16_t crcValue = 0;

    txPacket.dstAddr[0] = 0x00;
    txPacket.len = RF_SIZE_DATA;
    txPacket.payload[0] = seqNumber++;
    txPacket.payload[1] = temperatureValue;
    txPacket.payload[2] = temperatureValue >> 8;
    txPacket.payload[3] = temperatureValue >> 16;
    txPacket.payload[4] = temperatureValue >> 24;
    txPacket.payload[5] = VoltageValue;
    txPacket.payload[6] = VoltageValue >> 8;
    txPacket.payload[7] = VoltageValue >> 16;
    txPacket.payload[8] = VoltageValue >> 24;
    crcValue = crc16StrCalc((uint8_t*)&txPacket.payload,0x0000,CRC_LEN_SIZE);
    txPacket.payload[9] = crcValue;
    txPacket.payload[10] = crcValue >> 8;

    EasyLink_transmit(&txPacket);
}

