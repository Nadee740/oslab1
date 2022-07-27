#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
struct dirent *de;
DIR *dr;
dr=opendir("..");
if(dr==NULL){
	printf("Could not open the current directory!\n");
	exit(0);
}
while((de=readdir(dr))!=NULL){
	printf("%s\n",de->d_name);

}
closedir(dr);
}
