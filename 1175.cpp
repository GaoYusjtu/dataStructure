#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace  std;

long long average(long long* t, int n)
{
    long long ans=0;
    for (int i = 0; i < n; i++)
        ans += t[i];
    return ans;
}

bool comp(long long x1, long long x2)
{
    return x1 < x2 ? true : false;
}

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
    int item=0;
    while(true) {
        srand((int)time(0));
        int n, x;
        n=rand()%100+1;
        int *array;array=new int [n+1];
        long long *li;
        li = new long long[n + 1]{0};
        for (int i = 1; i <= n; i++) {
            array[i]=rand()%100001;
            li[i] = array[i] + li[i - 1];
        }
        int m;
        m=rand()%1000001;
        long long *boy, *girl;
        boy = new long long[m + 1]{0};
        girl = new long long[m + 1]{0};
        int bnum = 0, gnum = 0, *si, *ti;
        si=new int [m+1];ti=new int [m+1];
        for (int i = 0; i < m; i++) {
            si[i]=rand()%2+1;
            ti[i]=rand()%(li[n-1]+1);
            if (si[i] == 1) {
                boy[bnum] = ti[i];
                bnum++;
            } else {
                girl[gnum] = ti[i];
                gnum++;
            }
        }
        boy[bnum] = -1;
        girl[gnum] = -1;
        boy[bnum + 1] = -1;
        girl[gnum + 1] = -1;
        shellSort (boy, bnum);
        shellSort (girl, gnum);

        int i = 0, j = 0;
        long long bsum = 0, gsum = 0;
        while (boy[i] != -1 && girl[i] != -1) {
            while (boy[i] > li[j] || girl[i] > li[j]) {
                j++;
            }
//        cout<<j<<endl;
            bsum += li[j] - boy[i];
            gsum += li[j] - girl[i];
            i++;
        }
        int bi = i, gi = i;
        while (boy[bi] != -1) {
            bsum += li[n - 1] - boy[bi];
//        cout<<"11"<<endl;
            bi++;
        }
        while (girl[gi] != -1) {
            gsum += li[n - 1] - girl[gi];
//        cout<<"1"<<endl;
            gi++;
        }
        long double b = 0, g = 0;
        if (bnum != 0)b = bsum / (double) bnum;
        if (gnum != 0)g = gsum / (double) gnum;
//        cout << setiosflags (ios::fixed) << setprecision (2) << b << " " << g << endl;

        ////

        int k = 0;
        int start;
        int counter1 , counter2;
        for (int t = 0; t < n-1; t++)
        {
            start = k;
            counter1 = counter2 = k;
            while (boy[counter1] <= li[t]&&counter1<bnum&&bnum>0)
                counter1++;
            while (girl[counter2] <= li[t]&&counter2<gnum&&gnum>0)
                counter2++;
            k = (counter1 < counter2) ? counter1 : counter2;
            for (int l = start; l < k; l++)
            {
                boy[l] = li[t] - boy[l];
                girl[l] = li[t] - girl[l];
            }
        }
        for (int l =k; l < bnum; l++)
        {
            boy[l] = li[n-1] - boy[l];
        }
        for (int l =k; l < gnum; l++)
        {
            girl[l] = li[n - 1] -girl[l];
        }

        long long b2= average (boy,bnum),g2= average (girl,gnum);


        if(b2==bsum&&g2==gsum){
            cout<<item<<" "<<"right!"<<"\t";
        }
        else{
            cout<<"wrong!!!"<<endl;
            cout<<n<<endl;
            for(int a=1;a<=n;a++){
                cout<<array[a]<<" ";
            }
            cout<<endl;
            cout<<m<<endl;
            for(int a=0;a<m;a++){
                cout<<si[a]<<" "<<ti[a]<<endl;
            }
            cout<<bsum<<" "<<b2<<" "<<gsum<<" "<<g2<<endl;
            break;
        }
        item++;
        delete []array;delete [] boy;delete []girl;delete []li;delete []si;delete []ti;
    }
    return 0;
}
