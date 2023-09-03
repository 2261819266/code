#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300+10;
const int inf = INT_MAX;
const int mod = 998244353;
int read(){
	char ch=getchar();
	int f=1,s=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return f*s;
}
int t,id,n,m,c,f;
namespace Task1{
	int dp[N][N][N];
	int dp2[N][N][N];
	int val[N][N];
	int d[N][N];
	int a[N][N];
	set<int>s[N];
	int ans1=0,ans2=0;
	void init(){
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		memset(val,0,sizeof(val));
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		for(int i=0;i<N;i++)s[i].clear();
		ans1=0,ans2=0;
	}
	void pre(){
		for(int i=1;i<=n;i++){
			string str;
			cin>>str;
			for(int j=1;j<=m;j++){
				if(str[j-1]=='0')a[i][j]=1;
				else s[j].insert(i);
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=m;j>=1;j--){
				if(!a[i][j])continue;
				val[i][j]=val[i][j+1]+a[i][j];
			}
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=m;j++)
	//			cout<<val[i][j]<<' ';
	//		cout<<'\n';
	//	}
		for(int i=n;i>=1;i--)
			for(int j=1;j<=m;j++){
				if(!a[i][j])continue;
				d[i][j]=d[i+1][j]+a[i][j];
			}
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=m;j++)
	//			cout<<d[i][j]<<' ';
	//		cout<<'\n';
	//	}
	}
	bool chech(int i,int l,int r){
		if(a[l][i]==0||a[r][i]==0)return 0;
		s[i].insert(l);
		auto x=s[i].upper_bound(l);
		if(x==s[i].end())return 1;
		for(;*x<r;x++)
			if(!a[*x][i])return 0;
		return 1;
	}
	void work(){
		if(c==0&&f==0){
			ans1=0,ans2=0;
			return;
		}
	//	cout<<chech(1,1,2)<<'\n';
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				for(int k=j+2;k<=n;k++){
					if(!chech(i,j,k))continue;
					dp[i][j][k]=max(0ll,(val[j][i]-1)*(val[k][i]-1));
					ans1=(ans1+dp[i][j][k])%mod;
				}
			}
		}
	//	cout<<dp[1][1][3]<<' '<<dp[1][1][4]<<'\n';
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				for(int k=j+2;k<=n;k++){
					dp2[i][j][k]=dp[i][j][k]*max(0ll,(d[k][i]-1));
					ans2=ans2+dp2[i][j][k]%mod;
				}
			}
		}
	//	cout<<d[3][1]<<'\n';
	//	cout<<dp2[1][1][3]<<' '<<dp2[1][1][4]<<'\n';
	}	
}
namespace Task2{
	int dp[3][1100][1100];
	int dp2[3][1100][1100];
	int val[1100][1100];
	int d[1100][1100];
	int a[1100][1100];
	set<int>s[1100];
	int ans1=0,ans2=0;
	void init(){
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		memset(val,0,sizeof(val));
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		for(int i=0;i<1100;i++)s[i].clear();
		ans1=0,ans2=0;
	}
	void pre(){
		for(int i=1;i<=n;i++){
			string str;
			cin>>str;
			for(int j=1;j<=m;j++){
				if(str[j-1]=='0')a[i][j]=1;
				else s[j].insert(i);
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=m;j>=1;j--){
				if(!a[i][j])continue;
				val[i][j]=val[i][j+1]+a[i][j];
			}
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=m;j++)
	//			cout<<val[i][j]<<' ';
	//		cout<<'\n';
	//	}
		for(int i=n;i>=1;i--)
			for(int j=1;j<=m;j++){
				if(!a[i][j])continue;
				d[i][j]=d[i+1][j]+a[i][j];
			}
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=m;j++)
	//			cout<<d[i][j]<<' ';
	//		cout<<'\n';
	//	}
	}
	bool chech(int i,int l,int r){
		if(a[l][i]==0||a[r][i]==0)return 0;
		s[i].insert(l);
		auto x=s[i].upper_bound(l);
		if(x==s[i].end())return 1;
		for(;*x<r;x++)
			if(!a[*x][i])return 0;
		return 1;
	}
	void work(){
		if(c==0&&f==0){
			ans1=0,ans2=0;
			return;
		}
	//	cout<<chech(1,1,2)<<'\n';
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				for(int k=j+2;k<=n;k++){
					if(!chech(i,j,k))continue;
					dp[i][j][k]=max(0ll,(val[j][i]-1)*(val[k][i]-1));
					ans1=(ans1+dp[i][j][k])%mod;
				}
			}
		}
	//	cout<<dp[1][1][3]<<' '<<dp[1][1][4]<<'\n';
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				for(int k=j+2;k<=n;k++){
					dp2[i][j][k]=dp[i][j][k]*max(0ll,(d[k][i]-1));
					ans2=ans2+dp2[i][j][k]%mod;
				}
			}
		}
	//	cout<<d[3][1]<<'\n';
	//	cout<<dp2[1][1][3]<<' '<<dp2[1][1][4]<<'\n';
	}	
}
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read(),id=read();
	while(t--){
		n=read(),m=read(),c=read(),f=read();
		if(m==2){
			Task2::init();
			Task2::pre();
			Task2::work();
			printf("%lld %lld\n",(Task2::ans1*c)%mod,(Task2::ans2*f)%mod);
		}
		else{
			Task1::init();
			Task1::pre();
			Task1::work();
			printf("%lld %lld\n",(Task1::ans1*c)%mod,(Task1::ans2*f)%mod);			
		}

	}	
	return 0;
}

