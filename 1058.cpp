#include <iostream>
#include <cstdio>

using namespace std;

namespace LIST
{

    struct NODE {
        int data;
        NODE *next;
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        head=new NODE;
        head->next=head;
        head->data=0;
    }
    NODE* move(int i) {
        NODE *p=head;
        if(i>=-1||i<len) {
            int item = 0;
            while (p && item <= i) {
                p = p->next;
                item += 1;
            }
            if (p) return p;
            else return (NULL);
        }
        else return (NULL);
    }
    void insert(int i, int x) {
        NODE *tmp=new NODE,*p;
        tmp->data=x;
        p=move(i-1);
        tmp->next=p->next;
        p->next=tmp;
        len+=1;
    }
    void remove(int i) {
        NODE *p,*q=move(i-1);
        p=q->next;
        q->next=p->next;
        delete p;
        len-=1;
    }
    void remove_insert(int i) {
        int e=move(i)->data;
        remove(i);
        insert(len,e);
    }
    void get_length() {
        cout<<len<<endl;
    }
    void query(int i) {
        if(i<0||i>=len) {
            cout<<-1<<endl;
            return;
        }
        else{
            NODE *p=move(i);
            cout<<p->data<<endl;
        }
    }
    void get_max() {
        int item=0,max=0;
        if(head->next==head){
            cout<<"-1"<<endl;
            return;
        }
        NODE *p=head->next;
        while(p&&item<len){
            if(p->data> max) max=p->data;
            item++;
            p=p->next;
        }
        cout<<max<<endl;
    }
    void clear() {
        NODE *p,*q;
        p=head->next;
        delete head;
        int item=0;
        while(item<len){
            q=p->next;
            delete p;
            p=q;
            item++;
        }
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}