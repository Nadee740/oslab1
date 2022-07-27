#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>

#define num_philosophers 5
#define num_chopsticks 5

void dine(int n);
pthread_t philosophers[num_philosophers];
pthread_mutex_t chopsticks[num_chopsticks];

void main(){
	int status_message;
long i;
	void *msg;
	for(i=1;i<=num_chopsticks;i++){
		status_message=pthread_mutex_init(&chopsticks[i],NULL);
		if(status_message==-1){
			printf("\nMutex initialization failed");
			exit(0);
		}
	}
	for(i=1;i<=num_philosophers;i++){
		status_message=pthread_create(&philosophers[i],NULL,(void*)dine,(int*)i);
		if(status_message!=0){
			printf("\nThread creation failed");
			exit(0);
		}
	}
	for(i=1;i<=num_philosophers;i++){
		status_message=pthread_join(philosophers[i],&msg);
		if(status_message!=0){
			printf("\nThread join failed");
			exit(0);
		}
	}
	for(i=1;i<=num_chopsticks;i++){
		status_message=pthread_mutex_destroy(&chopsticks[i]);
		if(status_message!=0){
			printf("\nMutex destroyed");
			exit(0);
		}
	}
}

void dine(int n){
	printf("Philosopher %d is thinking\n",n);
	pthread_mutex_lock(&chopsticks[n]);
	pthread_mutex_lock(&chopsticks[(n+1)%num_chopsticks]);
	printf("Philosopher %d is eating\n",n);
	sleep(3);
	pthread_mutex_unlock(&chopsticks[n]);
	pthread_mutex_unlock(&chopsticks[(n+1)%num_chopsticks]);
	printf("Philosopher %d finished eating\n",n);
}
