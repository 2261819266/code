#include<bits/stdc++.h>
using namespace std;
#define fr(i,j,k) for(int i=j;i<=k;i++)
#define dr(i,j,k) for(int i=j;i>=k;i--)
#define int long long
const int N = 1e3+10;
const int mod = 998244353;
void file() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	return;
}
inline int read() {
	int x;
	scanf("%lld",&x);
	return x;
}
//------------------------------------
int T,id,n,m,a[N][N],b[N][N];
int t1[N][N],t2[N][N];
char s[N];
int last1,last2,c,f;
int ans1,ans2;
//------------------------------------
signed main() {
	file();
	T = read();id = read();
	while(T--) {
		n=read();m=read();
		c=read();f=read();
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		fr(i,1,n) {
			scanf("%s",s);
			fr(j,1,m)a[i][j] = s[j-1]-'0';
		}
		fr(i,1,n)dr(j,m,1) {
			if(!a[i][j])t1[i][j] = t1[i][j+1]+1;
			else t1[i][j] = 0;
		}
		fr(j,1,m)dr(i,n,1) {
			if(!a[i][j])t2[i][j] = t2[i+1][j]+1;
			else t2[i][j] = 0;
		}
		fr(j,1,m) {
			last1 = last2 = 0;
			fr(i,1,n) {
				if(!a[i][j]) {
					if(last1 == 0) {
						last1 = t1[i][j];
						last2 = 0;
						continue;
					}
					ans1 = (ans1+(t1[i][j]-1)*last2%mod)%mod;
					ans2 = (ans2+(t1[i][j]-1)*last2%mod*t2[i+1][j]%mod)%mod;
					last2 += last1-1;
					last2 %= mod;
					last1 = t1[i][j];
				} 
				else last1 = last2 = 0;
			}
		}
		printf("%lld %lld\n",c*ans1,f*ans2);
	}
	return 0;
}
