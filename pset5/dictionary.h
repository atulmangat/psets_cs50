
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define sizehash 10000
long words=0;

#define LENGTH 45

typedef struct node
 {  
    char Word[46];
     struct node* ptr;
     
 }
 node;
 
  node* array[sizehash];
 
 
  int hashfunction(const char *a)
 {
    long long h=0;
    char* copy=malloc(46);
    strcpy(copy,a);
   for(int i=0;i<strlen(copy);i++)
   {
   if(isupper(copy[i]))
    copy[i]=tolower(copy[i]);
   }
    for(int i=0;i<strlen(a);i++)
    
    h+=((int)copy[i])*10;
    free(copy);
     return labs(h%sizehash);
     
 }

 bool load(const char* dictionary)
  {  for(int i=0;i<sizehash;i++)
      array[i]=NULL;
   char word[46];
   FILE* fp;
   fp=fopen(dictionary,"r");
   if(fp==NULL)
    {
    return false;
    }
    
   fscanf(fp,"%s",word); 
    while(!feof(fp))
         { 
           words++;
           int hashvalue = hashfunction(word);
           node* ptrm=malloc(sizeof(node));
           ptrm->ptr=NULL;
           strcpy(ptrm->Word,word);
          
           node *sl=array[hashvalue];
           if(array[hashvalue]==NULL)
           array[hashvalue]=ptrm;
          else
          { 
           while(sl->ptr!=NULL)
           sl=sl->ptr;
           sl->ptr=ptrm;
          }
          fscanf(fp,"%s",word); 
          } 
        fclose(fp);
        return true;
        }
       

 
  bool check(const char* word)
 c{  
  char* copy=malloc(46);
     strcpy(copy,word);
    for(int i=0;i<strlen(copy);i++)
    if(isupper(word[i]))
     copy[i]=tolower(copy[i]);
     int a=hashfunction(word);
     if(array[a]==NULL)
    { free(copy);
     return false;
    }
     else 
   {
    node *temp=array[a];
       while(temp)
         {
           if(strcmp(temp->Word,copy)==0)
         { 
          free(copy);
           return true;
         }  
           temp=temp->ptr; 
         }
           
    }
      return false;
    } 

   unsigned int size(void)
    {

      return words;

    }

    bool unload(void)
    { 
     for(int i=0;i<sizehash;i++)
     if(array[i]==NULL)
     continue;
     else
   { node* head,*temp;
     head=array[i];
     while(head)
     { temp=head;
       head=head->ptr;
       free(temp);
       }
       }
       return true;
     }


#endif // DICTIONARY_H