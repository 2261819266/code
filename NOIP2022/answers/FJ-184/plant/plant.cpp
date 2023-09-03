#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e3+5;
const int Mod=998244353;
ll n,m,c,f,ansc,ansf;
int down[N][N],r[N][N];
int mp[N][N];
void chushi();
//I Love You CMQ
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ll t,id,td;
	char w;
	cin>>t>>td;
	while(t--) {
		if(td==1){
			cout<<"0 0\n";
			continue;
		}
		cin>>n>>m>>c>>f;
		chushi();
		if(c||f) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=m; j++) {
					cin>>w;
					if(w=='1')mp[i][j]=0;
					else mp[i][j]=1;
				}
			}
			for(int i=1; i<=n; i++) {
				r[i][m]=0;
				for(int j=m-1; j>=1; j--) {
					if(mp[i][j]&&mp[i][j+1])r[i][j]=r[i][j+1]+1;
					else r[i][j]=0;
				}
			}
			for(int j=1;j<=m&&td!=15;j++) {
				for(int i=n-1; i>=1; i--) {
					if(mp[i][j]&&mp[i+1][j])down[i][j]=down[i+1][j]+1;
					else down[i][j]=0;
				}
			}
			if(c) {
				c%=Mod;
				for(int k=1; k<m; k++) {
					for(int i=1; i<=n-2; i++) {
						for(int j=i+1; j<=n; j++) {
							if(mp[i][k]&&mp[j][k]) {
								if(j-i>1) {
									id=r[i][k]*r[j][k];
									ansc+=id;
									ansc%=Mod;
									if(td!=15){
										id*=down[j][k];
										id%=Mod;
										ansf+=id;
										ansf%=Mod;
									}
								} else continue;
							} else break;
						}
					}
				}
			}
			cout<<(c*ansc)%Mod<<' '<<(f*ansf)%Mod<<'\n';
		} else cout<<"0 0\n";
	}
	return 0;
}
void chushi() {
	//多测不清空，爆零两行泪
	ansc=0,ansf=0;
	for(int i=1; i<=m; i++) {
		down[n][i]=0;
	}
}
