#i n c l u d e <s y s / i p c . h>
#i n c l u d e <s y s /shm . h>
#i n c l u d e <s t d i o . h>
v o i d main ( ) {
key_t my_key = f t o k ( " s h m f i l e " , 6 5 ) ;
int
shmid = shmget ( my_key , 1 0 2 4 , 0 6 6 6 |IPC_CREAT ) ;
char
∗ s t r = ( c h a r ∗ ) shmat ( shmid , ( v o i d ∗ ) 0 , 0 ) ;
printf ( " Write Data : " ) ;
fgets ( s t r , 5 0 , s t d i n ) ;
printf ( " Data w r i t t e n i n memory : %s \n " , s t r ) ;
shmdt ( s t r ) ;
}
