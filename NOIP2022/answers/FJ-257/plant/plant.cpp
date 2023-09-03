#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+10,Mod=998244353;
ll n,m,c,f;
char S[N+2];
bool a[N+2][N+2];
ll TX[N+2][N+2];
ll TY[N+2][N+2];
ll Fc[N+2][N+2];
ll Ff[N+2][N+2];
inline ll R(){
    char c=getchar();
    for(;!(('0'<=c&&c<='9')||c=='-');c=getchar());
    ll s=1,num=0;
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
    ll i,j;
    freopen("plant.in","r",stdin);
    freopen("plant.out","w",stdout);
    ll T=R(),id=R();
    while(T--){
        memset(a,0,sizeof(a));
        memset(TX,0,sizeof(TX));
        memset(TY,0,sizeof(TY));
        memset(Fc,0,sizeof(Fc));
        memset(Ff,0,sizeof(Ff));
        n=R();m=R();c=R();f=R();
        for(j=0;j<=m+1;j++)a[0][j]=1;
        for(i=1;i<=n;i++){
            scanf("%s",S+1);
            a[i][0]=1;
            for(j=1;j<=m;j++)
                a[i][j]=S[j]-'0';
            a[i][m+1]=1;
        }
        for(j=0;j<=m+1;j++)a[n+1][j]=1;
        for(i=0;i<=n+1;i++)
            for(j=0;j<=m+1;j++)
                if(a[i][j])
                    TX[i][j]=TY[i][j]=-1;    
        for(i=n;i>=1;i--)
            for(j=m;j>=1;j--)
                if(!a[i][j])
                    TX[i][j]=TX[i][j+1]+1;
        for(i=n;i>=1;i--)
            for(j=m;j>=1;j--)
                if(!a[i][j])
                    TY[i][j]=TY[i+1][j]+1;
        ll ansc=0,ansf=0;
        if(c!=0){
            for(i=n;i>=1;i--)
                for(j=m;j>=1;j--)
                    if(!a[i][j]){
                        Fc[i][j]=Fc[i+1][j]+TX[i][j];
                        Fc[i][j]%=Mod;
                    }else{
                        Fc[i][j]=0;
                    }
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    if(TX[i][j]>0&&TY[i][j]>1){
                        ansc+=Fc[i+2][j]*TX[i][j];ansc%=Mod;
                    }

        }
        if(f!=0){
            for(i=n;i>=1;i--)
                for(j=m;j>=1;j--)
                    if(!a[i][j]){
                        Ff[i][j]=Ff[i+1][j]+TX[i][j]*TY[i][j];
                        Ff[i][j]%=Mod;
                    }else{
                        Ff[i][j]=0;
                    }
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    if(TX[i][j]>0&&TY[i][j]>1){
                        ansf+=Ff[i+2][j]*TX[i][j];  ansf%=Mod;    
                    }

        }
        printf("%lld %lld\n",ansc,ansf);
    }
    return 0;
} 
