#include <iostream>
using namespace std;

template<class elemType>
class binarySearchTree;

template<class elemType>
class node{
    friend class binarySearchTree<elemType>;
private:
    elemType data;
    node *left,*right;
public:
    node(){
        left=NULL;right=NULL;
    }
    node(const elemType &x,node *l=NULL,node *r=NULL){
        data=x;left=l;right=r;
    }
};
template<class elemType>
class binarySearchTree{
private:
    node<elemType> *root;
    void search(const elemType &x,node<elemType> *t,string c,int i);
    void insert(const elemType &x,node<elemType> *&t);
    void remove(const elemType &x,node<elemType> *&t);
public:
    binarySearchTree(){root=NULL;}
    void search(const elemType &x);
    void insert(const elemType &x);
    void remove(const elemType &x);
    void search_nrc(const elemType &x);
};

template<class elemType>
void binarySearchTree<elemType>::search(const elemType &x,node<elemType> *t,string c,int i){
    if(!t) {
        cout<<"Nothing."<<endl;
        return;
    }
    if(x==t->data) {
        cout<<c<<endl;
        return;
    }
    else if(x<t->data) {
        c+='l';i++;
        search(x,t->left,c,i);
    }
    else {
        c+='r';i++;
        search(x,t->right,c,i);
    }
}
template<class elemType>
void binarySearchTree<elemType>::insert(const elemType &x,node<elemType> *&t){
    if(!t){
        t=new node<elemType>(x);
        return;
    }
    if(x==t->data)return;
    else if(x>t->data)insert(x,t->right);
    else insert(x,t->left);
}
template<class elemType>
void binarySearchTree<elemType>::remove(const elemType &x){
    if(!root)return;
    node<elemType> *p,*parent;
    int flag;
    p=root;parent=NULL;
    while(p){
        if(x<p->data){
            parent=p;p=p->left;
            flag=0;
            continue;
        }
        else if(x>p->data){
            parent=p;p=p->right;
            flag=1;
            continue;
        }//找到要删除的元素
        ////
//        if(!p->right&&!p->left){
//            delete p;//删除
//            if(!parent){
//                root=NULL;
//                return;
//            }
//            if(flag==0)parent->left=NULL;
//            else parent->right=NULL;//断开父子关系
//            return;
//        }//叶子节点
        if(!p->right){
            node<elemType> *tmp=p;
            if(!parent)root=p->left;
            else{
                if(flag==0)parent->left=p->left;
                else parent->right=p->left;
            }
            delete tmp;
            return;
        }
        node<elemType> *substitute, *q;
        parent = p;
        flag = 1;
        q = p->right;
        while (q->left) {
            parent = q;
            flag = 0;
            q = q->left;
        }
        substitute = q;
        p->data = substitute->data;
        if(flag==0)parent->left=substitute->right;
        else parent->right=substitute->right;

        return;
        //双子节点
    }
}

template<class elemType>
void binarySearchTree<elemType>::search(const elemType &x){
    int i=1;
    string c{'*'};
    search(x,root,c,i);
//    delete []c;
}
template<class elemType>
void binarySearchTree<elemType>::insert(const elemType &x){
    insert(x,root);
}

int main () {
    int n;
    cin>>n;
    char c;
    binarySearchTree<long long>a;long long x;
    for(int i=0;i<n;i++){
        cin>>c;cin>>x;
        switch(c){
            case '+':
                a.insert(x);
                break;
            case '-':
                a.remove (x);
                break;
            case '*':
                a.search (x);
                break;
        }
    }
    return 0;
}
