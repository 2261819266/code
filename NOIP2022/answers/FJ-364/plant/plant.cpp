#include <bits/stdc++.h>
using namespace std;
unsigned long long t,id,n,m,c,f,cl[1005][1005],fl[1005][1005],fh[1005][1005],ansc,ansf;
const long long mod =  998244353;
char mp[1005][1005];
bool u[1005][1005],g[1005][1005];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t>>id;
	while(t--){
		memset(cl,0,sizeof(cl));
		memset(fl,0,sizeof(fl));
		memset(fh,0,sizeof(fh));
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>mp[i][j];
				mp[i][j]-=48;
			}
		}
		//C
		if(c){
			for(int i=1;i<n-1;++i){
				for(int j=1;j<m;++j){
					if(mp[i][j]||cl[i][j]||u[i][j]) continue;
					memset(cl,0,sizeof(cl));
					for(int k=i;k<=n;++k){
						if(mp[k][j]) break;
						u[k][j]=1;
						for(int l=j+1;l<=m;++l){
							if(mp[k][l]) break;
							cl[k][j]++;
						}
					}
					for(int k=i;k<=n;++k){
						for(int l=k+2;l<=n;++l){
							if(mp[l][j]) break;
							ansc=(ansc+cl[k][j]*cl[l][j])%mod;
						}
					}
				}
			}
		}
		//F
		if(f){
			for(int i=1;i<n-1;++i){
				for(int j=1;j<m;++j){
					if(mp[i][j]||fl[i][j]||fh[i][j]||g[i][j]) continue;
					memset(fl,0,sizeof(fl));
					memset(fh,0,sizeof(fh));
					for(int k=i;k<=n;++k){
						if(mp[k][j]) break;
						g[k][j]=1;
						for(int l=j+1;l<=m;++l){
							if(mp[k][l]) break;
							fl[k][j]++;
						}
						for(int l=k-1;l>=i;l--){
							if(mp[l][j]) break;
							fh[l][j]++;
						}
					}
					for(int k=i;k<=n;++k){
						for(int l=k+2;l<=n;++l){
							if(mp[l][j]) break;
							ansf=(ansf+fl[i][j]*fl[l][j]*fh[l][j])%mod;
						}
					}
				}
			}
		}
		cout<<ansc*c<<" "<<ansf*f<<'\n';
	}
	return 0;
}
