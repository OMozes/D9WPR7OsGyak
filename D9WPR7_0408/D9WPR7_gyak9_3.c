#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void alarmkezelo(int sig);

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Hasznalathoz irja be: ./D9WPR7_gyak9_3.out PID\n");
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[1]);
    kill(pid, SIGALRM);

 if (signal(SIGALRM, alarmkezelo) == SIG_ERR)
    {
        printf("A(z) \"SIGALRM\" jelre nem sikerult handlert allitani!\n");
        return 1;
    }

    pause();
    return 0;
}

void alarmkezelo(int sig)
{
    printf("D9WPR7\n Mostantol nem blokkol!\n");
    exit(1);
}

