#include<stdio.h>
#include<stdlib.h>
int memory[6]={200,100,400,300,500,350};
void firstfit(int a){
  int alloc;
  for(int i=0;i<6;i++){
    if(a<=memory[i]){
      alloc=memory[i];
      memory[i]=memory[i]-a;
      printf("Memory allocated at size %d\n",alloc);
      break;
    }
  }
}
void bestfit(int a){
  int alloc,index;
  for(i=0;i<6;i++){
if(f==0)
    if(a<=memory[i]){
      alloc=memory[i];
index=i;
      f=1;

    }
else
	if(a<=memory[i]&&memory[i]<alloc){
		alloc=memory[i];
index=i;}
  }
	memory[index]=memory[index]-alloc;
	printf("Memory allocated at size %d\n",alloc);
	
}
void worstfit(int a){
}
void main(){
  int ch,a;
  while(1){
    printf("\nMEMORY BLOCK\n");
    printf("============\n\n");
    printf("|");
    for(int i=0;i<6;i++){
      printf("%d|",memory[i]);
    }
    printf("\n\n");
    printf("1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Exit\nEnter your choice::");
    scanf("%d",&ch);
    switch (ch) {
      case 1:printf("\nEnter the memory to be allocated::");
              scanf("%d",&a);
              firstfit(a);
              break;
      case 2:printf("\nEnter the memory to be allocated::");
              scanf("%d",&a);
              bestfit(a);
              break;
      case 3:printf("\nEnter the memory to be allocated::");
              scanf("%d",&a);
              worstfit(a);
              break;
      case 4:exit(0);
      default:printf("Enter valid choice!\n");
    }
  }
}
