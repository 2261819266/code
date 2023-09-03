/*
	LINGFUNNY I KNOW YOU ARE READING THIS.
	LINGFUNNY AK IOI
	TONY AK IOI
	/hsh
*/ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1000+5;
const int mod=998244353;
int n,m,_C,_F,testid;
char G[maxn][maxn];
int leftgo[maxn][maxn];
int lgqz[maxn][maxn];
int lgqzA[maxn][maxn];
int downgo[maxn][maxn];
int calc_c(int x,int y){
	if(G[x][y]=='1')return 0;
	int ans=0;
	if(downgo[x][y]<2)return 0;
	int A=leftgo[x][y];
	ans=(ans+1ll*(A-1)*(lgqz[x+2][y]-lgqz[x+downgo[x][y]][y])%mod)%mod;
	return ans;
}
int calc_f_term1(int x,int y){
	if(G[x][y]=='1')return 0;
	int ans=0;
	if(downgo[x][y]<2)return 0;
	int A=leftgo[x][y];
	int R=A-1;
	ans=(ans+1ll*R*downgo[x][y]%mod*(lgqz[x+2][y]-lgqz[x+downgo[x][y]][y])%mod)%mod;
	return ans;
}
int calc_f_lgab(int x,int y){
	if(G[x][y]=='1')return 0;
	int ans=0;
	if(downgo[x][y]<2)return 0;
	int A=leftgo[x][y];
	int R=A-1;
	ans=(ans+1ll*R%mod*(lgqzA[x+2][y]-lgqzA[x+downgo[x][y]][y])%mod)%mod;
	return ans;
}
int calc_f_lgabx(int x,int y){
	if(G[x][y]=='1')return 0;
	int ans=0;
	if(downgo[x][y]<2)return 0;
	int A=leftgo[x][y];
	int R=A-1;
	ans=(ans+1ll*R*x%mod*(lgqz[x+2][y]-lgqz[x+downgo[x][y]][y])%mod)%mod;
	return ans;
}
int calc_f_last(int x,int y){
	if(G[x][y]=='1')return 0;
	int ans=0;
	if(downgo[x][y]<2)return 0;
	int A=leftgo[x][y];
	int R=A-1;
	ans=(ans+1ll*R*(lgqz[x+2][y]-lgqz[x+downgo[x][y]][y])%mod)%mod;
	return ans;
}
int calc_F(int x,int y){
	int ans=calc_f_term1(x,y);
	ans=(ans-((calc_f_lgab(x,y)-calc_f_lgabx(x,y))%mod+calc_f_last(x,y)%mod))%mod;
	ans+=mod,ans%=mod;
	return ans;
}
void sol(){
	memset(lgqz,0,sizeof(lgqz));
	memset(lgqzA,0,sizeof(lgqzA));
	memset(leftgo,0,sizeof(leftgo));
	memset(downgo,0,sizeof(downgo));
	memset(G,0,sizeof(G));
	cin>>n>>m>>_C>>_F;
	if(_C==0&&_F==0)return cout<<'0'<<' '<<'0'<<endl,void();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>G[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(G[i][j]=='1')leftgo[i][j]=0;
			else leftgo[i][j]=leftgo[i][j+1]+1;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i;i--){
			if(G[i][j]=='1')downgo[i][j]=0;
			else downgo[i][j]=downgo[i+1][j]+1;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i;i--){
			lgqz[i][j]=((lgqz[i+1][j]+leftgo[i][j]-1)%mod+mod)%mod;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=n;i;i--){
			lgqzA[i][j]=(lgqzA[i+1][j]+(leftgo[i][j]-1)*i%mod)%mod;
		}
	}
	int Fs=0,Cs=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)Cs+=calc_c(i,j),Cs%=mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)Fs+=calc_F(i,j),Fs%=mod;
	}
	cout<<(Cs*_C)%mod<<' '<<(Fs*_F)%mod<<endl;
}
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout); 
	ios::sync_with_stdio(0);
	int t;cin>>t>>testid;while(t--)sol();
	return 0;
} 
