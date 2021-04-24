#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int fd;
    pid_t gyerek;

    if((mkfifo("D9WPR7", S_IRUSR | S_IWUSR)) < 0)
{
        printf("Rendszer: FIFO letrehozas sikertelen!\n");
        exit(1);
}

    if((gyerek = fork()) < 0){
        printf("Rendszer: Gyerek fork processz letrehozas sikertelen!\n");
        exit(1);
    }
else
{
printf("Rendszer: Gyerek processz sikeresen elindult!\n");
}

//Gyerek processz
    if(!gyerek){
        char *uzenet = "Olah Mozes";


        if((fd = open("D9WPR7", O_WRONLY)) < 0){
            printf("Gyerek: FIFO megnyitasa sikertelen!\n");
            exit(1);


        } else {

            printf("Gyerek: FIFO irasra megnyitva, iras folyamatban\n");
            write(fd, uzenet, strlen(uzenet));

        }
        printf("Rendszer: A gyerek processz sikeresen befejezete az irast,\nA gyerek processz kilep.\n\n");
printf("Rendszer: Szulo processz inditasa\n");
    }

//Szulo processz
    if(gyerek){
        char buf[256];
        if((fd = open("D9WPR7", O_RDONLY)) <0 ){

            printf("Szulo: FIFO megnyitasa sikertelen!\n");
            exit(1);

        } else {

            printf("Szulo: FIFO olvasasra menyitva, olvasas folyamatban\n");
            read(fd, buf, sizeof(buf));
            printf("Szulo: Kiolvasott adat: %s.\n\n", buf);

            printf("Rendszer: A szulo processz sikeresen befejezete az olvasast.\n");

        }
        if((unlink("D9WPR7")) < 0 || (close(fd)) < 0){

            printf("Rendszer: FIFO torlese sikertelen!\n");

        } else {

            printf("Rendszer: FIFO sikeresen torolve, kilepes.\n");
        }
}
    return 0;
} 
