/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : uart.c
 */

#include "Board.h"

UART_Handle uart;
UART_Params uartParams;

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : UART_Interrupt_Handler
 * 내   용: Rx 인터럽트 핸들러(데이터가 들어오는 경우 링버퍼에 저장)
 */
static void UART_Interrupt_Handler(UART_Handle handle, void *rxBuf, size_t size)
{
  UartQueue.data[UartQueue.front] = ((uint8_t*)rxBuf)[0];
  if(++UartQueue.front >= UART_QUEUE_SIZE) UartQueue.front = 0;
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : Uart_Config_init
 * 내   용: UART 초기화 및 파라미터 설정
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
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : UartTextData
 * 내   용: UART String Tx
 */
void UartTextData(char* str)
{
    unsigned int buf_len;

    buf_len = strlen(str);
    UART_write(uart, str, buf_len);
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : UartSendData
 * 내   용: UART 터미널 디버깅
 */
void UartSendData(uint8_t data)
{
    data = data % 10 + 0x30;
    UART_write(uart, &data, sizeof(data));
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : UartNullData
 * 내   용: UART NULL
 */
void UartNullData(void)
{
    UartTextData((char*)"\r\n");
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : UartNullData
 * 내   용: 사이즈 만큼의 데이터 전송
 */
void UartSizeWriteData(uint8_t data, uint8_t size)
{
    while(size--)
    {
        UartWriteData(data);
    }
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : UartWriteCRCData
 * 내   용: CRC 체크 데이터 전송
 */
void UartWriteCRCData(uint8_t data)
{
    //calcCrc(data);
    UART_write(uart, &data, 1);
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : UartWriteData
 * 내   용: Hex 데이터 1Byte 전송
 */
void UartWriteData(uint8_t data)
{
    UART_write(uart, &data, 1);
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : Uart16bitData
 * 내   용: 2Byte 데이터 전송
 */
void Uart16bitData(uint16_t data)
{
    UartWriteCRCData( data & 0xFF );
    UartWriteCRCData( (data >> 8) & 0xFF );
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : Uart32bitData
 * 내   용: 4Byte 데이터 전송
 */
void Uart32bitData(uint32_t data)
{
    UartWriteCRCData( data & 0xFF );
    UartWriteCRCData( (data >> 8) & 0xFF );
    UartWriteCRCData( (data >> 16) & 0xFF );
    UartWriteCRCData( (data >> 24) & 0xFF );
}

/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 함수명 : UartReceive
 * 내   용: Rx 데이터 입력
 */
void UartReceive(void)
{
    uint8_t rxBuffer[UART_QUEUE_SIZE] = {0};

    UART_read(uart, &rxBuffer, 1);
}

