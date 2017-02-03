
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    double gpa;
} student;

int main(int argc, char** argv) {
    int n = 0;
    int index = 0;
    
    //Number of students input
    printf("Enter the number of students to input: \n");
    scanf("%d", &n);
    struct Student array[n];
    
    //Students input
    while (index < n) {
        struct Student student;
        printf("Enter the student name: \n");
        scanf("%s", student.name);
        printf("Enter the student gpa: \n");
        scanf("%lf", &student.gpa);
        array[index] = student;
        index++;

    }
    if (index == 20) {
        printf("LIMIT OF 20 STUDENTS REACHED\n");
    }

    //BubbleSort
    int c;
    for (c = 0; c < (n - 1); c++) {
        int d;
        for (d = 0; d < n - c - 1; d++) {
            if (array[d].gpa > array[d + 1].gpa) {
                struct Student swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }

    printf("SORTED LIST BY ASCENDING GPA: \n");
    int i;
    for (i = 0; i < n; i++) {
        printf("NAME: %s : ", array[i].name);
        printf("GPA: %lf\n", array[i].gpa);
    }
    return 1;
}

