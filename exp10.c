#include <stdio.h>

#define max 25

void main()
{
  int frag[3][max],b[max],f[max],i,j,nb,nf,temp,lowest=10000,highest=0;
  static int bf[3][max],ff[3][max];
  printf("\nEnter the number of blocks ::");
  scanf("%d",&nb);
  printf("Enter the number of files ::");
  scanf("%d",&nf);
  printf("\nEnter the size of the blocks ::\n");
  for(i=1;i<=nb;i++) {
    printf("Block %d::",i);
    scanf("%d",&b[i]);
  }
  printf("\nEnter the size of the files ::\n");
  for(i=1;i<=nf;i++) {
    printf("File %d::",i);
    scanf("%d",&f[i]);
  }
  int n=0;
  printf("\n\tMEMORY ALLOCATION\n");
  while (n!=4) {
    printf("\nEnter : \n   1 : First Fit Memory Allocation\n   2 : Best Fit Memory Allocation\n");
    printf("   3 : Worst Fit Memory Allocation\n   4 : Exit\nEnter your choice ::");
    scanf("%d", &n);
    switch(n) {
      case 1 : for(i=1;i<=nf;i++) {
                for(j=1;j<=nb;j++) {
                  if(bf[0][j]!=1) {
                    temp=b[j]-f[i];
                    if(temp>=0) {
                      ff[0][i]=j;
                      break;
                    }
                  }
                }
                frag[0][i]=temp;
                bf[0][ff[0][i]]=1;
              }
              break;

     case 2 : for(i=1;i<=nf;i++) {
                for(j=1;j<=nb;j++) {
                  if(bf[1][j]!=1) {
                    temp=b[j]-f[i];
                      if(lowest>temp&&b[j]>=f[i]) {
                        ff[1][i]=j;
                        lowest=temp;
                      }
                  }
                }
                frag[1][i]=lowest;
                bf[1][ff[1][i]]=1;
                lowest=10000;
              }
              break;

     case 3 : for(i=1;i<=nf;i++) {
                for(j=1;j<=nb;j++) {
                  if(bf[2][j]!=1) {
                    temp=b[j]-f[i];
                      if(highest<temp) {
                        ff[2][i]=j;
                        highest=temp;
                      }
                  }
                }
                frag[2][i]=highest;
                bf[2][ff[2][i]]=1;
                highest=0;
              }
              break;

     case 4 : break;

     default : printf("Invalid input!\n");
    }
    if (n==1||n==2||n==3) {
      printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment");
      for(i=1;i<=nf;i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[n-1][i],b[ff[n-1][i]],frag[n-1][i]);
      printf("\n");
    }
  }
}
