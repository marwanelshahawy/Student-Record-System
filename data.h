#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED



typedef struct student{
    int id;
    char *name;
    char *pass;
    int grade;
    int age;
    char gender;
}student;

extern student *lst;

 typedef struct admin{
     char *password;
 }adminpass;




#endif // DATA_H_INCLUDED
