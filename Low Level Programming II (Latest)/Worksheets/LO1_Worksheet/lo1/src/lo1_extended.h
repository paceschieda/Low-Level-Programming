/*
 * lo1_extended.h
 *
 *  Created on: Oct 20, 2018
 *      Author: llp2
 */

#ifndef LO1_EXTENDED_H_
#define LO1_EXTENDED_H_

void clear_stdin(){
	char c;
	while((c = getchar()) != '\n'){
		;
	}
}


int func (int argc, char *argv[]) {

	if(!(should_count_chars(argc, argv)) && argc == 2){
		printf("\nError: Not a valid argument\n");
		return 0;
	}

	while(1){
			char sentence[500];
			int noWords = 0;
			int noChar = 0;

			printf("\nEnter a sentence: ");
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
			clear_stdin();
	}


	return 0;
}

#endif /* LO1_EXTENDED_H_ */
