/*
 * lo1.h
 *
 *  Created on: Oct 20, 2018
 *      Author: llp2
 */


#ifndef LO1_H_
#define LO1_H_

#include <stdbool.h>
#include <string.h>

bool should_count_chars(int argc, char* argv[]){
	if(argc == 2){
		if(strcmp(argv[1], "-c") == 0){
			return true;
		}
		return false;
	}
	return false;
}

bool is_space(char c){
	if(c == '\0' || c == ' ' || c == '\t'){
		return true;
	}
	return false;
}

#endif /* LO1_H_ */
