#include "stdio.h"
#include "string.h"
 
int main(int argc, char *argv){
	 
	int i;
	char buf[8];    
	unsigned short int size;    
	char overflow[65550];
	memset(overflow,65,sizeof(overflow));    
	printf("please input:\n");
	scanf("%d",&i);      
	size = i;
	printf("size:%d\n",size);   
	printf("i:%d\n",i);
 	if (size > 8){
	  	printf("hello");	
		return -1;
	}

	memcpy(buf,overflow,i);  	
	return 0;
							     
}
