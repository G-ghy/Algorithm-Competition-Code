// 后序 + 中序 => 层次
// 后序: 左右根
// 中序: 左根右
// 

main() 
{ 
    int i, maxi, maxfd,sockfd;
    int nready;
    ssize_t n;
    fd_setrset, allset;
    int listenfd, connectfd;
    struct sockaddr_in server;
    CLIENT client[FD_SETSIZE];
    char recvbuf[MAXDATASIZE];
    int sin_size; 

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Creating socket failed");
        exit(1);
    }

    int opt = SO_REUSEADDR;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bzero(&server,sizeof(server));
    servin_family=AF_INET; 
    servin_port=htons(PORT); 
    servin_ad_addr = htonl (INADDR_ANY); 

    if (bind(listenfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1){ 
        perror("Bind err");
        exit(1); 
    } 

    if(listen(listenfd,BACKLOG) == -1){ 
        perror("listen() error\n"); 
        exit(1); 
    } 

    sin_size=sizeof(struct sockaddr_in); 
    maxfd = listenfd;
    maxi = -1;
    for (i = 0; i < FD_SETSIZE; i++) {
        client[i].fd = -1;
    }
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);

    while(1) {
        struct sockaddr_in addr;
        rset = allset;
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(listenfd, &rset)) {
            if ((connectfd = accept(listenfd,(struct sockaddr *)&addr,&sin_size))==-1) { 
                perror("accept() error\n"); 
                continue; 
            }

            for (i = 0; i < FD_SETSIZE; i++)
                if (client[d < 0) {
                    client[d = connectfd;
                    client[ame = new char[MAXDATASIZE];
                    client[ddr = addr;
                    client[ata = new char[MAXDATASIZE];
                    client[ame[0] = '\0';
                    client[ata[0] = '\0';
                    printf("You got a connection from  ",inet_ntoa(client[din_addr) ); 
                    break;
                }

            if (i == FD_SETSIZE) printf("too many clients\n");
            FD_SET(connectfd, &allset); /* add new descriptor to set */
            if (connectfd > maxfd) maxfd = connectfd;
            if (i > maxi) maxi = i;
            if (--nready <= 0) continue;
        }

        for (i = 0; i <= maxi; i++) {
            if ( (sockfd = client[i].fd) < 0) continue;

            if (FD_ISSET(sockfd, &rset)) {
                if ( (n = recv(sockfd, recvbuf, MAXDATASIZE,0)) == 0) 
                {
                    close(sockfd);
                    printf("Client( %s ) closed connectiUser's data: 
                    %s\n",client[ame,client[ata);
                    FD_CLR(sockfd, &allset);
                    client[d = -1;
                    free(client[i].name);
                    free(client[i].data);
                } 
                else {
                    process_cli(&client[i], recvbuf, n);
                }
                if (--nready <= 0) break; /* no more readable descriptors */
            }
        }
    }
    close(listenfd);
}

void process_cli(CLIENT *client, char* recvbuf, int len) {
    char sendbuf[MAXDATASIZE];
    recvbuf[len-1] = '\0';
    if (strlen(client->name) == 0) {
        memcpy(client->name,recvbuf, len);
        printf("Client's name is %s.\n",client->name);
        return;
    }   
    printf("Received client( %s ) message: %s\n",client->name, recvbuf);
    /* save user's data */
    savedata(recvbuf,len, client->data);
    /* reverse usr's data */
    for (int i1 = 0; i1 < len - 1; i1++) {
        sendbuf[i1] = recvbuf[len - i1 -2]; 
    }
    sendbuf[len - 1] = '\0';
    send(client->fd,sendbuf,strlen(sendbuf),0); 
}

void savedata(char* recvbuf, int len, char* data) {
    int start = strlen(data);
    for (int i = 0; i < len; i++) {
        data[start + i] = recvbuf[i];
    } 
}
