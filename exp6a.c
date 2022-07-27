#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
void main(){
	key_t my_key=ftok("shmfile",65);
	int shmid=shmget(my_key,1024,0666|IPC_CREAT);
	char *str=(char*)shmat(shmid,(void*)0,0);
	printf("Write data::");
	fgets(str,50,stdin);
	printf("Data written in memory:: %s",str);
	shmdt(str);
}
