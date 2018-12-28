/*
 ============================================================================
 Name        : LO2_Worksheet.c
 Author      : Christine Pace
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	const char *sentence = "The best teacher is your last mistake";
	char buffer1[50];   // stack
	char *buffer2 = malloc(50);  // heap
	strcpy(buffer1, sentence);
	strcpy(buffer2, sentence);
	printf("%s \n", buffer1);
	printf("%s", buffer2);
	free(buffer2);
	return EXIT_SUCCESS;
}
