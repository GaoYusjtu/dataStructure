#include <iostream>
using namespace std;
//
int counter=0;
bool state=false;
bool meshment=false;
//
class outOfBound{};
class illegalSize{};
class linkStack;
class node{
    friend class linkStack;
private:
    char x;
    bool mesh;
    node *next;
public:
    node(){
        next=NULL;
        mesh=false;
    }
    node(const char &e,node *p=NULL){
        x=e;
        mesh=false;
        next=p;
    }
};

class linkStack{
private:
    node *Top;
public:
    linkStack();
    ~linkStack();

    bool isEmpty();
    char top();
    bool top_state();
    void delete_push(const char &c);
    void judge_push(const char &c);
    void delete_pop(char c,bool flag);
    void judge_pop();
    void judge ();
};
//
linkStack::linkStack(){
    Top=NULL;
};
linkStack::~linkStack(){
    node *p;
    while(Top!=NULL){
        p=Top;
        Top=Top->next;
        delete p;
    }
    delete Top;
};
bool linkStack::isEmpty(){
    return(Top==NULL);
};
char linkStack::top(){
    if(Top==NULL)return '0';
    else return Top->x;
};
void linkStack::judge_push(const char &c){
    node *tmp,*p;
    tmp=new node;
    tmp->x=c;
    tmp->next=Top;
    if((c==')'||c==']'||c=='}')&&meshment==true){
        tmp->mesh=true;
    }
    Top=tmp;
};
void linkStack::delete_push(const char &c){
    if(c=='('||c=='{'||c=='['){
        judge_push (c);
    }
    else if(c==')'){
        if(top()=='('){
            judge_pop();
            meshment=true;
        }
        else judge_push(c);
    }
    else if(c==']'){
        if(top()=='['){
            judge_pop();
            meshment=true;
        }
        else {
            judge_push(c);
        }
    }
    else if(c=='}'){
        if(top()=='{'){
            judge_pop();
            meshment=true;
        }
        else judge_push (c);
    }
}
void linkStack::judge_pop(){
    if(Top==NULL)throw outOfBound();
    node *tmp;
    tmp=Top;
    Top=Top->next;
    delete tmp;
};
void linkStack::delete_pop(char c,bool flag){
    if(flag==false){
        judge_pop();
    }
    else if(flag==true){
        if(c==')')judge_push ('(');
        else if(c==']')judge_push ('[');
        else if(c=='}')judge_push ('}');
    }
}
bool linkStack::top_state(){
    return Top->mesh;
}
void linkStack::judge () {
    if(top()=='0')cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main () {
    linkStack a,b;
    int n,len=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        switch(op){
            case 1:
                char str;
                cin>>str;
                b.delete_push (str);
                a.judge_push(str);
                len+=1;
                meshment=false;
                counter+=1;
                break;
            case 2:
                if(len==0){
                    break;
                }
                else {
                    b.delete_pop(a.top(),a.top_state());
                    a.judge_pop();
                    len -= 1;
                    counter-=1;
                    break;
                }
            case 3:
                if(len==0) break;
                else{
                    cout<<a.top()<<endl;
                    break;
                }

            case 4:
                if (len == 0){
                    cout << "YES" << endl;
                    break;
                }
                if(counter!=0&&len%2==0) {
                    b.judge ();
                    break;
                }
                else if(counter==0){
                    if(state==true){
                        cout<<"YES"<<endl;
                        break;
                    }
                    else{
                        cout<<"NO"<<endl;
                        break;
                    }
                }
                else if(len%2!=0){
                    cout<<"NO"<<endl;
                    break;
                }
                counter=0;
        }
    }
    return 0;
}