#ifndef __LORA_H
#define __LORA_H
#include "main.h"

uint8_t* lora_check_cmd(uint8_t *str);
uint8_t lora_send_cmd(uint8_t *cmd,uint8_t *ack,uint16_t waittime);

void Lora_Init(void);
#endif

