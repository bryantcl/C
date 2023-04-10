#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

	// create socket
	int network_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specify address for socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// call connect function
	int connection_status =	connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if (connection_status == -1) {
		printf("There was an error making a connection to the remote socket \n\n");
	}
	
	char server_response[250];
	recv(network_socket, &server_response, sizeof(server_response), 0);

	// print data we get from server
	printf("The server the data: %s\n", server_response);
	
	close(network_socket);
	
	return 0;
}
