#include<stdio.h>

void main(){
int bt[10],p[10],wt[10],tt[10];
int  n,i,j,total,temp;
float avg_wt,avg_tt;
printf("enter the number of processes::");
scanf("%d",&n);
printf("enter the burst time of each process");
for(i=0;i<n;i++){
	scanf("%d",&bt[i]);
p[i]=i+1;
}
printf("ok");
for(i=0;i<n-1;i++)
	for(j=0;j<n-i-1;j++)
		if(bt[j]>bt[j+1]){
			temp=bt[j];
			bt[j]=bt[j+1];
			bt[j+1]=temp;

			temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
		}
wt[0]=0;
for(i=1;i<n;i++){
wt[i]=0;
for(j=0;j<i;j++)
	wt[i]+=bt[j];
total+=wt[i];
}
avg_wt=(float)total/n;
total=0;
printf("\nProcess\tBurst time\tWaiting time\tTurn around time\n");
for(i=0;i<n;i++){
tt[i]=bt[i]+wt[i];
total+=tt[i];
printf("p%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tt[i]);
}
avg_tt=(float)total/n;
printf("average waiting time::%.2f\n",avg_wt);
printf("average turn around time::%.2f\n",avg_tt);
}

