#include<stdio.h>
#include<stdlib.h>

int main(){
  int arr[20][5]={0},n;
  int t=0,min,pos;
  printf("\nFCFS\n\nEnter the no.of processes : ");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("Arrival and burst time of process %d : ",i+1);
    scanf("%d %d",&arr[i][1],&arr[i][2]);
    arr[i][0]=i+1;
  }

  printf("\nGantt Chart\n");
  while(n > 0){
    pos =-1;
    for(int i=0;i<n;i++){
      if (arr[i][4]==0){
        if(pos == -1)
          pos =i;
        else if (arr[pos][1] > arr[i][1])
          pos=i;
        else if(arr[pos][1]  == arr[i][1])
          if(arr[pos][2] > arr[pos][1])
            pos =i;
      }
    }
    if (pos == -1)
      break;
    else
      arr[pos][4] = 1;

    if(t <= arr[pos][1]){
      if( (arr[pos][1] - t) == 0)
        printf("%d| P%d |",t,pos+1);
      else{
        printf("%d|-|%d| P%d |",t,arr[pos][1],pos+1);
        t=arr[pos][1];
      }

      t=t+arr[pos][2];
      arr[pos][3]=t-arr[pos][1];
    }
    else{
      printf("%d| P%d |",t,pos+1);

      t=t+arr[pos][2];
      arr[pos][3]=t-arr[pos][1];
    }
  }

  printf("%d\n",t);
  float aw=0,at=0;
  for(int i=0;i<n;i++){
    aw+=(arr[i][3]-arr[i][1]);
    at+=(arr[i][3]);

  }

  for(int i=0;i<n+1;i++){
  for(int j=0;j<4;j++)
  {
    if(i==0){
    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time");
    break;}
    printf("%d\t\t",arr[i-1][j]);
  }
  printf("\n");
  }
  aw=aw/n;
  at=at/n;
  printf("\nWaiting time : %.2f \nTurnarround time : %.2f\n",aw,at);
}
