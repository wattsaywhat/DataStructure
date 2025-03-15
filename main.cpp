#include<bits/stdc++.h>
using namespace std;
//单链表定义
typedef struct LNode {
	int data;
	LNode* next;
}LNode, * linklist;//linklist 是 LNode* 的别名， LNode *强调这是一个结点，LinkList强调这是个单链表

//初始化链表
bool InitList(linklist& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) return false;//创建失败
	l->next = NULL;
	return true;
}
//清空链表
void Empty(linklist& l) {
	l->next = NULL;
}
//打印链表
void PrintList(linklist l) {
	while (l->next != NULL) {
		printf("%d->", l->next->data);
		l = l->next;
	}
	printf("NULL\n");
}
//求表长
int Length(linklist l) {
	int len = 0;
	LNode* p = l;//将指针变量 p 指向链表头节点 l
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	cout<<"链表长度为："<<len<<endl;
	return len;
}
//按位查找
void FindLocate(linklist l, int i) {
	int j = 0;
	LNode* p = l;
	while (p->next != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (j == i) {
		cout << "第" << i << "个结点值为：" << p->data << endl;//输出查找到的结点的值
	}
	else {
		cout << "查找失败" << endl;
	}
}
//按值查找
void FindValue(linklist l, int e) {
	LNode* p = l;
	int count = 0;
	while (p->next != NULL) {
		count++;
		if (p->next->data == e) {
			cout << "该值在第" << count << "个结点" << endl;
			return;
		}
		p = p->next;
	}
	cout << "该值不存在" << endl;
}
//头插法,形成的链表为倒序
bool InsertFront(linklist& l, int e) {
	if (l == NULL) return false;//链表为空
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) return false;//申请结点失败
	p->data = e;
	p->next = l->next;//将新结点插入到头结点之后
	l->next = p;//头结点的next指向新结点
	return true;
}
//尾插法，形成的链表为正序
bool InsertRear(linklist& l, int e) {
	if (l == NULL) return false; // 链表为空
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) return false; // 申请结点失败
	p->data = e;
	p->next = NULL; // 新结点的next指向NULL

	LNode* tail = l;
	while (tail->next != NULL) {
		tail = tail->next; // 找到链表的尾结点
	}
	tail->next = p; // 尾结点的next指向新结点
	return true;
}
//删除指定位置的结点，并输出被删除的结点的值
bool DeleteNode(LNode* l, int i) {
	int k = i;
	if (i < 1 || i > Length(l))
		return false; // 判断i是否合法
	LNode* p = l;
	while (--i) {
		p = p->next;
	}
	LNode* q = p->next;
	cout << "删除第" << k << "节点成功，删除为" << q->data << endl;
	p->next = q->next;
	free(q);
	return true;
}
int main() {
	linklist l;
	InitList(l);
	InsertFront(l, 4);
	InsertFront(l, 5);
	InsertRear(l, 6);
	PrintList(l);
	DeleteNode(l, 2);
	FindLocate(l, 2);
	PrintList(l);
	FindValue(l, 6);
	Length(l);
	return 0;
}