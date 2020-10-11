#include<stdio.h>
#include<stdlib.h>
int stirling(int,int);
int main()
{
	int n,*ptr,x=0,k,i,**ptr1,j,l,m;
	printf("Enter the number of elements in a set : ");
	scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    printf("Enter numbers:\n");
    for(i=0;i<n;i++)
    	scanf("%d",&ptr[i]);
    for(i=0;i<n;i++)
    	printf("%d\n",ptr[i]);
    for(k=0;k<=n;k++)
       x +=stirling(n,k);
    printf("No. of partitions are: %d",x);
    for(i=2;i<=n;i++)
    {
    	for(j=1;j<=stirling(n,i);j++)
    	{
           ptr1=(int**)malloc(stirling(n,i)*sizeof(int*));
           for(l=1;l<(n-i+1);l++)
           	 ptr1[l]=(int*)malloc((n-i+1)*sizeof(int));
           for(m=0;m<i;m++)
           	  {
                 ptr1[j][m]=ptr[j-1];
                  
           	  }
    	}
    }
}
int stirling(int n,int k)
{
   if(n==k)
   	return 1;
   else if(k==0)
   	return 0;
   else
    return stirling(n-1,k-1)+ k*stirling(n-1,k);
}