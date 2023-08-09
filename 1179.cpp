#include <iostream>
using namespace std;
struct mice{
    long long int mark;
    int str;
    int num;
};

void shellSort_mark(mice a[], int n)//时间复杂度o(nlog2n)~o(n^1.3),不稳定排序
{
    int step, i, j;
    mice tmp;
    for (step = n / 2; step > 0; step /= 2) {//步长从n/2到1
        for (i = step; i < n; i++)//对每一个步长的各子序列排序
        {
            tmp = a[i];
            j = i;
            while ((j - step >= 0) && (tmp.mark >= a[j - step].mark)) {
                a[j] = a[j - step];
                j -= step;
            }
            a[j] = tmp;
        }//所有子序列同时做直接插入排序
    }
}

void shellSort_num(mice *a, int n)//时间复杂度o(nlog2n)~o(n^1.3),不稳定排序
{
    int step, i, j;
    mice tmp;
    for (step = n / 2; step > 0; step /= 2) {//步长从n/2到1
        for (i = step; i < n; i++)//对每一个步长的各子序列排序
        {
            tmp = a[i];
            j = i;
            while ((j - step >= 0) && (tmp.num <= a[j - step].num)) {
                a[j] = a[j - step];
                j -= step;
            }
            a[j] = tmp;
        }//所有子序列同时做直接插入排序
    }
}
void sort_num(mice a[],int n){
    int counter, i=0, start;
    while(i<n){
        if(a[i].mark!=a[i+1].mark){
            i++;
            continue;
        }
        start=i;
        counter=1;
        while (a[i].mark==a[i+1].mark){
            counter++;
            i++;
        }
        shellSort_num (a+start,counter);
    }
}
int main () {
    int n,r;cin>>n>>r;
    mice *a;
    a=new mice [2*n];
    for(int i=0;i<2*n;i++){
        a[i].num=i+1;
    }
    for(int i=0;i<2*n;i++){
        cin>>a[i].mark;
    }
    for(int i=0;i<2*n;i++){
        cin>>a[i].str;
    }
    for(int i=0;i<r;i++){
//        shellSort_num (a,2*n);
        shellSort_mark (a,2*n);
        sort_num (a,2*n);
        for(int j=0;j<2*n;j+=2){
            if(a[j].str>a[j+1].str)a[j].mark+=2;
            else if(a[j].str<a[j+1].str)a[j+1].mark+=2;
            else {
                a[j].mark+=1;a[j+1].mark+=1;
            }
        }
    }
//    shellSort_num (a,2*n);
    shellSort_mark (a,2*n);
    sort_num (a,2*n);
    for(int i=0;i<2*n;i++){
        cout<<a[i].num<<" ";
    }
    return 0;
}
