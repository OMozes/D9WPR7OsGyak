#include	<stdio.h>
#include	<stdlib.h>

int main()
{
	int status;

	if ((status = system("date")) < 0)
		perror("system() error");

	if (WIFEXITED(status))
		printf("Elso eset normalis, visszaadott ertek = %d\n", WEXITSTATUS(status));

    	if ((status = system("alma")) < 0)
		perror("system() error");

	if (WIFEXITED(status))
		printf("Masodik eset nem normalis, visszaadott ertek = %d\n", WEXITSTATUS(status));

	exit(0);
}