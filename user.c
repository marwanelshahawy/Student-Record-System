#include "User.h"
#include "filehandling.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int num_std;
student *lst;
void view_record(int ID) {
    int flag=0;
    for(int i=0;i<num_std;i++) {

        if(ID==lst[i].id) {
                printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
            printf("\n\t\t\t        Record For Student %d\n",i+1);
                    printf("\n\t\t\t        NAME : %s\n\n\t\t\t        ID : %d\n\n\t\t\t        AGE : %d\n\n\t\t\t        GENDER : %c\n\n\t\t\t        PASSWORD : %s \n\n\t\t\t        TOTAL GRADE : %d\n",lst[i].name,lst[i].id,lst[i].age,lst[i].gender,lst[i].pass,lst[i].grade);
                    printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
                    flag=1;

            break;
        }

    }
    if(flag==0)
    {
            printf("\n\t\t\t        ID doesn`t exist...Try again");

    }

}


void name_edit(int ID) {
    int flag=0;
    char *nname=(char*)malloc(30*sizeof(char));
    printf("\n\t\t\t        Enter New Name : ");
    getchar();
    gets(nname);

    for(int i=0;i<num_std;i++) {
        if(ID==lst[i].id) {
            strcpy(lst[i].name,nname);
            printf("\n\t\t\t        Name changed Successfully\n");
            edit_user_info(i);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("\n\t\t\t        Fail to change Name\n");
    }
}


void pass_edit(int ID) {
    int flag=0;
    char *npass=(char *)malloc(30*sizeof(char));

    printf("\n\t\t\t        Enter new Password : ");
    getchar();
    gets(npass);

    for(int i=0;i<num_std;i++) {
        if(ID==lst[i].id) {
            strcpy(lst[i].pass,npass);
            printf("\n\t\t\t        Password changed Successfully\n");
            edit_user_info(i);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {

    printf("\n\t\t\t        Fail to change Password\n");
    }
}


