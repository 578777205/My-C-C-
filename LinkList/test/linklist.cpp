#include"linklist.h"
#include<iostream>
using namespace std;
void CreateListH(LinkNode*& L, ElemType *a, int n) {	//头插法创建
	LinkNode* s;
	L = new LinkNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = new LinkNode;
		s->next = L->next;
		s->data = a[i];
		L->next = s;
	}
}
void CreateListB(LinkNode*& L, ElemType *a, int n) {	//尾插法创建
	LinkNode* s,*r;
	L = new LinkNode;
	L->next = NULL;
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = new LinkNode;
		s->data = a[i];
		r->next = s;
		r=s;
	}
	r->next = NULL;
}

void DestroyList(LinkNode*& L) {	//销毁链表 
	LinkNode* p = L->next,*pre=L;
	while (p!=NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
bool Empty(LinkNode* L) {
	return(L->next == NULL);
}
int ListLength(LinkNode* L)
{
	int n = 0;
	LinkNode* p = L;
	while (p->next != NULL)
	{
		n++; p = p->next;
	}
	return n;
}
void DispList(LinkNode* L) {
	LinkNode* p = L->next;
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
ElemType GetElem(LinkNode* L, int n) {//查找第n个元素并返回值
	LinkNode* p = L;
	for (int i = 0; i < n; i++){
		if (Empty(p)) {
			cout << "未找到元素" << endl;
			return -1;
		}
		p = p->next;
	}
	return p->data;
}
int LocateElem(LinkNode* L, ElemType n) {
	LinkNode* p = L->next; int i = 1;
	while (p != NULL && p->data != n)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return i;
}
bool insertElem(LinkNode*& L, int i, ElemType e) {
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0)return false;
	while (j < i - 1 && p != NULL) {
		j++; p = p->next;
	}
	if (p == NULL)return false;
	else
	{
		s = new LinkNode;
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}
bool DelList(LinkNode*& L, int i)//删除第i个节点
{
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0)return false;
	while (j < i - 1 && p != NULL)
	{
		j++; p = p->next;
	}
	if (p == NULL)return false;
	else
	{
		s = p->next;
		if (s == NULL)return false;
		p->next = s->next;
		free(s);
		return true;
	}

}