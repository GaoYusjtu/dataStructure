#include <iostream>
using namespace std;
class outOfBound{};
class illegalSize{};
////
template<class elemType>
class seqQueue{
private:
    int maxSize;
    elemType *array;
    int Front,Rear;
    void doubleSpace();
    int len;
public:
    seqQueue(int iniSize=100);
    ~seqQueue();
    bool isFull();
    bool isEmpty();
    elemType front();
    void enQueue(const elemType &e);
    void deQueue();
};
template<class elemType>
seqQueue<elemType>::seqQueue(int iniSize){
    array=new elemType[iniSize];
    if(!array)throw illegalSize();
    maxSize=iniSize;
    Front=Rear=0;
    len=0;
}
template<class elemType>
seqQueue<elemType>::~seqQueue(){
    len=0;
    delete []array;
}
template<class elemType>
bool seqQueue<elemType>::isFull(){
    return ((Rear+1)%maxSize==Front);
}
template<class elemType>
bool seqQueue<elemType>::isEmpty(){
    return(Rear==Front);
}
template<class elemType>
void seqQueue<elemType>::enQueue(const elemType &e){
    if(isFull())doubleSpace();
    array[Rear]=e;
    len+=1;
    Rear=(Rear+1)%maxSize;
}
template<class elemType>
void seqQueue<elemType>::deQueue(){
    if(!isEmpty()){
        Front=(Front+1)%maxSize;
        len-=1;
    }
    else{
        throw outOfBound();
    }
}
template<class elemType>
void seqQueue<elemType>::doubleSpace(){
    elemType *newArray;
    newArray=new elemType[2*maxSize];
    int i,j;
    if(!newArray)throw illegalSize();
    for(i=0,j=Front;j!=Rear;i++,j=(j+1)%maxSize){
        newArray[i]=array[j];
    }
    delete []array;
    Front=0;
    Rear=i;
    array=newArray;
    maxSize=2*maxSize;
}
template<class elemType>
elemType seqQueue<elemType>::front(){
    return array[Front];
}

////
template<class elemType>
class seqStack{
private:
    elemType *array;
    int Top;
    int maxsize;
    void doubleSpace();
public:
    seqStack(int iniSize=100);
    ~seqStack();

    bool isFull();
    bool isEmpty();

    void pop();
    elemType top();
    void push(const elemType &e);
};

template<class elemType>
void seqStack<elemType>::doubleSpace(){
    elemType *newArray;
    newArray=new elemType[2*maxsize];
    if(!newArray) throw outOfBound();
    for(int i=0;i<=Top;i++){
        newArray[i]=array[i];
    }
    delete []array;
    array=newArray;
}

template<class elemType>
seqStack<elemType>::seqStack(int iniSize){
    array=new elemType[iniSize];
    if(!array)throw illegalSize();
    maxsize=iniSize;
    Top=-1;

}
template<class elemType>
seqStack<elemType>::~seqStack(){
    delete []array;
    Top=-1;
}
template<class elemType>
bool seqStack<elemType>::isFull(){
    if(Top==maxsize-1) return true;
    else return false;
}
template<class elemType>
bool seqStack<elemType>::isEmpty(){
    if(Top==-1)return true;
    else return false;
}
template<class elemType>
void seqStack<elemType>::pop(){
    if(Top==-1) throw outOfBound();
    else {
        array[Top] = 0;
        Top -= 1;
    }
}
template<class elemType>
elemType seqStack<elemType>::top(){
    if(Top==-1)throw outOfBound();
    return array[Top];
}
template<class elemType>
void seqStack<elemType>::push(const elemType &e){
    if(isFull())doubleSpace();
    Top+=1;
    array[Top]=e;
}
////
//BTree类的前向说明
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
public:
    BTree(){
        root=NULL;
    }
    ~BTree();
    void delTree();

    void creatTree();
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

//template <class elemType>
//void BTree<elemType>::creatTree(const elemType &flag){
//    seqQueue<node<elemType>*> que;
//    elemType e,el,er;
//    node<elemType> *p,*pl,*pr;
//    cin>>e;
//    if(e==flag)return;
//    p=new node<elemType>(e);
//    root=p;
//    que.enQueue (p);
//    while(!que.isEmpty()){
//        p=que.front();
//        que.deQueue();
//        cin>>el>>er;
//        if(el!=flag){
//            pl=new node<elemType>(el);
//            p->lf=pl;
//            que.enQueue (pl);
//        }
//        if(er!=flag){
//            pr=new node<elemType>;
//            p->rh=pr;
//            que.enQueue (pr);
//        }
//    }
//}

template <class elemType>
void BTree<elemType>::preOrder(){
    if(!root)return;
    node<elemType>*p;
    seqStack<node<elemType>*>s;
    s.push(root);
    while(!s.isEmpty()){
        p=s.top();
        cout<<p->data<<" ";
        s.pop();
        if(p->rh)s.push(p->rh);
        if(p->lf)s.push(p->lf);
    }
    cout<<endl;
}

template <class elemType>
void BTree<elemType>::inOrder_1(){
    if (!root) return;
    seqStack<node<elemType> *> s;
    s.push(root);
    node<elemType> *p;
    p=root;
    while(p->left) {
        s.push(p->left);
        p=p->left;
    }
    while(!s.isEmpty()){
        p=s.top();
        s.pop();
        cout<<p->data;
        if ( p->right)  {
            s.push(p->right);
            p=p->right;
            while(p->left) {
                s.push(p->left);
                p=p->left;
            }
        }
    }

}

template <class elemType>
void BTree<elemType>::inOrder_2(){
    if(!root)return;
    seqStack<node<elemType>*>s1;
    seqStack<int>s2;
    node<elemType>*p;
    int q;
    s1.push(root);s2.push (0);
    while(!s1.isEmpty()){
        p=s1.pop();
        q=s2.top();
        s1.pop();
        s2.pop();
        if(q==0){s1.push (p);s2.push (1);}
        if(p->rh){s1.push(p->rh);s2.push (0);}
        if(p->lf){s1.push (p->lf);s2.push(0);}
    }
}

template <class elemType>
void BTree<elemType>::postOrder(){
    if (!root) return;
    node<elemType> *p;
    seqStack<node<elemType> *> s1;
    seqStack<int> s2;
    int zero=0, one=1, two=2;
    int flag;
    s1.push(root);
    s2.push(zero);
    while (!s1.isEmpty())
    {
        flag = s2.top(); s2.pop();
        p = s1.top();
        switch(flag){
            case 2:
                s1.pop();
                cout << p->data<<" ";
                break;
            case 1:
                s2.push(two);
                if (p->rh){
                    s1.push(p->rh);
                    s2.push(zero);
                }
                break;
            case 0:
                s2.push(one);
                if (p->lf){
                    s1.push(p->lf);
                    s2.push(zero);
                }
                break;
        }//switch
    }//while
}

template <class elemType>
void BTree<elemType>::levelOrder(){
    seqQueue<node<elemType>*> que;
    node<elemType> *p;
    if(!root)return;
    que.enQueue (root);
    while(!que.isEmpty()){
        p=que.front();
        cout<<p->data<<" ";
        que.deQueue();
        if(p->lf){
            que.enQueue (p->lf);
        }
        if(p->rh){
            que.enQueue (p->rh);
        }
    }
    cout<<endl;
}
template<class elemType>
void BTree<elemType>::creatTree (){
    int n;
    cin>>n;
    node<elemType>**p;
    p=new node<elemType>*[10000]{0};
    int a,b,c;
    cin>>a>>b>>c;
    p[a]=new node<elemType>(a);
    root=p[a];
    if(b!=-1){
        p[a]->rh=new node<elemType>(b);
        p[b]=p[a]->rh;
    }
    if(c!=-1){
        p[a]->lf=new node<elemType>(c);
        p[c]=p[a]->lf;
    }
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        if(b!=-1){
            p[a]->rh=new node<elemType>(b);
            p[b]=p[a]->rh;
        }
        if(c!=-1){
            p[a]->lf=new node<elemType>(c);
            p[c]=p[a]->lf;
        }
    }
};
int main () {
    BTree<int> tree;
    tree.creatTree();
    tree.postOrder();
    return 0;
}
