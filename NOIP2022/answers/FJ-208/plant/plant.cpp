#include<bits/stdc++.h>
#define maxn 1010
#define mod 998244353
using namespace std;

typedef long long ll;


inline ll read(){
	ll n=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') n=n*10+ch-'0',ch=getchar();
	return n;
}

inline void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+'0');
	return ;
}

ll T,id,n,m,c,f;

ll mp[maxn][maxn];
bool fg[maxn][maxn];
ll ansc,ansf;

inline void dfs1(ll mg,ll yk,ll n1,ll m1){
	if(mg>n||yk>m||fg[mg][yk]==1) return ;
	fg[mg][yk]=1;
	if(mp[mg][yk]==0){
		ll cnt1=0,cnt2=0,cntt=0;
		for(ll i=1;i<=n1-1;i++){
			if(mp[mg+i][yk]==1||mg>=n) break;
			else cnt1++;
		}
		for(ll i=1;i<=m1-1;i++){
			if(mp[mg][yk+i]==1||yk>=m) break;
			if(mp[mg][yk+i]!=1) cntt++;
		}
		for(ll i=2;i<=cnt1;i++){
			cnt2=0;
			for(ll j=1;j<=m1-1;j++){
				if(mp[mg+i][yk+j]==1||yk>=m) break;
				if(mp[mg+i][yk+j]!=1) cnt2++;
			}
			ansc+=cnt2*cntt;
		}	
	}
	dfs1(mg+1,yk,n1-1,m1);
	dfs1(mg,yk+1,n1,m1-1);	
}

inline void dfs2(ll mg,ll yk,ll n1,ll m1){
	if(mg>n||yk>m||fg[mg][yk]==1) return ;
	fg[mg][yk]=1;
	ll cnt1=0,cnt2=0,cnt3=0;
	if(mp[mg][yk]==0){
		for(ll i=1;i<=n1-1;i++){
			if(mp[mg+i][yk]==1||mp[mg+i+1][yk]==1||mg>=n||mg+i>n||mg+i+1>n) break;
			else cnt1++;
		}
		for(ll i=1;i<=m1-1;i++){
			if(mp[mg][yk+i]==1||yk>=m) break;
			if(mp[mg][yk+i]!=1) cnt2++;
		}
		for(ll i=2;i<=cnt1;i++){
			cnt3=0;
			for(ll j=1;j<=m1-1;j++){
				if(mp[mg+i][yk+j]==1||yk>=m) break;
				if(mp[mg+i][yk+j]!=1) cnt3++;
			}
				ansf+=cnt2*cnt3*(cnt1-1);
		}
	}
	
	dfs2(mg+1,yk,n1-1,m1);
	dfs2(mg,yk+1,n1,m1-1);
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--){
		ansc=0,ansf=0;
		n=read(),m=read(),c=read(),f=read();
		for(ll i=1;i<=n;i++){
			string mids;
			cin>>mids;
			for(ll j=0;j<(ll)mids.size();j++){
				mp[i][j+1]=mids[j]-'0';
			}
		}
		
		if(c!=0) dfs1(1,1,n,m);
		memset(fg,0,sizeof(fg));
		if(f!=0) dfs2(1,1,n,m);
		print((ansc*c)%mod);putchar(' ');
		print((ansf*f)%mod);puts(" ");
		if(T==0) break; 
	}
	return 0;
}

/*我是某校的IMing，我来传递IMing思想，比如180充6张月卡，段八拿下，或者说公车上书，洋务运动等事件。总而言之，IMing将会遍布天下！*/
 
