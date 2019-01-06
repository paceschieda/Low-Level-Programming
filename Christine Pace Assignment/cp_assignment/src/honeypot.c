/*
 * honeypot.c
 *
 *  Created on: Dec 17, 2018
 *      Author: llp2
 */


#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#ifdef Honeypot_lite
	#include "honeypot_lite.h"
#endif
#ifdef Honeypot_full
	#include "Honeypot_full.h"
#endif

#define BUFFER_SIZE	1024
#define MAX_CONNECTIONS 5

int main(int argc, char *argv[]) {
	if(argc > 1){
		if(argc == 2){

			int sockfd, newsockfd, num_bytes;
			char buffer[BUFFER_SIZE];
			struct sockaddr_in serv_addr, cli_addr;
			socklen_t clilen = sizeof(cli_addr);


			/* Create a socket */
			sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (sockfd < 0) {
				fprintf(stderr, "ERROR: Failed to open socket\n");
				return 1;
			}

			/* Initialize socket structure (sockarrd_in) */
			memset(&serv_addr, 0, sizeof(serv_addr));
			serv_addr.sin_family = AF_INET;
			serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); //or INADDR_ANY
			int port = atoi(argv[1]);
			serv_addr.sin_port = htons(port);

			/* Bind the host address */
			if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
				fprintf(stderr, "ERROR: bind() failed\n");
				fprintf(stderr, "Error code: %s\n", strerror(errno));
				return 2;
			}

			/* Start listening for the clients (thread blocks) */
			if (listen(sockfd, MAX_CONNECTIONS) < 0) {
				fprintf(stderr, "ERROR: listen() failed\n");
				fprintf(stderr, "Error code: %s\n", strerror(errno));
				return 3;
			}

			//* Accept connection from a client */
			for(;;){
				newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
				if (newsockfd < 0) {
					fprintf(stderr, "ERROR: accept() failed\n");
					return 4;
				}
				printf('Accepted');
			}

		}
	}
	else{
		// No arguments
		printf("\nError: No arguments available\n");
	}

	return EXIT_SUCCESS;
}
