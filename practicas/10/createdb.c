#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "./student.c"

int main(){
    Student *myStudent;
    myStudent = calloc(1,sizeof(Student));

    int dFd= open("class.dat", O_WRONLY|O_CREAT,0600);
    for(int i =0;i<20;i++){
        write(dFd, myStudent, sizeof(Student));
    }
    close(dFd);    
    return 0;
}