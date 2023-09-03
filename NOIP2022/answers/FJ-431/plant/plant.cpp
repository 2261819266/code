#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int t,id,n,m,c,f,i,j;
long long h[1005][1005],s[1005][1005],sum[1005][1005],sumf[1005][1005],ans1,ans2;
bool bo[1005][1005];
string ss;
inline long long modd(long long x,long long y){x+=y;return x>mod?(x-mod):x;}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>id;
	while(t--){
		ans1=ans2=0;
		memset(h,0,sizeof(h));
		memset(s,0,sizeof(s));
		memset(sum,0,sizeof(sum));
		memset(sumf,0,sizeof(sumf));
		cin>>n>>m>>c>>f;
		for(i=1;i<=n;i++){
			cin>>ss;
			for(j=0;j<m;j++) bo[i][j+1]=ss[j]-48;
		}
		for(i=n;i;i--)
			for(j=m;j;j--){
				if(bo[i][j]) continue;
				if(!bo[i][j+1]&&j<m) h[i][j]=h[i][j+1]+1;
				if(!bo[i+1][j]&&i<n) s[i][j]=s[i+1][j]+1;
			}
		for(i=n;i;i--)
			for(j=m;j;j--){
				if(bo[i][j]) continue;
				sum[i][j]=sum[i+1][j]+h[i][j];
				sumf[i][j]=sumf[i+1][j]+h[i][j]*s[i][j];
			}
		if(!c) cout<<0<<' ';
		else{
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++){
					if(h[i][j]&&sum[i+2][j]&&!bo[i+1][j]) ans1=modd(ans1,(h[i][j]*sum[i+2][j])%mod);
				}
			cout<<ans1<<' ';
		}
		if(!f) cout<<0;
		else{
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
					if(h[i][j]&&sumf[i+2][j]&&!bo[i+1][j]) ans2=modd(ans2,(h[i][j]*sumf[i+2][j])%mod);
			cout<<ans2<<' ';
		}
	}
	return 0;
}
