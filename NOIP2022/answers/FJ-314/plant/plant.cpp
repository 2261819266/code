#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const long long mod = 998244353;
long long resc,resf,c_row[1010][1010],c_col[1010][1010];
char mp[1010][1010];
int t,id,n,m,c,f;
inline void calc_c(int j) {
	int a=0,b=0;
	long long mul = 0;
	while(a<=n&&b<n) {
		b++;
		if(mp[b][j]=='0') {
			mul += c_row[b][j] - 1;
		} else {
			while(a+1<b) {
				a++;
				mul -= c_row[a][j] - 1;
				resc = (resc + (mul - c_row[a+1][j] + 1) * (c_row[a][j] - 1) % mod) % mod;
			}
			a = b;
		}
	}
	while(a+1<b) {
		a++;
		mul -= c_row[a][j] - 1;
		resc = (resc + (mul - c_row[a+1][j] + 1) * (c_row[a][j] - 1) % mod) % mod;
	}
	a = b;
}
inline void calc_f(int j) {
	int a=0,b=0;
	long long mul = 0;
	while(a<n&&b<n-1) {
		b++;
		if(mp[b][j]=='0') {
			mul += (c_row[b][j] - 1) * (c_col[b][j] - 1);
		} else {
			while(a+1<b) {
				a++;
				mul -= (c_row[a][j] - 1) * (c_col[a][j] - 1);
				resf = (resf + (mul - (c_row[a+1][j] - 1) * (c_col[a+1][j] - 1)) * (c_row[a][j] - 1) % mod) % mod;
			}
			a = b;
		}
	}
	while(a+1<b) {
		a++;
		mul -= (c_row[a][j] - 1) * (c_col[a][j] - 1);
		resf = (resf + (mul - (c_row[a+1][j] - 1) * (c_col[a+1][j] - 1)) * (c_row[a][j] - 1) % mod) % mod;
	}
	a = b;
}
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d %d",&t,&id);
	while(t--) {
		memset(c_row,0,sizeof(c_row));
		memset(c_col,0,sizeof(c_col));
		resc = resf = 0;
		scanf("%d %d %d %d",&n,&m,&c,&f);
		for(int i=1; i<=n; i++)	scanf("%s",mp[i]+1);
		for(int i=1; i<=n; i++)
			for(int j=m; j>=1; j--)
				if(mp[i][j]=='0')	c_row[i][j] = c_row[i][j+1] + 1;
				else c_row[i][j] = 0;
		for(int j=1; j<=m; j++)
			for(int i=n; i>=1; i--)
				if(mp[i][j]=='0')	c_col[i][j] = c_col[i+1][j] + 1;
				else c_col[i][j] = 0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				c_row[i][j] = max(c_row[i][j],1ll),
				              c_col[i][j] = max(c_col[i][j],1ll);
		//prnt();
		for(int j=1; j<=m; j++) calc_c(j);
		for(int j=1; j<=m; j++) calc_f(j);
		printf("%lld %lld\n",resc,resf);
	}
	return 0;
}
/* I love zxl forever */
