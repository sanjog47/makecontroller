/*********************************************************************************

 Copyright 2006-2009 MakingThings

 Licensed under the Apache License, 
 Version 2.0 (the "License"); you may not use this file except in compliance 
 with the License. You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0 
 
 Unless required by applicable law or agreed to in writing, software distributed
 under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 CONDITIONS OF ANY KIND, either express or implied. See the License for
 the specific language governing permissions and limitations under the License.

*********************************************************************************/

#ifndef MT_SPI_H
#define MT_SPI_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif
void spiInit(void);
void spiDeinit(void);
bool spiEnableChannel(int channel);
int  spiConfigure(int channel, int bits, int clockDivider, int delayBeforeSPCK, int delayBetweenTransfers);
int  spiReadWriteBlock(int channel, unsigned char* buffer, int count);
void spiLock(void);
void spiUnlock(void);
#ifdef __cplusplus
}
#endif

#endif // MT_SPI_H