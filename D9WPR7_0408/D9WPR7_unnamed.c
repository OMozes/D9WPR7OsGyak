#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int array[2];
	int child;
	
	if(pipe(array)){
		perror("Pipe hiba!\n");
		return 1;
	}
	child = fork();
	
	if(child > 0){
		char s[1024];
		close(array[1]);
		read(array[0], s, sizeof(s));
		printf("%s", s);
		
		close(array[0]);
	}else if(child == 0 ){
		close(array[0]);
		write(array[1],"Olah Mozes D9WPR7\n",21);
		close(array[1]);
		}
		return 0;
}
	
