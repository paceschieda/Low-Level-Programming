/*
 * lo1_normal.h
 *
 *  Created on: Oct 20, 2018
 *      Author: llp2
 */

#ifndef LO1_NORMAL_H_
#define LO1_NORMAL_H_

int func (int argc, char *argv[]) {

	if(!(should_count_chars(argc, argv)) && argc == 2){
		printf("\nError: Not a valid argument\n");
		return 0;
	}

	char sentence[500];
	int noWords = 0;
	int noChar = 0;

	printf("Enter a sentence: ");
	scanf("%[^\n]s",sentence);

	if(!(is_space(sentence[0]))){
		noWords = 1;
		for(int i = 0; sentence[i] != '\0'; i++){
			if(sentence[i] == ' '){
				noWords++;
			}
			if(should_count_chars(argc, argv)){
				noChar++;
			}
		}

		if(should_count_chars(argc, argv)){
			printf("\nNumber of Words: %i (%i characters)\n", noWords, noChar);
		}
		else{
			printf("\nNumber of Words: %i \n", noWords);
		}
	}else{
		printf("\nError: No input was provided\n");
	}



	return 0;
}

#endif /* LO1_NORMAL_H_ */
