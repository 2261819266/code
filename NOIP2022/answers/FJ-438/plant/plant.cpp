#include<bits/stdc++.h>
#define MAXN 1017
#define debug(x) cout<<#x<<" is "<<x<<endl;
using namespace std;
const int mod = 998244353;
int T,id,n,m,c,f;
string s[MAXN];
int xt[MAXN][MAXN],yt[MAXN][MAXN];
long long ansc,ansf;
//xt:x y yt:y x
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		for(int i=1;i<=n;i++){
			int now = m;
			for(int j=m-1;j>=0;j--){
				if(s[i][j] == '0') xt[i][j+1] = now-j;
				else now = j;
			}
		}
		for(int j=0;j<m;j++){
			int now = n+1;
			for(int i=n;i>=1;i--){
				if(s[i][j] == '0'){
					yt[j+1][i] = now-i;
				}
				else now = i;
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				for(int k=i+2;k<i+yt[j][i];k++){
					if(xt[i][j]>=2 && xt[k][j]>=2){
						ansc += (xt[i][j]-1)*(xt[k][j]-1)%mod;
						ansf += (xt[i][j]-1)*(xt[k][j]-1)*(i+yt[j][i]-1-k)%mod;
						ansc%=mod,ansf%=mod;
					}
				}
			}
		}
		cout<<ansc<<" "<<ansf<<endl;
	}
	return 0;
}
