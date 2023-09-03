#include<bits/stdc++.h>
#define int long long
#define re register
#define il inilne
#define For(i,a,b) for(re int i=a;i<=b;++i)
#define pre(i,a,b) for(re int i=a;i>=b;--i)
using namespace std;
const int N = 1005,P = 998244353;
int T,n,m,c,f,id,ans1,ans2;
int r[N][N],up[N][N],le[N][N],ri[N][N],a[N][N];
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T>>id;
	while(T--){
		cin>>n>>m>>c>>f;
		ans1=ans2=0;
		memset(r,0,sizeof(r));
		memset(up,0,sizeof(r));
		memset(le,0,sizeof(r));
		memset(ri,0,sizeof(r));
		memset(a,0,sizeof(a));
		For(i,1,n){
			string s;
			cin>>s;
			For(j,1,m) a[i][j]=(s[j-1]-'0');
		}
		For(i,1,n) pre(j,m,1)
			if(!a[i][j]) r[i][j]=(r[i][j+1]+1)%P;
		For(i,3,n) For(j,1,m)
			if((!a[i][j])&&(!a[i-1][j])&&(!a[i-2][j]))
				up[i][j]=(up[i-1][j]+r[i-2][j]-1)%P;
		For(i,1,n) For(j,1,m){
			if(!a[i][j]){
				le[i][j]=(le[i][j-1]+up[i][j-1])%P;
				ri[i][j]=(ri[i-1][j]+up[i-1][j]*(r[i-1][j]-1)%P)%P;
				ans1=(ans1+le[i][j])%P;
				ans2=(ans2+ri[i][j])%P;
			}
		}
		cout<<ans1*c<<'\n'<<ans2*f;
	}
	return 0;
}




