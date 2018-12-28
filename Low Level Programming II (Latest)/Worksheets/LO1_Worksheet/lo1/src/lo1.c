/*
 ============================================================================
 Name        : lo1.c
 Author      : Christine Pace
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lo1.h"



#if defined NRM
	#include "lo1_normal.h"
#elif defined EXT
	#include "lo1_extended.h"
#endif

int main(int argc, char *argv[]){

	func(argc, argv);
}
