#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#define MAX 2

void dirProcess(){
  struct dirent *de;
  DIR *dr=opendir(".");
  if(dr==NULL){
    printf("Could not open current directory");
    exit(0);
  }
  while ((de=readdir(dr))!=NULL) {
    printf("%s\n",de->d_name);

  }
  closedir(dr);
}
void main(){
pid_t pid;
pid=fork();
dirProcess();
printf("Parent process with pid %d done\n",getpid());
}
