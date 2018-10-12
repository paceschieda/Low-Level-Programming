#include <stdio.h>

int main(int argc, char* argv[]){
	/* 
	NOTE: 	To access the entire element from argv, which are your arguments,
		one can simply iterate or loop through the array.
	 */
	for (int i = 0; i < argc; i++)
		printf("argv[%d] is: %s\n", i, argv[i]);
	
	return 0;
}