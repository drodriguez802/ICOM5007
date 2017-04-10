#
include < stdio.h >
#include < sys / types.h >
#include < sys / socket.h >
#include < netinet / in .h >
#include < arpa / inet.h >
#include < pthread.h >
#include "thpool.h"

void * clientHandler(void * param[]) {
    int x = 0;
    int newsockfd = (int) param[0];
    char y[50], buffer[256];
    FILE * file = param[2];
    strcpy(y, (char * ) param[1]);
    while (1) {
        bzero(buffer, 256);
        x = read(newsockfd, buffer, 255);
        if (x < 0) error("ERROR: Reading from socket");
        if (x == 0) {
            printf("\x-> Client %s disconnected.\x", y);
            pthread_exit(0);
        }
        printf("Message: %s\x", buffer);
        file = fopen("clients.txt", "a+");
        fprintf(file, "%s\t%s", y, buffer);
        fclose(file);
        x = write(newsockfd, "Message Received\nMessage: %s", 18);
        if (x < 0) error("ERROR: Writing to socket");
    }
}

void error(char * msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char * argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    char * z;
    FILE * file;

    // Threadpool Declaration
    threadpool thpool = thpool_init(4);

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR Opening Socket");
    bzero((char * ) & serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr * ) & serv_addr,
            sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Listening for New Clients
    while ((newsockfd = accept(sockfd,
            (struct sockaddr * ) & cli_addr, & clilen)) >= 0) {
        if (newsockfd < 0)
            error("ERROR on Accept");

        z = inet_ntoa( * (struct in_addr * ) & cli_addr);
        printf("Client information: %s\n", z);

        // Handle
        void * threadArgs[3] = {
            (void * ) newsockfd,
            (void * ) z,
            (void * ) file
        };
        thpool_add_work(thpool, clientHandler, threadArgs);
        printf("-> Handle to client assigned.\n");
    }

    puts("Killing threadpool");
    // Destroy threadpool
    thpool_destroy(thpool);
    printf("Server Shutted Down\n");
    return 0;
}
