#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
pid_t pid;
if ((pid = fork()) == -1)
perror("Hiba");

else if (pid == 0) {
execl("/bin/ls", "ls", "-la", NULL);
printf("Execlp hiba\n");
}
else {
waitpid(pid,0,0);
printf("A gyermek processz befejezte a futast!\n");
}
return 0;
}
