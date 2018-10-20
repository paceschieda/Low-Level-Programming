/*
 * demo_version.h
 *
 *  Created on: Oct 20, 2018
 *      Author: llp2
 */

#ifndef DEMO_VERSION_H_
#define DEMO_VERSION_H_

void Calculation(int num1, int num2, char *argv[]){
	if(strcmp(argv[2], "+") == 0){
		printf("\n%d + %d = %d \n", num1, num2, (num1+num2));
	}
	else if((strcmp(argv[2], "-") == 0) || (strcmp(argv[2], "/") == 0) || (strcmp(argv[2], "x") == 0)){
		printf("\nError: Demo only supports addition\n");
	}
	else{
		printf("\nError: invalid operator\n");
	}
}



#endif /* DEMO_VERSION_H_ */
