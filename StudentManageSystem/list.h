/*list.h -- 简单链表类型的头文件 */
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h> /* c99特性	*/

/* 特定程序的声明 */

#define TSIZE   20 /* 储存学生名字的数组大小 */
 
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

/* 一般类型定义 */

typedef struct student Item;

typedef struct node
{
	Item item;
	struct node * next;
}Node;

typedef Node * List;


extern List pstudent;//链表指针 

extern char a[6][51];//主函数数组 

extern unsigned int count;//学生人数 

extern char * s_gets(char *st,int n);//输入 

extern Item temp;//结构体变量
 
extern char data[45];//打开文件名 

extern int decide;//弹窗判断框 

/* 函数原型 */

/*
  操作：  初始化一个链表
  前提条件：plist指向一个链表
  后置条件：链表初始化为空                                             
*/
void InitializeList(List * plist);

/*展示学生信息*/ 
void showstudent(Item item);

/*遍历整个链表显示所有成员信息*/ 
void loopshow(void);

/*用户界面*/ 
void UI(void);

/*学生信息的输入*/ 
void inputstudent(void);

/*打开文件*/ 
void file(void);

/*删除节点*/ 
void delete(void);

/*修改节点的信息*/ 
void revision(void);

/*搜索节点信息*/ 
void searchstudent(void);

/* 
  操作： 确定链表是否为空定义，plist指向一个已初始化的链表
  后置条件：如果链表为空，该函数返回true；否则返回false
*/

bool ListIsEmpty(const List *plist);

/*
  操作：确定链表是否已满，plist指向一个已初始化链表
  后置条件：如果链表已满，该函数返回为真，否则返回假
*/

bool ListIsFull(const List *plist);

/*
  操作：确定链表中的项数，plist指向一个已初始化的链表
  后置条件：该函数返回链表中的项数
*/

unsigned int ListIsemCount(const List *plist);

/*
  操作：在链表的末端添加项
  前提条件：item是一个待添加至链表的项，plist指向一个已初始化的链表
  后置条件：如果可以，该函数在链表末端添加一个项，且返回true；否则返回false
*/

bool AddItem(Item item, List * plist);

/*
  操作：把函数作用于链表的每一项
        plist指向一个已初始化的链表
		pfun指向一个函数，该函数接收一个Item类型的参数，且无返回值
  后置条件：pfun指向的函数作用于链表的每一项一次
*/
void Traverse(const List *plist,void(*pfun)(Item item));

/* 
  操作：把函数作用于链表每一项
        plist指向一个已初始化的链表
		接收一个Item类型参数
  后置条件：判断学号是否重复; 重复返回true；否则返回false 
*/
bool  idcompare(const List * plist,int ID); 
/* 
  操作：把函数作用于链表每一项
        plist指向一个已初始化的链表
		接收一个int类型参数
  后置条件：判断学号是否重复; 重复则删除该学号的所有信息 
*/
Node * deleteofid(List * plist,int ID); 
/*
  操作：把函数作用于链表每一项
        plist指向一个已初始化的链表
		接收一个 字符串
  后置条件：判断名字是否一样，一样则删除该学生所有信息 
*/
Node * deleteofname(List *plist,char *n); 
/* 
  操作：把函数作用于链表每一项
        plist指向一个已初始化的链表
		接收一个int类型参数
  后置条件：判断学号是否重复; 重复则修改该学号的信息 
*/
Node * revisionofid(List * plist,int ID);
/*
  操作：把函数作用于链表每一项
        plist指向一个已初始化的链表
		接收一个 字符串
  后置条件：判断名字是否一样，一样则修改该学生信息 
*/
Node * revisionofname(List * plist,char *NAME);
/* 
  操作：把函数作用于链表的每一项
  		plist指向一个已初始化的链表
		  接收一个int类型的参数 
  后置条件：判断学号是否重复；重复则显示该学生所有信息 
*/
void searchofid(const List * plist,int ID);
/*
  操作：把函数作用于每一项
  		plist指向一个已初始化的链表
		NAME接收一个字符串
		pfun指向一个函数，该函数接收一个Item类型的参数，且无返回值
  后置条件：判断名字是否一样；一样则显示该学生所有信息
*/
void searchofname(const List * plist,char *NAME,void(*pfun)(Item item));
/*
  操作：把函数作用于每一项
     	plist指向一个已初始化的链表
		pfun指向一个函数，该函数接收一个Item类型的参数，且无返回值
  后置条件：根据各科成绩查询学生信息
 */
void searchofach(const List * plist,void(*pfun)(Item item)); 
/*  
  操作：释放已分配的内存（如果有的话）
        plist指向一个已初始化的链表
  后置条件：释放了为链表分配的所有内存，链表设置为空
*/

void EmptyTheList(List * plist);

#endif

											 
