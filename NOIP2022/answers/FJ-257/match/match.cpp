#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=3e5,M=4e3;
int n;
int a[N+1],b[N+1];
ull sum[M+1][M+1];
ull xxx[M+1][M+1];
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
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int T;
    T=R();n=R();
    for(i=1;i<=n;i++)a[i]=R();
    for(i=1;i<=n;i++)b[i]=R();
    int ma,mb;  
    ull sss;
    int Q;
    int h,t,p,q;
    if(T<=5){
        for(i=1;i<=n;i++){
            ma=0;mb=0;sss=0;
            for(j=i;j<=n;j++){
                ma=max(ma,a[j]);
                mb=max(mb,b[j]);
                xxx[i][j]=ma*mb;
            }            
        }
        for(i=1;i<=n;i++){
            sss=0;
            for(j=1;j<=n;j++){
                sss+=xxx[i][j];sum[i][j]=sum[i-1][j]+sss;
            }
        }
        Q=R();
        while(Q--){
            h=R();t=R();
            sss=sum[t][t]-sum[h-1][t]-sum[t][h-1]+sum[h-1][h-1];
            cout<<sss<<"\n";
        }
        return 0;
    } 
    ull ans;
    Q=R();
    while(Q--){
        h=R();t=R();ans=0;
        for(i=h;i<=t;i++){
            ma=0;mb=0;
            for(j=i;j<=t;j++){
                ma=max(ma,a[j]);
                mb=max(mb,b[j]);
                ans+=ma*mb;
            }            
        }
        cout<<ans<<"\n";
    }
    return 0;
}

