#include <iostream>
using namespace std;
template <class elemType>
void shellSort(elemType a[], int n)//时间复杂度o(nlog2n)~o(n^1.3),不稳定排序
{
    int step, i, j;
    elemType tmp;
    for (step = n / 2; step > 0; step /= 2) {//步长从n/2到1
        for (i = step; i < n; i++)//对每一个步长的各子序列排序
        {
            tmp = a[i];
            j = i;
            while ((j - step >= 0) && (tmp <= a[j - step])) {
                a[j] = a[j - step];
                j -= step;
            }
            a[j] = tmp;
        }//所有子序列同时做直接插入排序
    }
}
int main () {
    int n;cin>>n;
    long long *hash;
    hash=new long long [n];
    char c[1501];
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>c;
        int j=0;
        while(c[j]!='\0'){
            sum=sum*131+c[j];
            j++;
        }
        hash[i]=sum;
        sum=0;
    }
    shellSort (hash,n);
    int num=0;
//    cout<<endl;
//    for(int i=0;i<n;i++)cout<<hash[i]<<endl;
//    cout<<endl;
    for(int i=0;i<n;i++){
        if((i<=n-2&&hash[i+1]!=hash[i]))num+=1;
    }
    cout<<num+1<<endl;
    return 0;
}
