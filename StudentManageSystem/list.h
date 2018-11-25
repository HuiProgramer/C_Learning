/*list.h -- ���������͵�ͷ�ļ� */
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h> /* c99����	*/

/* �ض���������� */

#define TSIZE   20 /* ����ѧ�����ֵ������С */
 
struct student
{
	char name[TSIZE];
	int id;
	int math;
	int politics;
	int english;
	int computer;
	int c;
};

/* һ�����Ͷ��� */

typedef struct student Item;

typedef struct node
{
	Item item;
	struct node * next;
}Node;

typedef Node * List;


extern List pstudent;//����ָ�� 

extern char a[6][51];//���������� 

extern unsigned int count;//ѧ������ 

extern char * s_gets(char *st,int n);//���� 

extern Item temp;//�ṹ�����
 
extern char data[45];//���ļ��� 

extern int decide;//�����жϿ� 

/* ����ԭ�� */

/*
  ������  ��ʼ��һ������
  ǰ��������plistָ��һ������
  ���������������ʼ��Ϊ��                                             
*/
void InitializeList(List * plist);

/*չʾѧ����Ϣ*/ 
void showstudent(Item item);

/*��������������ʾ���г�Ա��Ϣ*/ 
void loopshow(void);

/*�û�����*/ 
void UI(void);

/*ѧ����Ϣ������*/ 
void inputstudent(void);

/*���ļ�*/ 
void file(void);

/*ɾ���ڵ�*/ 
void delete(void);

/*�޸Ľڵ����Ϣ*/ 
void revision(void);

/*�����ڵ���Ϣ*/ 
void searchstudent(void);

/* 
  ������ ȷ�������Ƿ�Ϊ�ն��壬plistָ��һ���ѳ�ʼ��������
  �����������������Ϊ�գ��ú�������true�����򷵻�false
*/

bool ListIsEmpty(const List *plist);

/*
  ������ȷ�������Ƿ�������plistָ��һ���ѳ�ʼ������
  ������������������������ú�������Ϊ�棬���򷵻ؼ�
*/

bool ListIsFull(const List *plist);

/*
  ������ȷ�������е�������plistָ��һ���ѳ�ʼ��������
  �����������ú������������е�����
*/

unsigned int ListIsemCount(const List *plist);

/*
  �������������ĩ�������
  ǰ��������item��һ���������������plistָ��һ���ѳ�ʼ��������
  ����������������ԣ��ú���������ĩ�����һ����ҷ���true�����򷵻�false
*/

bool AddItem(Item item, List * plist);

/*
  �������Ѻ��������������ÿһ��
        plistָ��һ���ѳ�ʼ��������
		pfunָ��һ���������ú�������һ��Item���͵Ĳ��������޷���ֵ
  ����������pfunָ��ĺ��������������ÿһ��һ��
*/
void Traverse(const List *plist,void(*pfun)(Item item));

/* 
  �������Ѻ�������������ÿһ��
        plistָ��һ���ѳ�ʼ��������
		����һ��Item���Ͳ���
  �����������ж�ѧ���Ƿ��ظ�; �ظ�����true�����򷵻�false 
*/
bool  idcompare(const List * plist,int ID); 
/* 
  �������Ѻ�������������ÿһ��
        plistָ��һ���ѳ�ʼ��������
		����һ��int���Ͳ���
  �����������ж�ѧ���Ƿ��ظ�; �ظ���ɾ����ѧ�ŵ�������Ϣ 
*/
Node * deleteofid(List * plist,int ID); 
/*
  �������Ѻ�������������ÿһ��
        plistָ��һ���ѳ�ʼ��������
		����һ�� �ַ���
  �����������ж������Ƿ�һ����һ����ɾ����ѧ��������Ϣ 
*/
Node * deleteofname(List *plist,char *n); 
/* 
  �������Ѻ�������������ÿһ��
        plistָ��һ���ѳ�ʼ��������
		����һ��int���Ͳ���
  �����������ж�ѧ���Ƿ��ظ�; �ظ����޸ĸ�ѧ�ŵ���Ϣ 
*/
Node * revisionofid(List * plist,int ID);
/*
  �������Ѻ�������������ÿһ��
        plistָ��һ���ѳ�ʼ��������
		����һ�� �ַ���
  �����������ж������Ƿ�һ����һ�����޸ĸ�ѧ����Ϣ 
*/
Node * revisionofname(List * plist,char *NAME);
/* 
  �������Ѻ��������������ÿһ��
  		plistָ��һ���ѳ�ʼ��������
		  ����һ��int���͵Ĳ��� 
  �����������ж�ѧ���Ƿ��ظ����ظ�����ʾ��ѧ��������Ϣ 
*/
void searchofid(const List * plist,int ID);
/*
  �������Ѻ���������ÿһ��
  		plistָ��һ���ѳ�ʼ��������
		NAME����һ���ַ���
		pfunָ��һ���������ú�������һ��Item���͵Ĳ��������޷���ֵ
  �����������ж������Ƿ�һ����һ������ʾ��ѧ��������Ϣ
*/
void searchofname(const List * plist,char *NAME,void(*pfun)(Item item));
/*
  �������Ѻ���������ÿһ��
     	plistָ��һ���ѳ�ʼ��������
		pfunָ��һ���������ú�������һ��Item���͵Ĳ��������޷���ֵ
  �������������ݸ��Ƴɼ���ѯѧ����Ϣ
 */
void searchofach(const List * plist,void(*pfun)(Item item)); 
/*  
  �������ͷ��ѷ�����ڴ棨����еĻ���
        plistָ��һ���ѳ�ʼ��������
  �����������ͷ���Ϊ�������������ڴ棬��������Ϊ��
*/

void EmptyTheList(List * plist);

#endif

											 
