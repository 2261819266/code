#include"stdio.h"
#define reg register
// #define getchar()(inBuf==lenBuf?lenBuf=(inBuf=Buf)+fread(Buf,1,1<<20,stdin):0,inBuf==lenBuf?EOF:*inBuf++)
char Buf[1<<20],*inBuf,*lenBuf;
template<class T>void read(T&x){reg char ch,f=x=0;while(ch=getchar(),ch<'0'||ch>'9');while(x=x*10+(ch&15),ch=getchar(),ch<='9'&&ch>='0');f?x=-x:0;}
#define mod 998244353
int T,n,m,c,f;
char s[1010][1010];
int R[1010],nx[1010];
int F(int i,int x){
    if(x<=i)return 0;
    return x-i;
}
main(){
     freopen("plant.in","r",stdin);
     freopen("plant.out","w",stdout);
    for(read(T),read(n);T--;){
        read(n),read(m),read(c),read(f);
        for(reg int i=1;i<=n;++i)scanf("%s",s[i]+1);
        int ans=0;
        if(c){
            for(reg int i=1;i<=n;++i)R[i]=m;
            for(reg int i=m;i;--i){
                for(reg int j=1;j<=n;++j)if(s[j][i]=='1')R[j]=i-1;
                int sm=0;
                for(reg int j=1;j<=n;++j){
                    if(j>2)sm=(sm+F(i,R[j-2]))%mod;
                    if(j>2&&R[j-2]<i)sm=0;
                    ans=(ans+1ll*F(i,R[j])*((j>1&&R[j-1]<i)||R[j]<i?0:sm))%mod;
                }
            }
        }
        printf("%d ",ans);
        ans=0;
        if(f){
            for(reg int i=1;i<=n;++i)R[i]=m;
            for(reg int i=m;i;--i){
                for(reg int j=1;j<=n;++j)if(s[j][i]=='1')R[j]=i-1;
                nx[n]=s[n][i]=='1'?n-1:n;
                for(reg int j=n-1;j;--j)if(s[j][i]=='1')nx[j]=j-1;else nx[j]=nx[j+1];
                // for(reg int j=1;j<=n;++j)printf("%d ",nx[j]);puts("");
                int sm=0;
                for(reg int j=1;j<=n;++j){
                    if(j>2)sm=(sm+F(i,R[j-2]))%mod;
                    if(j>2&&R[j-2]<i)sm=0;
                    int t=1ll*sm*(nx[j]-j)%mod;
                    ans=(ans+1ll*F(i,R[j])*((j>1&&R[j-1]<i)||R[j]<i?0:t))%mod;
                }
            }
        }
        printf("%d\n",ans);
    }
}
