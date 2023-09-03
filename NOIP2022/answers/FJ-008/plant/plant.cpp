#include<bits/stdc++.h>
using namespace std;
#define maxn 1009
const long long mod=998244353;
int t,id,n,m,c,f,cnt1[maxn][maxn],cnt2[maxn][maxn],sumc[maxn][maxn],sumf[maxn][maxn];
long long ansc,ansf;
char s[maxn][maxn];
inline int read(){
	int sum=0,d=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')d=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*d;
}
void work(){
	ansc=ansf=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)sumc[i][j]=0,cnt1[i][j]=cnt2[i][j]=(s[i][j]=='0'?1:0);
	}
	for(int i=n;i>0;i--)for(int j=m;j>0;j--)if(s[i][j]=='0'){
		if(i+1<=n)cnt1[i][j]+=cnt1[i+1][j];
		if(j+1<=m)cnt2[i][j]+=cnt2[i][j+1];
	} 
	for(int i=n-2;i>0;i--)for(int j=m;j>0;j--)if(s[i][j]=='0'&&s[i+1][j]=='0'){
		sumc[i][j]=sumc[i+1][j]+max(cnt2[i+2][j]-1,0);
		if(sumc[i][j]>=mod)sumc[i][j]-=mod;
		sumf[i][j]=sumf[i+1][j]+1ll*max(cnt2[i+2][j]-1,0)*max(cnt1[i][j]-3,0)%mod;
		if(sumc[i][j]>=mod)sumc[i][j]-=mod;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='0'){
		ansc+=1ll*max(cnt2[i][j]-1,0)*sumc[i][j]%mod;
		ansc%=mod;
		ansf+=1ll*max(cnt2[i][j]-1,0)*sumf[i][j]%mod;
		ansf%=mod;
	}
	printf("%lld %lld\n",ansc*c%mod,ansf*f%mod);
	return ;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read();id=read();
	while(t--){
		n=read();m=read();c=read();f=read();
		for(int i=1;i<=n;i++)cin>>(s[i]+1);
		work();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
