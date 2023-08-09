#include <iostream>

using namespace std;
class outOfBound{};
class illegalSize{};

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
    cout<<Rear<<" "<<len<<endl;
}
template<class elemType>
void seqQueue<elemType>::deQueue(){
    if(!isEmpty()){
        Front=(Front+1)%maxSize;
        len-=1;
    }
    cout<<Front<<" "<<len<<endl;
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
int main () {
    int s,n;
    cin>>s>>n;
    seqQueue<int> a(s);
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        switch(op){
            case 0:
                int x;
                cin>>x;
                a.enQueue (x);
                break;
            case 1:
                a.deQueue();
                break;
        }
    }
    return 0;
}
