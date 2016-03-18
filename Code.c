/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stud
{
char name[20];
char bth[20];
int en;
struct stud *down;
struct atn * right;
};
struct atn
{
char pres;
char date[10];
struct atn *right;
};
struct atn *temp_st,*tempatn,*pstartatn=NULL,*startatn=NULL;
struct stud *faltu,*pstud=NULL,*tempstud,*new_stud,*currentstud;

int displaystall();
void displayallall();
void displayallat();
int addstud();
void addatn();
int upst();
int upatn();


int main()
{
int j,i;
FILE *x,*y;
/*    x=fopen("c:\4.txt","r+");
    tempstud=pstud;
    do
    {
        tempstud=(struct stud *)malloc(sizeof(struct stud));
        fflush(stdin);
        fscanf(x,"%s %d %c ",tempstud->name,&tempstud->en,&tempstud->bth);
        tempatn=tempstud->right;
        do
        {
        fflush(stdin);
        fscanf(x,"%c %s",&tempatn->pres,tempatn->date);
        tempatn=tempatn->right;
        }while(tempatn && EOF);
        tempstud->down=(struct stud *)malloc(sizeof(struct stud));
        tempstud=tempstud->down;

    }while(tempstud!=NULL && EOF);
    fclose(x);*/
for(i=0;i<10;i++)
{
printf("\n\n1 - Enter more Students\n2 - Update a Student's info\n3 - Take Attendance\n4 - Update or Change somebody's Attendance for a day\n5 - Display all details\n6 - Display attendance for a day of every student\n7 - Display all attendances of single student \n8 - To exit\n\n");
scanf("%d",&j);
if(j==1)
j=addstud();
else if(j==2)
j=upst();
else if(j==3)
addatn();
else if(j==4)
j=upatn();
else if(j==5)
displayallall();
else if(j==6)
displayallat();
else if(j==7)
j=displaystall();
else if(j==8)
{
    y=fopen("c:\4.txt","w+");
    tempstud=pstud;
    while(tempstud!=NULL)
    {
        fflush(stdin);
        fprintf(y,"%s %d %c ",tempstud->name,tempstud->en,tempstud->bth);
        tempatn=tempstud->right;
        while(tempatn)
        {
        fflush(stdin);
        fprintf(y,"%c %s",tempatn->pres,tempatn->date);
        tempatn=tempatn->right;
        }
        tempstud=tempstud->down;
    }
    fclose(y);
return 0;
}
i--;
}}


void displayallall()
{
tempstud=pstud;
printf("\n");
printf("Student Name|Enrollmennt No.|Batch");
tempatn=tempstud->right;
while(tempatn)
{
printf(" |||| Attendance on DATE");
tempatn=tempatn->right;
}
printf("\n");
while(tempstud)
{
tempatn=tempstud->right;
printf("%s\t",tempstud->name);
printf("%d\t",tempstud->en);
printf("\t%s\t",tempstud->bth);
while(tempatn)
{
printf("\t%s->",tempatn->date);
printf("%c",tempatn->pres);
tempatn=tempatn->right;
}
printf("\n");
tempstud=tempstud->down;
}
}

int displaystall()
{
int tempen;
tempstud=pstud;
printf("\n");
printf("Enter the Enrollment no. of student\t");
scanf("%d",&tempen);
while(tempstud)
{
if(tempstud->en==tempen)
{
printf("Student Name|Enrollmennt No.|Batch");
tempatn=tempstud->right;
while(tempatn)
{
printf(" |||| Attendance on DATE");
tempatn=tempatn->right;
}
printf("\n");
tempatn=tempstud->right;
printf("%s\t",tempstud->name);
printf("%d\t",tempstud->en);
printf("\t%s\t",tempstud->bth);
while(tempatn)
{
printf("\t%s->",tempatn->date);
printf("%c",tempatn->pres);
tempatn=tempatn->right;
}
printf("\n");
}
tempstud=tempstud->down;
}
return 0;}


void displayallat()
{
char dtemp[10];
tempstud=pstud;
printf("\nEnter the date of attendance to be viewed :\t");
scanf("%s",dtemp);
printf("\n");
printf("Student Name|Enrollmennt No.|Batch");
printf(" |||| Attendance on DATE");
printf("\n");
while(tempstud)
{
tempatn=tempstud->right;
printf("%s\t",tempstud->name);
printf("%d\t",tempstud->en);
printf("\t%s\t",tempstud->bth);
while(tempatn)
{
if(strcmp(tempatn->date,dtemp)==0)
{
printf("\t%s->",tempatn->date);
printf("%c",tempatn->pres);
printf("\n");
}
tempatn=tempatn->right;
}
tempstud=tempstud->down;
}
}

int addstud()
{
tempstud=pstud;
new_stud=(struct stud *)malloc(sizeof(struct stud));
printf("\nEnter the Student's name : ");
scanf("%s",new_stud->name);
printf("\nEnter the Student's Enrollment no. : ");
scanf("%d",&new_stud->en);
printf("\nEnter the Student's Batch : ");
scanf("%s",new_stud->bth);
new_stud->right=NULL;
new_stud->down=NULL;
    if(tempstud==NULL)
        {
        pstud=new_stud;
        tempstud=new_stud;
        }
    else if(tempstud->en<=new_stud->en)
        {
        while(tempstud->en<=new_stud->en && tempstud->down!=NULL)
            {
            if(tempstud->en==new_stud->en)
            {
            printf("Student already Exists");
            return 0;
            }
            faltu=tempstud;
            tempstud=tempstud->down;
            }
            if(tempstud->down==NULL && tempstud->en<new_stud->en)
            {
            tempstud->down=new_stud;
            return 0;
            }
            if(tempstud->down==NULL && tempstud->en>new_stud->en)
            {
            faltu->down=new_stud;
            new_stud->down=tempstud;
            return 0;
            }
            else
            {
            faltu->down=new_stud;
            new_stud->down=tempstud;
            return 0;
            }
            }
        else if(tempstud->en>new_stud->en)
        {
        new_stud->down=pstud;
        pstud=new_stud;
        return 0;
        }
        return 0;
}


void addatn()
{
int ln=0;
char ch,tempdate[10];
printf("\n\nEnter the Date in order of DD-MM-YYYY:\t");
scanf("%s",tempdate);
printf("\nPress y if present else n\n");
new_stud=pstud;
while(new_stud!=NULL)
{
struct atn *new_atn,*currentatn;
new_atn=(struct atn *)malloc(sizeof(struct atn));
ln=0;
fflush(stdin);
printf("%s\t%s\t%d :\t",new_stud->name,new_stud->bth,new_stud->en);
scanf("%c",&new_atn->pres);
strcpy(new_atn->date,tempdate);
currentatn=new_stud->right;
if(currentatn!=NULL)
{
    while(currentatn->right)
    {
    currentatn=currentatn->right;
    }

currentatn->right=(struct atn *)malloc(sizeof(struct atn));
currentatn->right=new_atn;
currentatn=currentatn->right;
currentatn->right=NULL;
new_stud=new_stud->down;
}
else
{
new_stud->right=(struct atn *)malloc(sizeof(struct atn));
new_stud->right=new_atn;
new_atn->right=NULL;
new_stud=new_stud->down;
}
}
}


int upst()
{
int ln,cmn=0;
int enck;
printf("\nEnter the Enrollment No. of the student which has to be updated :\t");
scanf("%d",&enck);
currentstud=pstud;
while(currentstud)
{
if(currentstud->en==enck)
{
printf("\nEnter the Student's Corrected name : ");
scanf("%s",currentstud->name);
printf("\nEnter the Student's Corrected Enrollment no. : ");
scanf("%d",&currentstud->en);
printf("\nEnter the Student's Corrected Batch : ");
scanf("%s",currentstud->bth);
return 0;
}
currentstud=currentstud->down;
}
return 0;
}

int upatn()
{
int ln,cmn=0;
int enck;
char dttemp[10];
printf("\nEnter the Enrollment No. of the student which has to be updated :\t");
scanf("%d",&enck);
currentstud=pstud;
while(currentstud)
{
if(currentstud->en==enck)
{
    tempatn=currentstud->right;
    printf("\nEnter the Date :\t");
    scanf("%s",dttemp);
    while(tempatn)
    {
        if(strcmp(tempatn->date,dttemp)==0)
        {
            printf("\nOriginal Attendance was :\t%c",tempatn->pres);
            fflush(stdin);
            printf("\nEnter corrected Attendance :\t");
            scanf("%c",&tempatn->pres);
            return 0;
        }
        tempatn=tempatn->right;
    }
    printf("\nDate not found");
    return 0;
}
currentstud=currentstud->down;
}
printf("\nStudent not found");
return 0;
}

/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */