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

    printf("Index: ");
    scanf("%d", &index);
    int fd= open(dbName, O_RDONLY, 0);
    int offset = index * sizeof(Student);
    lseek(fd, offset, SEEK_SET);
    read(fd, &myStudent,sizeof(Student));
    close(fd);

    //printf("index %d, id %d, firstname %s,lastName %s, semester %c",index,
    //myStudent.id,myStudent.firstName,myStudent.lastName,myStudent.semester);
    printf("Attribute: ");
    char attributeName[20];
    scanf("%s", attributeName);
    if(strcmp(attributeName, "id")==0){
        printf("current id %d, new ID: ", myStudent.id);
        scanf("%d", &myStudent.id);
    }
    if(strcmp(attributeName, "fistName")==0){
        printf("current id %s, new FirstName: ", myStudent.firstName);
        scanf("%s", myStudent.firstName);
    }

    if(strcmp(attributeName, "lastName")==0){
        printf("current id %s, new LastName: ", myStudent.lastName);
        scanf("%s", myStudent.lastName);
    }
        if(strcmp(attributeName, "fistName")==0){
        printf("current id %c, new Semester: ", myStudent.semester);
        scanf("\n%c", &myStudent.semester);
    }

    fd= open(dbName, O_WRONLY, 0);
    lseek(fd, offset, SEEK_SET);
    write(fd, &myStudent,sizeof(Student));
    close(fd);


    return 0;


}