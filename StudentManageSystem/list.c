#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"list.h"
/* 局部函数原型 */
static void  CopyToNode(Item item,Node * pnode);
/*局部函数原型*/
static void  CopyToItem(Node * pn,Item * pi);

/* 接口函数 */
/*把链表设置为空 */
void InitializeList(List * plist)
{
	*plist = NULL;
}
/* 如果链表为空，返回true */
bool ListIsEmpty(const List *plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

/* 如果链表已满，返回true */
bool ListIsFull(const List * plist)
{
	Node * pt;
	bool full;

	pt = (Node *)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

/* 返回节点的数量 */
unsigned int ListItemCount(const List * plist)
{
	unsigned int  count = 0;
	Node * pnode = *plist;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;/*设置下一个节点*/
	}

	return count;

}

/*创建储存项的节点，并将其添加至由plist指向的链表末尾（较慢的实现）*/
bool AddItem(Item item,List *plist)
{
	Node * pnew;
	Node * scan = *plist;
	pnew = (Node *) malloc(sizeof(Node));
	if (pnew == NULL)
		return false;/* 失败时退出函数 */

	CopyToNode(item,pnew);
	pnew->next = NULL;
	if (scan == NULL) /*空链表，所以把*/
		*plist = pnew; /*pnew放在链表的开头*/
	else 
	{
		while(scan->next != NULL)
			scan =scan->next;  /*找到链表的末尾*/
		scan->next = pnew;     /*把pnew添加到链表的末尾*/
	}

	return true;

}

/*访问每个节点并执行pfun指向的函数*/
void Traverse(const List * plist,void(*pfun)(Item item))
{
	Node *pnode = *plist; /*设置链表的开始*/

	while(pnode != NULL)
	{
		(*pfun)(pnode->item); /*把函数应用于链表中的项 */
		pnode = pnode->next; /*前进到下一项*/
	}
}
bool idcompare(const List * plist,int ID)
{
	Node *pnode = *plist; /*设置链表的开始*/

	while(pnode != NULL)
	{
		if (pnode->item.id == ID)
			return true; /*把函数应用于链表中的项 */
		pnode = pnode->next; /*前进到下一项*/
	}
	return false;
}

/*释放由malloc（）分配的内存*/
/*设置链表指针为NULL*/
void EmptyTheList(List * plist)
{
	Node * psave;
	while (*plist != NULL)
	{
		psave = (*plist)->next;/*保存下一个节点的地址*/
		free(*plist);          /*释放当前节点*/
		*plist = psave;		   /*前进至下一个节点*/
	}
}
/*局部函数定义*/
/*把一个函数拷贝到节点中*/
static void CopyToNode(Item item,Node * pnode)
{
	pnode->item = item;  /*拷贝结构*/
}
/*局部函数定义*/
static void CopyToItem(Node * pn, Item * pi)
{
	*pi = pn->item;
}


