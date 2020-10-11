#include<stdio.h>   
#include<stdlib.h>
#include<string.h>
// MACRO to swap two strings
#define SWAP(i, j) {\
    char *tmp = argv[i]; \
    argv[i] = argv[j]; \
    argv[j] = tmp; \
}
int main(int argc,char* argv[]) 
{ 
    int counter,i,j,res,res1,flag=0;  
     if(argc==1) 
         printf("\nNo Extra Command Line Argument Passed Other Than Program Name"); 
     int n=argc-1;
     for(i=1;i<n;i++)
     {
         res=strcmp(argv[i],argv[i+1]);
         if(res==0)
         {
             for(j=i+2;j<=n;j++)
             {
                 res1=strcmp(argv[j],argv[i]);
                 if(res1 != 0)
                 {
                     flag=1;
                     if((strcmp(argv[j-1],argv[i+1])) == 0 && (strcmp(argv[j+1],argv[i+1])) != 0 ) 
                         SWAP(j+1,i+1);
                     break;
                 }
             }
             if(flag==0)
             {
                for(j=1;j<=n;j++)
                {
                  res1=strcmp(argv[j],argv[i]);
                  if(res1 != 0)
                   {
                     SWAP(j,i+1);
                     break;
                   }
                }
             }
         }
     }
     for(counter=1;counter<=n;counter++) 
             printf("%s ",argv[counter]);
     printf("\n");         
    return 0; 
} 