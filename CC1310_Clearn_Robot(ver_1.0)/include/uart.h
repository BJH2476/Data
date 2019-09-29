/*
 * �ۼ��� : ������
 * �ۼ��� : 2019.09.07
 * ���ϸ� : uart.h
 * ���� : UART ���� ����
 */
#ifndef INCLUDE_UART_H_
#define INCLUDE_UART_H_

#define UART_QUEUE_SIZE     500                                         // UART Ring ���� ť ������

// ���۹��� ������ ����ü
struct QueueData
{
    uint8_t data[UART_QUEUE_SIZE];                                      // UART ť ������ ����
    uint16_t front;                                                     // �����Ͱ� �Է� �ɶ����� ī����
    uint16_t rear;                                                      // �����͸� ��� �Ҷ����� ī����

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
