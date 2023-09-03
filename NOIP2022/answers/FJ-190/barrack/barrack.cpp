#include<bits/stdc++.h>

using namespace std;
const int N=1e6+10;
struct node{
	int to,nxt;
}e[N*2];
int head[N]={0},tot;
int n,m;

void add(int u,int v){
	e[++tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	
	return 0;
}
