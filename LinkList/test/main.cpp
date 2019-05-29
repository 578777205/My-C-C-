#include<iostream>
#include"linklist.h"
using namespace std;
int main()
{
	ElemType a[5] = { 1, 3, 5, 7, 9 };
	LinkNode* L1,*L2;
	ElemType n = 0;
	CreateListH(L1, a, 5);
	CreateListB(L2, a, 5);
	DispList(L1); DispList(L2);

	n = GetElem(L1, 3);
	cout <<"L1第3个元素值："<< n << endl;
	n = LocateElem(L1, 3);
	cout << "L1元素值为3的元素是第"<< n <<"个节点"<< endl;
	insertElem(L1, 4, 6);
	cout << "插入后L1的值:";
	DispList(L1);
	DelList(L1, 5);
	DispList(L1);
	DestroyList(L2);
	DestroyList(L1);
	return 0;
}