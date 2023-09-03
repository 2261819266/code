#include <bits/stdc++.h>
using namespace std;
const int N=250100;
const int inf=0x3f3f33f;

#define ULL unsigned long long

int dp[N][20][2];//a=1,b=2
int lg[20];

int getmax(int l,int r,int x){
	int k=lg[r-l+1];
	return max(dp[l][k][x],dp[r+1-(1<<k)][k][x]);
}
	  
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n,Q;cin>>T>>n;
	for(int i=1;i<=n;i++) cin>>dp[i][0][1];
	for(int i=1;i<=n;i++) cin>>dp[i][0][2];
	for(int i=1;i<=log2(n);i++) lg[i]=int(log2(i));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=lg[n-i+1];j++){
			dp[i][j][1]=max(dp[i][j-1][1],dp[i+(1<<(j-1))][j-1][1]);
			dp[i][j][2]=max(dp[i][j-1][2],dp[i+(1<<(j-1))][j-1][2]);
		}
	cin>>Q;
	while(Q--){
		int amax,bmax;
		ULL ans=0;
		int l,r;cin>>l>>r;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				amax=getmax(i,j,1);
				bmax=getmax(i,j,2);
				ans+=amax*bmax;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
