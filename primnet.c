#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main() {
    int update_socket, lbind, tam;
    //The sockaddr_in structure is used to specify a transport address and an IPv4 port.
    struct sockaddr_in local, remote;
    unsigned char msj[100] = "Hola red soy Luis";
    int update_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (update_socket == -1) {
        perror("Error opening socket");
        exit(1);
    }
    else {
        perror("Socket created");
        local.sin_family = AF_INET;
        local.sin_addr.s_addr = INADDR_ANY;
        local.sin_port = htons(0);
        lbind = bind(update_socket, (struct sockaddr*)&local, sizeof(local));
        if (lbind == -1) {
            perror("Error in bind");
            exit(1);
        }
        else {
            perror("Bind done");
            remote.sin_family = AF_INET;
            remote.sin_addr.s_addr = INADDR_ANY;
            remote.sin_port = htons(53);
            remote.sin_addr.s_addr = inet_addr("8.8.8.8");
            tam = sendto(udp_socket, msj, sizeof(msj), 0, (struct sockaddr*)&remote, sizeof(remote));
            if (tam == -1) {
                perror("Error in sendto");
                exit(1);
            }
            else {
                perror("Sendto done");
            }
        }
    }

    close(update_socket);
    return 0;
}

//The socket function allows us to create a communication endpoint and returns a file descriptor that we will use for all subsequent network operations.
//It has the following structure: socket(int domain, int type, int protocol). The domain specifies the address or protocol family to be used—for example, AF_INET (IPv4), AF_INET6 (IPv6), or AF_UNIX/AF_LOCAL (for inter-process communication on the same machine).
//The type defines the communication mode of the connection: SOCK_DGRAM (UDP) or SOCK_STREAM (TCP).
//The protocol specifies a particular protocol for the connection; however, if set to 0, the operating system will select the optimal one for the connection type.
