#include<bits/stdc++.h>
%:line 3 "Suruka"//Luogu User
using namespace std;
#define fr(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using ll = long long;
constexpr ll mod = 998244353;
#define m(x) (((x)%mod)+mod)%mod
ll T,id,n,m,c,f,ans=0,ans2=0;
char g[1005][1005];
set<int>nw[1005],ok[1005];
signed main(){
	fr(plant);
	scanf("%lld%lld",&T,&id);
	while(scanf("%lld%lld%lld%lld",&n,&m,&c,&f),T--){
		for(int i=0;i<n;i++)scanf("%s",g+i),g[i][m]=0,nw[i].clear(),nw[i].insert(m);
		for(int i=0;i<m;i++)ok[i].clear(),ok[i].insert(n);
		ans=0,ans2=0;
		for(int i=0;i<n;i++)for(int j=0,k=0;j<m;j++)if(g[i][j]=='1')ok[j].insert(i),nw[i].insert(j);
		for(int i=0;i<n;i++){
			for(int j=i+2;j<n;j++){
				for(int k=0;k<m;k++){
					if(g[i][k]=='0'&&g[j][k]=='0'){
						ll a=*nw[i].lower_bound(k)-1,b=*nw[j].lower_bound(k)-1;
						if(a-k<1||b-k<1)continue;
						for(int l=0;l<min(a-k,b-k);l++){
							if(*ok[k+l].lower_bound(i)<=j)continue;
							ans=m(ans+m((a-k-l)*(b-k-l))),ans2=m(ans2+m(m((a-k-l)*(b-k-l))*(*ok[k+l].lower_bound(i)-j-1)));
						}k=max(a,b)+1;
					}
				}
			}
		}
		printf("%lld %lld\n",c*ans,f*ans2);
	}
	return 0;
}

