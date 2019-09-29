/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : uart.h
 * 내용 : UART 동작 정의
 */
#ifndef INCLUDE_UART_H_
#define INCLUDE_UART_H_

#define UART_QUEUE_SIZE     500                                         // UART Ring 버퍼 큐 사이즈

// 링퍼버를 정의한 구조체
struct QueueData
{
    uint8_t data[UART_QUEUE_SIZE];                                      // UART 큐 데이터 버퍼
    uint16_t front;                                                     // 데이터가 입력 될때마다 카운터
    uint16_t rear;                                                      // 데이터를 사용 할때마다 카운터

}__attribute__((aligned(1), packed));
typedef struct QueueData UartQ;

void Uart_Config_init(uint32_t baudrate);                               //UART Init & Param
void UartTextData(char *str);                                           //UART String
void UartSendData(uint8_t data);                                        //UART Terminal Type
void UartNullData(void);                                                //UART NULL
void UartWriteData(uint8_t data);                                       //UART 1Byte Send
void Uart32bitData(uint32_t data);                                      //UART 4Byte Send
void Uart16bitData(uint16_t data);                                      //UART 2Byte Send
void UartSizeWriteData(uint8_t data, uint8_t size);                     //UART Sizeof Send
void UartWriteCRCData(uint8_t data);                                    //UART CRC + 1Byte Send

UartQ UartQueue;

#endif /* INCLUDE_UART_H_ */
