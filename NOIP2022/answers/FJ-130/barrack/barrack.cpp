#include <bits/stdc++.h>
using namespace std;
int mod=1000000007;
int d[5010][5010],dd[5010][5010];
int jy[5010][5010],jyy[5010][5010];
int er[500010];
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m; cin>>n>>m; er[0]=1;
	for(int j=1;j<=n;j++)
		er[j]=er[j-1]*2%mod;
	if(m==n-1){
		for(int i=1;i<=m;i++){
			int u,v; cin>>u>>v;
			if(i==m){
				long long ans=0;
				ans=n*er[n-1]%mod;
				for(int j=n-1;j>=1;j--)
					ans=(ans+er[n-1-j]*er[j-1]*j)%mod;
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	memset(d,0x3f,sizeof(d));
	long long ans=0;
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++){
		int u,v; cin>>u>>v;
		d[u][v]=d[v][u]=1;
		dd[u][v]=dd[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					jy[i][j]=jy[i][k]+jy[k][j]+1;
				}
//				if(dd[i][j]<dd[i][k]+dd[k][j]){
//					dd[i][j]=dd[i][k]+dd[k][j];
//				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<dd[i][j]<<" ";
//		cout<<endl;
//	}
	ans=n*er[m]%mod;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ls1=m-d[i][j];
			int ls2=jy[i][j];
			ans=(ans+er[ls2]*er[ls1]%mod);
		}
	}
	cout<<ans<<endl;
	return 0;
}
