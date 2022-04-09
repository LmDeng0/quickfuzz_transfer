#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
int vuln(char *str)
{
	    int len = strlen(str);
	        if(str[0] == 'A' && len == 66)
			    {
				            raise(SIGSEGV);
			    }
					            
						        else if(str[0] == 'F' && len == 6)
						            {
						                    raise(SIGSEGV);
						    }
						                                else
						                                    {
						                                            printf("it is good!\n");
						                                               }
						                                                   return 0;
						                                                   }
 
int main (int argc, char *argv[])
{
	        char buff[1024];    // ÉÖջ¿ռä
		        	gets(buff);
			        printf(buff); //´¥·¢©¶´
				vuln(buff);
				 
				        return 0;
}
