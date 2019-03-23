#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("usage: dnsres NAME\n");
		printf("example: dnsres www.google.com\n");
		exit(1);
	}
	char *hostname = argv[1];
	struct addrinfo hints, *res;
	int err;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;

	if ((err = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
		gai_strerror(err);
		exit(1);
	}
	printf("ip address : %s\n", inet_ntoa(((struct sockaddr_in *)res->ai_addr)->sin_addr));
	freeaddrinfo(res);
	exit(0);
}

