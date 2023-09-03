#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {
	ll ans=0,f=1;
	char x;
	x=getchar();
	while(!(('0'<=x&&x<='9')||x!='-')) {
		x=getchar();
	}
	if(x=='-') {
		f=-1;
		x=getchar();
	}
	while('0'<=x&&x<='9') {
		ans*=10;
		ans+=x-'0';
		x=getchar();
	}
	return ans*f;
}
const int N=2000110;
ll n,m,k;
ll a[N];
ll T;
int p=0;
vector<int> q[310];
int bs[2000010][3],cnt;
int z1[N],z2[N],cnt1=0,cnt2=0,l1=0,l2=0;
int dfs2(int x){
	if(p==1) return 0;
	if(x==m+1){
		if((cnt1-l1==0)&&(cnt2-l2==0)){
			p=1;
			for(int i=1;i<=cnt;i++){
				if(bs[i][0]==1) printf("1 %d\n",bs[i][1]);
				else printf("2 %d %d\n",bs[i][1],bs[i][2]);
			}
			return 0;
		}
		return 0;
	}
	int xi=0;
	if(z1[cnt1]!=a[x]||cnt1-l1==0)z1[++cnt1]=a[x];
	else {
		cnt1--;
		xi=1;
	}
	bs[++cnt][0]=1;
	bs[cnt][1]=1;
	dfs2(x+1);
	cnt--;
	if(xi==1){
		cnt1++;
	}
	else cnt1--;
	xi=0;
	if(z2[cnt2]!=a[x]||cnt2-l2==0)z2[++cnt2]=a[x];
	else {
		cnt2--;
		xi=1;
	}
	bs[++cnt][0]=1;
	bs[cnt][1]=2;
	dfs2(x+1);
	cnt--;
	if(xi==1){
		cnt2++;
	}
	else cnt2--;
	if(z1[l1]==z2[l2]&&!((cnt1-l1==0)&&(cnt2-l2==0))){
		l1++;
		l2++;
		bs[++cnt][0]=2;
		bs[cnt][1]=1;
		bs[cnt][2]=2;
		dfs2(x);
		l1--;
		l2--;
		cnt--;
	}
	return 0;
}
void solve(){
	if(n==2){
		dfs2(1);
	}
	return;
}
int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	for(int xsxs=0;xsxs<T;xsxs++) {
		cnt=0,cnt1=0,cnt2=0,l1=0,l2=0;
		n=read(),m=read(),k=read();
		for(int i=1; i<=m; i++) {
			a[i]=read();
		}
		solve();
	}
	return 0;
}
/*
1
2 4 2
1 2 1 2
*/
