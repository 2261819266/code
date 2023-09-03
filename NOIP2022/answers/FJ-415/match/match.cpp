#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
inline void dd(int &ss){
	ss=0;
	char ch=getchar();int ff=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ss=ss*10+ch-'0',ch=getchar();
	ss*=ff;	
}
const int N=300001;
ull ans,dp[3001][3001];
int t,n,a[N],b[N],q,mxa[3001][18],mxb[3001][18];
int qqq(int l,int r){
	int t=log(r-l+1)/log(2);
	int ma=max(mxa[l][t],mxa[r-(1<<t)+1][t]);
	int mb=max(mxb[l][t],mxb[r-(1<<t)+1][t]);
	return ma*mb;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	dd(t),dd(n);
	for(int i=1;i<=n;++i)dd(a[i]);
	for(int i=1;i<=n;++i)dd(b[i]);
	if(t<=2){
		dd(q);
		while(q--){
			int l,r;
			dd(l),dd(r);
			for(int p=l;p<=r;++p){
				for(int q=p;q<=r;++q){
					int ma=0,mb=0;
					for(int i=p;i<=q;++i)
					ma=max(ma,a[i]),mb=max(mb,b[i]);
					ans=ans+ma*mb;
				}
			}
			cout<<ans<<'\n';
			ans=0;
		}
		return 0;
	}
	if(t<=5){
		for(int i=1;i<=n;++i)
		mxa[i][0]=a[i],mxb[i][0]=b[i];
		for(int i=1;i<=15;++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
		mxa[j][i]=max(mxa[j][i-1],mxa[j+(1<<i-1)][i-1]),mxb[j][i]=max(mxb[j][i-1],mxb[j+(1<<i-1)][i-1]);
		for(int i=1;i<=n;++i)
		dp[i][i]=a[i]*b[i];
		for(int i=1;i<=n;++i){
			for(int l=1,r;l+i<=n;++l){
				r=l+i;
				dp[l][r]=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]+qqq(l,r);
			}
		}
		dd(q);
		int l,r;
		while(q--){
			dd(l),dd(r);
			cout<<dp[l][r]<<'\n';
		}
		return 0;
	}
}
