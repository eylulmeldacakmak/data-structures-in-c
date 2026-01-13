#include <stdio.h>

void increment_PbV(int value){
    value = value + 1;
    printf("Inside the fuction the value is %d\n", value);
}

void increment_PbR(int *ptr_value){
    *ptr_value = *ptr_value + 1;
    printf("Inside the fuction the value is %d\n", *ptr_value);
}

//pass-by-reference modifies the caller variables
void swap_PbR(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//pass-by-value does not modify the caller variables
void swap_PbV(int x, int y){
    x = x+y;
    y = x;
    x = x-y;
}

//alternative swap without temp
void swap_PbR_new(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main(){
    /*
    int id = 123456;
    printf("%d\n", id);
    int *ptr_id = &id;
    printf("%p\n", ptr_id);
    printf("%p\n", &ptr_id);

    int arr[3] = {1,2,3};
    int *ptr_arr = arr;
    printf("%d\n", *ptr_arr);
    ptr_arr++;
    printf("%d\n", *ptr_arr);
    
    int variable = 10;
    printf("Before calling the fuction the value is %d\n", variable);
    increment_PbV(variable);
    printf("After calling the fuction the value is %d\n", variable);
    printf("Before calling the fuction the value is %d\n", variable);
    increment_PbR(&variable);
    printf("After calling the fuction the value is %d\n", variable);
    */

    int a = 10;
    int b = 2;
    
    swap_PbR_new(&a,&b);
    printf("%d, %d\n", a, b);

    swap_PbV(a,b);
    printf("%d, %d", a, b);
    return 0;
}