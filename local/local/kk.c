/*
	group : local
	name : kk.c
	srcPath : /home/aryan/Dropbox/Documents from PC/Sem6/Network/ass3/kk.c
	url : /home/aryan/Dropbox/Documents from PC/Sem6/Network/ass3/kk.c
*/
#include<stdio.h>

int main(){
	unsigned char file_header[3];
	int d = 200;


	int mask = (1<<8) - 1;

	printf("%d\n",mask&d);

	file_header[2]=(int)(mask&d);
	mask<<=8;
	file_header[1]=mask&d;

	printf("%d %d %d ^\n",d,file_header[2],file_header[1]);
}