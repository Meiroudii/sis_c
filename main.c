#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "dbcrud.h"
#include "bootanim.h"

int main() {
    int choice;
    while(choice != 5) {
        boot_anim();
        system("clear");
        printf("\nStudent Database Management System\n");
        printf("\n[1] Add student record\n");
        printf("\n[2] View student records\n");
        printf("\n[3] Search student record\n");
        printf("\n[4] Delete student record\n");
        printf("\n[5] EXIT\n");
        printf("\n\t>> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                system("clear");
                add_student();
                break;

            case 2:
                system("clear");
                student_record();
                getchar();
                break;
            case 3:
                system("clear");
                search_student();
                break;
            case 4:
                system("clear");
                delete_student();
                break;
            case 5:
                system("clear");
                printf("Shutting Down...");
                break;
            default:
                printf("\t\tEnter a valid number\n");
                break;
        }
    }
    return 0;
}

