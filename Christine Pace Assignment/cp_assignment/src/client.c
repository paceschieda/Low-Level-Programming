/*
 * client.c
 *
 *  Created on: Jan 4, 2019
 *      Author: llp2
 */

#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include "linked_list.h"

#define BUFFER_SIZE	1024
#define MAX_CONNECTIONS 5

int main(int argc, char *argv[])
{
	// pass range as arguments
	for(int i = 10; i < 21; i++){
		int sockfd, num_bytes;
			struct sockaddr_in serv_addr;
			struct hostent *url;
			char buffer[BUFFER_SIZE] = {0};

			/* Create a socket */
			sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (sockfd < 0) {
				fprintf(stderr, "ERROR: Failed to open socket\n");
				return 1;
			}

			/* Initialize socket structure (sockarrd_in) */
			memset(&serv_addr, 0, sizeof(serv_addr));
			serv_addr.sin_family = AF_INET;
			memcpy(&serv_addr.sin_addr, url->h_addr, url->h_length);
			serv_addr.sin_port = htons(i);

			/* Connect to the server */
			if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == 0) {
				printf('Port: %i connected', i);
			}

			close(sockfd);
	}

	return 0;
}



