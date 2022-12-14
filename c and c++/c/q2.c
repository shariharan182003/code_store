#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
int n,n1,ihead=0,dhead=0;
struct student
{
	char stud_name[60];
	char reg_num[10];
	int mark1;
	int mark2;
	int mark3;
	int total;
	float average;
	char grade;
	struct student *next,*prev;
}*tail,*head,*temp,*cnode,*temp2,*temp3;
int repetition(char a[])
{
    temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->reg_num,a)==0)
            return 1;
        temp=temp->next;
    }
    return 0;
}
char grade(float a)
{
    char g;
    if((a>=91)&&(a<=100))
        g='S';
    else if((a>=81)&&(a<=90))
        g='A';
    else if((a>=71)&&(a<=80))
        g='B';
    else if((a>=61)&&(a<=70))
        g='C';
    else if((a>=51)&&(a<=60))
        g='D';
    else if((a>=41)&&(a<=50))
        g='E';
    else if((a>=0)&&(a<=40))
        g='F';
    else 
        g='N';
    return g;
}
void creation()
{
    printf("Enter number of nodes: ");
    scanf("%d",&n);n1=n;
    cnode=(struct student*)malloc(sizeof(struct student));
    cnode->next=NULL;
    cnode->prev=NULL;
    tail=cnode;
    head=cnode;
    int i;
    for(i=0;i<n1;i++)
    {
        char a[10];
        printf("Enter regno: ");
        scanf("%s",&a);
        if(i==0)
        {
            strcpy(tail->reg_num,a);ihead+=9;
            printf("Enter name: ");
            scanf("%s",&tail->stud_name);
            printf("Enter mark1 mark2 mark3: ");
            scanf("%d %d %d",&tail->mark1,&tail->mark2,&tail->mark3);
            tail->total=tail->mark1+tail->mark1+tail->mark3;
            tail->average=tail->total/3;
            tail->grade=grade(tail->average);
            printf("\n");

        }
        else
        {
            cnode=(struct student*)malloc(sizeof(struct student));
            cnode->next=NULL;
            cnode->prev=NULL;
            if(repetition(a)==1)
            {
                printf("The regno is repeated\n");
                n1++;
            }
            else
            {
                strcpy(cnode->reg_num,a);
                printf("Enter name: ");
                scanf("%s",&cnode->stud_name);
                printf("Enter mark1 mark2 mark3: ");
                scanf("%d %d %d",&cnode->mark1,&cnode->mark2,&cnode->mark3);
                cnode->total=cnode->mark1+cnode->mark1+cnode->mark3;
                cnode->average=cnode->total/3;
                cnode->grade=grade(cnode->average);
                tail->next=cnode;
                cnode->prev=tail;
                tail=cnode;
                printf("\n");
            }
        }
    }
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp->reg_num,temp->stud_name,temp->average,temp->grade);
		temp=temp->next;
	}
    printf("\n");
}
void count_grade()
{
    int s=0,a=0,b=0,c=0,d=0,e=0,f=0,n2=0;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->grade=='S')
            s++;
        else if(temp->grade=='A')
            a++;
        else if(temp->grade=='B')
            b++;
        else if(temp->grade=='C')
            c++;
        else if(temp->grade=='D')
            d++;
        else if(temp->grade=='E')
            e++;
        else if(temp->grade=='F')
            f++;
        else
            n2++;
        temp=temp->next;
    }
    printf("\nThe number of students is %d\n",n);
    if(s>0)
        printf("The number of S grades are %d\n",s);
    if(a>0)
        printf("The number of A grades are %d\n",a);
    if(b>0)
        printf("The number of B grades are %d\n",b);
    if(c>0)
        printf("The number of C grades are %d\n",c);
    if(d>0)
        printf("The number of D grades are %d\n",d);
    if(e>0)
        printf("The number of E grades are %d\n",e);
    if(f>0)
        printf("The number of F grades are %d\n",f);
    if(n2>0)
        printf("The number of N grades are %d\n",n2);
}
void deletion(int index)
{
    if(index==0)
    {
        head=head->next;dhead++;
        head->prev=NULL;
    }
    if(index==(n-1))
    {
        temp2=head;dhead++;
        for(int i=0;i<(n-1);i++)
            temp2=temp2->next;
        temp2->next=NULL;
        tail=temp2;
    }
    else
    {
        temp2=head;
        for(int i=0;i<index-1;i++)
            temp2=temp2->next;
        temp2->next=temp2->next->next;
    }
}
void del_fail()
{
    temp=head;
    while(temp!=NULL)
    {
        if(temp->grade=='F')
        {
            temp2=head;int ind=0;
            printf("Deleted node: \n\n");
            printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp->reg_num,temp->stud_name,temp->average,temp->grade);
            printf("f. Traverse of the list: \n\n");
            while(temp2!=temp)
            {
                ind++;
                printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp2->reg_num,temp2->stud_name,temp2->average,temp2->grade);
                temp2=temp2->next;
            }
            deletion(ind);
        }
        temp=temp->next;
    }
}
int main()
{
    printf("a. Creation\n\n");
	creation();
    printf("b. Count the number of grades\n\n");
    count_grade();
    printf("c. Traverse\n\n");
    display();
    printf("d. Count the number of times the head value is changed during insertion\n\n");
    printf("The count is %d",ihead);
    printf("e. delete all fail grade nodes and display\n\n");
    del_fail();
    printf("g. Count the number of times the head value is changed during deletion\n\n");
    printf("The count is %d",dhead);
	getch();
	return 0;
}