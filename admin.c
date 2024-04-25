#include "admin.h"
#include "data.h"
#include "mode.h"
#include "filehandling.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 int num_std=0;
int MAXSTD=300;

 FILE *fp;

void add_record(){


    student st;
    char another;
    do{
        fp= fopen("student.txt","a");
        if (fp==NULL)
            printf("error opening the file");
            int count=1;

        st.name=(char*)malloc(30*sizeof(char));
        st.pass=(char*)malloc(30*sizeof(char));
        printf("\n\t\t\t        Enter Name: ");
        getchar();
        gets(st.name);
        printf("\n\t\t\t        Enter Age: ");
        scanf("%d",&st.age);
        printf("\n\t\t\t        Enter Password: ");
        scanf("%s",st.pass);
        getchar();
        printf("\n\t\t\t        Enter Gender (M/F): ");
        scanf("%c",&st.gender);
        printf("\n\t\t\t        Enter ID: ");
        scanf("%d",&st.id);
        if(num_std==0)
        {
            count=0;
        }
        while(count)
        {
            int mark=0;
            for(int i=0;i<num_std;i++)
            {
                if(lst[i].id==st.id)
                {
                    printf("\n\t\t\t        ID is already exist");
                    printf("\n\t\t\t        Enter ID: ");
                    scanf("%d",&st.id);
                    mark=1;
                }
                if(mark==0)
                {
                    count=0;
                }
            }

        }
        printf("\n\t\t\t        Enter Grade: ");
        scanf("%d",&st.grade);
        while(st.grade>100||st.grade<0)
        {
            printf("\n\t\t\t        The Grade not between 0:100");
            printf("\n\t\t\t        Enter Grade: ");
            scanf("%d",&st.grade);
        }


             num_std++;
             write_student_count(num_std);
        if(num_std>MAXSTD)
        {
            lst =  realloc(lst, (num_std+1)*sizeof(student));
        }

                lst[num_std-1].name=st.name;
                lst[num_std-1].id=st.id;
                lst[num_std-1].age=st.age;
                lst[num_std-1].gender=st.gender;
                lst[num_std-1].pass=st.pass;
                lst[num_std-1].grade=st.grade;


fprintf(fp,"%d,%s,%s,%d,%d,%c\n",lst[num_std-1].id,lst[num_std-1].name,lst[num_std-1].pass,lst[num_std-1].grade,lst[num_std-1].age,lst[num_std-1].gender);
        fclose(fp);

            printf("\n\t\t\t        Successfully added...");
            printf("\n\t\t\t        Do you want to add another student (y/n)");
            getchar();
            scanf("%s",&another);
    }while(another == 'y');
}
void vew_record(){
    int flag=0;
    int ID;
    printf("\n\t\t\t        Enter ID: ");
        scanf("%d",&ID);

    for(int i=0;i<num_std;i++) {

        if(ID==lst[i].id) {
                                printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");

            printf("\n\t\t\t        Record For Student %d\n",i+1);
                    printf("\n\t\t\t        NAME : %s\n\n\t\t\t        ID : %d\n\n\t\t\t        AGE : %d\n\n\t\t\t        GENDER : %c\n\n\t\t\t        PASSWORD : %s\n\n\t\t\t        TOTAL GRADE : %d\n",lst[i].name,lst[i].id,lst[i].age,lst[i].gender,lst[i].pass,lst[i].grade);
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
void rm_record(){
    int flag=0;
    int ID;
    printf("\n\t\t\t        Enter ID: ");
        scanf("%d",&ID);

    for(int i=0;i<num_std;i++) {

        if(ID==lst[i].id) {
            lst[i].name=NULL;
            lst[i].age=0;
            lst[i].gender=0;
            lst[i].grade=0;
            lst[i].pass=NULL;
            lst[i].id=0;
            rm_student( i);
            printf("\n\t\t\t        Successfully removed\n");

                    flag=1;

            break;
        }

    }
    if(flag==0)
    {
            printf("\n\t\t\t        ID doesn`t exist...Try again");

    }


}
void View_all_records() {
    int check=0;
    int count=0;
    for(int i=0;i<num_std;i++) {
        if(lst[i].id) {

            check=1;
            printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");

            printf("\n\t\t\t        Record For Student %d\n",count+1);
                    printf("\n\t\t\t        NAME : %s\n\n\t\t\t        ID : %d\n\n\t\t\t        AGE : %d\n\n\t\t\t        GENDER : %c\n\n\t\t\t        PASSWORD : %s\n\n\t\t\t        TOTAL GRADE : %d\n",lst[i].name,lst[i].id,lst[i].age,lst[i].gender,lst[i].pass,lst[i].grade);
                                    printf("\n\t\t\t        =-=-=-=-=-=-=-=\n");
                                    count++;
        }
    }
        if(check==0) {
            printf("\n\t\t\t        There is no Student to view\n");
        }

}
void apass_edit(adminpass *ad) {
   char *npass = (char*)malloc(strlen(ad->password)+1);
    printf("\n\t\t\t        Enter New Password : ");
    getchar();
    gets(npass);
    ad->password=npass;
    add_admin_pass(ad);
    printf("\n\t\t\t        Password edited Successfully\n");
}
void edit_grade(){
    int flag=0;
    int ID,ngrade;
    printf("\n\t\t\t        Enter ID: ");
        scanf("%d",&ID);

    for(int i=0;i<num_std;i++) {

        if(ID==lst[i].id) {
            printf("\n\t\t\t        Enter New Grade : ");
            scanf("%d",&ngrade);
            while(ngrade>100||ngrade<0)
        {
            printf("\n\t\t\t        The Grade not between 0:100");
            printf("\n\t\t\t        Enter New Grade: ");
            scanf("%d",&ngrade);
        }
        lst[i].grade=ngrade;
            printf("\n\t\t\t        Updated Successfully\n");
            edit_user_info(i);

            flag=1;

            break;
        }

    }
    if(flag==0)
    {
            printf("\n\t\t\t        ID doesn`t exist...Try again");

    }

}
