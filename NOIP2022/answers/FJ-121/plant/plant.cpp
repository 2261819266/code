#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1009][1009];
ll rt[1009][1009];
ll dn[1009][1009];
ll cnt[1009][1009];//shuxiangqianzhuihe
ll ans[1009][1009];
ll Up[1009][1009];
const ll Mod=998244353;
map<int,set<int> > h,s;//heng shu
int read(){
	int out=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		out=(out<<3)+(out<<1)+(c^48);
		c=getchar();
	}
	if(f) return out;
	return ~(out-1);
}
void D(){
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			rt[i][j]=dn[i][j]=cnt[i][j]=ans[i][j]=Up[i][j]=a[i][j]=0;
	h.clear();s.clear();
}
int main(){
	int T,id,n,m,c,f;ll ansc,ansf;
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();id=read();
	while(T--){
		n=read();m=read();c=read();f=read();
		char x;ansc=ansf=0;
		D();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf(" %c",&x);
				a[i][j]=x^48;
				if(a[i][j]) h[i].insert(j),s[j].insert(i);
			}
		for(int i=1;i<=n;i++) h[i].insert(0),h[i].insert(m+1);
		for(int j=1;j<=m;j++) s[j].insert(0),s[j].insert(n+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(a[i][j]) continue;
				auto it=h[i].upper_bound(j);
				rt[i][j]=*it-j-1;
				it=s[j].upper_bound(i);
				dn[i][j]=*it-i-1;
				it=s[j].lower_bound(i);it--;
				Up[i][j]=i-*it-1;
			}
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++){
				if(a[i][j]) continue;
				cnt[i][j]=cnt[i-1][j]+rt[i][j];
			}
		for(int i=1;i<=n;i++)//count C
			for(int j=1;j<=m;j++){
				if(a[i][j]||dn[i][j]<=1) continue;
				ans[i][j]=rt[i][j]*(cnt[i+dn[i][j]][j]-cnt[i+1][j])%Mod;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ansc=(ansc+ans[i][j])%Mod;
		ansc=(ansc+Mod)%Mod;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans[i][j]=0;
		for(int i=1;i<=n;i++)//count F
			for(int j=1;j<=m;j++){
				if(a[i][j]||dn[i][j]==0||Up[i][j]<=1) continue;
				ans[i][j]=rt[i][j]*(cnt[i-2][j]-cnt[i-Up[i][j]-1][j])%Mod*dn[i][j]%Mod;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ansf=(ansf+ans[i][j])%Mod;
		ansf=(ansf+Mod)%Mod;
		if(c==0) ansc=0;
		if(f==0) ansf=0;
		printf("%lld %lld\n",ansc,ansf);
	}
	return 0;
}
