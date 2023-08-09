#include <iostream>
using namespace std;

void buildTree(char pre[],char in[],char res[],int len,int pos,int pstart,int istart){
    if(len<=0) {
        return;
    }
    char root=pre[pstart];
    res[pos]=root;
    int i=istart,leftlen,rightlen;
    for(;i<istart+len;i++){
        if(in[i]==root)break;
    }
    leftlen=i-istart;
    rightlen=len-leftlen-1;
    buildTree (pre,in,res,leftlen,2*pos,pstart+1,istart);
    buildTree(pre,in,res,rightlen,2*pos+1,pstart+1+leftlen,istart+1+leftlen);
}

int main () {
    char pre[27]={'\0'},in[27]={'\0'};
    cin>>pre>>in;

    int len=0;
    while(pre[len]!='\0'){
        len++;
    }

    char c[1000]={'\0'};
    buildTree(pre,in,c,len,1,0,0);
    int t=999;
    for(;t>=0;t--){
        if(c[t]!='\0')break;
    }
    int i=1;
    while(i<t){
        if(c[i]=='\0')cout<<"NULL ";
        else cout<<c[i]<<" ";
        i++;
    }
    if(c[i]=='0')cout<<"NULL"<<endl;
    else cout<<c[i]<<endl;

    return 0;
}
