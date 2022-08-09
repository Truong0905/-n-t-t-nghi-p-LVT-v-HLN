#include"DataPLC.h"

volatile static uint8_t I[3][8]={};
volatile static uint8_t Q[3][8]={};
volatile static uint8_t M[3][8]={};
volatile static uint8_t C1 = 0 ;
volatile static uint32_t countC1 = 0 ;
volatile static uint8_t vaoC1 = 0 ;
volatile static uint8_t resetC1 = 0 ;
volatile static const uint32_t datC1 = 5;
volatile static uint8_t startC1 = 0 ;
volatile static uint8_t checkC1 = 0 ;

void read_Pin_Input()
{
I0_0 = !HAL_GPIO_ReadPin(I0_0_PORT, I0_0_PIN);
I0_1 = !HAL_GPIO_ReadPin(I0_1_PORT, I0_1_PIN);
I0_2 = !HAL_GPIO_ReadPin(I0_2_PORT, I0_2_PIN);
I0_3 = !HAL_GPIO_ReadPin(I0_3_PORT, I0_3_PIN);
I0_4 = !HAL_GPIO_ReadPin(I0_4_PORT, I0_4_PIN);
I0_5 = !HAL_GPIO_ReadPin(I0_5_PORT, I0_5_PIN);
I1_0 = !HAL_GPIO_ReadPin(I1_0_PORT, I1_0_PIN);
I1_1 = !HAL_GPIO_ReadPin(I1_1_PORT, I1_1_PIN);
}
void write_Pin_Output()
{
if(Q0_0 >= 1){
		HAL_GPIO_WritePin(Q0_0_PORT, Q0_0_PIN, ENABLE);
		}
	else{
		HAL_GPIO_WritePin(Q0_0_PORT, Q0_0_PIN, DISABLE);
	}
}
void Main_task( void *param)
{
while(1)
{
read_Pin_Input();
/*--------------NetWork 1 -----------*/

vaoC1 = (((!(I0_0*I0_1))+(I0_3*I0_2))*I0_4) ;
resetC1 = (I0_5) ;
if (resetC1) 
{
countC1 = 0 ;
C1 = 0 ; 
startC1 = 1 ;
}
else
{
if (vaoC1)
{
 if ( ( (checkC1 ==1 ) || ( startC1 ==1 ) ) && (countC1 <= 4294967295)  )
{
countC1 ++ ;
startC1 = 0 ;
}
if (countC1 >= datC1 )
{C1 =1 ;
}
}
else 
{
 checkC1 = 1 ;
}
}
/*--------------NetWork 2 -----------*/

Q0_0=(((((I1_0*I1_1))+Q0_0))*!M0_0) ;
if (Q0_0>0)
{
Q0_0 = 1;
}
else
{
Q0_0 = 0 ;
}
 write_Pin_Output();
}
}
