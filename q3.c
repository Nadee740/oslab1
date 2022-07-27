#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#define MAX 2

void childprocess(){
  struct stat sfile;
  stat('stat.c',&sfile);
  printf("File st_size %ld\n",sfile.st_size);
  exit(0);
}
void parentprocess(){
  pid_t cid=wait(NULL);
  printf("Child process pid - %d\n",cid);
  execl("/bin/date","date",NULL);
  
}



int main(int argc,char *argv[]){
  pid_t pid;
  pid = fork();
  if(pid==0)
    childprocess();
  else
 {
    printf("Parent process id %d\n",getpid());
    parentprocess();
 } 


}
