#ifndef _LINKLIST_H_
#define _LINKLIST_H_
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LinkNode;
void CreateListH(LinkNode*& L, ElemType *a, int n);	//头插法创建
void CreateListB(LinkNode*& L, ElemType *a, int n);	//尾插法创建
void DestroyList(LinkNode*& L);//销毁
bool Empty(LinkNode* L);//判空
int ListLength(LinkNode* L);//返回长度
void DispList(LinkNode* L);//输出链表
ElemType GetElem(LinkNode* L, int n);//求第n个节点的值
int LocateElem(LinkNode* L, ElemType n);//找到值为n的节点位置
bool insertElem(LinkNode*& L, int i, ElemType e);//在第i位前面插入元素
bool DelList(LinkNode*& L, int i);//删除第i位前的元素

#endif
#pragma once
