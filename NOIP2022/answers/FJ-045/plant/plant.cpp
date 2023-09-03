#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1001,mod=998244353;
int nex[N][N],pre[N][N];
bool a[N][N];
int ans1,ans2;
inline int read(){
	int x=0;char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x;
}
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read();
	while(T--){
	int n=read(),m=read(),c=read(),f=read();ans1=0;ans2=0;
	memset(a,0,sizeof(a));
	memset(nex,0,sizeof(nex));
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=n;i++){
		char c=getchar();a[i][m+1]=1;
		while(c!='1'&&c!='0') c=getchar();
		a[i][1]=c-'0';
		for(int j=2;j<=m;j++){
			c=getchar();
			a[i][j]=c-'0';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--)
		 if(a[i][j]!=1)
		  nex[i][j]=nex[i][j+1]+(a[i][j+1]^1);
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i>=1;i--)
		 if(a[i][j]!=1)
		  pre[i][j]=pre[i+1][j]+1;
	}
	for(int j=1;j<=m;j++){
	int sum=0;
	for(int i=2;i<=n;i++){
		sum+=nex[i-2][j];sum%=mod;
		if(a[i][j]==1||a[i-1][j]==1||a[i-2][j]==1) sum=0;
		ans1+=sum*nex[i][j];ans1%=mod;
		ans2+=(sum*nex[i][j])%mod*(pre[i][j]-1)%mod;ans2%=mod;
	}
    }
    cout<<(ans1*c)%mod<<' '<<(ans2*f)%mod<<'\n';
    }
	return 0;
}
