#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "linked_list.h"

int main(int argc, char *argv[])
{
	if(argc == 3)
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
				node * newNode = CreateNode(i);
				Push(&top, newNode);
			}
			
			close(sockfd);
		}
		int size = ListSize(top);
		if (size > 0) {
			printf("\r\n-----------------------\n");
			printf("\r\nList of Connected Ports\n");
			ShowList(&top);
		}
		else if (size == 0) {
			printf("\nNo Ports where connected!\n");
		}
	}
	else
	{
		printf("\nProvide two arguments as range\n");
	}

	return 0;
}



