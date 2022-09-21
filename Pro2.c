#include<stdio.h>

int main() 
{
	int arrival_time[10], burst_time[10], temp[10];
	int i, smallest, count=0, time, limit;	
	double wait_time=0,turnarround_time=0, end;
	double avarage_waiting_time, avarage_turn_around_time;
	printf("\n Enter the Total No of Prosses \t");
	scanf("%d", &limit);
	printf("Enter Details of %d Process", limit);
	for(i=0; i< limit; i++)
	{
		printf("\n Enter Arrival Time \t"); 
		scanf("%d", &arrival_time[i]);
		printf("Enter Burst Time\t");
		scanf("%d", &burst_time[i]);
		temp[i] = burst_time[i];
	} 
	burst_time[9] =9999;
	for(time=0;count != limit; time++)
	{
		smallest = 9;
		for(i=0;i<limit;i++)
		{
			if(arrival_time[i] <=time && burst_time[i] < burst_time[smallest] && burst_time[i]>0)
			{
				smallest = i;
				
			}
		}
		burst_time[smallest]--;
		if(burst_time[smallest]==0)
		{
			count++;
			end =time+1;
			wait_time = wait_time+end-arrival_time[smallest]-temp[smallest];
			turnarround_time = turnarround_time+end-arrival_time[smallest];
			
		
		}
	}
		
	avarage_waiting_time = wait_time/time/limit;
	avarage_turn_around_time = turnarround_time/limit;
	printf("\n\nAvarage waiting Time \t%f\n", avarage_waiting_time);
	printf("\n\nAvarage waiting Time \t%f\n",avarage_turn_around_time);
	return 0;


}
