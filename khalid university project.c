#include<stdio.h>
#include<conio.h>

void addstudents();
void studentrecord();
void searchstudent();
void delete();

struct student
{
    char student_name[1000];
    int student_id[1000];
};

void main()
{
    int choice ;
    while(choice!=5)
    {
        printf("\t\t\t\t****STUDENT MANAGEMENT SYSTEM****");
        printf("\n\n\n\t\t\t  1.Add Student Records \n");
        printf("\t\t\t  2.Student Records \n");
        printf("\t\t\t  3.Search  Student\n");
        printf("\t\t\t  4.Delete Record \n");
        printf("\t\t\t  5.Exit \n");
        printf("\t\t\t  ______________________\n");
        printf("\t\t\t  ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            addstudents();
            break;
        case 2:
            studentrecord();
            printf("\t\t\t\tPress any key in exit\n");
            getch();
            break;
        case 3:
            searchstudent();
            printf("\t\t\t\tPress any key in exit\n");
            getch();
            break;
        case 4:
            delete();
            printf("\t\t\t\tPress any key in exit\n");
            getch();
            break;
        case 5:
            printf("\n\t\t\t\tThank you \n\n");
            exit(0);
            break;
        default:
               getch();
                printf("\t\t\t\tEnter a valid  number  ");
               printf("\n\t\t\t\tPress any key to continue____\n");
               getch();
               break;

            }

    }

}
void addstudents()
{
    char another ;
    FILE *fp;
    struct student info;

    do
    {

        printf("\t\t\t\t=====Add Student info=====\n\n\n");
        fp=fopen("student_info.text","a");
        printf("\n\t\t\t Enter student  name : ");
        scanf("%s",&info.student_name);
        fflush(stdin);
        printf("\n\t\t\t student_id : ");
        scanf("%d",&info.student_id);
        printf("\n\t\t\t____________________\n");

        if (fp==NULL)
        {
            fprintf(stderr,"t\t\tCan't open file\n");
        }
        else
        {
            printf("\t\t\tRecord stored successfully\n");
        }

        fwrite (&info,sizeof (struct student),1,fp);
        fclose(fp);

        printf("\t\t\tDo you want to add another record?(y/n): ");
        scanf("%s",&another );



    }
    while(another=='y'||another=='Y' );
}

void studentrecord()
{
    FILE *fp;
    struct student info;
    fp=fopen("student_info.text","r");

    printf("\t\t\t\t=====Add Student info=====\n\n\n");

    if (fp==NULL)
    {
        fprintf(stderr,"t\t\t\tCan't open file\n");
    }
    else
    {
        printf("\t\t\t\tRecords\n");
        printf("\t\t\t\t___________\n\n");
    }

    while(fread(&info,sizeof(struct student),1,fp))
    {
        printf("\n\t\t\t\tStudent name : %s ",info.student_name);
        printf("\n\t\t\t\tstudent_id   : %d ",info.student_id);
        printf("\n\t\t\t\t_______________________________\n");
    }
    fclose(fp);
    getch();
}

void searchstudent()
{
    FILE *fp;
    struct student info;
    int student_id,found=0;
    fp=fopen("student_info.text","r");

    printf("\t\t\t\t=====Search Student=====\n\n\n");
    printf("\n\t\t\t\tstudent_id   : ");
    scanf("%d",&student_id);

    while(fread(&info,sizeof(struct student),1,fp))
    {
        if(info,student_id=student_id)
        {

            found=1;
            printf("\n\t\t\t\tStudent name : %s ",info.student_name);
            printf("\n\t\t\t\tStudent_id   : %d ",info.student_id);
            printf("\n\t\t\t\t_______________________________\n");
        }
    }

    if(!found)
    {
        printf("\n\t\t\tRecord not found\n");
    }
    fclose(fp);
    getch();


}
void delete()
{
    FILE *fp,*fp1;
    struct student info;
    int student_id,found=0;
    fp=fopen("student_info.text","r");

    printf("\t\t\t\t=====Search Student=====\n\n\n");
    fp=fopen("student_info.text","r");
    fp=fopen("student_info.text","r");
    printf("\t\t\tEnter the roll no : ");
    scanf("%d",&student_id);

    if(fp==NULL)
    {
        fprintf(stderr,"\t\t\t\tCan't open file\n");
    }
    while(fread(&info,sizeof(struct student),1,fp))
    {
        if(info,student_id==student_id)
        {
            found=1;
        }
        else
        {
            fwrite (&info,sizeof(struct student),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if (found)
    {
        remove("student_info");
        rename("temp.text","student_info");
        printf("\n\t\t\tRecord deleted successfully\n");
    }
    if (!found)
    {
        printf("\n\t\t\tRecord not found\n");
    }
    getch();
}

