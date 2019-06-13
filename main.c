#include "LPC17xx.H"
#include "Keypad.H"
#include "GLCD.h"
#include "LPC1768_utility.h"
#include <stdlib.h>
#include "lpc17xx_timer.h"
#include "Gui.h"
#include "LPC1768_fnd.h"


uint8_t time_10m =0 ;
uint8_t time_1m =0 ;
uint8_t time_10s = 0;
uint8_t time_1s = 0;
uint8_t time_tmp = 0;

TIM_TIMERCFG_Type TIM_ConfigStruct;
TIM_MATCHCFG_Type TIM_MatchConfigStruct ;

int userpass[6];
int userjob[6];
int day = 1;
int live = 6;
int dead_ = 0;


void TIMER0_Config(void);


void WinCitizens(){
	citizen_Win();
}

void winMafia(){
	marfia_Win();
}

void isFin(){
	int mafiaTeam=0;
	int citizensTeam=0;
	for(int i=0;i<6;i++){
		if(userjob[i] == 0) mafiaTeam++;
		else if(userjob[i] < 7) citizensTeam ++;
	}
	if(mafiaTeam == 0) WinCitizens();
	else if(mafiaTeam == citizensTeam) winMafia();
}

void findpass(int user){
	uint8_t Keypad_Value=0;
	int pas=0;
	int temp=0;
	for(;;){
		temp=0;
		pas=0;
		star_pass(9);
		for(int i=0;i<4;i++){
			while(1){
				Keypad_Value = 0;
				Keypad_Value = Keypad('C');
				if(Keypad_Value == 1){
					temp = 1;
					break;
				}
				else if(Keypad_Value == 2){
					temp = 2;
					break;
				}
				else if(Keypad_Value == 3){
					temp = 3;
					break;
				}
				else if(Keypad_Value == 5){
					temp = 4;
					break;
				}
				else if(Keypad_Value == 6){
					temp = 5;
					break;
				}
				else if(Keypad_Value == 7){
					temp = 6;
					break;
				}
				else if(Keypad_Value == 9){
					temp = 7;
					break;
				}
				else if(Keypad_Value == 10){
					temp = 8;
					break;
				}
				else if(Keypad_Value == 11){
					temp = 9;
					break;
				}
				else continue;
			}
			Delay(SEC_1/2);
			star_pass(i);
			for(int j=3;j>i;j--){
				temp *= 10;
			}
			pas += temp;
		}
		
		
		if(pas == userpass[user]){
			return;
		}
	}
}
int killcitizens(){
	uint8_t Keypad_Value=0;
	mafia();
	
	for(;;){
		Keypad_Value = Keypad('C');
		if(Keypad_Value < 8 && Keypad_Value>0) break;
	}
	Delay(SEC_1/2);
	if(Keypad_Value >4) Keypad_Value--;
	
	fix_doctor(Keypad_Value);
	Delay(SEC_2);
	return Keypad_Value;
	
}
int healUser(){
	uint8_t Keypad_Value=0;
	
	doctor();
	
	while(1){
		Keypad_Value = Keypad('C');
		if(Keypad_Value < 8 && Keypad_Value > 0) break;
	}
	Delay(SEC_1/2);
	if(Keypad_Value >4) Keypad_Value--;
	
	fix_doctor(Keypad_Value);
	Delay(SEC_2);
	return Keypad_Value;
	
}
void findUser(){
	uint8_t Keypad_Value=0;
	police();
	
	for(;;){
		Keypad_Value = Keypad('C');
		if(Keypad_Value < 8 && Keypad_Value>0) break;
	}
	Delay(SEC_1/2);
	if(Keypad_Value >4) Keypad_Value--;
	
	fix_doctor(Keypad_Value);
	
	Keypad_Value--;
	
	po_Result(userjob[Keypad_Value],Keypad_Value);	
	Delay(SEC_2);
	
//	if(userjob[Keypad_Value]==0)
//		po_Result();	
//	else
//		GLCD_displayStringLn(Line0, "    not mafia       ");	
}


void checkUser(){
	int user;
	int dead;
	int heal;
	for(int i = 0;i<live;i++){
		select_Player();
		uint8_t Keypad_Value=0;
		for(;;){
			Keypad_Value = Keypad('C');
			if(Keypad_Value < 8 && Keypad_Value>0) break;
		}
		Delay(SEC_1/2);
		if(Keypad_Value >4) Keypad_Value--;
		
		fix_select_player(Keypad_Value);
		
		user = Keypad_Value;
		user--;
		findpass(user);

		if(userjob[user] == 0){
			dead = killcitizens();
		}
		else if(userjob[user] == 1){
			heal = healUser();
		}
		else if(userjob[user] == 2){
			findUser();
		}
		
	}
	if(dead == heal){
		dead_ = 0;
	}
	else{
		userjob[--dead] = 7;
		dead_ = ++dead;
		live--;
	}
	isFin();
}


void vote(){
	vote_screen();
	uint8_t Keypad_Value=0;
	int user;
	int yes;
	int no;
	for(;;){
		Keypad_Value = Keypad('C');
		if(Keypad_Value < 8&&Keypad_Value > 0) break;
	}
	Delay(SEC_1/2);
	if(Keypad_Value >4) Keypad_Value--;
	fix_player_num(Keypad_Value);
	user = Keypad_Value;
	Keypad_Value = 0;
	for(;;){
		Keypad_Value = Keypad('C');
		if((Keypad_Value < 8 && Keypad_Value > 0 )|| Keypad_Value == 14 ) break;

	}
	Delay(SEC_1/2);
	if(Keypad_Value == 14) Keypad_Value = 0;
	else if(Keypad_Value > 4) Keypad_Value--;
	
	fix_Yes_num(Keypad_Value);
	yes = Keypad_Value;
	Keypad_Value = 0;
	for(;;){
		Keypad_Value = Keypad('C');
		if((Keypad_Value < 8&&Keypad_Value > 0 )|| Keypad_Value == 14) break;
	}
	Delay(SEC_1/2);
	if(Keypad_Value == 14) Keypad_Value = 0;
	else if(Keypad_Value > 4) Keypad_Value--;
	
	fix_No_num(Keypad_Value);
	no = Keypad_Value;
	Keypad_Value = 0;
	
	
	if(yes > no){
		userjob[--user] = 7;
		live--;
	}
	
	isFin();
}

void showFnd(){
	
	time_1s = 5;
	time_10s = 0;
	time_1m = 0;
	
	while(1){
		if(time_1s == 4){
			GLCD_displayStringLn(Line5, "*-*-*-*-*-*-*-*-*-*-");
		}
		if(time_1s == 0 && time_10s == 0 && time_1m == 0 ) break;
	}
	
//	while(1) 
//	{
//		
//		/* 진행 Time 표시 */
//		FND_COM_DATA_Select(8,time_1s);	// 8번째(오른쪽 맨 끝) 세그먼트에 time_1s 값 표시
//		Delay(5000);
//		FND_COM_DATA_Select(7,time_10s);	
//		Delay(5000);
//		FND_COM_DATA_Select(6,time_1m);	
//		Delay(5000);
//		FND_COM_DATA_Select(5,time_10m);	
//		Delay(5000);
//		
//		
//	}
	
}

void endDay(){
	
	day++;
	
	day_two(dead_,day);
	Delay(SEC_2);
	
//	showFnd();
		
	
	vote();
	
	checkUser();
	
	endDay();
	
}




void startday(){
	
	day_one();
	
//	showFnd();
	
	vote();
	checkUser();
	endDay();
}




void findJob(int job,int tmp){
	
	/****************************************
	* 0 mafia
	* 1 doctor
	* 2 police
	* 3~5 citizens
	*****************************************/
	
	player_Job(job,tmp);
}

void select_pass(int tmp){
	uint8_t Keypad_Value=0;
	
	if (tmp > 0) return;
	
	player_Id(tmp);
	
	int pas=0;
	for(int i=0;i<4;i++){
		int temp;
		
		Keypad_Value = 0;	
		while(1){
			
			Keypad_Value = Keypad('C');
			
			if(Keypad_Value == 1){
				temp = 1;
				break;
			}
			else if(Keypad_Value == 2){
				temp = 2;
				break;
			}
			else if(Keypad_Value == 3){
				temp = 3;
				break;
			}
			else if(Keypad_Value == 5){
				temp = 4;
				break;
			}
			else if(Keypad_Value == 6){
				temp = 5;
				break;
			}
			else if(Keypad_Value == 7){
				temp = 6;
				break;
			}
			else if(Keypad_Value == 9){
				temp = 7;
				break;
			}
			else if(Keypad_Value == 10){
				temp = 8;
				break;
			}
			else if(Keypad_Value == 11){
				temp = 9;
				break;
			}
			else continue;
		}
		Delay(SEC_1/2);
		star(i);
		for(int j=3;j>i;j--){
			temp *= 10;
		}
		pas += temp;
	}
	
	userpass[tmp] = pas;
		
	findJob(userjob[tmp],tmp);
	tmp++;
	select_pass(tmp);
//	return tmp;
}



void init(){
	players_Info();
	Delay(SEC_2);
	keypad();
	Delay(SEC_2);
	select_pass(0);
	startday();
}

void Start_Page(){
	// LCD
	start_Screen();

}

int main(){
	
	
	
	FND_Init();	// FND 사용 PIN 초기화
	
	SystemInit();		/* Initialize the MCU clocks     */
	
	GLCD_init();		/* Initialize the GLCD           */
	GLCD_clear(Black);                        /* Clear the GLCD                */
	EXT_IO_init();
	
	Keypad_DIR_Input();		/* Keypad direction = input */
	
	
	
//	Start_Page();
	
	EXTI_Init(); // EXTI init
	AF_ConfigPin(GPIO_PORT_2, PINSEL_PIN_10, PINSEL_FUNC_1);	// 단순 GPIO 기능이 아닌 Alternate Function을 사용하기 위해 설정
	EXTI_ConfigPin(EXTI_EINT0); // EXTI0 설정
	NVIC_EnableIRQ(EINT0_IRQn); // EXTI0 활성화
	
	
	TIMER0_Config();
	TIM_Init(LPC_TIM0, TIM_TIMER_MODE,&TIM_ConfigStruct);	//  TIM_ConfigStruct 설정 적용
	TIM_ConfigMatch(LPC_TIM0,&TIM_MatchConfigStruct);		// TIM_MatchConfigStruct 설정 적용
	NVIC_EnableIRQ(TIMER0_IRQn);	//	TIMER0 Interrupt 활성화
	TIM_Cmd(LPC_TIM0, ENABLE);	//	Timer Start
	
//	time_1m=3;
	
	
	
	/****************************************
	* 0 mafia
	* 1 doctor
	* 2 police
	* 3~5 citizens
	*****************************************/

	Start_Page();
	
	
	

	
}



void EINT0_IRQHandler(void)
{
	EXTI_ClearEXTIFlag(EXTI_EINT0);	// Interrupt 정보를 클리어 하여 다시 대기 상태로 바꾼다.
	
	srand(time_tmp);
	
	int bFound=0;
	
	for(int i=0;i<6;i++){
		while(1){
			userjob[i] = rand()%6;
			bFound = 0;
			for(int j = 0;j < i; ++j){
				if(userjob[j] == userjob[i]){
					bFound = 1;
					break;
				}
			}
			if(!bFound)break;
		}
	}
	
	init();
}


void TIMER0_IRQHandler(void)	// 1초에 한번 씩 진입
{
	TIM_ClearIntPending(LPC_TIM0, TIM_MR0_INT); //TIM0 interrupt clear
	// 초 : 1의 자리 , 10의 자리 / 분 : 1의 자리, 10의 자리

	time_tmp++;
	
	if(time_tmp == 100){
		time_1s--;
		
		if(time_1s == 0 && time_10s != 0){
			time_10s--;
			time_1s=9;
		
		}
	
		if(time_10s == 0 && time_1m != 0){
			time_1m--;
			time_10s=9;
		}
		
		
		time_tmp=0;
	}
}

void TIMER0_Config(void)
{
	TIM_ConfigStruct.PrescaleOption = TIM_PRESCALE_USVAL;	//	us(microsecond) 기준으로 Prescale 설정
	TIM_ConfigStruct.PrescaleValue	= 100;	//	100us
	TIM_MatchConfigStruct.MatchChannel = 0;	//	0번 채널 사용
	TIM_MatchConfigStruct.IntOnMatch = ENABLE;	//	Timer가 일치할 때  Interrupt 발생 Enable
	TIM_MatchConfigStruct.ResetOnMatch = ENABLE;	//	Timer가 일치할 때  Reset Enable
	TIM_MatchConfigStruct.StopOnMatch = DISABLE;	//	Timer가 일치할 때 Timer Stop Disable
	TIM_MatchConfigStruct.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;	//	Timer 일치할때 아무런 외부 출력 하지 않음 (외부로 출력하지 않기 때문에 GPIO를 설정하지 않아도 됨.)
	TIM_MatchConfigStruct.MatchValue = 100;	// Timer 일치 값 설정 100us * 10000번 = 1초
}
