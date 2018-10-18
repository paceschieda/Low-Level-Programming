/*
 ============================================================================
 Name        : Worksheet4.c
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

BOOL check_if_number(char* string){
	for(int i = 0; i < strlen(string); i++){
		if(!isdigit(string[i]) && string[i] != '-'){
			return FALSE;
		}
	}
	return TRUE;
}

int main(int argc, char *argv[]) {

	int valid = 0;
	int num1;
	int num2;

	if(argc > 1){
		// Check first argument
		if(argc == 2){
			if(!check_if_number(argv[1])){
				printf("\nError: missing number\n");
			}else if(strcmp(argv[1], "-") != 0){
				printf("\nError: missing operator \n");
			}
		}
		//Check second argument
		if(argc == 3){
			if(!check_if_number(argv[2])){
				printf("\nError: missing number\n");
			}else if(strcmp(argv[2], "-") != 0){
				printf("\nError: missing operator \n");
			}
		}
		if(argc == 4){
			if(valid == 0){
				if(!check_if_number(argv[1])){
					printf("\nError: invalid number\n");
				}
				else if(!check_if_number(argv[3])){
					printf("\nError: invalid number\n");
				}else{
					valid = 1;
				}
			}
			if(valid == 1){
				num1 = atoi(argv[1]);
				num2 = atoi(argv[3]);
				if(strcmp(argv[2], "-") == 0){
					printf("\n%d - %d = %d \n", num1, num2, (num1-num2));
				}
				else if(strcmp(argv[2], "+") == 0){
					printf("\n%d + %d = %d \n", num1, num2, (num1+num2));
				}
				else if(strcmp(argv[2], "x") == 0){
					printf("\n%d x %d = %d \n", num1, num2, (num1*num2));
				}
				else if(strcmp(argv[2], "/") == 0){
					printf("\n%d / %d = %f \n", num1, num2, ((float)num1/num2));
				}else{
					printf("\nError: invalid operator\n");
				}
			}
		}
	}
	else{
		printf("\nError: No Arguments\n");
	}


	return EXIT_SUCCESS;
}
