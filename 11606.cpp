#include <iostream>
using namespace std;
int num=3,counter1=0,counter2=0,counter3=0,counter4=0,counter5=0,counter6=1,counter7=0;
//void judge(int **a,int i,int j,int ){
//    if(num==4){
//        if(counter3==0){
//            for(int i=0;i<m;i++){
//                for(int j=0;j<n;j++){
//                    if(a[i+1][j+1]==0)cout<<'#';
//                    else cout<<'.';
//                }
//                cout<<endl;
//            }
//            return;
//        }
//        else{
//            for(int i=1;i<=m;i++){
//                for (int j = 1; j <=n; ++j){
//                    if(a[i][j]==2 && (a[i-1][j]>2 || a[i+1][j]>2 || a[i][j-1]>2 || a[i][j+1]>2)){
//                        state=false;
//                        cout<<"Ambiguous"<<endl;
//                        return;
//                    }
//                }
//            }
//            for(int i=1;i<=m;i++){
//                for(int j=1;j<=n;j++){
//                    if(a[i][j]==0)cout<<'#';
//                    else if(a[i][j]>2) cout<<'.';
//                }
//                cout<<endl;
//            }
//            return;
//        }
//    }
//    else if(num>4){
//        for (int i = 1; i <=m ; ++i) {
//            for (int j = 1; j <=n ; ++j) {
//                if(a[i][j]==2){
//                    if(judgedoubt(a,i,j)==false)return;
//                }
//            }
//        }
//    }
//}
void sort2(int **a,int**flag,int** visit,int i,int j){
    if(a[i][j]!=1 && a[i][j]!=2)return;
    if(flag[i][j]==1)return;
    if(a[i][j]==1){
        counter4++;
        flag[i][j]=1;
    }
    else if(a[i][j]==2){
        a[i][j]=4;
        counter5++;
        flag[i][j]=1;
        visit[0][counter6]=i;
        visit[1][counter6]=j;
        counter6++;
    }

//    a[i][j]=1000000;
    sort2(a,flag,visit,i-1,j);
    sort2(a,flag,visit,i+1,j);
    sort2(a,flag,visit,i,j-1);
    sort2(a,flag,visit,i,j+1);
}
void scan(int **a,int** flag,int**visit,int m,int n){
    int i=1,j=1;
    for(;i<=m;i++){
        bool state=true;
        j=1;
        for(;j<=n;j++){
            if(a[i][j]==1){
                state=false;
                visit[0][0]=i;visit[1][0]=j;
                break;
            }
        }
        if(state==false)break;
    }
    sort2(a,flag,visit,i,j);
}

//读取区块
 void sort3(int **a,int**flag,int i,int j){
    if(a[i][j]!=1&&a[i][j]!=4){
        return;
    }
    if(flag[i][j]==1)return;
    flag[i][j]=1;
    counter7++;
    sort3(a,flag,i-1,j);
    sort3(a,flag,i+1,j);
    sort3(a,flag,i,j-1);
    sort3(a,flag,i,j+1);
}
void sort1(int **a,int**flag,int** visit,int m,int n){
    sort3(a,flag,visit[0][0],visit[1][0]);
}
void judgefinal(int **a,int **flag,int **visit,int m,int n){
    for(int i=1;i<counter6;i++){
        for(int i=0;i<m+2;i++){
            for(int j=0;j<n+2;j++){
                flag[i][j]=0;
            }
        }
        a[visit[0][i]][visit[1][i]]=3;
        counter7=0;
        sort1(a,flag,visit,m,n);
        if(counter7==counter4+counter5-1){
            cout<<"Ambiguous"<<endl;
            return;
        }
        a[visit[0][i]][visit[1][i]]=4;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i+1][j+1]==0||a[i+1][j+1]==2)cout<<'#';
            else if(a[i+1][j+1]==1)cout<<'.';
            else if(a[i+1][j+1]==4)cout<<'.';
        }
        cout<<endl;
    }
}

int main () {
    int m,n;
    cin>>m>>n;
    int **land,**land2;
    int **visit;
    int **flag;
    visit=new int*[2];
    visit[0]=new int [m*n];
    visit[1]=new int [m*n];
    flag=new int*[m+2];
    for(int i=0;i<m+2;i++){
        flag[i]=new int[n+2]{0};
    }
    land=new int *[m+2];
//    land2=new int *[m+2];
    land[0]=new int [n+2];land[m+1]=new int [n+2];
//    land2[0]=new int [n+2];land2[m+1]=new int [n+2];
    for(int i=0;i<n+2;i++){
        land[0][i]=0;
        land2[0][i]=0;
    }
    char c;
    for(int i=1;i<=m;i++){
        land[i]=new int [n+2];
        land[i][0]=0;land[i][n+1]=0;
//        land2[i]=new int [n+2];
//        land2[i][0]=0;land[i][n+1]=0;
        for(int j=1;j<=n;j++){
            cin>>c;
            if(c=='#'){
                land[i][j]=0;counter1++;
//                land2[i][j]=0;
            }
            else if(c=='.'){
                land [i][j]=1;counter2++;
//                land2 [i][j]=1;
            }
            else if(c=='?'){
                land [i][j]=2;counter3++;
//                land2 [i][j]=2;
            }
        }
    }
    if(counter2==0&&counter3==0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    else if(counter2==0&&counter3==1){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i+1][j+1]==0)cout<<'#';
                else if(land[i+1][j+1]==1)cout<<'.';
                else if(land[i+1][j+1]==2)cout<<'.';
            }
            cout<<endl;
        }
        return 0;
    }
    else if(counter2==0&&counter3>1){
        cout<<"Ambiguous"<<endl;
    }
    scan(land,flag,visit,m,n);
//    cout<<counter4<<endl;
    if(counter4<counter2){
        cout<<"Impossible"<<endl;
        return 0;
    }
    judgefinal (land,flag,visit,m,n);
    return 0;
}
