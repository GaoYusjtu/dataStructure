#include <iostream>

using namespace  std;

class illegalSize{};
class outOfBound{};
class linkList;

class node{
    friend class linkList;
public:
    int data;
    node *next;
    node():next(NULL){};
    node(const int &e,node *N=NULL){
        data=e;
        next=N;
    }
};

class linkList{
private:
    node *head;
    node *p;
public:
    linkList(int i);
    ~linkList();
    node* remove(int K,int M);
    void insert(int i,const int &e);
};

linkList::linkList(int i){
    head=new node(i);
    head->next=head;
    p=head;
}

linkList::~linkList(){
    delete p;
};

void linkList::insert(int i,const int &e){
    if(i<1)throw outOfBound();
    node *p,*tmp;
    int num=1;
    p=head;
    while(p){
        if(num==i-1) break;
        p=p->next;
        num++;
    }
    if(!p) return;
    tmp=new node(e,p->next);
    p->next=tmp;
};

node* linkList::remove(int K,int M){
    static node *q;
    if(K>M)K=K%M+M;
    while(K-2<0){
        K=M+K;
    }
    for(int i=1;i<K-1;i++){
        q=p->next;
        p=q;
    }
    q=p->next;
    p->next=q->next;
    p=p->next;
    delete q;
    q=p;
    return p;
}

int main () {
    int M;
    cin>>M;
    linkList monkey(1);
    for(int i=2;i<=M;i++){
        monkey.insert (i,i);
    }
    node *p;
    while(M>1){
        int K;
        cin>>K;
        p=monkey.remove(K,M);
        M-=1;
    }
    cout<<p->data<<endl;
    return 0;
}
