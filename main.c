#include <stdio.h>
#include <fcntl.h>
int main(int argc,char *argv[]){
    if(argc==2){
        int fd;
        char c;
        fd = open(argv[1],O_RDWR);
        if(fd < 0){
            printf(" %s open failed. \n",argv[1]);
            return -1;
        }
        printf(" %s opened successfully. \n",argv[1]);
        printf(" type a character:");
        scanf("%d",&c);
        write(fd,c,1);
        printf(" wrote %c to %s. \n",c,argv[1]);
        printf(" hit return to read. ");
        getchar();
        read(fd,&c,1);
        printf(" read %c from %s. \n",c,argv[1]);
        printf(" hit return to close file %s. ",argv[1]);
        getchar();
        close(fd);
        return 0;
    }
    printf("usage: main <char device>. \n");
    return -1;
}

