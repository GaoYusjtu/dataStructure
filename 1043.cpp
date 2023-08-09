#include <iostream>
using namespace std;

template <class elemType>
class BTree;

template <class elemType>
class node{
    friend class BTree<elemType>;
private:
    elemType data;
    node *lf,*rh;
public:
    node(){
        lf=NULL;
        rh=NULL;
    }
    node(const elemType &e,node<elemType> *left=NULL,node<elemType> *right=NULL){
        data=e;
        lf=left;
        rh=right;
    }
};
template <class elemType>
class BTree{
private:
    node<elemType> *root;
    int size(node<elemType> *t);
    int height(node<elemType> *t);
    void delTree(node<elemType> *t);
    void judge(node<elemType>*p,int *a,int pos,bool &flag,int n);
public:
    BTree(){
        root=NULL;
    }
    ~BTree();
    void delTree();

    void creatTree(const elemType &flag);
    bool isEmpty();
    node<elemType>* getRoot(){
        return root;
    }
    int size();
    int height();

    void preOrder();
    void inOrder_1();
    void inOrder_2();
    void postOrder();
    void levelOrder();
    void buildTree(int n);
    void judge(int n);
};
template <class elemType>
BTree<elemType>::~BTree(){
    delTree();
}

template <class elemType>
int BTree<elemType>::size(){
    return(size(root));
}
template <class elemType>
int BTree<elemType>::size(node<elemType> *t){
    if(t==NULL)return 0;
    else return(1+size(t->lf)+size(t->rh));
}

template <class elemType>
int BTree<elemType>::height(node<elemType> *t){
    if(t==NULL)return 0;
    if(height(t->rh)>=height(t->lf))return (1+height(t->rh));
    else return(1+height(t->lf));
}
template <class elemType>
int BTree<elemType>::height(){
    return(height(root));
}

template <class elemType>
void BTree<elemType>::delTree(node<elemType> *t){
    if(t==NULL)return;
    else{
        delTree(t->lf);
        delTree(t->rh);
        delete t;
    }
}
template <class elemType>
void BTree<elemType>::delTree(){
    delTree(root);
}

template <class elemType>
bool BTree<elemType>::isEmpty(){
    return(root==NULL);
}

template<class elemType>
void BTree<elemType>::buildTree(int n){
    node<elemType> **p;
    p=new node<elemType>*[n];
    p[0]=new node<elemType>(0);
    root=p[0];
    for(int i=1;i<n;i++){
        int t;
        cin>>t;
        p[i]=new node<elemType>(0);
        if(p[t]->lf==NULL)p[t]->lf=p[i];
        else p[t]->rh=p[i];
    }
}
template<class elemType>
void BTree<elemType>::judge(int n){
    int *a;a=new int[n+1]{0};
    bool flag=true;
    judge(root,a,1,flag,n);
    if(flag) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == -1) {
                flag = false;
                break;
            }
        }
    }
    if(!flag)cout << "false" << endl;
    else cout<<"true"<<endl;
}
template<class elemType>
void BTree<elemType>::judge(node<elemType>*p,int *a,int pos,bool &flag,int n){
    if(p==NULL)a[pos]=-1;
    else a[pos]=p->data;
    if(p->lf!=NULL&&2*pos<=n) judge(p->lf,a,2*pos,flag,n);
    else if(p->lf!=NULL&&2*pos>n) {flag=false;}
    if(p->rh!=NULL&&2*pos+1<=n) judge(p->rh,a,2*pos+1,flag,n);
    else if(p->rh!=NULL&&2*pos+1<=n) {flag=false;}
}

int main () {
    BTree<int> tree;
    int n;
    cin>>n;
    tree.buildTree(n);
    tree.judge(n);
    return 0;
}
