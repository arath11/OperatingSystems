#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "./student.c"
#include <string.h>

int main(){
    unsigned index;
    Student myStudent;

    //printf("Index: ");
    //scanf("%d", &index);
    char lastName[20];
    printf("LastName: ");
    scanf("%s", lastName);
    int fd= open(dbName, O_RDONLY, 0);
    //int offset = index * sizeof(Student);
    //lseek(fd, offset, SEEK_SET);
    while (read(fd, &myStudent,sizeof(Student))){
        if(strcmp(myStudent.lastName, lastName)==0){
        printf("index %d, id %d, firstname %s,lastName %s, semester %c\n",index,
            myStudent.id,myStudent.firstName,myStudent.lastName,myStudent.semester);
        }
    }

    close(fd);

    return 0;


}