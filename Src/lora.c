#include "lora.h"
#include "string.h"
#include "stdio.h"

uint8_t* lora_check_cmd(uint8_t *str)
{
	char *strx=0;
	if(USART2_RX_Flag)
	{
		USART2_RX_BUF[USART2_RX_Cnt] = 0;
		strx=strstr((const char*)USART2_RX_BUF,(const char*)str);
		USART2_RX_Cnt = 0;
		USART2_RX_Flag = 0;
	}   
	return (uint8_t*)strx;
}
uint8_t lora_send_cmd(uint8_t *cmd,uint8_t *ack,uint16_t waittime)
{
	uint8_t res=0; 
	USART2_RX_Flag=0;
	
	HAL_Delay(20);
	printf("%s\r\n",cmd);//发送命令
	
	if(ack&&waittime)		//需要等待应答
	{
	   while(--waittime)	//等待倒计时
	   {
		  HAL_Delay(10);
			if(USART2_RX_Flag)
			{
				if(lora_check_cmd(ack))
			  {
				  USART2_RX_Flag=0;
					res = 1;
				  break;//得到有效数据
			  }  
			} 
	   }
	   if(waittime==0)res=0; 
	}
	return res;
} 

void Lora_Init(void)
{
	uint8_t i=5,sendBuf[30];
	uint16_t mflag = 0;
	HAL_GPIO_WritePin(LORA_MDO_GPIO_Port,LORA_MDO_Pin,GPIO_PIN_SET);//进入配置模式
	HAL_Delay(500);
	if(lora_send_cmd("AT","OK",100))	mflag++;
	sprintf((char*)sendBuf,"AT+ADDR=%s,%s",ADDRH,ADDRL);
	if(lora_send_cmd(sendBuf,"OK",100))	mflag++;
	sprintf((char*)sendBuf,"AT+WLRATE=%d,%d",CHANNEL,RATE);
	if(lora_send_cmd(sendBuf,"OK",100))	mflag++;
	sprintf((char*)sendBuf,"AT+TPOWER=%d",POWER);
	if(lora_send_cmd(sendBuf,"OK",100))	mflag++;
	sprintf((char*)sendBuf,"AT+CWMODE=%d",CWMODE);
	if(lora_send_cmd(sendBuf,"OK",100))	mflag++;
	sprintf((char*)sendBuf,"AT+UART=%d,%d",UART_RATE,UART_PAR);//设置串口波特率、数据校验位
	if(lora_send_cmd(sendBuf,"OK",100))	mflag++;
	HAL_GPIO_WritePin(LORA_MDO_GPIO_Port,LORA_MDO_Pin,GPIO_PIN_RESET);//退出配置模式
	HAL_Delay(500);
	while(i--)
	{
		HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
		HAL_Delay(50);
	}
	printf("flag:%d\r\n",mflag);
}
