#include <iostream>
#include <iomanip>
using namespace std;
template <class elemType>
void merge(elemType a[], int low, int mid, int high)//归并算法，将两有序数列合并为一个有序数列
{
    int i, j, k;
    elemType *c;
    //创建实际空间存储合并后结果
    c=new elemType[high-low+1];
    i = low;j = mid+1;k = 0;
    //两个有序序列中元素的比较合并
    while ((i<=mid)&&(j<=high))
    {
        if (a[i]<=a[j]){
            c[k]=a[i];i=i+1;
        }
        else
        {
            c[k]=a[j];j=j+1;
        }
        k=k+1;
    }
    while (i<=mid)
    {
        c[k]=a[i];i=i+1;k=k+1;
    }
    //若b序列中j未越界，抄写剩余元素
    while (j<=high)
    {
        c[k]=a[j];j=j+1;k=k+1;
    }
    for (i=0;i<high-low+1; i++)a[i+low] = c[i];
    delete []c;
}
////
template <class elemType>
void mergeSort(elemType a[], int low, int high)
{
    int mid;
    if (low>=high) return;
    mid =(low+high)/2;
    mergeSort(a, low, mid);//前半部分排序
    mergeSort(a, mid+1, high);//后半部分排序
    merge(a, low, mid, high);//全部序列排序
}
template <class elemType>
void mergeSort(elemType a[], int n)//归并排序（递归），时间复杂度o（nlog2n），稳定排序
{
    mergeSort(a, 0, n-1);
}
int main () {
    int m,n,size;
    cin>>m>>n;
    size=m*n;
    long long int *grid,*height;
    long double wheight,volumn;
    double portion;
    grid=new long long [size]{0};
    height=new long long [size]{0};
    for(int i=0;i<size;i++){
        cin>>grid[i];
    }
    cin>>volumn;
    mergeSort<long long int> (grid,size);
//    for(int i=0;i<size;i++){
//        cout<<grid[i]<<" ";
//    }
//    cout<<endl;
    height[0]=grid[0];
    for(int i=1;i<size;i++){
        height[i]=height[i-1]+grid[i];
    }
//    for(int i=0;i<size;i++){
//        cout<<height[i]<<" ";
//    }

    if(volumn==0){
        wheight=0;portion=0;
    }
    else {
        int index=0;
        for (; index < size; index++) {
            if ((grid[index + 1] * (index + 1) - height[index] >= volumn) &&
                (grid[index] * (index + 1) - height[index] < volumn))
                break;
        }
//        cout<<index<<endl;
        if (index == size) {
            wheight = (volumn - (grid[size - 1] * size - height[size - 1])) / (double) size + (double) grid[size - 1];
            portion=100;
        }
        else {
            wheight = (volumn - (grid[index] * (index + 1) - height[index])) / ((double) index + 1) +
                      (double) grid[index];
            portion = (index + 1) * 100 / (double) size;
        }
    }
    cout <<setiosflags(ios::fixed)<< setprecision(2) << wheight << endl;
    cout <<setiosflags(ios::fixed)<< setprecision(2) << portion << endl;
    return 0;
}
