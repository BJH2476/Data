/*
 * 작성자 : 변진혁
 * 작성일 : 2019.09.07
 * 파일명 : Flash.h
 * 내용 : Flash 메모리에 대한 정의
 */

#ifndef INCLUDE_FLASH_H_
#define INCLUDE_FLASH_H_

#define SECTOR_SIZE             0x1000
#define FLASH_SECTOR_BASE       0x0001A000
#define FLASH_SECTOR_ADD1       FLASH_SECTOR_BASE                           // Flash Address : 0x001A000
#define FLASH_SECTOR_ADD2       FLASH_SECTOR_BASE + SECTOR_SIZE             // Flash Address : 0x001B000
#define FLASH_SECTOR_ADD3       FLASH_SECTOR_BASE + (SECTOR_SIZE * 2)       // Flash Address : 0x001C000
#define FLASH_SECTOR_ADD4       FLASH_SECTOR_BASE + (SECTOR_SIZE * 3)       // Flash Address : 0x001D000

uint32_t WriteToFlash(uint32_t address, uint8_t * writeData, uint8_t length);
void ReadToFlash(uint32_t address, uint8_t *readData, uint8_t length);

#endif /* INCLUDE_FLASH_H_ */
