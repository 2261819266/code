#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	while(isdigit(c))x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return x*f;
}
const int N=1010,p=998244353;
char a[N][N];
int n,m,c[N][N],d[N][N],s[N],t[N];
int ans,res,C,F;
void solve()
{
	ans=res=0;
	n=read(),m=read(),C=read(),F=read();
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++){
		int len=0;
		for(int j=m;j>=1;j--){
			if(a[i][j]=='0')len++;
			else len=0;
			c[i][j]=len;
		}
	}
	for(int j=1;j<=m;j++){
		int len=0;
		for(int i=n;i>=1;i--){
			if(a[i][j]=='0')len++;
			else len=0;
			d[i][j]=len;
		}
	}
	//检查时间复杂度是否为 O(n^2) ，是，总司令！ 
	for(int j=1;j<=m-1;j++){ //枚举y0 
		int nex; 
		for(int i=1;i<=n-2;i=nex){ //枚举x1 
			//不可能形成 
			if(d[i][j]<3){
				nex=i+1;
				continue;
			}
			int len=d[i][j];
			s[i-1]=0;
			for(int k=i;k<=i+len-1;k++)s[k]=s[k-1]+c[k][j+1]; //预处理前缀和 
			for(int k=i;k<=i+len-3;k++)ans=(ans+c[k][j+1]*(s[i+len-1]-s[k+1]))%p; //枚举x1，统计答案。
			nex=i+len; 
		}
	}
	for(int j=1;j<=m-1;j++){ //枚举y0 
		int nex; 
		for(int i=1;i<=n-3;i=nex){ //枚举x1 
			//不可能形成 
			if(d[i][j]<4){
				nex=i+1;
				continue;
			}
			int len=d[i][j];
			s[i-1]=0;
			for(int k=i;k<=i+len-1;k++)s[k]=(s[k-1]+d[k][j]*c[k-1][j+1]%p)%p; //预处理前缀和 
			for(int k=i;k<=i+len-4;k++)res=(res+c[k][j+1]*(s[i+len-1]-s[k+2])%p)%p; //枚举x1，统计答案。
			nex=i+len; 
		}
	}
	printf("%lld %lld\n",(ans*C%p+p)%p,(res*F%p+p)%p);
}
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read();
	while(T--)solve();
	return 0;
}
