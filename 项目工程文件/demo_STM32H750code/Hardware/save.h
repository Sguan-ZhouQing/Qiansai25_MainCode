#ifndef __SAVE_H
#define __SAVE_H

#include "stm32h7xx_hal.h"

uint8_t SaveImageToSD(uint32_t frame_count, void* buffer, uint32_t size);
void Save_ImgToCard(void);

#endif  // SAVE_H
