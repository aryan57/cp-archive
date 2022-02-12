/*
	group : local
	name : temp.c
	srcPath : /home/aryan/Dropbox/Documents from PC/Sem6/Network/ass3/temp.c
	url : /home/aryan/Dropbox/Documents from PC/Sem6/Network/ass3/temp.c
*/
#include <stdio.h>

int main(){

	char buf[3];

	buf[2]=200; // [-128, 127]
	buf[1]=0;

	// int sz=(unsigned int)buf[2] + (((unsigned int)buf[1])*(1<<8));
	// printf("%u \n",sz);
	printf("%u \n",buf[2]);
	// printf("%u \n",(((unsigned int)buf[1])*(1<<8)));
}