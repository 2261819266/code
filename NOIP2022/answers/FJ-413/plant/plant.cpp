#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int t, id, n, m, c, f, a[1010][1010], b[1010][1010], C, F;
bool d[1010][1010];
int cc[1010], ff[1010], _c, _f;
string s;
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--) {
		cin>>n>>m>>c>>f;
		if (c==0&&f==0) {
			cout<<0<<" "<<0<<endl;
			continue;
		}
		for (int i=1; i<=n; ++i) {
			cin>>s;
			for (int j=0; j<s.length(); ++j)
				d[i][j+1]=s[j]-'0';
		}
		for (int i=1; i<=n+1; ++i) d[i][m+1]=1;
		for (int j=1; j<=m+1; ++j) d[n+1][j]=1;
		for (int i=1; i<=n; ++i) {
			for (int j=m+1; j>=1; --j) {
				if (d[i][j]==1) {
					while(d[i][j]==1) --j;
					a[i][j]=0;
				}
				else a[i][j]=a[i][j+1]+1;
			}
		}
		for (int i=1; i<=m; ++i) {
			for (int j=n+1; j>=1; --j) {
				if (d[j][i]==1) {
					while(d[j][i]==1) --j;
					b[j][i]=0;
				}
				else b[j][i]=b[j+1][i]+1;	
			}
		}
		for (int i=1; i<=m-1; ++i) {
			for (int j=1; j<=n; ++j) {
				if (d[j][i]==1) continue;
				int k=b[j][i];
				_c=0; _f=0;
				for (int x=j; x<=j+k; ++x) 
					if (a[x][i]!=0) cc[++_c]=x;
				for (int x=j; x<=j+k-1; ++x) 
					if (a[x][i]!=0) ff[++_f]=x;
				for (int x=1; x<=_c-1; ++x) {
					for (int y=x+1; y<=_c; ++y) {
						if (cc[y]-cc[x]>1) C=(C+a[cc[x]][i]*a[cc[y]][i])%mod;
					}
				}
				for (int x=1; x<=_f-1; ++x) {
					for (int y=x+1; y<=_f; ++y) {
						if (ff[y]-ff[x]>1) F=(F+a[ff[x]][i]*a[ff[y]][i]*b[ff[y]][i])%mod;
					}
				}
				j=j+k+1;
			}
		}
		cout<<c*C<<" "<<f*F<<endl;	
	}
	return 0;
}
