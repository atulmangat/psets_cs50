#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
// hello world
int main()
{
    string a=get_string();
  if(islower(a[0]))
    a[0]=toupper(a[0]);
    printf("%c",a[0]);
    
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]==' ')
       { a[i+1]=toupper(a[i+1]);
    printf("%c",a[i+1]);
       }
        
        }
        printf("\n");
    
    }

