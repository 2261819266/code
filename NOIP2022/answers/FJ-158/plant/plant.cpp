#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=998244353;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

char ch[N][N];
int h[N][N],l[N][N],n,m,c,f;
int s[N][N],ss[N][N],ansc,ansf;

//int qpow(int x,int y){int res=1;
//	for(;y;y>>=1;x=1ll*x*x%mod)
//		if(y&1)res=1ll*res*x%mod;
//	return res;
//}
//
//int C(int x,int y){
//	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
//}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
//	inv[0]=inv[1]=fac[0]=fac[1]=1;
//	for(int i=1;i<=1000000;i++)fac[i]=1ll*fac[i-1]*i%mod;
//	inv[1000000]=qpow(fac[1000000],mod-2);
//	for(int i=999999;i>1;i--)inv[i]=1ll*inv[i+1]*i%mod;
	int T=read(),id=read();while(T--){
		ansc=0,ansf=0;
		memset(h,0,sizeof(h));
		memset(l,0,sizeof(l));
		memset(s,0,sizeof(s));
		memset(ss,0,sizeof(ss));
		n=read(),m=read();c=read(),f=read();
		for(int i=1;i<=n;i++)scanf("%s",ch[i]+1);
		for(int i=1;i<=n;i++){
			h[i][m]=ch[i][m]=='0'?m+1:m;
			for(int j=m-1;j>=1;j--)
				h[i][j]=ch[i][j]=='0'?h[i][j+1]:j;
		}for(int i=1;i<=m;i++){l[n][i]=ch[n][i]=='0'?n+1:n;
			for(int j=n-1;j>=1;j--)
				l[j][i]=ch[j][i]=='0'?l[j+1][i]:j;
		}for(int i=1;i<=m;i++){
			s[n][i]=ch[n][i]=='0'?h[n][i]-i-1:0;
			for(int j=n-1;j>=1;j--)
				s[j][i]=s[j+1][i]+(ch[j][i]=='0'?h[j][i]-i-1:0);
		}
//			for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++)printf("%d ",l[i][j]);
//			printf("\n");
//		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j=l[j][i]+1){
				for(int k=l[j][i]-1;k>=j;k--)
					ss[k][i]=(ss[k+1][i]+1ll*(s[k][i]-s[k+1][i])*(l[j][i]-k-1)%mod)%mod;
//				printf("%d %d %d\n",i,j,l[i][j]+1);
				}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++)printf("%d ",ss[i][j]);
//			printf("\n");
//		}printf("\n");
//	
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=m;j++){
				int p=s[i][j]-s[i+1][j],q=ch[i][j]=='0'?l[i][j]-i-1:0;
				if(ch[i][j]=='1'||q<2)continue;
				int k=s[i+2][j]-s[i+q+1][j];
				ansc=(ansc+1ll*k*p%mod)%mod;
				ansf=(ansf+1ll*p%mod*((ss[i+2][j]-ss[l[i][j]][j]+mod)%mod)%mod)%mod;
//				printf("%d %d %d %d\n",i,j,p,k);
			}
		}printf("%d %d\n",1ll*ansc*c%mod,1ll*ansf*f%mod);
	}
}
