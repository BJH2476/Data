/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : flash.c
 */
#include "Board.h"

uint32_t WriteToFlash(uint32_t address, uint8_t * writeData, uint8_t length)
{
    uint32_t result;

    VIMSModeSet(VIMS_BASE, VIMS_MODE_DISABLED);
    while(VIMSModeGet(VIMS_BASE) != VIMS_MODE_DISABLED);

    result = FlashProtectionGet(address);
    if(result == FLASH_WRITE_PROTECT)
    {
        while(1)
            return result;
    }
    CPUcpsid();

    result = FlashSectorErase(address);
    if(result != FAPI_STATUS_SUCCESS)
    {
        while(1)
            return result;
    }

    result = FlashProgram(writeData, address, length);
    if(result != FAPI_STATUS_SUCCESS)
    {
        while(1)
            return result;
    }

    CPUcpsie();
    VIMSModeSet(VIMS_BASE, VIMS_MODE_ENABLED);

    return result;
}

void ReadToFlash(uint32_t address, uint8_t *readData, uint8_t length)
{
    uint8_t *Flash_Ptr = (uint8_t *) address;
    while(length --)
       *(readData++) = *(Flash_Ptr++);
}
