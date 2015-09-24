#include <stdio.h>
#include "velha.h"

int main(){

	initialSetup();

	int op = 0;

	while(op != 3){

		printf("\033[2J");
		printf("#############################################################################\n");
		printf("#                                  Velha                                    #\n");
		printf("#                                                                           #\n");
		printf("#                              1) Start                                     #\n");
		printf("#                                                                           #\n");
		printf("#                              2) Configure                                 #\n");
		printf("#                                                                           #\n");
		printf("#                              3) Exit                                      #\n");
		printf("#                                                                           #\n");
		printf("#############################################################################\n");
		printf("\n\n///> ");

		scanf("%d", &op);

		if(op == 1){
			start();
		}else if(op == 2){
			configure();
		}

	}

	printf("\033[2J");

	return 0;

}

