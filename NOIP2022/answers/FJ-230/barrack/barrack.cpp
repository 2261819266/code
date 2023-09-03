#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll ans=0,f=1;
	char x;
	x=getchar();
	while(!(('0'<=x&&x<='9')||x!='-')){
		x=getchar();
	}
	if(x=='-'){
		f=-1;
		x=getchar();
	}
	while('0'<=x&&x<='9'){
		ans*=10;
		ans+=x-'0';
		x=getchar();
	}
	return ans*f;
}
int n,m;
int book[10010];
struct q{
	int to;
	int x;
};
vector mp[3010];
void dfs(int x)
int main(){
//	freopen("barrack.in","r",stdin);
//	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	int u,v;
	q ls;
	for(int i=1;i<=m*2-1;i+=2){
		u=read(),v=read();
		ls.x=i;
		ls.to=v;
		mp[u].push_back(ls);
		ls.to=u;
		ls.x=i+1;
		mp[v].push_back(ls);
	}
	
	return 0;
}

