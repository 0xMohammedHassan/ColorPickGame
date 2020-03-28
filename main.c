#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int cash = 100; //started money

void Start(int bid) {
	system("cls");
	char *o = (char*) malloc(30000* sizeof(char)); //dynamic memory allocation
	o[0] = 'G';
	o[1] = 'R';
	o[2] = 'B';
	printf("\n Randomization now.....\n");
	srand(time(NULL));
	int i;
	for (i =0; i < 5; i++) { // here will will do the randomization 5 times
		int x = rand() % 3;
		int y = rand() % 3;
		int z = o[x];
		o[x] = o[y];
		o[y] = z;
	}
	int GuessNow;
	//printf("\n Test  %c %c %c \n", o[0], o[1], o[2]); just a test to check where is the current position of Green
	printf("What is the position of Green? 1,2 or 3? ");

	scanf("%d", &GuessNow);

	if (bid > 30) { //Increasing the chance of winning only if the bid is more than 30, the trick here is if the current bid of the user is not true , we are increasing the index to the next one and then guess, and here the chance of win will be 66.666%
		if (o[GuessNow - 1] != 'G') {

			GuessNow++;
		}
	}
	
	if (o[GuessNow -1 ] == 'G') {// here we minus 1 because the array start from 0, so if the user enter 2 , that mean the second element of array
		cash += bid*2;
		printf(" \n You Win! , The result is: %c %c %c, and your current cash is:%d", o[0], o[1], o[2],cash);
	}
	else {
		cash -= bid; // minus the current bid from the current cash
		printf("\n You lost :( , Your current cash is: %d \n", cash);
		printf("\n The result is %c %c %c \n", o[0], o[1], o[2]);
	}
	free(o); //deallocation from memory or we will have a memory leak :p
}


int main() {
	int option;
	int bid =0;
	system("title PickGame");
	printf("*****Pick Game*******\n");
	printf("1-)Start \n");
	printf("2-)Help \n");
	printf("\nEnter an option to start: ");
	
	scanf("%d",&option);
	if (option > 3 || option < 0 || option == NULL) {

		printf("\n Error option!\n");
		exit(0);
	}
	if (option == 1) {

		while(cash > 0 ){
			printf("**Total Cash = %d**\n", cash);
			printf("\nWhat is your bid?");

		scanf("%d", &bid);
		if (bid > cash || bid == 0 ||  bid < 0) {

			printf(" \n Wrong entry! Exit now...");

			break;
		
		}
		

		Start(bid);
		printf("\n**************************************\n");
		}
	}
	else if (option == 2) {

		printf("Welcome to Color Pick game!, Here you will need to guess the position of the color\nThere will be a 3 positions and it will be randomized each time you play\nYou have only 100$ cash, you will start tries for cash,when you success guessing the position,\nyou will earn a double price	 based into your current bid!, when you lose , you will just lose\nthe current bid of cash from your total cash , each time you increase the amount of bid \nYou will higher your chance of win!\n Hint: Bids from 30 and more will have higher chance for win. \nGood Luck!");
	}
	else {

		printf("\nInsert a correct option! \n");
	}
	
	getchar();

	return 0;
}