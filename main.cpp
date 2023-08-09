#include <iostream>
using namespace std;
int maxarea(int **mar,int m,int n){
    int **mar2;mar2=new int*[m];
    int maxlen=0;
    for(int i=0;i<m;i++){
        mar2[i]=new int[n];
        for(int j=0;j<n;j++){
            if(mar[i][j]==1)mar2[i][j]=0;
            else{
                int t=1,len=1;
                while(mar[i][j+t]!=1&&j+t<n){
                    len++;
                    t++;
                }
                mar2[i][j]=len;
                if(len>maxlen)maxlen=len;
            }
        }
    }
//    for(int i=0;i<m;i++){
//        for(int j=0;j<n;j++){
//            cout<<mar2[i][j];
//        }
//        cout<<endl;
//    }
    int maxsize=0;
    bool state=false;
    for(int a=maxlen/2*2;a>=2;a-=2){
        if(state==true)break;
        for(int b=0;b<=m-a/2;b++){
            if(state==true)break;
            for(int c=0;c<=n-a;c++){
                if(mar2[b][c]>=a){
                    for(int d=1;d<a/2;d++){
                        if(mar2[b+d][c]<a){
                            state=false;
                            break;
                        }
                        else state=true;
                    }
                    if(state==true){
                        maxsize=a*a/2;
                        break;
                    }
                }
            }
        }
    }
    return maxsize;
}
int main () {
    int m,n;char c;
    cin>>m>>n;
    int **mar;
    mar=new int*[m];
    for(int i=0;i<m;i++){
        mar[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>c;
            if(c=='X'){
                mar[i][j]=1;
            }
            else {
                mar[i][j]=0;
            }
        }
    }
    int t=maxarea(mar,m,n);
    cout<<t;
    return 0;
}
