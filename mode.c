#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"data.h"
#include "mode.h"
#include "admin.h"
#include "user.h"
#include "filehandling.h"
int mode;
extern int num_std;
void MODE(){
    write_student_count(num_std);
    read_student_count();
    lst = (student*)malloc(300*sizeof(student));
    if(num_std==0)
    {
        FILE *fp;
        fp= fopen("student.txt","a");
        if (fp==NULL)
            printf("error opening the file");
        fclose(fp);
    }
    ReadStudentFile();
    adminpass *ad;
    ad = (adminpass *)malloc(sizeof(adminpass));
    ad->password = "1234";
   add_admin_pass(ad);   //run for the first excution only
    read_admin_pass(ad);

    do{
        printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t        [1]Admin mode  \n\n\t\t\t        [2]User mode  \n\n\t\t\t        [3]EXIT\n ");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t        choose from 1:3\n");
        printf("\n\t\t\t        ");
        scanf("%d",&mode);
        switch(mode)
        {
            case 1:
            amode(ad);
            break;
            case 2:
            umode();
            break;
            case 3:
            break;
            default :
                printf("\n\t\t\t        Invalid choise");
                break;


        }

    }while(mode!=3);


}
void amode(adminpass *ad){
    int achoice;

   for(int j=0;j<3;j++)
   {

       char *pass = (char*)malloc(strlen(ad->password)+1);
    printf("\n\t\t\t        Enter Admin Password : ");
    scanf("%s",pass);
    if(strcmp(pass,ad->password)==0)
    {

    do{

        printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t        [1]Add student record\n\n\t\t\t        [2]Remove student record \n\n\t\t\t        [3]View student record\n\n\t\t\t        [4]View all records\n\n\t\t\t        [5]Edit admin password \n\n\t\t\t        [6]Edit student grade\n\n\t\t\t        [7]Exit\n ");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t        choose from 1:7\n");
        printf("\n\t\t\t        ");
        scanf("%d",&achoice);
        switch(achoice)
        {
            case 1:
             add_record();
            break;
            case 2:
            rm_record();
            break;
            case 3:
            vew_record();
            break;
            case 4:
            View_all_records();
            break;
            case 5:
            apass_edit(ad);
            break;
            case 6:
            edit_grade();
            break;
            case 7:
                break;
            default :
                printf("\n\t\t\t        Invalid choise");
                break;

        }

    }while(achoice!=7);
    break;
    }
    else{
        printf("\n\t\t\t        Incorrect Admin Password");
    }
   }
}
void umode(){
    int ID,hi,flag=0;
    char *pass = (char*)malloc(sizeof(char));
    printf("\n\t\t\t        Enter User ID : ");
    scanf("%d",&ID);
    printf("\n\t\t\t        Enter User Password : ");
    scanf("%s",pass);
    for(int i=0;i<num_std;i++)
    {
        if(ID==lst[i].id&&strcmp(pass,lst[i].pass)==0)
        {

            flag=1;
            hi=i;
            break;
        }

    }
    if(flag)
    {
        printf("\n\t\t\t        >> WELCOME %s <<\n\n\t\t\t",lst[hi].name);
       int uchoice;


    do{
        printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t        [1]View student record\n\n\t\t\t        [2]Edit your name \n\n\t\t\t        [3]Edit your password \n\n\t\t\t        [4]Exit\n ");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t        choose from 1:4\n");
        printf("\n\t\t\t        ");
        scanf("%d",&uchoice);
        switch(uchoice)
        {
            case 1:
             view_record(ID);
            break;
            case 2:
            name_edit(ID);
            break;
            case 3:
            pass_edit(ID);
            break;
            case 4:
            break;

            default :
                printf("\n\t\t\t        Invalid choise");
                break;

        }

    }while(uchoice!=4);

   }else{
   printf("\n\t\t\t        Incorrect User Password or ID");
   }

    }



