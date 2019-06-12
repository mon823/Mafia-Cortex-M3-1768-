#include <LPC17xx.H>                    /* LPC17xx definitions                */
#include "GLCD.h"
#include "LPC1768_utility.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>



void start_Screen() {
	GLCD_clear(Black);
	for (;;)
	{
		GLCD_setBackColor(Black);
		GLCD_setTextColor(White);
		GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
		GLCD_displayStringLn(Line3, "     M A R F I A    ");
		GLCD_displayStringLn(Line5, " verson 1.          ");
		GLCD_displayStringLn(Line7, "          Press INT!");
		GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
		Delay(SEC_1);

		GLCD_setBackColor(Black);
		GLCD_setTextColor(White);
		GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line3, "     M A R F I A    ");
		GLCD_setTextColor(White);
		GLCD_displayStringLn(Line5, " verson 1.          ");
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line7, "          Press INT!");
		GLCD_setTextColor(White);
		GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
		Delay(SEC_1);

	}
}

void players_Info() {
	GLCD_clear(Black);
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
	GLCD_displayStringLn(Line1, "-                  *");
	GLCD_displayStringLn(Line2, "*   Player NUM [6] -");
	GLCD_displayStringLn(Line3, "-                  *");
	GLCD_displayStringLn(Line4, "*     Mafia    1   -");
	GLCD_displayStringLn(Line5, "-     Citizens 3   *");
	GLCD_displayStringLn(Line6, "*     Police   1   -");
	GLCD_displayStringLn(Line7, "-     Doctor   1   *");
	GLCD_displayStringLn(Line8, "*                  -");
	GLCD_displayStringLn(Line9, "-*-*-*-*-*-*-*-*-*-*");
}

void player_Id(int tmp) {
	GLCD_clear(Black);
	
	char s1[20] = "          1         ";
	s1[10] = tmp+49;
	
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
	GLCD_displayStringLn(Line2, "       Player       ");
	GLCD_setTextColor(Red);
	GLCD_displayStringLn(Line4,s1);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line7, "       _ _ _ _      ");
	GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
}

void star(int tmp){
	if(tmp == 0){
		GLCD_displayStringLn(Line7, "       * _ _ _      ");
	}else if(tmp == 1){
		GLCD_displayStringLn(Line7, "       * * _ _      ");
	}else if(tmp == 2){
		GLCD_displayStringLn(Line7, "       * * * _      ");
	}else if(tmp == 3){
		GLCD_displayStringLn(Line7, "       * * * *      ");
	}
	
}

void player_Job(int job, int tmp) {
	GLCD_clear(Black);
	
	
	
	char s2[20];
	
	if(job == 0) {
		strcpy(s2,"     M A R F I A    ");
	}
	else if(job == 1){
		strcpy(s2,"     D O C T O R    ");
	}
	else if(job == 2){
		strcpy(s2,"     P O L I C E    ");
	}
	else{
		strcpy(s2,"   C I T I Z E N S  ");
	}
	
	char s1[20]= "      Player  1     ";
	s1[14] = tmp+49;
	
	for (int i =0;i<2;i++) {
		GLCD_setBackColor(Black);
		GLCD_setTextColor(White);
		GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
		GLCD_displayStringLn(Line2, s1); 
		GLCD_displayStringLn(Line5, "      You are a     ");
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line7, s2); // 
		GLCD_setTextColor(White);
		GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
		Delay(SEC_5);                                        // <- System/8

		GLCD_setBackColor(Black);
		GLCD_setTextColor(White);
		GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
		GLCD_displayStringLn(Line2,s1); 
		GLCD_displayStringLn(Line5, "      You are a     ");
		GLCD_setTextColor(Black);
		GLCD_displayStringLn(Line7,s2); // 
		GLCD_setTextColor(White);
		GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
		Delay(SEC_5);                                        // <- System/8

	}
}

void day_one() {
	GLCD_clear(Black);
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
	GLCD_displayStringLn(Line3, "       D A Y 1      ");
	GLCD_displayStringLn(Line5, "     D E B A T E    ");
	GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");

}

void vote_screen() {
	GLCD_clear(Black);
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
	GLCD_displayStringLn(Line2, "       -VOTE-       ");
	GLCD_displayStringLn(Line4, "     Player [ ]     ");  // player number
	GLCD_displayStringLn(Line6, "       Yes[ ]       ");  // agree number
	GLCD_displayStringLn(Line7, "        No[ ]       ");  // disagree number
	GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");

}
void fix_player_num(int num){
	
	char s1[20] = "     Player [ ]     ";
	s1[13] = num + 48;
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line4, s1);  // player number
}

void fix_Yes_num(int num){
	
	char s1[20] = "       Yes[ ]       ";
	
	if(num == 0){
		s1[11] = '0';
	}
	else s1[11] = num + 48;
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line6, s1);  // player number
}

void fix_No_num(int num){
	
	char s1[20] = "        No[ ]       ";
	
	if(num == 0){
		s1[11] = '0' ;
	}
	
	else s1[11] = num + 48;
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line7, s1);  // player number
}

void select_Player() {
	GLCD_clear(Black);
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
	GLCD_displayStringLn(Line3, "       Select       ");  // marfia, doctor, police
	GLCD_displayStringLn(Line5, "        [ ]         ");
	GLCD_displayStringLn(Line7, "    PW : _ _ _ _    ");
	GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
}

void fix_select_player(int tmp){
	char s1[20] = "        [ ]         ";
	s1[9] = tmp+48;
	
	GLCD_displayStringLn(Line5,s1);
}

void star_pass (int tmp){
	if(tmp == 0){
		GLCD_displayStringLn(Line7, "    PW : * _ _ _    ");
	}else if(tmp == 1){
		GLCD_displayStringLn(Line7, "    PW : * * _ _    ");
	}else if(tmp == 2){
		GLCD_displayStringLn(Line7, "    PW : * * * _    ");
	}else if(tmp == 3){
		GLCD_displayStringLn(Line7, "    PW : * * * *    ");
	}
	else if(tmp == 9){
		GLCD_displayStringLn(Line7, "    PW : _ _ _ _    ");
	}
	
}

void test(int tmp){
	char s1[20] = "    PW : * * * *    ";
	s1[9]= tmp/1000 + '0';
	s1[11] = tmp%1000 / 100 +'0';
	s1[13] = tmp%100 / 10 + '0';
	s1[15] = tmp%10 + '0';
	
	GLCD_displayStringLn(Line7,s1);
	
	
}

void mafia()
{
	GLCD_clear(Black);
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
	GLCD_setTextColor(Red);
	GLCD_displayStringLn(Line2, "     M A R F I A    ");
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line4, "     Kill anyone    ");
	GLCD_displayStringLn(Line5, "      you want      ");
	GLCD_displayStringLn(Line7, "        [   ]       ");
	GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
}

void police()
{
	GLCD_clear(Black);
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
	GLCD_setTextColor(Red);
	GLCD_displayStringLn(Line2, "     P O L I C E    ");
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line4, "    select anyone   ");
	GLCD_displayStringLn(Line5, "  you want to know  ");
	GLCD_displayStringLn(Line7, "        [   ]       ");
	GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
}


// Mafia 
void po_Result(int tmp, int tmp1)
{
	
	char s1[20]= "                    ";
	char s2[20]= "       Player       ";
	
	
	tmp1++;
	if(tmp == 0){
		
		strcpy(s1,"      is Mafia      ");
		
	}
	else{
		strcpy(s1,"    is not Mafia    ");
		
	}
	
	
	
	s2[14] = tmp1+ 48;
	
	GLCD_clear(Black);
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
	GLCD_setTextColor(Red);
	GLCD_displayStringLn(Line2, "     P O L I C E    ");
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line5,s2); // 
	GLCD_displayStringLn(Line7,s1);
	GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
}

void doctor() {

	GLCD_clear(Black);
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
	GLCD_setTextColor(Red);
	GLCD_displayStringLn(Line2, "     D O C T O R    ");
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line4, "    select anyone   ");
	GLCD_displayStringLn(Line5, "  you want to heal  ");
	GLCD_displayStringLn(Line7, "        [   ]       ");
	GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");

}

void fix_doctor(int tmp){
	char s1[20] = "        [   ]       ";
	s1[10] = tmp+48;
	
	GLCD_displayStringLn(Line7, s1);
}

void day_two(int tmp) {
	
	char s1[20] = " player [ ] is dead " ;
	
	if(tmp == 0){
		strcpy(s1,"                    ");
	}
	else {
		s1[9] = tmp+48;
	}
	
	GLCD_clear(Black);
	GLCD_setBackColor(Black);
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
	GLCD_displayStringLn(Line3, "       D A Y 2      ");
	GLCD_setTextColor(Red);
	GLCD_displayStringLn(Line6, s1 );  // player [] is dead.
	GLCD_setTextColor(White);
	GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");

}

void marfia_Win() {
	GLCD_clear(Black);
	for (;;) {

		GLCD_setBackColor(Black);
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
		GLCD_setTextColor(Cyan);
		GLCD_displayStringLn(Line3, "     M A R F I A    "); //
		GLCD_displayStringLn(Line5, "     ** W I N **    ");
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
		Delay(SEC_5);   																			// <- System/8

		GLCD_setBackColor(Black);
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
		GLCD_setTextColor(White);
		GLCD_displayStringLn(Line3, "     M A R F I A    "); //
		GLCD_displayStringLn(Line5, "     ** W I N **    ");
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
		Delay(SEC_5);   																			// <- System/8	 
	}
}

void citizen_Win() {
	GLCD_clear(Black);
	for (;;) {

		GLCD_setBackColor(Black);
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
		GLCD_setTextColor(Cyan);
		GLCD_displayStringLn(Line3, "   C I T I Z E N S  "); //
		GLCD_displayStringLn(Line5, "     ** W I N **    ");
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
		Delay(SEC_5);   																			// <- System/8

		GLCD_setBackColor(Black);
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line0, "*-*-*-*-*-*-*-*-*-*-");
		GLCD_setTextColor(White);
		GLCD_displayStringLn(Line3, "   C I T I Z E N S  "); //
		GLCD_displayStringLn(Line5, "     ** W I N **    ");
		GLCD_setTextColor(Red);
		GLCD_displayStringLn(Line9, "*-*-*-*-*-*-*-*-*-*-");
		Delay(SEC_5);   																			// <- System/8	 
	}
}
