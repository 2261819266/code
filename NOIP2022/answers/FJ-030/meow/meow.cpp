#include"stdio.h"
#include"time.h"
#include"stdlib.h"
#include"set"
#define reg register
#define getchar()(inBuf==lenBuf?lenBuf=(inBuf=Buf)+fread(Buf,1,1<<20,stdin):0,inBuf==lenBuf?EOF:*inBuf++)
char Buf[1<<20],*inBuf,*lenBuf;
template<class T>void read(T&x){reg char ch,f=x=0;while(ch=getchar(),ch<'0'||ch>'9');while(x=x*10+(ch&15),ch=getchar(),ch<='9'&&ch>='0');f?x=-x:0;}
int T,n,m,k;
int tp[1010][1010],sz[1010],pos[1010];
int opt[3000010][3],ansn;
int a[2000010],fl;
// unsigned long long dp[2000010];
void ps(int op,int u,int v=0){
    opt[++ansn][0]=op,opt[ansn][1]=u,opt[ansn][2]=v;
}
std::set<unsigned long long>st[2000010];
void dfs(int u){
    if(u>m){
        for(reg int i=1;i<=n;++i)if(sz[i])return;
        fl=1;return;
    }
    if(m>14)for(reg int i=1;i<=n;++i)if(sz[i]>3)return;
    unsigned long long hs=0;
    for(reg int i=1;i<=n;++i)hs=hs*31+sz[i];
    for(reg int i=1;i<=n;++i)for(reg int j=0;j<sz[i];++j)hs=hs*31+tp[i][j];
    if(st[u].find(hs)!=st[u].end())return;st[u].insert(hs);
    if(pos[a[u]]){
        int t=pos[a[u]];
        if(tp[t][sz[t]-1]==a[u]){
            ps(1,t),--sz[t],pos[a[u]]=0;
            dfs(u+1);if(fl)return;
            tp[t][sz[t]++]=a[u],--ansn,pos[a[u]]=t;
        }
        if(sz[t]>1&&tp[t][0]==a[u]){
            for(reg int j=1;j<=n;++j)if(!sz[j]){
                ps(1,j),ps(2,j,t),pos[a[u]]=0;
                --sz[t];for(reg int k=0;k<sz[t];++k)tp[t][k]=tp[t][k+1];
                dfs(u+1);if(fl)return;
                ++sz[t];for(reg int k=sz[t]-1;k;--k)tp[t][k]=tp[t][k-1];tp[t][0]=a[u];
                ansn-=2,pos[a[u]]=t;
                break;
            }
        }
        return;
    }
    for(reg int j=1;j<=n;++j){
        ps(1,j),pos[a[u]]=j,tp[j][sz[j]++]=a[u];
        dfs(u+1);if(fl)return;
        --sz[j],pos[a[u]]=0,--ansn;
    }
}
main(){
     freopen("meow.in","r",stdin);
     freopen("meow.out","w",stdout);
    // for(reg int i=)
    for(read(T);T--;){
        read(n),read(m),read(k);
        for(reg int i=1;i<=n;++i)tp[i][0]=tp[i][1]=0;
        ansn=0;
        if(k==n*2-2){
            for(reg int i=1;i<=m;++i){
                int x;read(x);int t=x>n-1?x-(n-1):x;
                if(tp[t][0]==x){ps(1,n),ps(2,n,t);tp[t][0]=tp[t][1],tp[t][1]=0;}
                else{
                    if(tp[t][0]==0)ps(1,t),tp[t][0]=x;
                    else ps(1,t),tp[t][1]=x-tp[t][1];
                }
            }
        }
        else{
            // if(n==2){
            //     dp[0]=1;
            //     for(reg int i=1;i<=m;++i){
            //         int x;read(x);
            //         for(reg int j=0;j<64;++j)if(dp[i-1]>>j&1){
            //             int p1=j&3,p2=j>>2&3,p3=j>>4&3;
            //             if(x==1){

            //             }
            //         }
            //     }
            // }
            for(reg int i=1;i<=m;++i)read(a[i]),st[i].clear();
            for(reg int i=1;i<=n;++i)sz[i]=0;
            for(reg int i=1;i<=k;++i)pos[i]=0;
            fl=0;dfs(1);if(!fl)return 0;
        }
        printf("%d\n",ansn);
        for(reg int i=1;i<=ansn;++i)
            if(opt[i][0]==1)printf("1 %d\n",opt[i][1]);
            else printf("2 %d %d\n",opt[i][1],opt[i][2]);
    }
    // while(1.0*clock()/CLOCKS_PER_SEC<0.05);
}
