#include <stdio.h>
#include <stdlib.h>
#include<cs50.h>
#include <ctype.h>
#include<string.h>

int main( int argc,string argv[])
{   
    if (argc!=2)
    {
    printf("wrong input");
    return 1;
        
    }
    else
    {
        int i=atoi(argv[1]);
        string k=get_string();
        for(int j=0;j < strlen(k);j++)
        {
            if(isupper(k[j]))
          k[j]=(char)((i%26+(int)k[j]%65)%26+65);
          else
          if (islower(k[j]))
          k[j]=(char)((i%26+(int)k[j]%97)%26+97);
        }
     for(int s=0;s<strlen(k);s++)
     printf("%c",k[s]);
     printf("\n");
     return 0;
    }
        
} 
        
        
        
    