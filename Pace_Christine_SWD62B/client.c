#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "linked_list.h"

int main(int argc, char *argv[])
{
	if(argc == 4)
	{
		for(int i = atoi(argv[1]); i < atoi(argv[2]); i++){
			int sockfd;
			struct sockaddr_in serv_addr;

			/* Create a socket */
			sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (sockfd < 0) {
				fprintf(stderr, "ERROR: Failed to open socket\n");
				return 1;
			}

			/* Initialize socket structure (sockarrd_in) */
			memset(&serv_addr, 0, sizeof(serv_addr));
			serv_addr.sin_family = AF_INET;
			serv_addr.sin_port = htons(i);

			/* Connect to the server */
			if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == 0) {
				printf("\nPort: %d connected\n", i);
				// ADD PORT TO LIST
				node * newNode = CreateNode(i);
				Push(&top, newNode);
			}
			
			close(sockfd);
		}

		// PRINT LIST
		int size = ListSize(top);
		int*list;
		if (size > 0) {
			printf("\r\n-----------------------\n");
			printf("\r\nList of Connected Ports\n");
			list = ShowList(&top);
		}
		else if (size == 0) {
			printf("\nNo Ports where connected!\n");
		}
		printf("\r\n-----------------------\n");

		// SAVE TO OUTPUTFILE.CSV
		FILE *fp_output = fopen(argv[3], "w");
		if(fp_output != NULL)
		{
			for(int i = 0; list[i] != '\0'; ++i) {
				fprintf(fp_output, "%d \n", list[i]);
			}
			printf("Processing rows... \n");
			printf("Finished all file, results in outputfile.csv \n");

			fclose(fp_output);
		}
		else
		{
			printf("Failed to open %s \n", argv[3]);
			return -2;
		}


	}
	else
	{
		printf("\nProvide two arguments as range and an output file\n");
	}

	return 0;
}



