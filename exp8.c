#include<stdio.h>
void main(){
  int np,nr,res[10],max[10][10],all[10][10],need[10][10],i,j,x;
  printf("Enter the no. of resources::");
  scanf("%d",&nr);
  printf("Enter the max instances of each resources::\n");
  for(i=0;i<nr;i++){
  	printf("Resource %d::",i+1);
  	scanf("%d",&res[i]);
  }
  printf("Enter the no of processes::");
  scanf("%d",&np);
  printf("Enter the allocation matrix::\n");
  for(i=0;i<np;i++){
  	printf("Process %d::\n",i);
  	for(j=0;j<nr;j++){
  		printf("Resource %d::",j+1);
  		scanf("%d",&all[i][j]);
  	}
  }
  printf("Enter the max matrix::\n");
  for(i=0;i<np;i++){
  	printf("Process %d::\n",i);
  	for(j=0;j<nr;j++){
  		printf("Resource %d::",j+1);
  		scanf("%d",&max[i][j]);
  		need[i][j]=max[i][j]-all[i][j];
  	}
  }
  int op[10],req[20];
  int work[10];
  for (int i = 0; i < np; ++i)
  {
  	work[i]=0;
  }
   for(i=0;i<np;i++){
  for(j=0;j<nr;j++)
  		printf("need %d::",need[i][j]);
  	printf("\n");
  }
  i=0;
  int k=-1,m=-1;
  int c=1;
  while(c==1){
  	int f=0;
  	if(i==np)
  		i=0;
  	if(work[i]==0){
  		int flag=1;
  		for(j=0;j<nr;j++){
  			if(need[i][j]>res[j])
  			{
  				flag=0;
  				break;
  			}
  		}
  		if(flag==0){
  			req[++k]=i;
  			continue;
  		}
  		else{
  			printf("Request of process %d is granted\n",i);
  			sleep(3);
  			for(j=0;j<nr;j++){
  				res[j]=res[j]+all[i][j];
  			}
  			work[i]=1;
  			op[++m]=i;
  		}

  	}
  	for(x=0;x<np;x++){
  		if(work[x]==0){
  			c=1;
  			break;
  		}
  	}
  	if(x==np)
  		c=0;
  	i++;
  }
  printf("Resorce allocatedv to process in the order::");
  printf("P[%d]",op[0]);
  for(i=1;i<np;i++)
  	printf("-->P[%d]",op[i]);
  printf("\n");

}
