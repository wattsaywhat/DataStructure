#include<bits/stdc++.h>
using namespace std;
typedef int BTDataType;// �Զ�����������
typedef struct BinaryTreeNode
{
    BTDataType data;
     BinaryTreeNode *left;
     BinaryTreeNode *right;// ��������������
} BTNode, *BinaryTree;//BTNodeΪ�ڵ����ͣ�BinaryTreeΪ����������

//��ʼ��������
void InitBinaryTree(BinaryTree &T) {
    T=NULL;
}
//�����½ڵ�
BinaryTree NewNode(BTDataType data) {
    BinaryTree p=new BTNode;// �����ڴ�
    if (p==NULL) {// �ڴ����ʧ��
        cerr<<"error"<<endl;
        exit(-1);
    }
    p->data=data;
    p->left=p->right=NULL;
    return p;// �����½ڵ�ĵ�ַ
}
//����ڵ�
void InsertNode(BinaryTree& root,BTDataType data) {
    if (root==NULL) {// ����
    root=NewNode(data);
    return;
    }
    if(root->data>data)
        InsertNode(root->left,data);// �ݹ����������
    else
        InsertNode(root->right,data);// �ݹ����������
}
//ǰ�������˳��Ϊ������
void PreOrder(BinaryTree root) {
    if (root==NULL) {// ����
        return;
    }
    printf("%d->",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
//�������,˳��Ϊ�����
void InOrder(BinaryTree root) {
    if (root == NULL) {// ����
        return;
    }
        InOrder(root->left);
printf("%d->", root->data);
    InOrder(root->right);

}
//�������
void PostOrder(BinaryTree root) {
    if (root == NULL) {// ����
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d->", root->data);
}
//�������
void LevelOrder(BinaryTree root) {
    queue<BinaryTree> q;
    q.push(root);
    printf("����������Ϊ");
    while (!q.empty()) {
        BTNode* front = q.front();
        printf("%d->", front->data);
        q.pop();
        if (front->left != NULL) 
            q.push(front->left);
        if (front->right != NULL) 
            q.push(front->right);
    }
    //���ٶ���
}
//�������ڵ����:�ݹ���⣬һ���ڵ���Чʱ������1��֮��ݹ��жϸýڵ�����Һ����Ƿ���Ч......�����Щ��1����Ӽ���
int BTSize(BinaryTree root) {
    if (root == NULL){//����
    return 0;
    }
    else return 1 + BTSize(root->left)+BTSize(root->right);
}
//Ҷ�ӽڵ����
int BTLeafSize(BinaryTree root) {
    if (root == NULL) {// ����
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return BTLeafSize(root->left) + BTLeafSize(root->right);
}
//��K��ڵ����:��ʹ�õݹ�ʱ��ÿ�α�����һ�㣨���Һ��ӣ�������k-1���ֵ����kֵΪ1ʱ������ͳ�ƣ���ʵ����ͳ�Ƶ�k��ڵ�Ĺ���
int BTLevelKSize(BinaryTree root, int k) {
    if (root == NULL)//���ʵ��գ�����0
    {
        return 0;
    }
    if (k == 1)//kֵΪ1����ͳ��
    {
        return 1;
    }
    return BTLevelKSize(root->left, k - 1) + BTLevelKSize(root->right, k - 1);//�ݹ�������Һ��ӣ���һ�㣩
}
//�������߶�:��������һ����Ч�ڵ�֮��˵����������Ϊ1��֮����ȥ�����������������������Ƿ���Ч
int BTDepth(BinaryTree root) {
    if (root == NULL) {// ����
        return 0;
    }
    return max(BTDepth(root->left), BTDepth(root->right)) + 1;
}
//����
BinaryTree BTFind(BinaryTree root, BTDataType n) {
    if (root == NULL) {// ����ֱ�ӷ���
        cout<<"δ�ҵ�"<<n<<endl;
        return NULL;
    }
    if (root->data == n) {// �ҵ��ͷ��ظýڵ�
        cout<<"�ҵ�"<<n<<endl;
        return root;
    }
    if (root->data > n) {// �ݹ����������
        return BTFind(root->left, n);
    }
    else {// �ݹ����������
        return BTFind(root->right, n);
    }
}
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// ... existing code ...

bool BTComplete(BinaryTree root) {
    if (root == NULL) {// ����
        cout << "����ȫ������" << endl;
        return true;
    }
    queue<BinaryTree> q;
    q.push(root);
    while (!q.empty()) {
        BTNode* front = q.front();// ��¼��ͷԪ��
        q.pop();// ��ͷ����
        if (front == NULL)
            break;
        q.push(front->left);
        q.push(front->right);
    }
    //��ʱ���ٴ�ѭ����ȡ��ͷ���ݣ�����ȡ���ǿսڵ㣬˵��������ȫ������

    while (!q.empty())
    {
        BTNode* front = q.front();//��¼��ͷ
        q.pop();//��ͷ����
        if (front != NULL)// ����ȡ���ǿսڵ㣬˵��������ȫ������
        {
            cout << "������ȫ������" << endl;
            return false;
        }
    }
    cout<< "����ȫ������" << endl;
    return true;
}
//���ٶ�����
void BTDestroy(BinaryTree& root) {
        if (root == NULL) {
            return; // ����ڵ�Ϊ�գ�ֱ�ӷ���
        }
       BTDestroy(root->left);  // �ݹ�����������
        BTDestroy(root->right); // �ݹ�����������
        delete root;              // �ͷŵ�ǰ�ڵ���ڴ�
    }
int main()
{
    BinaryTree bt;
    InitBinaryTree(bt);
    InsertNode(bt, 1);
    InsertNode(bt, 4);
    InsertNode(bt, 0);
    InsertNode(bt, -1);
    InsertNode(bt, 5);
    printf("ǰ��������Ϊ");
    PreOrder(bt);
    printf("\n");
    printf("����������Ϊ");
    InOrder(bt);
    printf("\n");
    printf("����������Ϊ");
    PostOrder(bt);
    printf("\n");
    LevelOrder(bt);
    printf("\n");
    cout << "�ö������Ľڵ����Ϊ" << BTSize(bt) << endl;
    cout << "�ö�������Ҷ�ӽڵ����Ϊ" << BTLeafSize(bt) << endl;
    cout << "��2��ڵ����Ϊ" << BTLevelKSize(bt, 2) << endl;
    cout << "��3��ڵ����Ϊ" << BTLevelKSize(bt, 3) << endl;
    cout << "��4��ڵ����Ϊ" << BTLevelKSize(bt, 4) << endl;
    cout << "�ö������ĸ߶�Ϊ" << BTDepth(bt) << endl;
    BTFind(bt, 2);
    BTComplete(bt);
    BTDestroy(bt);
    return 0;
}