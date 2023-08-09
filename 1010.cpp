#include <iostream>
using namespace std;
int main () {
    long long int *a,*b;
    int m,n,x;
    cin>>n>>m;
    a=new long long int [n+1]{0};
    b=new long long int [m];
    for(int i=1;i<=n;i++){
        cin>>x;
        a[i]=x+a[i-1];
    }
    for(int i=0;i<m;i++){
        cin>>x;
        b[i]=x;
    }
    for(int i=0;i<m;i++){
        int l=1,r=n,mid=(l+r)/2;
        while(l<=r){
            if(a[mid-1]<b[i]&&a[mid]>=b[i]){
                cout<<mid<<" "<<b[i]-a[mid-1]<<endl;
                break;
            }
            else if(a[mid-1]>=b[i]){
                r=mid-1;
                mid=(l+r)/2;
            }
            else if(a[mid]<b[i]){
                l=mid+1;
                mid=(l+r)/2;
            }
        }
    }
//    for(int i=0;i<m;i++){
//        cout<<b[1][i]<<" "<<b[0][i]<<endl;
//    }
    return 0;
}
