//
// Created by MARWAN on 4/23/2024.
#include <stdio.h>
#include <stdlib.h>
#include "Filehandling.h"
#include "data.h"
extern int num_std;
void ReadStudentFile() {
FILE *fp;
    fp= fopen("Student.txt", "r");
    if (fp == NULL) {
        printf("\nUnable to open file\n");
        exit(1);
    }
    char *pass;
    pass=(char *) malloc(30*sizeof(char ));
    char *name;
    name=(char *) malloc(30*sizeof(char ));

for(int i=0;i<num_std;i++)
{
    fscanf(fp,"%d,%49[^,],%49[^,],%d,%d,%c/n",&lst[i].id,name,pass,&lst[i].grade,&lst[i].age,&lst[i].gender);
    lst[i].pass=pass;
    lst[i].name=name;
    pass=(char *) malloc(30*sizeof(char ));
    name=(char *) malloc(30*sizeof(char ));
}


    fclose(fp);

}
void write_student_count(int count)
{
    FILE *fp;
    fp= fopen("count.txt", "w");
    if (fp == NULL) {
        printf("\nUnable to open file\n");
        exit(1);
    }
    fprintf(fp,"%d,",count);
    fclose(fp);

}
void read_student_count()
{
    FILE *fp;
    fp= fopen("count.txt", "r");
    if (fp == NULL) {
        printf("\nUnable to open file\n");
        exit(1);
    }
    fscanf(fp,"%d,",&num_std);
    fclose(fp);

}
void add_admin_pass(adminpass *ad)
{
    FILE *fp;
    fp= fopen("admin.txt", "w");
    if (fp == NULL) {
        printf("\nUnable to open file\n");
        exit(1);
    }
    fprintf(fp,"%s,",ad->password);
    fclose(fp);
}
void read_admin_pass(adminpass *ad)
{
    FILE *fp;
    fp= fopen("admin.txt", "r");
    if (fp == NULL) {
        printf("\nUnable to open file\n");
        exit(1);
    }
    char *pass;
    pass=(adminpass *)malloc(sizeof(adminpass));
    fscanf(fp,"%49[^,],",pass);
    ad->password=pass;
    fclose(fp);
}
void rm_student(int j)
{
    FILE *fp,*fo;
    fp= fopen("student.txt","r");
    fo= fopen("temp.txt","w");
    if (fp == NULL || fo == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }
    student st;
    char *pass;
    pass=(char *) malloc(30*sizeof(char ));
    char *name;
    name=(char *) malloc(30*sizeof(char ));
for(int i=0;i<num_std;i++)
{
    if(i==j)
    {
        fscanf(fp, "%d,%49[^,],%49[^,],%d,%d,%c\n", &st.id, name, pass, &st.grade, &st.age, &st.gender);
        pass = (char *) malloc(30 * sizeof(char));
        name = (char *) malloc(30 * sizeof(char));
        st.id=0;
        name=NULL;
        pass=NULL;
        st.grade=0;
        st.age=0;
        st.gender=0;
        fprintf(fo,"%d,%s,%s,%d,%d,%c\n",st.id,name,pass,st.grade,st.age,st.gender);
        pass = (char *) malloc(30 * sizeof(char));
        name = (char *) malloc(30 * sizeof(char));
        continue;
    }else {
        fscanf(fp, "%d,%49[^,],%49[^,],%d,%d,%c\n", &st.id, name, pass, &st.grade, &st.age, &st.gender);
        fprintf(fo, "%d,%s,%s,%d,%d,%c\n", st.id, name, pass, st.grade, st.age, st.gender);
        pass = (char *) malloc(30 * sizeof(char));
        name = (char *) malloc(30 * sizeof(char));
    }
}

    fclose(fp);
    fclose(fo);
    remove("student.txt");
    rename("temp.txt","student.txt");
}
void edit_user_info(int j){
    FILE *fp,*fo;
    fp= fopen("student.txt","r");
    fo= fopen("temp.txt","w");
    if (fp == NULL || fo == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }
    student st;
    char *pass;
    pass=(char *) malloc(30*sizeof(char ));
    char *name;
    name=(char *) malloc(30*sizeof(char ));
    for(int i=0;i<num_std;i++)
    {
        if(i==j)
        {
            fscanf(fp, "%d,%49[^,],%49[^,],%d,%d,%c\n", &st.id, name, pass, &st.grade, &st.age, &st.gender);
            pass = (char *) malloc(30 * sizeof(char));
            name = (char *) malloc(30 * sizeof(char));
            st.id=lst[i].id;
            name=lst[i].name;
            pass=lst[i].pass;
            st.grade=lst[i].grade;
            st.age=lst[i].age;
            st.gender=lst[i].gender;
            fprintf(fo,"%d,%s,%s,%d,%d,%c\n",st.id,name,pass,st.grade,st.age,st.gender);
            pass = (char *) malloc(30 * sizeof(char));
            name = (char *) malloc(30 * sizeof(char));
            continue;
        }else {
            fscanf(fp, "%d,%49[^,],%49[^,],%d,%d,%c\n", &st.id, name, pass, &st.grade, &st.age, &st.gender);
            fprintf(fo, "%d,%s,%s,%d,%d,%c\n", st.id, name, pass, st.grade, st.age, st.gender);
            pass = (char *) malloc(30 * sizeof(char));
            name = (char *) malloc(30 * sizeof(char));
        }
    }

    fclose(fp);
    fclose(fo);
    remove("student.txt");
    rename("temp.txt","student.txt");
}
