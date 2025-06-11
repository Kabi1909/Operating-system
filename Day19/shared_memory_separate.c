// writer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 //size of shared memory in bytes

int main(){
	key_t key=ftok("shmfile",1109);//Generate unique key
	int shmid=shmget(key,SHM_SIZE,IPC_CREAT|0666);//craete shared memory segment
	if(shmid==-1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr=(char*) shmat(shmid,NULL,0);//Attach to shared memory
	if(shmaddr==(char*)-1){
		perror("shmat");
		exit(1);
	}
	
	printf("Write data: ");
	fgets(shmaddr,SHM_SIZE,stdin);//write data to shared memory
	
	printf("Data written in memory: %s\n",shmaddr);
	
	shmdt(shmaddr);//Detach from shared memory
	
	return 0;
}


//reader
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 //size of shared memory in bytes

int main(){
	key_t key=ftok("shmfile",1109);//Generate unique key
	int shmid=shmget(key,SHM_SIZE,0666);//access shared memory segment
	if(shmid==-1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr=(char*) shmat(shmid,NULL,0);//Attach to shared memory
	if(shmaddr==(char*)-1){
		perror("shmat");
		exit(1);
	}
	
	printf("Data read from memory: %s\n",shmaddr);//read data from shared memory
	
	shmdt(shmaddr);//detach from shared memory
	
	shmctl(shmid,IPC_RMID,NULL);//remove shared memory segment
	
	return 0;
}



/*Output
[2021ict56@fedora ~]$ ./writer
Write data: Saja
Data written in memory: Saja

[2021ict56@fedora ~]$ ./reader
Data read from memory: Saja
*/