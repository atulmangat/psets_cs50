
 
 #include<cs50.h>
  #include<stdio.h>
  #include<stdint.h>
  #include<stdlib.h>
  int main()
{   uint8_t buffer[512];
     int nophotos=0;
    FILE* photos=fopen("card.raw","r");
    FILE* outp;
    char* filename;
    filename=malloc(100);
    
     outp=fopen("000.jpg","w");
     
    while(fread(buffer,sizeof(buffer),1,photos)==1)
    { 
      
    if(buffer[0]==0xff && buffer[1]==0xd8 )
     {
      fclose(outp);
      sprintf(filename,"%03d.jpg",nophotos);     
      outp=fopen(filename,"w");
      fwrite(buffer,sizeof(buffer),1,outp);
      nophotos++;
      }
       else
      fwrite(buffer,sizeof(buffer),1,outp);
       }
       free(filename);
       fclose(outp);
       fclose(photos);
       }