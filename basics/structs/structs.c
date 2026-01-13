#include <stdio.h>
#include <string.h>

struct Student{
    char name[50];
    int age;
    float gpa;
};

struct Point{
    int x;
    int y;
}; //we cannot initalize in struct

typedef struct {
    int day, month, year;
}Date;

typedef struct {
    int ISBN;
    int page_number;
    Date date;
}Book;


void getCoords(struct Point point){
    printf("The X coord of the point is %d and the Y coord is %d\n", point.x, point.y);
}

int main(){

    /*
    struct Student student;
    strcpy(student.name, "Ali");
    student.age = 26;
    student.gpa = 3.87;

    printf("The name of the student is %s and the age is %d and the GPA is %f\n", student.name, student.age, student.gpa);
    return 0;
    */

    struct Point p1;
    p1.x = 10;
    p1.y = 20;
    struct Point p2 = {20,40};
    getCoords(p1);

    struct Point *ptr_p2 = &p2;
    printf("The X is %d\n", ptr_p2 -> x);

    Book book1 = {123, 250, {24,1,2000}}; //nested struct initialization
    printf("The ISBN of the book is %d\n", book1.ISBN);
    printf("The date of publishing is %d/%d/%d\n", book1.date.day, book1.date.month, book1.date.year);
    
    return 0;
}
