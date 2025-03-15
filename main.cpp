#include<bits/stdc++.h>
using namespace std;
//��������
typedef struct LNode {
	int data;
	LNode* next;
}LNode, * linklist;//linklist �� LNode* �ı����� LNode *ǿ������һ����㣬LinkListǿ�����Ǹ�������

//��ʼ������
bool InitList(linklist& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) return false;//����ʧ��
	l->next = NULL;
	return true;
}
//�������
void Empty(linklist& l) {
	l->next = NULL;
}
//��ӡ����
void PrintList(linklist l) {
	while (l->next != NULL) {
		printf("%d->", l->next->data);
		l = l->next;
	}
	printf("NULL\n");
}
//���
int Length(linklist l) {
	int len = 0;
	LNode* p = l;//��ָ����� p ָ������ͷ�ڵ� l
	while (p->next != NULL) {
		p = p->next;
		len++;
	}
	cout<<"������Ϊ��"<<len<<endl;
	return len;
}
//��λ����
void FindLocate(linklist l, int i) {
	int j = 0;
	LNode* p = l;
	while (p->next != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (j == i) {
		cout << "��" << i << "�����ֵΪ��" << p->data << endl;//������ҵ��Ľ���ֵ
	}
	else {
		cout << "����ʧ��" << endl;
	}
}
//��ֵ����
void FindValue(linklist l, int e) {
	LNode* p = l;
	int count = 0;
	while (p->next != NULL) {
		count++;
		if (p->next->data == e) {
			cout << "��ֵ�ڵ�" << count << "�����" << endl;
			return;
		}
		p = p->next;
	}
	cout << "��ֵ������" << endl;
}
//ͷ�巨,�γɵ�����Ϊ����
bool InsertFront(linklist& l, int e) {
	if (l == NULL) return false;//����Ϊ��
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) return false;//������ʧ��
	p->data = e;
	p->next = l->next;//���½����뵽ͷ���֮��
	l->next = p;//ͷ����nextָ���½��
	return true;
}
//β�巨���γɵ�����Ϊ����
bool InsertRear(linklist& l, int e) {
	if (l == NULL) return false; // ����Ϊ��
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) return false; // ������ʧ��
	p->data = e;
	p->next = NULL; // �½���nextָ��NULL

	LNode* tail = l;
	while (tail->next != NULL) {
		tail = tail->next; // �ҵ������β���
	}
	tail->next = p; // β����nextָ���½��
	return true;
}
//ɾ��ָ��λ�õĽ�㣬�������ɾ���Ľ���ֵ
bool DeleteNode(LNode* l, int i) {
	int k = i;
	if (i < 1 || i > Length(l))
		return false; // �ж�i�Ƿ�Ϸ�
	LNode* p = l;
	while (--i) {
		p = p->next;
	}
	LNode* q = p->next;
	cout << "ɾ����" << k << "�ڵ�ɹ���ɾ��Ϊ" << q->data << endl;
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