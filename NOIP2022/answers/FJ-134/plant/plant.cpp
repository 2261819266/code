#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=2e3+10;
const ll mod =998244353;
int n,m,c,f;
char s[N][N];
ll cnt[N][N];
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read();
	while(T--){
		n=read();m=read();c=read();f=read();
		for(int i=1;i<=n+2;i++)
		    for(int j=1;j<=m+2;j++)
		        cnt[i][j]=0;
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
			    if(s[i][j]=='0') cnt[i][j]=1;
		    for(int j=m-1;j>=1;j--)
		        if(s[i][j]=='0') cnt[i][j]+=cnt[i][j+1];
		}
		ll ansc=0,ansf=0;
		   for(int j=1;j<=m-1;j++){
		   	   int l=0,r=0;
		   	   ll now=0,nf=0;
		   	   while(r<n){
		   	   	    l=0;
		   	   	    now=0;nf=0;
		   	   		for(int i=r+1;i<=n;i++){
		   	   			if(cnt[i][j]>=2&&!l) l=i;
		   	   			if(cnt[i][j]>=1) r=i;
		   	   			if(cnt[i][j]==0) break;
						if(i-l>=2) now=(now+cnt[i][j]-1)%mod;
					}
					if(r<l+2||!l){
					   while(cnt[r+1][j]==0&&r<=n) r++;
					   continue;
					}
					for(int i=l+2;i<=r;i++)
					    nf=(nf+(cnt[i][j]-1)*(r-i)%mod)%mod;
					for(int i=l;i<=r;i++){
						if(cnt[i][j]>=2&&i+2<=r) 
						   ansc=(ansc+(cnt[i][j]-1)*now%mod)%mod;
						if(cnt[i][j]>=2&&i+3<=r) 
						   ansf=(ansf+(cnt[i][j]-1)*nf%mod)%mod;
						if(i+2<=r&&cnt[i+2][j]>=2) 
						   now=((now-cnt[i+2][j]+1)%mod+mod)%mod,
						   nf=(nf-(cnt[i+2][j]-1)*(r-(i+2))%mod+mod)%mod;
					}
					while(cnt[r+1][j]==0&&r<=n) r++;
					//cout<<l<<" "<<r<<" "<<now<<" "<<nf<<endl;
			   }
			   //cout<<j<<" "<<ansc<<" "<<ansf<<endl;
		   }	
		printf("%lld %lld\n",ansc*c,ansf*f);
	}
	return 0;
}
