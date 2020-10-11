#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr,i,n,max_sum,j,temp_sum,sum=0,sum1=0,*len,count,min,end_index,flag=0,temp1=0;
	printf("Enter the number of elements which you want to put in array: ");
	scanf("%d",&n);
	ptr=(int*)malloc(n*sizeof(int));
	len=(int*)malloc(n*sizeof(int));
	printf("Enter the numbers:\n");
	for(i=0;i<n;i++)
		scanf("%d",&ptr[i]);
	max_sum=ptr[0];
	temp_sum=ptr[0];
	for(i=1;i<n;i++)
	{
         temp_sum +=ptr[i];
         if(temp_sum < ptr[i])
             temp_sum=ptr[i];
         if(temp_sum>=max_sum)
         	max_sum=temp_sum;
	}
	printf("Maximum sum of subarray is : %d\n",max_sum);//using Kadane's algo,findinf the max sum sub-array in O(n) time
	if(max_sum>=0)//if max sum of subrray is >=0, it means some elements are +ve and some are negative
	{	
	  for(i=0;i<n;i++)
		len[i]=0;
	  for(i = 0; i < n; i++)
	   {
		if(ptr[i]>=0)
		{
			count=1;
			sum=ptr[i];
			while(sum!=max_sum)
			{
				i=i+1;
				if(i>=n)
					break;
				sum+=ptr[i];
				if(sum<0)
					break;
				count++;
			}
			if((i<n) && (sum >=0))
			  {	
			   len[i]=count;
			   //printf("len[%d]=%d\n",i,len[i] );//mapped the length of max sum subarray to the last index of max sum subarray  
			  } 
		}
	   }	
	    min=n;
	    for(i=0;i<n;i++)
	    {
		  if((len[i]!=0) && (len[i]< min))
			min=len[i];
	    }
	    //printf("min is : %d\n",min); // findind the min. length of max sum sub-array
	    for(i=0;i<n;i++)
         {
       	   if(len[i]==min)
       	   {
       	 	temp1=min;
       	 	end_index=i;
       	 	j=i;
       	 	flag=0;
       	 	while(sum1!=max_sum)
       	 	{
       	 		sum1+=ptr[j];
       	 		j--;
       	 		flag=1;
       	 	}
       	 	if(flag==1)
       	 	   printf("%d %d\n",j+1,end_index);//printing the indices
       	 	else
       	 		printf("%d %d\n",end_index,end_index); //printing the indices
        	}

         }
     }
     else
        {
        	for(i=0;i<n;i++)
        	{
        		if(ptr[i]==max_sum)
        			printf("%d %d",i,i);
        	}
        }    
}