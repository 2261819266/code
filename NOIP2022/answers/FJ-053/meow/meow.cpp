#include<bits/stdc++.h>
#define ll long long
using namespace std;

void read(int &x) {
	x=0;
	int w=1;
	char ch;
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+(ch-48);
		ch=getchar();
	}
	x*=w;
}
int T;
int n,m,k;
//栈的个数、卡牌的个数、卡牌上图案的种类
int a[100001];
int stac[301][100001],top[100001];
int q[100001],qx[100001],qy[100001];
int be[100001];
int ans=2147484647;
int ansq[1000001],ansqx[100001],ansqy[100001];
int check() {
	int cnt=0;
	for(int i=1; i<=n; ++i)
		be[i]=1;
	int ddd=1;
	while(ddd) {
		ddd=0;
		for(int i=1; i<=n; ++i)
			for(int j=i+1; j<=n; ++j)
				if(top[i]>=be[i]&&top[j]>=be[j])
					if(i!=j&&stac[i][be[i]]==stac[j][be[j]]) {
						be[i]++;
						be[j]++;
						qx[++cnt]=i;
						qy[cnt]=j;
						ddd=1;
					}
		bool dd=1;
		for(int i=1; i<=n; ++i)
			if(be[i]<=top[i])dd=0;
		if(dd==1)return cnt;
	}
	return 0;
}
int tott=0;
void dfs(int x) {
//	tott++;
//	if(tott>1000000)return ;
	if(x==m+1) {
		int anss=check();
		if(anss<=m&&anss!=0) {
			ans=anss;
			for(int i=1; i<=m; ++i)
				ansq[i]=q[i];
			for(int i=1; i<=ans; ++i)
				ansqx[i]=qx[i],ansqy[i]=qy[i];
		}
//		ans=min(ans,check());
		return ;
	}
	if(ans!=2147483647)return ;
	for(int i=1; i<=n; ++i)
		if(stac[i][top[i]]==a[x]) {
			q[x]=i;
			top[i]--;
			dfs(x+1);
			stac[i][++top[i]]=a[x];
			q[x]=0;
		}
	for(int i=1; i<=n; ++i)
		if(stac[i][top[i]]!=a[x]) {
			q[x]=i;
			stac[i][++top[i]]=a[x];
			dfs(x+1);
			--top[i];
			q[x]=0;
		}
}
int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	read(T);
	for(int t=1; t<=T; ++t) {
		ans=2147483647;
		tott=0;
		memset(stac,0,sizeof(stac));
		memset(top,0,sizeof(top));
//			memset(top,0,sizeof(top));
		read(n);
		read(m);
		read(k);
//		ans=m/2+1;
		for(int i=1; i<=m; ++i)
			read(a[i]);
		dfs(1);
		cout<<ans+m<<"\n";
		for(int i=1; i<=m; ++i)
			cout<<"1"<<" "<<ansq[i]<<"\n";
		for(int i=1; i<=ans; ++i)
			cout<<"2"<<" "<<ansqx[i]<<" "<<ansqy[i]<<"\n";
//			cout<<
	}
}
/*
2
2 4 2
1 2 1 2
2 4 2
1 2 1 2
*/
