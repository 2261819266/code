#include<bits/stdc++.h>
using namespace std;
int n,m,ans,idx;
struct qwq {
	int next,to;
} a[2000010];
int pre[2000010];
void add(int x1,int x2) {
	++idx;
	a[idx].to=x2;
	a[idx].next=pre[x1];
	pre[x1]=idx;
}
int main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	ans+=2*n;
	for(int i=1,x,y; i<=m; i++) {
		cin>>x>>y;
		//	add(x,y);
		//	add(y,x);
	}
	for(int i=2; i<=n; i++) {
		ans+=(n-i+1);
	}
	cout<<ans;
	return 0;
}
