#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>
int main (int argc, string argv[])
{   int x,e=0;
    if(argc!=2)
    {
        printf("wrong");
        return 1;
    }
    else
    {
    string k=argv[1];
    for(int i=0; i<strlen(k);i++)
     if(!isalpha(k[i]))
    { printf("expected input characters must be between A-Z & a-z");
        return 1;
    }    
    int i=strlen(k);
    string s=get_string();
       
    for (int j=0;j<strlen(s);j++)
    {
        if(islower(s[j]))
        
     {    if(islower(k[e]))
     x=(int)k[e]%97;
    else
     x=(int)k[e]%65;
         s[j]=(char)((x+(int)s[j]%97)%26+97);
         e++;
         e=e%i;
     }
      if(isupper(s[j]))
      { if(islower(k[e]))
      x=(int)k[e]%97;
      else
      x=(int)k[e]%65;
      
          s[j]=(char)((x+(int)s[j]%65)%26+65);
          e++;
          e=e%i;
      }
    }
    printf("%s\n",s);
    
    }
    
    return 0;
}
