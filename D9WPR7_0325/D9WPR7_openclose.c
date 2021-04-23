#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main()
{
    int sd, vissza;
    char buffer[100];

    buffer[0] = 0;

    sd = open("D9WPR7.txt", O_RDWR);

    if (sd == -1) {
        perror("Fajl megnyitas [open()] hiba! \n");
        exit(-1);
    }

    vissza = read(sd, buffer, 100);
    printf("A read() %d byteot olvasott.\n\n", vissza);
    strcpy(buffer, "D9WPR7");


    vissza = lseek(sd, 30, SEEK_SET);
    printf("Az lseek() beallt a %d. helyre, es ide ", vissza);

    vissza = write(sd, buffer, 6);
    printf("a write() %d byteot irt: %s\n\n", vissza, buffer);
    strcpy(buffer, "D9WPR7");

    close(sd);

    return 0;
}
