#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>

char  line[100], c;
int main()
{
    /*
    key_t MyKey;
    int   ShmID;
    pid_t *ShmPTR;
    
    MyKey   = ftok(".", 's');
    ShmID   = shmget(MyKey, sizeof(pid_t), 0666);
    ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
//    pid     = *ShmPTR;
//    shmdt(ShmPTR);
     while (1) {                       
        printf("Want to interrupt the other guy or kill it (i or k)? ");
        gets(line);
        kill(45078, SIGINT);
        printf("Sent a SIGINT signal\n");
     }
     return 0;
     */
    char line[100];
    FILE *cmd = popen("pidof...", "r");

    fgets(line, 100, cmd);
    pid_t pid = strtoul(line, NULL, 10);

    pclose(cmd);
}
