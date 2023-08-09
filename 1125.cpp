#include <iostream>
using namespace std;
class outOfBound{};
class illegalSize{};
template <class elemType>
class linkQueue;
template<class elemType>
class node{
    friend class linkQueue<elemType>;
private:
    elemType data;
    node *next;
public:
    node(){next=NULL;};
    node(const elemType &e,node<elemType> *p=NULL){
        data=e;
        next=p;
    }
};
template <class elemType>
class linkQueue{
private:
    node<elemType> *head;
    node<elemType> *rear;
public:
    linkQueue();
    ~linkQueue();
    void clear();
    bool isEmpty();
    elemType Front();
    void enQueue(const elemType &x);
    void deQueue();

    void deletemin();
    void combine(linkQueue<elemType> &a);
};

template <class elemType>
linkQueue<elemType>::linkQueue(){
    head=NULL;
    rear=NULL;
}
template <class elemType>
linkQueue<elemType>::~linkQueue(){
    clear();
}
template <class elemType>
void linkQueue<elemType>::clear(){
    node<elemType> *p;
    p=head;
    while(p){
        head=head->next;
        delete p;
        p=head;
    }
    rear=head=NULL;
}
template <class elemType>
bool linkQueue<elemType>::isEmpty(){
    return(!head);
}
template <class elemType>
elemType linkQueue<elemType>::Front(){
    if(isEmpty()){
        return -1;
    }
    return head->data;
}
template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x){
    if(!rear){
        head=rear=new node<elemType>(x);
    }
//    else{
//        rear->next=new node<elemType>(x);
//        rear=rear->next;
//    }
    else{
        node<elemType> *p,*q;
        if(head==rear && head->data<x){
            rear->next=new node<elemType>(x,NULL);
            rear=rear->next;
        }
        else if(head==rear && head->data>=x){
            p=new node<elemType>(x,head);
            head=p;
        }
        else if(head!=rear){
//            p=head;
//            while(p->next&&p){
//                if(p->data<=x && p->next->data>=x){
//                    q=new node<elemType>(x,p->next);
//                    p->next=q;
//                    return;
//                }
//            }
            p=head;
            if(p->data>x){
                q=new node<elemType>(x,head);
                head=q;
            }
            else{
                q=head;
                p=p->next;
                while((p->data<x) && (p->next)){
                    p=p->next;
                    q=q->next;
                }
                if(p->data>x){
                    node<elemType> *tmp;
                    tmp=new node<elemType>(x,q->next);
                    q->next=tmp;
                }
                else{
                    rear->next=new node<elemType>(x);
                    rear=rear->next;
                }
            }
        }
    }
}
template <class elemType>
void linkQueue<elemType>::deQueue(){
    if(isEmpty()){
        return;
    }
    node<elemType> *tmp=head;
    head=head->next;
    delete tmp;
    if(!head) rear=NULL;
}
template<class elemType>
void linkQueue<elemType>::combine(linkQueue<elemType> &a){
    elemType p;
    p=Front();
    if(isEmpty())return;
//    p=head;
    while(p!=-1){
        a.enQueue(p);
        deQueue();
//        a.len++;
        p=Front();
    }
//    clear();
}
//template<class elemType>
//void linkQueue<elemType>::deletemin(){
//    if(isEmpty()){
//        cout<<"-1"<<endl;
//        return;
//    }
//    node<elemType> *p,*q;
//    p=head;int min=p->data;
//    while(p){
//        if(min>p->data){
//            min=p->data;
//        }
//        p=p->next;
//    }
//    cout<<min<<endl;
//    p=head;
//    if(p->data==min){
//        deQueue();
//        return;
//    }
//    else {
//        q = p;
//        p = p->next;
//        while(p){
//            if(p->data==min){
//                q->next=q->next->next;
//                delete p;
//                return;
//            }
//            q=p;
//            p=p->next;
//        }
//    }
//}

int main () {
    int n,m,charm,op;
    cin>>n>>m;
    linkQueue<int> list[n];
//    list=new linkQueue<int>[n];
    for(int i=0;i<n;i++){
        cin>>charm;
        list[i].enQueue(charm);
    }
    for(int i=0;i<m;i++){
        cin>>op;
        switch(op){
            case 0:
                int a,b;
                cin>>a>>b;
                list[b].combine(list[a]);
                break;
            case 1:
                cin>>a;
                cout<<list[a].Front()<<endl;
                list[a].deQueue();
                break;
            case 2:
                cin>>a>>b;
                list[a].enQueue(b);
                break;
        }
    }
    return 0;
}
