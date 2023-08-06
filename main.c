#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define rand rand()%7;//replace rand()%7 with word
int snakes[101]; //chart part an index of the array
int ladders[101];//part where to put the snake and ladders inside the chart
int cur_pos1=0,cur_pos2=0;//postion of p1 and p2 starting point 0

void red () { //red color of p1 and p2
  printf("\033[1;31m");
}

void reset () { //is for making other colors not in red
  printf("\033[0m");
}


int random (){ //dice random move
    srand(time(NULL));
	int rem= rand;
    while(! rem) rem= rand;
    return rem;
}

static inline void pxcd(int n){ //inline directly puts the code no need to call into the main function
    while(n--) printf("\xcd"); // Line
    printf("\n");
}

static inline void print_S_L(char* s, int* array){ //For Ladders and Snake to print
        printf("%s: |",s);
        for(int i=0; i<101; i++)
        if(array[i]) printf(" %2d to %2d |", i,array[i]);
        printf("\n");
}

static inline void print_value(int diceres){ //To print the board with color from 1-100
	    red();
		if(diceres== cur_pos1 && diceres ==cur_pos2)
				      printf("-P1-P2- ");
	    else if(cur_pos1==diceres)
					  printf("%s\t","-P1-");
	    else if(cur_pos2==diceres)
			 	      printf("%s\t","-P2-");
    	else { reset(); printf("%3d\t",diceres); }
		reset();
}

void displaychart(int dice,char* string){ //For Logic and placement of the number 1-10 11-20
	    system("cls");
		printf("%s\n",string);
		printf("\n\n");       pxcd(75);
        printf("\t\t\t    Snakes And Ladders\n");     pxcd(75);

	int i,j,t,c,diceres;
	for(i=10;i>0;i--)
	{
		t=i-1;
		if((i%2)==0)  {
			c=0;
			for(j=10;j>=1;j--)
			{
				diceres=(i*j)+(t*c++);
                print_value(diceres);
			}
		}
		else  {
			c=9;
			for(j=1;j<=10;j++)
			{
				diceres=(i*j)+(t*c--);
                print_value(diceres);
			}
		}
	     	printf("\n\n");
	}       pxcd(75);
           printf("\t\t\t\tDice = %d\n",dice);      pxcd(75);
	       print_S_L("Snakes",snakes);
           print_S_L("Ladder",ladders);
		   printf("\nChoose your option\n");
	 	   printf("[1] Player 1 plays\n");
		   printf("[2] Player 2 plays\n");
		   printf("[3] Exit\n");
}

static inline void displ(int n){ //Winning part
        system("cls");
		printf("\n\n");       pxcd(75);
        printf("\t\t\t    Snakes And Ladders\n");
        printf("\n\nCongratulations!!!!!! \n\nPlayer %d wins\n\n\n\n",n);
							 exit(0);
}

static inline int abcd(){ //User interface front page
	    system("cls");
		printf("\n\n");       pxcd(75);
        printf("\t\t\t    Snakes And Ladders\n");     pxcd(75);
		printf("\n\n\n");
		printf("\nChoose your option\n");
	 	printf("[1] START GAME\n");
		printf("[2] INSTRUCTIONS\n");
		printf("[3] Exit\n\n\n");
		pxcd(75);
		printf(" \t\t\tMade By: John Paul Cu\n");
		 pxcd(75);

		int x; scanf("%d",&x);
		if(x==1) return 1;
		if(x==2) return 2;
		if(x==3) exit(0);

}

static inline void instruction(){ //Instruction Part
	while(1){
	   system("cls");
		printf("\n\n");       pxcd(75);
        printf("\t\t\t    Snakes And Ladders\n");     pxcd(75);
		printf("\n\n");
	printf("The objective of the game is to be the first player to reach the end of the \nboard by typing 1 or 2 but the game has a twist the game  won't end if its \n100 above, it can only be finished if the player is accurately at the 100\nposition on the board.\n\n");

    printf("Here is how to play Snake and Ladders:\n");

   printf("1. The first player rolls the dice to determine how many spaces they can move\n   their game piece.\n");
printf("2. The game won't start if you type any incorrect characters.\n");
printf("3. If you land on a square with a ladder, you can move your game piece up the\n   ladder to a higher square. If you land on a square with a snake, you must\n   move your game piece down the snake to a lower square.\n");
printf("4. The next player rolls the dice and moves their game piece according to the\n   rules above. Play continues in a clockwise direction until one player reaches\n   the end of the board. The first player to reach the end \n   of the board is the winner.\n");
printf("5. Some variations of the game include special squares that allow players to\n   roll the dice again or skip their turn.\n");
   printf("\nChoose your option\n");
   printf("[1] BACK TO MAIN MENU\n");
   printf("[2] Exit\n");

   int x; scanf("%d",&x);
		if(x==1) return ;
		if(x==2) exit(0);
	}
}

void main(){
	//system("Color E0");

	while(1){
		int x= abcd(); //option pannel loop for instructions and front page
		if(x==1) break;
		if(x==2) instruction();
	}

	int dice;
	int ch;

    snakes[22]=2;             ladders[4]=16;
    snakes[28]=6;             ladders[8]=12;
    snakes[30]=10;            ladders[18]=36;
    snakes[44]=26;            ladders[20]=74;
    snakes[58]=42;            ladders[24]=36;
    snakes[64]=14;            ladders[32]=56;
    snakes[68]=52;            ladders[34]=44;
    snakes[72]=50;            ladders[40]=60;
    snakes[84]=62;            ladders[48]=54;
    snakes[94]=64;            ladders[70]=88;
    snakes[96]=82;            ladders[76]=86;
    snakes[98]=78;            ladders[80]=100;
                              ladders[90]=92;


	displaychart(0,"");
	while(1) // dice part and to check the ladder and the snake if p1 or p2 landed on it
	{
		char string[150]="";
		scanf("%d",&ch);
		switch(ch)
		{

			case 1:
                    dice=random();
					cur_pos1=dice+cur_pos1;
					if(cur_pos1<100){
                        if(snakes[cur_pos1]) cur_pos1=snakes[cur_pos1];
						else if(ladders[cur_pos1]) cur_pos1=ladders[cur_pos1];

					}
					else{
                        if(cur_pos1==100)
							 displ(1);

						cur_pos1=cur_pos1-dice;
					    strcat(string,"Range exceeded of Player 1.");
					}
					displaychart(dice,string);
				break;

			case 2:
			        dice=random();
					cur_pos2=dice+cur_pos2;
					if(cur_pos2<100){
                        if(snakes[cur_pos2]) cur_pos2=snakes[cur_pos2];
						else if(ladders[cur_pos2]) cur_pos2=ladders[cur_pos2];
					}
					else{
                        if(cur_pos2==100)
							 displ(2);

						cur_pos2=cur_pos2-dice;
						strcat(string,"Range exceeded of Player 2.");
					}
                    displaychart(dice,string);
				break;

			case 3 :exit(0);
				break;

			default:printf("Incorrect choice.Try Again\n");
		}

	}

}
