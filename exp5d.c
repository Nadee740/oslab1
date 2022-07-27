#include<stdio.h>
#include<stdlib.h>

int main(){
  int arr[20][6]={0},n;
  int t=0,min,pos;
  printf("\nPriority\n\nEnter the no.of processes : ");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("Arrival , burst time and priority of process %d : ",i+1);
    scanf("%d %d %d",&arr[i][1],&arr[i][2],&arr[i][5]);
    arr[i][0]=i+1;
  }

  printf("\nGantt Chart\n");
  while(n > 0){
    pos =-1;
    for(int i=0;i<n;i++){
      if (arr[i][4]==0){
        if(pos == -1)
          pos =i;
        else if (t<arr[pos][1] && arr[pos][1] > arr[i][1])
          pos=i;
        else if(t>=arr[pos][1] && t>=arr[i][1])
          if(arr[pos][5] > arr[i][5])
            pos =i;
          else if( (arr[pos][5] == arr[i][5]) && (arr[pos][1] < arr[i][1]) ){
            pos =i;
          }
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
  printf("\n");
  for(int i=0;i<n+1;i++){
  for(int j=0;j<4;j++)
  {
    if(i==0){
    printf("Process\tArrival Time\tBurst Time\tTurnaround Time");
    break;}
    printf("%d\t\t",arr[i-1][j]);
  }
  printf("\n");
  }
  aw=aw/n;
  at=at/n;
  printf("\nWaiting time : %f \nTurnarround time : %f\n",aw,at);
}
