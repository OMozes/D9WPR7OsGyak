#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
int i = 0;
    pid_t pid=fork();
    if (pid==0) {
        printf("Gyermek processz:\n");
        do
        {
            printf("A tanulo neve: Olah Mozes\nNeptun kod:D9WPR7\n");
            i++;
        }while (i<5);

        exit(127);
    }
    else {
        waitpid(pid,0,0);

        printf("Szulo processz:\nA gyermek processz befejezte a futast\n");
    }
    return 0;
}
