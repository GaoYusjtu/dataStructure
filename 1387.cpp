#include <iostream>
using namespace std;
template<class elemType>
struct HuffmanNode{
//    elemType data;
    long long int weight;
    int parent;
    int left,right;
    int height;
};
template<class elemType>
int minIndex(HuffmanNode<elemType>Bt[],int k,int m){
    int i,min;
    long long minWeight=9223372036854775800;
    for(i=m-1;i>k;i--){
        if(Bt[i].parent==0&&Bt[i].weight<minWeight){
            min=i;
            minWeight=Bt[i].weight;
        }
    }
    return min;
};
template <class elemType>
void height(HuffmanNode<elemType> t[],int pos,int h){
    t[pos].height=h;
//    cout<<pos<<" "<<t[pos].weight<<" "<<t[pos].left<<" "<<t[pos].right<<endl;
    if(t[pos].left!=0)height (t,t[pos].left,h+1);
    if(t[pos].right!=0)height(t,t[pos].right,h+1);
}
template<class elemType>
void BestBinaryTree(long long int w[],int n){
    HuffmanNode<elemType> *BBTree;
    int first_min,second_min;
    int m=n*2;
    int i,j;
    BBTree=new HuffmanNode<elemType>[m];
    for(j=0;j<n;j++){
        i=m-1-j;
//        BBTree[i].data=a[j];
        BBTree[i].weight=w[j];
        BBTree[i].parent=0;
        BBTree[i].left=0;
        BBTree[i].right=0;
        BBTree[i].height=0;
    }
    i=n-1;
    while(i!=0){
        first_min= minIndex (BBTree,i,m);
        BBTree[first_min].parent=i;

        second_min= minIndex (BBTree,i,m);
        BBTree[second_min].parent=i;

        BBTree[i].weight=BBTree[first_min].weight+BBTree[second_min].weight;
        BBTree[i].left=first_min;BBTree[i].right=second_min;
        BBTree[i].parent=0;
        i--;
    }
    long long int sum=0;
    height(BBTree,1,0);
    for(j=n;j<m;j++){
//        cout<<BBTree[j].height<<" "<<BBTree[j].weight<<endl;
        sum+=(BBTree[j].height)*BBTree[j].weight;
    }
    cout<<sum<<endl;
}

int main () {
    int n;
    cin>>n;
    long long int *w;
    w=new long long [n]{0};
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    BestBinaryTree<long long int>(w,n);
    return 0;
}
