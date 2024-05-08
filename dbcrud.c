#include <stdio.h>

typedef struct {
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
    char address[20];
    float percentage;
}Student;

void add_student() {
    char another;
    FILE *fp;
    Student info;

    do {
        printf("\nAdd student\n");
        fp=fopen("student_info", "a");
        printf("\nEnter Last name:\n");
        scanf("%s", &info.last_name);
        printf("\nEnter First name:\n");
        scanf("%s", &info.first_name);
        printf("\nEnter Roll no.:\n");
        scanf("%d", &info.roll_no);
        printf("\nEnter Class:\n");
        scanf("%s", &info.Class);
        printf("\nEnter Address:\n");
        scanf("%s", &info.address);
        printf("\nEnter Percentage:\n");
        scanf("%f", &info.percentage);

        if(fp==NULL) {
            printf("\nCan't open the file\n");
        }
        else {
            printf("\nStudent saved successfuly\n");
        }
        fwrite(&info,sizeof(Student),1,fp);
        fclose(fp);

        printf("\nAdd another student?:(y/n)\n");
        scanf("%s", &another);
    }while(another == 'Y' || another == 'y');
}

void student_record() {
    char quit_f;
    FILE *fp;
    Student info;
    fp = fopen("student_info", "r");
    printf("\nAdd student\n");

    if(fp==NULL) {
        fprintf(stderr,"\nCan't open the file\n");
    }
    else {
        printf("\nRecords\n");
    }

    while(fread(&info,sizeof(Student),1,fp)) {
        printf("\nRecords\n");
        printf("\nStudent name: %s %s\n", info.first_name, info.last_name);
        printf("\nRoll no: %d\n", info.roll_no);
        printf("\nClass: %s\n", info.Class);
        printf("\nAddress: %s\n", info.address);
        printf("\nPercentage: %f\n", info.percentage);
    }
    fclose(fp);
    printf("\nPress any key to exit\n");
    scanf("%c", &quit_f);

}

void search_student() {
    FILE *fp;
    Student info;
    int roll_no, found=0;

    fp=fopen("student_info", "r");
    printf("\nSearch Student\n");
    printf("\nEnter Roll Number:\n");
    scanf("%d", &roll_no);
    while(fread(&info,sizeof(Student),1,fp)) {
        if(info.roll_no==roll_no) {
            found = 1;
            printf("\nRecords\n");
            printf("\nStudent name: %s %s\n", info.first_name, info.last_name);
            printf("\nRoll no: %d\n", info.roll_no);
            printf("\nClass: %s\n", info.Class);
            printf("\nAddress: %s\n", info.address);
            printf("\nPercentage: %f\n", info.percentage);
        }
    }
    if(!found) {
        printf("\nRecord not found\n");
    }

}

void delete_student() {
    FILE *fp, *fp_temp;
    Student info;
    int roll_no, found=0;

    fp=fopen("student_info", "r");
    fp_temp=fopen("temp.txt", "w");
    printf("\nRemove Student\n");
    printf("\nEnter Roll Number:\n");
    scanf("%d", &roll_no);

    if(fp==NULL) {
        printf("\nCan't open the file\n");
    }
    else {
        printf("\nStudent saved successfuly\n");
    }

    while(fread(&info,sizeof(Student),1,fp)) {
        if(info.roll_no==roll_no) {
            found = 1;
            printf("\nRecords\n");
            printf("\nStudent name: %s %s\n", info.first_name, info.last_name);
            printf("\nRoll no: %d\n", info.roll_no);
            printf("\nClass: %s\n", info.Class);
            printf("\nAddress: %s\n", info.address);
            printf("\nPercentage: %f\n", info.percentage);
        }
        else {
            fwrite(&info,sizeof(Student),1,fp_temp);
        }
    }
    fclose(fp);
    fclose(fp_temp);

    if(found) {
        remove("student_info");
        rename("temp.txt", "student_info");
        printf("Student has been remove successfuly!");
    }
    if(!found) {
        printf("\nRecord not found\n");
    }
}
