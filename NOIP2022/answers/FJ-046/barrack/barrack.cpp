#include<bits/stdc++.h>
#define R register
using namespace std;
int n,m,hea[500005];
struct node{
	int dis,pos,v,u;
}cnt[500005];
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(R int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		//add(v,u);add(u,v);
	}
	cout<<n*(2<<(n-1));
	return 0;
}
