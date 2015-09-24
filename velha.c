#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "velha.h"

Player player1;
Player player2;

void initialSetup(){

	strcpy(player1.name, "Player 1");
	strcpy(player1.symbol, "X");

	strcpy(player2.name, "Player 2");
	strcpy(player2.symbol, "O");

	int i;

	for(i=0; i<sizeof(scenario)/sizeof(char); i++){
		scenario[i] = ' ';
	}

}

void changePlayerName(){

	int p;

	printf("\033[2J");
	printf("#############################################################################\n");
	printf("#                             Velha - Configure                             #\n");
	printf("#                                                                           #\n");
	printf("#      Choose the player to change its name(1 or 2):                        #\n");
	printf("#############################################################################\n");
	printf("\n\n///> ");

	scanf("%d", &p);

	if(p == 1){

		printf("\033[2J");
		printf("#############################################################################\n");
		printf("#                             Velha - Configure                             #\n");
		printf("#                                                                           #\n");
		printf("#      Write the new name:                                                  #\n");
		printf("#############################################################################\n");
		printf("\n\n///> ");

		scanf("%s", player1.name);

	}else if(p == 2){

		printf("\033[2J");
		printf("#############################################################################\n");
		printf("#                             Velha - Configure                             #\n");
		printf("#                                                                           #\n");
		printf("#      Write the new name:                                                  #\n");
		printf("#############################################################################\n");
		printf("\n\n///> ");

		scanf("%s", player2.name);

	}

}

void changePlayerSymbol(){

	int p;
	char newSymbol[1];

	printf("\033[2J");
	printf("#############################################################################\n");
	printf("#                             Velha - Configure                             #\n");
	printf("#                                                                           #\n");
	printf("#      Choose the player to change its symbol(1 or 2):                      #\n");
	printf("#############################################################################\n");
	printf("\n\n///> ");

	scanf("%d", &p);

	if(p == 1){

		printf("\033[2J");
		printf("#############################################################################\n");
		printf("#                             Velha - Configure                             #\n");
		printf("#                                                                           #\n");
		printf("#      Write the new symbol:                                                #\n");
		printf("#############################################################################\n");
		printf("\n\n///> ");

		scanf("%s", newSymbol);

		if(strcmp(newSymbol, player2.symbol) != 0)
			strcpy(player1.symbol, newSymbol);

	}else if(p == 2){

		printf("\033[2J");
		printf("#############################################################################\n");
		printf("#                             Velha - Configure                             #\n");
		printf("#                                                                           #\n");
		printf("#      Write the new symbol:                                                #\n");
		printf("#############################################################################\n");
		printf("\n\n///> ");

		scanf("%s", newSymbol);

		if(strcmp(newSymbol, player1.symbol) != 0)
			strcpy(player2.symbol, newSymbol);

	}

}

void configure(){

	int op = 0;

	while(op != 3){

		printf("\033[2J");
		printf("#############################################################################\n");
		printf("#                             Velha - Configure                             #\n");
		printf("#                                                                           #\n");
		printf("#                              1) Change player name                        #\n");
		printf("#                                                                           #\n");
		printf("#                              2) Change player symbol                      #\n");
		printf("#                                                                           #\n");
		printf("#                              3) Back                                      #\n");
		printf("#                                                                           #\n");
		printf("#############################################################################\n");
		printf("\n\n///> ");

		scanf("%d", &op);

		if(op == 1){
			changePlayerName();
		}else if(op == 2){
			changePlayerSymbol();
		}

	}

}

void drawScenario(){

	printf("\033[2J");
	printf("#############\n");
	printf("#   #   #   #\n");
	printf("# %c # %c # %c #\n", scenario[0], scenario[1], scenario[2]);
	printf("#   #   #   #\n");
	printf("#############\n");
	printf("#   #   #   #\n");
	printf("# %c # %c # %c #\n", scenario[3], scenario[4], scenario[5]);
	printf("#   #   #   #\n");
	printf("#############\n");
	printf("#   #   #   #\n");
	printf("# %c # %c # %c #\n", scenario[6], scenario[7], scenario[8]);
	printf("#   #   #   #\n");
	printf("#############\n");

}

void start(){

	short int status = 0;
	short int round;
	short int winner;

	if((rand() % 2) + 1 == 1)
		round = 0;
	else 
		round = 1;

	while(!status){

		int cel;

		if(round){

			do {
				drawScenario();
				printf("%s/> ", player1.name);
				scanf("%d", &cel);
			} while(scenario[cel-1] != ' ');

			scenario[cel-1] = player1.symbol[0];
			round = !round;

		}else{

			do {
				drawScenario();
				printf("%s/> ", player2.name);
				scanf("%d", &cel);
			} while(scenario[cel-1] != ' ');

			scenario[cel-1] = player2.symbol[0];
			round = !round;

		}

		if(scenario[0] == player1.symbol[0]
			&& scenario[1] == player1.symbol[0]
			&& scenario[2] == player1.symbol[0]){

			winner = 0;
			status = 1;

		}else if(scenario[3] == player1.symbol[0]
			&& scenario[4] == player1.symbol[0]
			&& scenario[5] == player1.symbol[0]){

			winner = 0;
			status = 1;

		}else if(scenario[6] == player1.symbol[0]
			&& scenario[7] == player1.symbol[0]
			&& scenario[8] == player1.symbol[0]){

			winner = 0;
			status = 1;

		}else if(scenario[0] == player1.symbol[0]
			&& scenario[3] == player1.symbol[0]
			&& scenario[6] == player1.symbol[0]){

			winner = 0;
			status = 1;

		}else if(scenario[1] == player1.symbol[0]
			&& scenario[4] == player1.symbol[0]
			&& scenario[7] == player1.symbol[0]){

			winner = 0;
			status = 1;

		}else if(scenario[2] == player1.symbol[0]
			&& scenario[5] == player1.symbol[0]
			&& scenario[8] == player1.symbol[0]){

			winner = 0;
			status = 1;

		}else if(scenario[0] == player1.symbol[0]
			&& scenario[4] == player1.symbol[0]
			&& scenario[8] == player1.symbol[0]){

			winner = 0;
			status = 1;

		}else if(scenario[2] == player1.symbol[0]
			&& scenario[4] == player1.symbol[0]
			&& scenario[6] == player1.symbol[0]){

			winner = 0;
			status = 1;

		}else if(scenario[0] == player2.symbol[0]
			&& scenario[1] == player2.symbol[0]
			&& scenario[2] == player2.symbol[0]){

			winner = 1;
			status = 1;

		}else if(scenario[3] == player2.symbol[0]
			&& scenario[4] == player2.symbol[0]
			&& scenario[5] == player2.symbol[0]){

			winner = 1;
			status = 1;

		}else if(scenario[6] == player2.symbol[0]
			&& scenario[7] == player2.symbol[0]
			&& scenario[8] == player2.symbol[0]){

			winner = 1;
			status = 1;

		}else if(scenario[0] == player2.symbol[0]
			&& scenario[3] == player2.symbol[0]
			&& scenario[6] == player2.symbol[0]){

			winner = 1;
			status = 1;

		}else if(scenario[1] == player2.symbol[0]
			&& scenario[4] == player2.symbol[0]
			&& scenario[7] == player2.symbol[0]){

			winner = 1;
			status = 1;

		}else if(scenario[2] == player2.symbol[0]
			&& scenario[5] == player2.symbol[0]
			&& scenario[8] == player2.symbol[0]){

			winner = 1;
			status = 1;

		}else if(scenario[0] == player2.symbol[0]
			&& scenario[4] == player2.symbol[0]
			&& scenario[8] == player2.symbol[0]){

			winner = 1;
			status = 1;

		}else if(scenario[2] == player2.symbol[0]
			&& scenario[4] == player2.symbol[0]
			&& scenario[6] == player2.symbol[0]){

			winner = 1;
			status = 1;

		}else if(scenario[0] != ' ' && scenario[1] != ' ' && scenario[2] != ' '
			&& scenario[3] != ' ' && scenario[4] != ' ' && scenario[5] != ' '
			&& scenario[6] != ' ' && scenario[7] != ' ' && scenario[8] != ' '){

			winner = 2;
			status = 1;

		}

	}

	drawScenario();
	printf("\n\n");

	if(winner == 0){
		printf("%s win!\n", player1.name);
	}else if(winner == 1){
		printf("%s win!\n", player2.name);
	}else{
		printf("Velha!\n");
	}

	int op;
	printf("1) New Game - 2) Finish: ");
	scanf("%d", &op);

	int i;

	for(i=0; i<sizeof(scenario)/sizeof(char); i++){
		scenario[i] = ' ';
	}

	if(op == 1) start();

}

