#include "LPC17xx.H"
#include "Keypad.H"
#include "GLCD.h"
#include "LPC1768_utility.h"
#include <stdlib.h>
#include <time.h>

uint8_t Keypad_Value=20;
uint8_t userpass[6];
uint8_t userjob[6];
uint8_t day = 1;


void WinCitizens(){
	GLCD_displayStringLn(Line0, "    WinCitizens     ");
}

void winMafia(){
	GLCD_displayStringLn(Line0, "    WinMafia        ");
}

void isFin(){
	int mafiaTeam=0;
	int citizensTeam=0;
	for(int i=0;i<5;i++){
		if(userjob[i] == 0) mafiaTeam++;
		else if(userjob[i] < 7) citizensTeam ++;
	}
	if(mafiaTeam == 0) WinCitizens();
	else if(mafiaTeam == citizensTeam) winMafia();
}

void findpass(int user){
	int pas;
	for(;;){
		for(int i=0;i<4;i++){
			int temp;
			for(;;){
				Keypad_Value = 20;
				Keypad_Value = Keypad('C');
				if(Keypad_Value == 0)temp = 1;
				else if(Keypad_Value == 1){
					temp = 2;
					break;
				}
				else if(Keypad_Value == 2){
					temp = 3;
					break;
				}
				else if(Keypad_Value == 4){
					temp = 4;
					break;
				}
				else if(Keypad_Value == 5){
					temp = 5;
					break;
				}
				else if(Keypad_Value == 6){
					temp = 6;
					break;
				}
				else if(Keypad_Value == 8){
					temp = 7;
					break;
				}
				else if(Keypad_Value == 9){
					temp = 8;
					break;
				}
				else if(Keypad_Value == 10){
					temp = 9;
					break;
				}
				else continue;
			}
			for(int j=3;j>i;j--){
				temp *= 10;
			}
			pas += temp;
		}
		if (pas == userpass[user])break;
	}
	
}
void killcitizens(){
}
void healUser(){
	
}
void findUser(){
	
}

void checkUser(){
	int user;
	GLCD_displayStringLn(Line0, "    Select Player   ");	
	Keypad_Value = 20;
	for(;;){
		Keypad_Value = Keypad('C');
		if(Keypad_Value < 7) break;
	}
	user = Keypad_Value;
	findpass(user);
		
	if(user == 0)killcitizens();
	else if(user == 1) healUser();
	else if(user == 2) findUser();
}


void endDay(){
	
	
}

void debate(){
	
}



void startday(){
	
	GLCD_displayStringLn(Line0, "    Day  N          ");	
	
	debate();
}




void findJob(int i){
	
	/****************************************
	* 0 mafia
	* 1 doctor
	* 2 police
	* 3~5 citizens
	*****************************************/
	
	GLCD_displayStringLn(Line0, "    _ _ _ _         ");
	
}

int select_pass(int tmp){
	
	GLCD_displayStringLn(Line0, "    player n        ");
	GLCD_displayStringLn(Line0, "    _ _ _ _         ");
	
	if (tmp > 6)
	tmp++;
	int pas;
	for(int i=0;i<4;i++){
		int temp;
		for(;;){
			Keypad_Value = 20;
			Keypad_Value = Keypad('C');
			if(Keypad_Value == 0)temp = 1;
			else if(Keypad_Value == 1){
				temp = 2;
				break;
			}
			else if(Keypad_Value == 2){
				temp = 3;
				break;
			}
			else if(Keypad_Value == 4){
				temp = 4;
				break;
			}
			else if(Keypad_Value == 5){
				temp = 5;
				break;
			}
			else if(Keypad_Value == 6){
				temp = 6;
				break;
			}
			else if(Keypad_Value == 8){
				temp = 7;
				break;
			}
			else if(Keypad_Value == 9){
				temp = 8;
				break;
			}
			else if(Keypad_Value == 10){
				temp = 9;
				break;
			}
			else continue;
		}
		for(int j=3;j>i;j--){
			temp *= 10;
		}
		pas += temp;
	}
	
	userpass[tmp] = pas;
	
	findJob(userpass[tmp]);
	
	return tmp;
}


void init(){
	GLCD_displayStringLn(Line0, "    init page       ");
	
	
}

void Start_Page(){
	// LCD
	GLCD_displayStringLn(Line0, "    Start page      ");
}

int main(){
	
	SystemInit();		/* Initialize the MCU clocks     */
	GLCD_init();		/* Initialize the GLCD           */
	EXT_IO_init();
	
	Keypad_DIR_Input();		/* Keypad direction = input */
	
	srand(time(NULL));
	
	/****************************************
	* 0 mafia
	* 1 doctor
	* 2 police
	* 3~5 citizens
	*****************************************/
	
	
	for(int i=0;i<5;i++){
		userjob[i] = rand();
	}
	
	Start_Page();
	
	EXTI_Init(); // EXTI init
	AF_ConfigPin(GPIO_PORT_2, PINSEL_PIN_10, PINSEL_FUNC_1);	// 단순 GPIO 기능이 아닌 Alternate Function을 사용하기 위해 설정
	EXTI_ConfigPin(EXTI_EINT0); // EXTI0 설정
	NVIC_EnableIRQ(EINT0_IRQn); // EXTI0 활성화
	
	
	
}

void EINT0_IRQHandler(void)
{
	EXTI_ClearEXTIFlag(EXTI_EINT0);	// Interrupt 정보를 클리어 하여 다시 대기 상태로 바꾼다.
	init();
}
