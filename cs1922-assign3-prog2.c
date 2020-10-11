#include<stdio.h>
#include<stdlib.h>
int isPrime(int n) // To check whether a number is prime or not
{  
    if (n <= 1)  return 0; 
    if (n <= 3)  return 1; 
    if (n%2 == 0 || n%3 == 0) return 0; 
    for (int i=5; i*i<=n; i=i+6)
    { 
        if (n%i == 0 || n%(i+2) == 0) 
           return 0; 
    }
    return 1; 
} 
int main()
{
    int n,i,j,*arr,*arr1,count=1,x,m=0;
    char ch;
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    arr1=(int*)malloc(sizeof(int));
    for(i=0;i<n;i++)
    	scanf("%d",arr+i);
    i=0;
    while(1)
     {
       scanf("%d",arr1+i);
       scanf("%c",&ch);
       arr1=(int*)realloc(arr1,(i+2)*sizeof(int)); 
       if(ch =='\n')
           break;
       else
         {
            i++;   
            count++;
         }
      }
    for(i=0;i<n;i++)
    {
    	for(j=0;j<count;j++)
    	{
    		x=arr1[j];
    		if(isPrime(x) == 1)
    		{
    			if(arr[i] % x ==0)
    			{
    				for(int k=j+1;k<count;k++)
    				{
    					if(arr1[k]==(arr[i]/x) && isPrime(arr1[k])==1)
                           	m++;
    				}
    			}
    		}	
    	}
    }
    if(n==m)
    	printf("TRUE\n");
    else
    	printf("FALSE\n");
	return 0;
}