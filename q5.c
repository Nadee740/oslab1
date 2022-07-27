#include<stdio.h>
//struct process
//{
//	int at,wt,tt,bt;
//};
//struct process a[10];
void main(){
int n;
int burst=0;
int at[10],wt[10],bt[10],tt[10];
int cmp_time;
float avg_wt,avg_tt,total=0;
printf("Enter the number of processes::");
scanf("%d",&n);
printf("Enter the arrival time and burst time for each processes::\n\n");
printf("AT BT\n");

for(int i=0;i<n;i++)
{
	scanf("%d",&at[i]);
	scanf("%d",&bt[i]);	
}

printf("ok");

for(int i=0;i<n;i++)
{
	if(i==0)
		wt[i]=at[i];
	else
		wt[i]=burst-at[i];

	burst+=bt[i];
	total+=wt[i];
}
avg_wt=total/n;

cmp_time=0;
total=0;
for(int i=0;i,n;i++)
{
	cmp_time+=bt[i];
	tt[i]=cmp_time-at[i];
	total+=tt[i];
}
avg_tt=total/n;
printf("Process		waiting time		turnAround time\n");
for(int i=0;i<n;i++)
{
	printf("%d\t\t%d\t\t%d\n",i+1,wt[i],tt[i]);
}

printf("Average waiting time::%f\n",avg_wt);
printf("Average turnaround time::%f\n",avg_tt);
}

