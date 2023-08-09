#include <iostream>
using namespace std;

int jump2(int ** a,int m,int n,int mi,int ni,int i,int j,int endm,int endn,int direction,int num){
    switch(direction){
        case 0:i+=mi;j+=ni;break;
        case 1:i+=ni;j+=mi;break;
        case 2:i+=mi;j-=ni;break;
        case 3:i-=ni;j+=mi;break;
        case 4:i+=ni;j-=mi;break;
        case 5:i-=mi;j+=ni;break;
        case 6:i-=ni;j-=mi;break;
        case 7:i-=mi;j-=ni;break;
    }
    if(i<0||i>=m||j<0||j>=n)return 1000000;
//    cout<<a[i][j]<<endl;
    if(a[i][j]!=1&&a[i][j]!=4){
        return 1000000;
    }
    else if(a[i][j]==4){
        return 1;
    }
    if(num<0){
        return 1000000;
    }
    num--;
    int item=0,min=999999;
    for(int dir=0;dir<8;dir++){
        if(dir==7-direction)continue;
        item=jump2(a,m,n,mi,ni,i,j,endm,endn,dir,num);
        if(min>item){
            min=item;
        }
    }
    return min+1;
}
int jump(int ** a,int m,int n,int mi,int ni,int startm,int startn,int endm,int endn){
    int min=999999;
    int num=19,item=0;
    for(int i=0;i<8;i++){
        item=jump2(a,m,n,mi,ni,startm,startn,endm,endn,i,num);
        if(min>item){
            min=item;
        }
    }

    return min;
}
int main () {
    int m,n,mi,ni;
    cin>>m>>n>>mi>>ni;
    int **land;
    land=new int * [m];
    int startm,startn,endm,endn;
    for(int i=0;i<m;i++){
        land[i]=new int [n];
        for(int j=0;j<n;j++){
            cin>>land[i][j];
            if(land[i][j]==3){
                startm=i;startn=j;
            }
            else if(land[i][j]==4){
                endm=i;endn=j;
            }
        }
    }

    int step=jump (land,m,n,mi,ni,startm,startn,endm,endn);
    cout<<step<<endl;

    return 0;
}
