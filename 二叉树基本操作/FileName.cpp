#include<bits/stdc++.h>
using namespace std;
typedef int BTDataType;// 自定义数据类型
typedef struct BinaryTreeNode
{
    BTDataType data;
     BinaryTreeNode *left;
     BinaryTreeNode *right;// 左子树，右子树
} BTNode, *BinaryTree;//BTNode为节点类型，BinaryTree为二叉树类型

//初始化二叉树
void InitBinaryTree(BinaryTree &T) {
    T=NULL;
}
//创建新节点
BinaryTree NewNode(BTDataType data) {
    BinaryTree p=new BTNode;// 分配内存
    if (p==NULL) {// 内存分配失败
        cerr<<"error"<<endl;
        exit(-1);
    }
    p->data=data;
    p->left=p->right=NULL;
    return p;// 返回新节点的地址
}
//插入节点
void InsertNode(BinaryTree& root,BTDataType data) {
    if (root==NULL) {// 空树
    root=NewNode(data);
    return;
    }
    if(root->data>data)
        InsertNode(root->left,data);// 递归插入左子树
    else
        InsertNode(root->right,data);// 递归插入右子树
}
//前序遍历，顺序为根左右
void PreOrder(BinaryTree root) {
    if (root==NULL) {// 空树
        return;
    }
    printf("%d->",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
//中序遍历,顺序为左根右
void InOrder(BinaryTree root) {
    if (root == NULL) {// 空树
        return;
    }
        InOrder(root->left);
printf("%d->", root->data);
    InOrder(root->right);

}
//后序遍历
void PostOrder(BinaryTree root) {
    if (root == NULL) {// 空树
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d->", root->data);
}
//层序遍历
void LevelOrder(BinaryTree root) {
    queue<BinaryTree> q;
    q.push(root);
    printf("层序遍历结果为");
    while (!q.empty()) {
        BTNode* front = q.front();
        printf("%d->", front->data);
        q.pop();
        if (front->left != NULL) 
            q.push(front->left);
        if (front->right != NULL) 
            q.push(front->right);
    }
    //销毁队列
}
//二叉树节点个数:递归求解，一个节点有效时，返回1，之后递归判断该节点的左右孩子是否有效......最后将这些“1”相加即可
int BTSize(BinaryTree root) {
    if (root == NULL){//空树
    return 0;
    }
    else return 1 + BTSize(root->left)+BTSize(root->right);
}
//叶子节点个数
int BTLeafSize(BinaryTree root) {
    if (root == NULL) {// 空树
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return BTLeafSize(root->left) + BTLeafSize(root->right);
}
//第K层节点个数:在使用递归时，每次遍历下一层（左右孩子）并传入k-1这个值，当k值为1时，再做统计，就实现了统计第k层节点的功能
int BTLevelKSize(BinaryTree root, int k) {
    if (root == NULL)//访问到空，返回0
    {
        return 0;
    }
    if (k == 1)//k值为1，做统计
    {
        return 1;
    }
    return BTLevelKSize(root->left, k - 1) + BTLevelKSize(root->right, k - 1);//递归访问左右孩子（下一层）
}
//二叉树高度:当访问了一个有效节点之后，说明层数至少为1。之后再去访问它的左子树和右子树是否有效
int BTDepth(BinaryTree root) {
    if (root == NULL) {// 空树
        return 0;
    }
    return max(BTDepth(root->left), BTDepth(root->right)) + 1;
}
//查找
BinaryTree BTFind(BinaryTree root, BTDataType n) {
    if (root == NULL) {// 空树直接返回
        cout<<"未找到"<<n<<endl;
        return NULL;
    }
    if (root->data == n) {// 找到就返回该节点
        cout<<"找到"<<n<<endl;
        return root;
    }
    if (root->data > n) {// 递归查找左子树
        return BTFind(root->left, n);
    }
    else {// 递归查找右子树
        return BTFind(root->right, n);
    }
}
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// ... existing code ...

bool BTComplete(BinaryTree root) {
    if (root == NULL) {// 空树
        cout << "是完全二叉树" << endl;
        return true;
    }
    queue<BinaryTree> q;
    q.push(root);
    while (!q.empty()) {
        BTNode* front = q.front();// 记录队头元素
        q.pop();// 队头出队
        if (front == NULL)
            break;
        q.push(front->left);
        q.push(front->right);
    }
    //此时，再次循环读取队头数据，若读取到非空节点，说明不是完全二叉树

    while (!q.empty())
    {
        BTNode* front = q.front();//记录队头
        q.pop();//队头出队
        if (front != NULL)// 若读取到非空节点，说明不是完全二叉树
        {
            cout << "不是完全二叉树" << endl;
            return false;
        }
    }
    cout<< "是完全二叉树" << endl;
    return true;
}
//销毁二叉树
void BTDestroy(BinaryTree& root) {
        if (root == NULL) {
            return; // 如果节点为空，直接返回
        }
       BTDestroy(root->left);  // 递归销毁左子树
        BTDestroy(root->right); // 递归销毁右子树
        delete root;              // 释放当前节点的内存
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
    printf("前序遍历结果为");
    PreOrder(bt);
    printf("\n");
    printf("中序遍历结果为");
    InOrder(bt);
    printf("\n");
    printf("后序遍历结果为");
    PostOrder(bt);
    printf("\n");
    LevelOrder(bt);
    printf("\n");
    cout << "该二叉树的节点个数为" << BTSize(bt) << endl;
    cout << "该二叉树的叶子节点个数为" << BTLeafSize(bt) << endl;
    cout << "第2层节点个数为" << BTLevelKSize(bt, 2) << endl;
    cout << "第3层节点个数为" << BTLevelKSize(bt, 3) << endl;
    cout << "第4层节点个数为" << BTLevelKSize(bt, 4) << endl;
    cout << "该二叉树的高度为" << BTDepth(bt) << endl;
    BTFind(bt, 2);
    BTComplete(bt);
    BTDestroy(bt);
    return 0;
}