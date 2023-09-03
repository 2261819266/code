#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
int n,m,u,v;
vector<int> a[50005];

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	return 0;
}

//I love NOIP!!!!!!!!
//I love CCF!!!!!!!!!
//**!!!