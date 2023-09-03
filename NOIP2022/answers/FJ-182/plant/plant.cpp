#include<bits/stdc++.h>
#define F(i,x,n) for(int i=x;i<=n;++i)
#define _F(i,x,n) for(int i=x;i>=n;--i)
#define ll long long
#define ull unsgined long long
#define lson x<<1
#define rson x<<1|1
#define lowbit(x) x&-x
using namespace std;

inline int read(){
	int s=0;char c=getchar();bool flag=0;
	while(!isdigit(c))flag|=(c=='-'),c=getchar();
	while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return flag?-s:s;
}

const int N=1e3+5;//数组不要开小，记得检查。 
const int mod=998244353;

int a[N][N],r[N][N],d[N][N];
int T,id,n,m,c,f;
ll sum1,sum2;

void solve(){
	ll sum;
	F(j,1,m){
		sum=0;
		F(i,1,n){
			if(a[i][j]==2){sum=0;continue;}
			else if(i>=3&&a[i][j]==1&&a[i-1][j]==1&&a[i-2][j]==1)sum=(sum+r[i-2][j]-j+mod)%mod;
			sum1=(sum1+sum*(r[i][j]-j)%mod)%mod;
			sum2=(sum2+sum*(r[i][j]-j)%mod*(d[i][j]-i)%mod)%mod;
		}		
	}
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--){
		n=read(),m=read(),c=read(),f=read();sum1=0,sum2=0;
		F(i,1,n){
			string s;
			cin>>s;
			F(j,0,m-1){
				if(s[j]=='0')a[i][j+1]=1;
				else a[i][j+1]=2;
			}
		}
		F(i,1,n){
			_F(j,m,1){
				if(a[i][j+1]==1&&a[i][j]!=2)r[i][j]=max(j,r[i][j+1]);
				else r[i][j]=j;
			}
		}
		F(j,1,m){
			_F(i,n,1){
				if(a[i+1][j]==1&&a[i][j]!=2)d[i][j]=max(i,d[i+1][j]);
				else d[i][j]=i;
			}
		}
		solve();
		printf("%lld %lld\n",c*sum1%mod,f*sum2%mod);
	}
	return 0;
}
//等下测一下全 0 
