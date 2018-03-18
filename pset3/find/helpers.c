  
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
  bool search(int value, int values[], int n)
   {    int front,end,mid;
     front=0;
     end=n-1;
   while(true) 
    { 
        mid=(front+end)/2;
       
    if(values[mid]==value) 
        return true;
        else
        if(front==end)
        return false;
        else
     if( values[mid]>value)
       end=mid-1;
        else 
         front=mid+1;
        
       }      
   }


  void sort(int values[], int n)
  {   int t,s;
    for(int i=0;i<n;i++)
    {s=0;
    for(int j=i+1;j<n;j++)
    if(values[j]<values[j-1])
     {
      s++;
     t=values[j];
     values[j]=values[j-1];
     values[j-1]=t;
     }
     if(s==0)
     return;
     }    
    return;
  }