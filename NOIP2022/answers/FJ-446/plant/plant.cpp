#include <bits/stdc++.h>
using namespace std;
int a[1010][1010],sumh[1010][1010],sumz[1010][1010],p[1010][1010],pp[1010][1010],t,id,n,m,c,f;
long long ans=0,anss=0;
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	char c;
	scanf("%d%d",&t,&id);
	while(t--) {
		cin>>n>>m>>c>>f;
		memset(a,0,sizeof(a));
		memset(sumh,0,sizeof(sumh));
		memset(sumz,0,sizeof(sumz));
		memset(p,0,sizeof(p));
		memset(pp,0,sizeof(pp));
		ans=0;
		anss=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>c;
				if(c=='0')a[i][j]=0;
				else a[i][j]=1;
			}
		}
		if(c==0&&f==0) {
			printf("0 0\n");
			return 0;
		}
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				sumz[j][i]=sumz[j-1][i]+a[j][i];
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				sumh[i][j]=sumh[i][j-1]+a[i][j];
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(a[i][j]==1)continue;
				int cnt=0;
				for(int k=j+1; k<=m; k++) {
					if(sumh[i][k]!=sumh[i][j])break;
					else cnt++;
				}
				p[i][j]=cnt;
			}
		}
		for(int i=1; i<=m-1; i++) {
			for(int j=1; j<=n-2; j++) {
				for(int k=j+2; k<=n; k++) {
					if(sumz[k][i]==sumz[j][i])ans=(ans+p[k][i]*p[j][i])%998244353;
				}
			}
		}
		cout<<ans<<" ";
		if(f==0) {
			cout<<"0"<<endl;
			return 0;
		}
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n-1; j++) {
				if(a[j][i]==1)continue;
				int cnt=0;
				for(int k=j+1; k<=n; k++) {
					if(sumz[k][i]!=sumz[j][i])break;
					else cnt++;
				}
				pp[j][i]=cnt;
			}
		}
		for(int i=1; i<=m-1; i++) {
			for(int j=1; j<=n-2; j++) {
				for(int k=j+2; k<=n; k++) {
					if(sumz[k][i]==sumz[j][i])anss=(anss+p[k][i]*p[j][i]*pp[k][i])%998244353;
				}
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}
