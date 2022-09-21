#include<stdio.h>

int main() 
{
	int count, j,n,time, remain, flag=0, time_quant;
	int wait_time=0, turnaround_time=0, at[100], bt[100], rt[100];
	printf("Enter A Total Process \t");
	scanf("%d", &n);
	remain=n;
	for(count=0; count<n;count++)
	{
		printf("Enter Arrival Time and Burst Time for Process id %d", count+1);
		
		scanf("%d", &at[count]);
		scanf("%d", &bt[count]);
		rt[count]=bt[count];
				
	}	
	printf("Enter Time Quantum\t");
	scanf("%d", &time_quant);
	printf("\n\n Process \t | Turn Around Time  | Waiting Time \n\t");
	for(time=0; count=0;remain!=0)
	{
		if(rt[count] <= time_quant && rt[count]>0)
		{
			time+=rt[count];
			rt[count]=0;
			flag=1;
			
		}
		else if(rt[count]>0)
		{
			rt[count]-=time_quant;
			time+=time_quant;
				
		}	
		if(rt[count]==0 && flag==1)  {
			remain--;
			printf("P | %d \t | %d | \t %d", count+1, time+at[count], time+at[count]+bt[count]);	
 			wait_time+=time-at[count]-bt[count];
			turnaround_time+=time-at[count];
			flag=0;	
		}
		if(count == n-1) 
		{	
			count=0;
		}
		else if(at[count+1] <= time) 
		{
			count++;
		}else {
			count=0;
		}
	} 
	double aw = wait_time*1.0/n;
	double tw = turnaround_time*1.0/n;
	printf("\n Average Waiting time = %f \n", aw);
	printf("\n Average Turn Aound Time = %f \n", tw);
	return 0;
	
	
}
