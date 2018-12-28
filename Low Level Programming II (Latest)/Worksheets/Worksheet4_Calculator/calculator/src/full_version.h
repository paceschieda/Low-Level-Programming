/*
 * full_version.h
 *
 *  Created on: Oct 20, 2018
 *      Author: llp2
 */

#ifndef FULL_VERSION_H_
#define FULL_VERSION_H_

void Calculation(int num1, int num2, char *argv[]){
	if(strcmp(argv[2], "+") == 0){
		printf("\n%d + %d = %d \n", num1, num2, (num1+num2));
	}
	else if(strcmp(argv[2], "-") == 0){
		printf("\n%d - %d = %d \n", num1, num2, (num1-num2));
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

#endif /* FULL_VERSION_H_ */
