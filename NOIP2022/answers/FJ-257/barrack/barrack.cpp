#include<bits/stdc++.h>
using namespace std;
const int N=5e5,M=1e6;
int n,m;
bool a[N+1];
bool b[M+1];
struct S{
    int x,y;
};
S SS[M+1];
int fa[N+1];
inline F(int x){
    if(fa[x]==x)return fa[x];
    fa[x]=F(fa[x]);
    return fa[x];
}
inline bool check(){
    int i,j;
    int fx,fy;int fff,sum;
    for(i=1;i<=m;i++)
        if(!b[i]){
            for(j=1;j<=n;j++)fa[j]=j;
            for(j=1;j<=m;j++)
                if(i!=j){
                    fx=F(SS[j].x);fy=F(SS[j].y);
                    if(fx!=fy)fa[fy]=fx;     
                }
                fff=0;sum=0;
                for(j=1;j<=n;j++)
                    if(a[j]&&fff!=F(j)){
                        fff=F(j);
                        sum++;
                    }
            if(sum>1)return false;  
            if(sum==0)return false;
        }
    return true;
}
int D1(int x){
    if(x>m){
        if(check()){
            return 1;          
        }
        return 0;
    }
    int sum=0;
    b[x]=true;
    sum+=D1(x+1);
    b[x]=false;
    sum+=D1(x+1);
    return sum;
}
int D2(int x){
    if(x>n){
        int OK=0;
        for(int i=1;i<=n;i++)if(a[i])OK++;
        if(OK==0)return 0;
        return D1(1);
    }
    int sum=0;
    a[x]=true;
    sum+=D2(x+1);
    a[x]=false;
    sum+=D2(x+1);
    return sum;
}
inline int R(){
    char c=getchar();
    for(;!(('0'<=c&&c<='9')||c=='-');c=getchar());
    int s=1,num=0;
    if(c=='-'){
        s=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        num=num*10+(c-'0');
        c=getchar();
    }
    num=num*s;
    return num;
}
int main(){
    int i,j;
    freopen("barrack.in","r",stdin);
    freopen("barrack.out","w",stdout);
    n=R();m=R();
    for(i=1;i<=m;i++){
        SS[i].x=R();SS[i].y=R();
    }
    printf("%d",D2(1));
    return 0;
}

