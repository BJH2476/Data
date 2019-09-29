/*
 * easyRF.h
 *
 *  Created on: 2019. 9. 7.
 *      Author: jinhyuk
 */

#ifndef INCLUDE_EASYRF_H_
#define INCLUDE_EASYRF_H_

#define RFEASYLINKTX_BURST_SIZE         10
#define RFEASYLINKTXPAYLOAD_LENGTH      15
#define RFEASYLINKTX_RF_POWER           0
#define RF_SIZE_DATA                    11
#define CRC_LEN_SIZE                    9

void RF_Config_init(void);                                                                                  //RF Init
void RF_Send_Manager(uint32_t temperatureValue, int32_t VoltageValue);                                      //RF Send Data

#endif /* INCLUDE_EASYRF_H_ */
