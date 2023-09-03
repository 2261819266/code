#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=1005;
const ll mod=998244353;
ll raw[N][N],col[N][N];
ll dp[N][N],ret[N][N],cnt[N][N],dpf[N][N];
vector<ll> retf[N][N];
bool mp[N][N];
int n,m,c,f;
void readmp(){
	char ch;
	for(ll i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ch='@';raw[i][j]=col[i][j]=dp[i][j]=ret[i][j]=cnt[i][j]=dpf[i][j]=0;
			retf[i][j].clear();
			while(ch!='0'&&ch!='1')ch=getchar();
			if(ch=='0')mp[i][j]=1;
			else mp[i][j]=0;
		}
	}
}
void solveraw(){
	for(int i=1;i<=n;i++){
		if(mp[i][m])raw[i][m]=m;
	}
	for(int i=1;i<=n;i++){
		for(int j=m-1;j>=1;j--){
			if(mp[i][j]==1&&mp[i][j+1]==1)raw[i][j]=raw[i][j+1];
			else if(mp[i][j]==0)raw[i][j]=0;
			else raw[i][j]=j;
		}
	}
}
void solvecol(){
	for(int i=1;i<=m;i++){
		if(mp[n][i])col[i][n]=n;
	}
	for(int i=1;i<=m;i++){
		for(int j=n-1;j>=1;j--){
			if(mp[j][i]==1&&mp[j+1][i]==1)col[i][j]=col[i][j+1];
			else if(mp[j][i]==0)col[i][j]=0;
			else col[i][j]=j;
		}
	}
}
int main(){
	int T,id;
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		readmp();
		if(c==0&&f==0){
			printf("0 0\n");
			continue;
		}
		solveraw();solvecol();
		
		//raw:n-2 col:m-1
		for(int j=m-1;j>=1;j--){
			if(raw[n][j]>j){
				ret[n][j]=raw[n][j]-j;
				cnt[n][j]=1;
				retf[n][j].push_back(n);
			}
		}
		for(int j=m-1;j>=1;j--){
			if(raw[n-1][j]>j){
				ret[n-1][j]=raw[n-1][j]-j;
				cnt[n-1][j]=1;
				retf[n-1][j].push_back(n-1);	
			}
			if(ret[n][j]>0){
				ret[n-1][j]+=ret[n][j];
				cnt[n-1][j]++;
				retf[n-1][j].push_back(n);
			}
		}
		for(int i=n-2;i>=1;i--){
			for(int j=m-1;j>=1;j--){
				if(raw[i][j]>j){
					if(col[j][i]==col[j][i+2]){
						dp[i][j]=(raw[i][j]-j)*ret[i+2][j]%mod;
						ret[i][j]+=(raw[i][j]-j);
						cnt[i][j]++;
					}
					else ret[i][j]=raw[i][j]-j,cnt[i][j]=1;
				}
				if(col[j][i]==col[j][i+1])ret[i][j]+=ret[i+1][j],cnt[i][j]++;
			}
		}
		if(f==0){
			ll ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					ans=(ans+dp[i][j])%mod;
				}
			}
			printf("%lld 0\n",ans*c);
			continue;
		}
		for(int i=n-2;i>=1;i--){
			for(int j=m-1;j>=1;j--){
				if(col[j][i]==col[j][i+1]){
					retf[j][i]=retf[j][i+1];
				}
				if(raw[i][j]>j){
					if(col[j][i]==col[j][i+2]){
						retf[i][j]=retf[i+2][j];
						for(unsigned int k=0;k<retf[i][j].size();k++){
							dpf[i][j]+=(raw[i][j]-j)*(raw[retf[i][j][k]][j]-j)%mod*(col[j][i]-retf[i][j][k])%mod;
							dpf[i][j]%=mod;
						}
					}
					retf[i][j].push_back(i);
				}
				
			}
		}
		long long ans=0,ansf=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans=(ans+dp[i][j]);
				ansf=(ansf+dpf[i][j])%mod;	
			}
			
		}
		printf("%lld %lld\n",ans*c,ansf*f);
	}
	return 0;
}
