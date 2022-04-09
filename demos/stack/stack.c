#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

int vuln(char *str)
{
	char stack[10];
	strcpy(stack,str);
	printf("good\n");
}
int main()
{	
	char buf[99];
	gets(buf);
	printf("cool\n");
	char buf2[1024];
	scanf("%s",buf2);
	vuln(buf2);
	return 0;
}
