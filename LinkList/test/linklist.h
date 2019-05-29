#ifndef _LINKLIST_H_
#define _LINKLIST_H_
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LinkNode;
void CreateListH(LinkNode*& L, ElemType *a, int n);	//ͷ�巨����
void CreateListB(LinkNode*& L, ElemType *a, int n);	//β�巨����
void DestroyList(LinkNode*& L);//����
bool Empty(LinkNode* L);//�п�
int ListLength(LinkNode* L);//���س���
void DispList(LinkNode* L);//�������
ElemType GetElem(LinkNode* L, int n);//���n���ڵ��ֵ
int LocateElem(LinkNode* L, ElemType n);//�ҵ�ֵΪn�Ľڵ�λ��
bool insertElem(LinkNode*& L, int i, ElemType e);//�ڵ�iλǰ�����Ԫ��
bool DelList(LinkNode*& L, int i);//ɾ����iλǰ��Ԫ��

#endif
#pragma once
