/*
 ============================================================================
 Name        : calculator.c
 Author      : Christine Pace
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

#if defined DEMO
	#include "demo_version.h"
#elif defined FULL
#include "full_version.h"
#endif


BOOL check_if_number(char* string){
	for(int i = 0; i < strlen(string); i++){
		if(!isdigit(string[i]) && string[i] != '-'){
			return FALSE;
		}
	}
	return TRUE;
}


int main(int argc, char *argv[]) {

	if(argc > 1){
		// Check the arguments
		if(argc == 2){
			// Only one argument
			if((strcmp(argv[1], "-") == 0) || (strcmp(argv[1], "+") == 0) || (strcmp(argv[1], "/") == 0) || strcmp(argv[1], "x") == 0){
				printf("\nError: Missing a number\n");
			}
			else if(check_if_number(argv[1]) == 1){
				printf("\nError: Missing an operator\n");
			}
			else{
				printf("\nError: Missing a number\n");
			}
		}
		else if(argc == 3){
			// Only two arguments
			if((strcmp(argv[1], "-") == 0) || (strcmp(argv[1], "+") == 0) || (strcmp(argv[1], "/") == 0) || strcmp(argv[1], "x") == 0){
				printf("\nError: Missing a number\n");
			}
			else if(check_if_number(argv[1]) == 1){
				if((strcmp(argv[2], "-") == 0) || (strcmp(argv[2], "+") == 0) || (strcmp(argv[2], "/") == 0) || strcmp(argv[2], "x") == 0){
					printf("\nError: Missing a number\n");
				}
				else if(check_if_number(argv[2]) == 1){
					printf("\nError: Missing an operator\n");
				}
				else{
					printf("\nError: Missing a number\n");
				}
			}
			else{
				printf("\nError: Missing a number\n");
			}
		}
		else if(argc == 4){
			// All arguments passed
			if((!check_if_number(argv[1])) || (!check_if_number(argv[3]))){
				printf("\nError: Invalid number\n");
			}else{
				int num1 = atoi(argv[1]);
				int num2 = atoi(argv[3]);

				Calculation(num1, num2, argv);
			}
		}
		else{
			// A lot of arguments provided
			printf("\nError: Only 3 arguments should be passed\n");
		}
	}
	else{
		// No arguments
		printf("\nError: No arguments available\n");
	}


	return EXIT_SUCCESS;
}
