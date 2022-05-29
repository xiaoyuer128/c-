/*#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct date
{
    int year;
    int month;
    int day;
}DATE;//�ṹ�������յĶ��塣
typedef struct student
{
    long studentID;
    char name[10];
    char sex;
    DATE birthday;
    int score[4];
}STUDENT;
//�ṹ��ѧ���Ķ��塣
void Input(int n,STUDENT stu[]);
int main()
{
    int i,j,n,sum[N];
    STUDENT stu[N];
    printf("please input student number:\n");
    scanf("%d",&n);
    Input(n,stu);
    Output(n,stu);
    return 0;
}

void Input(int n,STUDENT stu[])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("---------please input student%d's record:---------\n",i);
        printf("please input ID:");
        scanf("%ld",&stu[i].studentID);
        printf("please input name:");
        scanf("%s",&stu[i].name);
        printf("please input sex:");
        scanf(" %c",&stu[i].sex);
        printf("please input birthday(****,*,*):");
        scanf("%d,%d,%d",&stu[i].birthday.year,&stu[i].birthday.month,&stu[i].birthday.day);
        printf("please input score:");
        for(j=0;j<4;j++)
        {
            scanf("%d",&stu[i].score[j]);
        }
    }
}
void Output(int n,STUDENT stu[])
{
    int i,j,sum[N];
    for(i=0;i<n;i++)
    {
        sum[i]=0;
        for(j=0;j<4;j++)
        {
            sum[i]=sum[i]+stu[i].score[j];
        }
        printf("%10d%8s%3c%6d/%02d/%02d%4d%4d%4d%4d%6.1f\n",
               stu[i].studentID,
               stu[i].name,
               stu[i].sex,
               stu[i].birthday.year,
               stu[i].birthday.month,
               stu[i].birthday.day,
               stu[i].score[0],
               stu[i].score[1],
               stu[i].score[2],
               stu[i].score[3],
               sum[i]/4.0
               );
    }
}
*/


/*
#include<stdio.h>
#include<stdlib.h>
struct Book
{
    char title[10];
    char author[20];
    struct Book *next;
};
void getInput(struct Book *book)
{
    printf("����������");
    scanf("%s",book->title);
    printf("�������ߣ�");
    scanf("%s",book->author);

}
void addBook(struct Book **library)
{
    struct Book *book,*temp;
    book = (struct Book*)malloc(sizeof(struct Book));
    if(book==NULL)
    {
        printf("�ڴ����ʧ�ܣ�");
        exit(1);
    }
    getInput(book);
    if(*library != NULL)
    {
        temp = *library;
        *library = book;
        book->next = temp;

    }
    else
    {
        *library = book;
        book->next = NULL;
    }
}
void Print(struct Book *library)
{
    struct Book *book;
    int count = 1;
    book = library;
    while(book != NULL)
    {
    printf("------Book%d------\n",count);
    printf("����:%s\n",book->title);
    printf("����:%s\n��",book->author);
    book = book->next;
    count++;
    }
}
void release(struct Book **library)
{
    struct Book *temp;
    while(*library != NULL)
    {
        temp = *library;
        *library = library.next;
        free(temp);

    }
}
int main(void)
{
    struct Book *library = NULL;
    int ch;
    while(1)
    {
        printf("�����Ƿ���Ҫ¼���鼮��Ϣ(Y/N)");
        do
        {
            ch = getchar();
        }while(ch !='Y'&&ch!='N');
        if(ch=='Y')
        {
            addBook(&library);
        }
        else
        {
            break;
        }
    }
    printf("�����Ƿ���Ҫ��ӡͼ����Ϣ(Y/N):");
    do
        {
            ch = getchar();
        }while(ch !='Y'&&ch!='N');
        if(ch=='Y')
        {
            Print(library);
        }
        release(&library);
    return 0;
}*/

/*
#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
    int data;
    struct link *next;
}Link;
Link *Appendnode(Link *head);
void Displaynode(Link *head);
void release(Link *head);
int main(void)
{
    int i=0;
    char c;
    Link *head = NULL;
    printf("Do you want to append a new node?(Y/N):");
    scanf("%c",&c);
    while(c=='Y'||c=='y')
    {
        head = Appendnode(head);
        Displaynode(head);
        printf("Do you want to append a new node?(Y/N):");
        scanf(" %c",&c);
        i++;
    }
    printf("%d new node have been appended.",i);
    release(head);

    return 0;
}

Link *Appendnode(Link *head)
{
    Link *p=NULL,*pr = head;
    int data;
    p = (Link *)malloc(sizeof(Link));
    if(p == NULL)
    {
        printf("no enough memory\n");
        exit(0);
    }
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        while(pr->next!=NULL)
        {
            pr = pr->next;
        }
        pr->next = p;
    }
    printf("input node data:");
    scanf("%d",&data);
    p->data = data;
    p->next = NULL;
    return head;
}
void Displaynode(Link *head)
{
    Link *p = head;
    int j = 1;
    while(p != NULL)
    {
        printf("%5d%10d\n",j,p->data);
        p=p->next;
        j++;
    }
}
void release(Link *head)
{
    Link *p = head,*pr = NULL;
    while(p != NULL)
    {
        pr = p;
        p=p->next;
        free(pr);
    }
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
typedef struct stu
{
	char ID[12];//ѧ��
	char name[20];//����
	int c1;//���ĳɼ�
	int c2;//��ѧ�ɼ�
	int c3;//Ӣ��ɼ�
	struct stu * next;
}STU;
STU *Append(STU *head);
void DisLink(STU *head);
void release(STU *head);
int main(void)
{
    int i,n;
    printf("1  ��������\n");
    printf("2  �˳�\n");
    scanf("%d",&n);
    if(n==1)
    {

    }
    if(n==2)
    {

    }
    return 0;
}

STU *Append(STU *head)
{
    STU *p = NULL,*pr = head;
    p = (STU *)malloc(sizeof(STU));
    if(p == NULL)
    {
        printf("error!\n");
        exit(0);
    }
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        while(pr->next!=NULL)
        {
            pr=pr->next;
        }
        pr->next = p;
    }
    printf("������ѧ�ţ�");
    scanf("%s",p->ID);
    printf("���������֣�");
    scanf("%s",p->name);
    printf("�������������ģ���ѧ������ɼ���");
    scanf("%d%d%d",p->c1,p->c2,p->c3);
    p->next = NULL;
    return head;
}
void DisLink(STU *head)
{
    STU *p = head;

    while(p != NULL)
    {
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n",p->ID,p->name,p->c1,p->c2,p->c3,(p->c1+p->c2+p->c3));
        p=p->next;

    }
}
void release(STU *head)
{
    STU *p = head,*pr = NULL;
    while(p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

struct stu
{
    char ID[12];
    char name[20];
    int c1;
    int c2;
    int c3;
    struct stu * next;
}		  	   ;

struct stu * Append(struct stu *);//����
struct stu * Start();//��ʼ��ֵ
void DisLink(struct stu *);//��ʾ
void Sort(struct stu *);//����
void DeleteMemory(struct stu *);//�ͷ�



struct stu * Start( )
{
    struct stu * head = NULL;
    int flag = 1, a;

    while (flag)
    {
        printf("1  ��������\n");//1
        printf("2  �˳�\n");//1
        printf("ѡ��");
        scanf(" %d", &a);//1
        switch (a)
        {
        case 1:
            head = Append(head);//1
            break;
        case 2:
            flag = 0;
            break;
        default:
            printf("��������Чѡ��\n");//1
        }
    }
    return head;
}
void DisLink( struct stu * head )
{
    struct stu * p = head;
    int j = 1;
    printf("���\tѧ��\t���� \t����\t��ѧ\t����\t�ܷ�\n");
    while (p != NULL)//1
    {
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n", j, p->ID, p->name, p->c1, p->c2, p->c3, p->c1 + p->c2 + p->c3);//1
        p = p->next;//1
        j++;
    }
}

struct stu * Append (struct stu * head)
{
    struct stu *p = NULL;
    struct stu *pr = head;
    p = (struct stu *)malloc(sizeof(struct stu));//1
    if (p == NULL)//1
    {
        printf("No enough memory to alloc");
        exit(0);
    }
    if (head == NULL)//1
    {
        head = p;//1
    }
    else
    {
        while (pr->next != NULL)//1
        {
            pr = pr->next;//1
        }
        pr->next = p;//1
    }
    pr = p;
    printf("������ѧ�ţ�");
    scanf(" %s", &pr->ID);//1
    printf("���������֣�");
    scanf(" %s", &pr->name);//1
    printf("�������������ģ���ѧ������ɼ���");
    scanf(" %d%d%d", &pr->c1, &pr->c2, &pr->c3);//1
    pr->next = NULL;
    return head;
}

void Sort(struct stu * head)
{
    struct stu *pr = head, *p = head, temp1;
    int i = 1, j, k;
    while (p->next != NULL)//1
    {
        p = p->next;//1
        i++;
    }
    p = head;
    for (j = 1; j<i; j++)//1
    {
        p = p->next;//1
        for (k = 0; k<(i - j); k++)//1
        {
            if ((pr->c1 + pr->c2 + pr->c3) <(p->c1 + p->c2 + p->c3) )//1
            {
                temp1 = *pr;//1
                temp1.next = p->next;//1
                *pr = *p;//1
                *p = temp1;//1
                pr->next = p;//1
            }
            p = p->next;
            pr = pr->next;
        }
        p = head;
        pr = head;
    }
}

void DeleteMemory(struct stu * head)
{
    struct stu *p = head, *pr = NULL;
    while (p != NULL)//1
    {
        pr = p;//1
        p = p->next;//1
        free(pr);//1
    }
}

int main()
{
    struct stu * head = NULL;//1
    head = Start();
    DisLink(head);

    printf("�����\n");
    Sort(head);
    DisLink(head);

    DeleteMemory(head);

    return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#define N 100
struct student{
    int ID;          //ѧ��ѧ��
    char name[20];     //ѧ������
    float score;          //���Գɼ�
    struct student * pNextNode;
};

int main(void)
{
    int i,n;
    struct student Stu[N];
    printf("������ѧ��������\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("�������%d��ѧ����ID�������ͳɼ�:",i+1);
        scanf("%d %s %f",&Stu[i].ID,&Stu[i].name,&Stu[i].score);
    }
    printf("����ѧ���ĳɼ���\n");
    for(i=0;i<n;i++)
    {
        printf(" %-5d  %-8s  %-4.2f\n",Stu[i].ID,Stu[i].name,Stu[i].score);
    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++
        {
         if(Stu[i].score>Stu[j].score)

        }

    }

    return 0;
}
*/

//
//#include <stdio.h>
//#include <stdlib.h>
//#define N 6
//struct LNode
//{
//    int data;
//    struct LNode *next;
//}                        ;
//
//struct LNode* create_rear(int a[], int n);
//void output(struct LNode *h);
//
//int main(int argc, char *argv[])
//{
//    int a[N], i;
//    struct LNode* head;
//    /*����������Ԫ�ص�ֵ*/
//    printf("��������%d��Ԫ�ص�ֵ��\n", N);
//    for (i = 0; i < N; i++)
//        scanf("%d", &a[i]);
//
//    /*�۴�������head,�����ֵ����Ϊ����aԪ�ص�ֵ*/
//    head = create_rear(a, N);
//    /*���������head*/
//    printf("�������������������Ϊ��");
//    output(head);
//
//    return 0;
//}
//
//struct LNode* create_rear(int a[], int n)
//{
//    /*�½�һ������h��ÿ��������β��뵽��β���������ͷָ�뷵�� */
//    struct LNode *h = NULL;
//    struct LNode *s, *r; /*��sָ��Ҫ�����㣬rָ�������β���*/
//    int i;
//
//    for (i = 0; i < n; i++)
//    {
//        s = (struct LNode *)malloc(sizeof(struct LNode));
//        s->data = a[i];
//        s->next = NULL;
//        if (h == NULL)
//            h = s;       /*�������Ϊ�գ���ͷָ��hָ��s */
//        else
//            r->next = s; /*����s���ӵ�β���r֮��     */
//        r = s;           /*��rָ��β���               */
//    }
//    return h;  /*���������ͷָ��*/
//}
//
//void output(struct LNode *h)
//{
//    /*������h�ĸ����������������������������������*/
//    struct LNode *p = h;/*�ӵ�һ����㿪ʼ����p����ָ��������*/
//    while (p)
//    {
//        /*ֻҪp��һ���ǿս�㣬�������������Ȼ��p����*/
//        printf("%d ", p->data);
//        p = p->next;  //��p����
//    }
//
//
//}
