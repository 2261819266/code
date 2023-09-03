#include<bits/stdc++.h>
using namespace std;
#define fr(i,j,k) for(int i=j;i<=k;i++)
#define dr(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
const int N = 1e6+10;
const int mod = 1e9+7;
const int M = 5e5+10;
void file(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	return;
}
inline int read(){
	int x=0,f=1;char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*f;
}
//------------------------------------
int n,m,u[N],v[N];
int book[20];
int t1,t2,t3;
ll ans,c[M],jc[M];
ll f[M],cf[M],ad[M];
//---------------------------------------
void ycl(){
	jc[1] = 1;jc[0] = 1;
	fr(i,2,20)jc[i] = jc[i-1]*i%mod;
	fr(i,1,20)fr(j,1,i)
	{
		c[i] = (c[i]+jc[i]/(jc[j]*jc[i-j]))%mod;
	}
	return;
}
//-------------------------------------
void dfs(int now,int sum){
	if(now==m+1){
		ans = (ans+c[sum])%mod;
		return;
	}
	dfs(now+1,sum);
    t3 = sum;
	book[u[now]]++;
	book[v[now]]++;
	t3 += (book[u[now]]==1)+(book[v[now]]==1);
	dfs(now+1,t3);
	book[u[now]]--;
	book[v[now]]--;
	return;
}
//------------------------------------
signed main(){
	file();
    n=read();m=read();
    ycl();
//    fr(i,1,20)cout<<c[i]<<' ';
    fr(i,1,m){
    	u[i] = read();
    	v[i] = read();
	}
	if(m<=0){
		dfs(1,0);
		printf("%lld",ans);
	}
	else {
		cf[1] = 2;
		f[1] = 1;
		ad[1] = 0;
		fr(i,2,n){
			cf[i] = cf[i-1]*2%mod;
			ad[i] = (ad[i-1]+i-1)%mod;
			f[i] = (3*f[i-1]%mod+cf[i-1]-ad[i-1])%mod;
		}
		printf("%lld",f[n]);
	}
	
	return 0;
}

