#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
void main(){
  char c;
  int fl=open("f.txt",O_RDWR);
  if(fl==-1)
    printf("File not found!\n");
  read(fl,&c,1);
  printf("First character of file is %c\n",c);
  int w=write(fl,"hello world",strlen("hello world"));
  if(w>-1)
    printf("Write to file success\n");
  int cl=close(fl);
  if(cl==0)
    printf("File closed\n");
}
