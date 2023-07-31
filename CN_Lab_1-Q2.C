#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct dob{
    int age_present;
};
struct student_info{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void print_call_by_value(struct student_info s){
    printf("Call by value");
    printf("Roll: %d\n",s.roll_no);
    printf("Name: ");
    puts(s.name);
    printf("\nCGPA: %f",s.CGPA);
    printf("\nAge: %d",s.age.age_present);
}
void print_call_by_reference(struct student_info * s){
    printf("Call by reference");
    printf("Roll: %d\n",s->roll_no);
    printf("Name: ");
    puts(s->name);
    printf("\nCGPA: %f",s->CGPA);
    printf("\nAge: %d",s->age.age_present);
}
int main(){
    struct student_info s1;
    printf("Enter the roll no: ");
    scanf("%d",&s1.roll_no);
    fflush(stdin);
    printf("Enter the name: ");
    fgets(s1.name, sizeof(s1.name), stdin);
    fflush(stdin);
    printf("Enter the CGPA: ");
    scanf("%f",&s1.CGPA);
    printf("Enter the age: ");
    scanf("%d",&s1.age.age_present);
    print_call_by_value(s1);
    print_call_by_reference(&s1);
    return 0;
    
}