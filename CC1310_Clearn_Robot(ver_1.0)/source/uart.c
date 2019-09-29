/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : uart.c
 */

#include "Board.h"

UART_Handle uart;
UART_Params uartParams;

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : UART_Interrupt_Handler
 * ��   ��: Rx ���ͷ�Ʈ �ڵ鷯(�����Ͱ� ������ ��� �����ۿ� ����)
 */
static void UART_Interrupt_Handler(UART_Handle handle, void *rxBuf, size_t size)
{
  UartQueue.data[UartQueue.front] = ((uint8_t*)rxBuf)[0];
  if(++UartQueue.front >= UART_QUEUE_SIZE) UartQueue.front = 0;
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : Uart_Config_init
 * ��   ��: UART �ʱ�ȭ �� �Ķ���� ����
 */
void Uart_Config_init(uint32_t baudRate)
{
    UART_init();
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readMode = UART_MODE_CALLBACK;
    uartParams.writeMode = UART_MODE_BLOCKING;
    uartParams.readReturnMode = UART_RETURN_NEWLINE;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = baudRate;
    uartParams.dataLength = UART_LEN_8;
    uartParams.stopBits = UART_STOP_ONE;
    uartParams.parityType = UART_PAR_NONE;
    uartParams.readCallback = UART_Interrupt_Handler;

    uart = UART_open(Board_UART0, &uartParams);
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : UartTextData
 * ��   ��: UART String Tx
 */
void UartTextData(char* str)
{
    unsigned int buf_len;

    buf_len = strlen(str);
    UART_write(uart, str, buf_len);
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : UartSendData
 * ��   ��: UART �͹̳� �����
 */
void UartSendData(uint8_t data)
{
    data = data % 10 + 0x30;
    UART_write(uart, &data, sizeof(data));
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : UartNullData
 * ��   ��: UART NULL
 */
void UartNullData(void)
{
    UartTextData((char*)"\r\n");
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : UartNullData
 * ��   ��: ������ ��ŭ�� ������ ����
 */
void UartSizeWriteData(uint8_t data, uint8_t size)
{
    while(size--)
    {
        UartWriteData(data);
    }
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : UartWriteCRCData
 * ��   ��: CRC üũ ������ ����
 */
void UartWriteCRCData(uint8_t data)
{
    //calcCrc(data);
    UART_write(uart, &data, 1);
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : UartWriteData
 * ��   ��: Hex ������ 1Byte ����
 */
void UartWriteData(uint8_t data)
{
    UART_write(uart, &data, 1);
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : Uart16bitData
 * ��   ��: 2Byte ������ ����
 */
void Uart16bitData(uint16_t data)
{
    UartWriteCRCData( data & 0xFF );
    UartWriteCRCData( (data >> 8) & 0xFF );
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : Uart32bitData
 * ��   ��: 4Byte ������ ����
 */
void Uart32bitData(uint32_t data)
{
    UartWriteCRCData( data & 0xFF );
    UartWriteCRCData( (data >> 8) & 0xFF );
    UartWriteCRCData( (data >> 16) & 0xFF );
    UartWriteCRCData( (data >> 24) & 0xFF );
}

/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * �Լ��� : UartReceive
 * ��   ��: Rx ������ �Է�
 */
void UartReceive(void)
{
    uint8_t rxBuffer[UART_QUEUE_SIZE] = {0};

    UART_read(uart, &rxBuffer, 1);
}

