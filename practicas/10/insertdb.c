#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "./student.c"

int main(){
    unsigned index;
    Student myStudent;

    printf("Index: ");
    scanf("%d", &index);
    
    printf("id: ");
    scanf("%d", &myStudent.id);

    printf("First Name: ");
    scanf("%s", myStudent.firstName);

    printf("Last Name: ");
    scanf("%s", myStudent.lastName);

    printf("Semester: ");
    scanf("\n%c", &myStudent.semester);

//    printf("index %d, id %d, firstname %s,lastName %s, semester %c",index,
    //myStudent.id,myStudent.firstName,myStudent.lastName,myStudent.semester);
    int fd= open(dbName,O_WRONLY,0);
    int offset=index*sizeof(Student);
    lseek(fd, offset, SEEK_SET);
    write(fd, &myStudent, sizeof(Student));
    close(fd);
    return 0;
}

