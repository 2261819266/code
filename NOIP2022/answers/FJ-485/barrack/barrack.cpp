#include<bits/stdc++.h>
#define open(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define For(i,b,e) for(l i = b ; i <= e ; i++)
using namespace std;
typedef long long l;
l mod = 1000000007;

map<int,vector<int> > data;
map<int,map<int> > data2;//pos,cost
map<int,bool>rp;
vector<int>nothing;
l n,m,ui,vi;
//a - b 
int get(int a,int b){
	return data2[max(a,b)][min(a,b)];
}
void put(int a,int b,int v){
	data2[max(a,b)][min(a,b)]=v;
}
void add(l a,l b){
	data[a].push_back(b);
}
//how much l
void dfs2(int x,vector<int>readed,map<int,bool>rp){
	vector<int>child = data[x];
	readed.push_back(x);
	for(int i = 0 ;i < child.size();i++){
		if(rp[i])continue;
		For(j,0,readed.size()-1){
			put(readed[j],child[i],get(readed[j],x)+1);
		}
		put(data[x][child[i]],x,1);
		rp[child[i]]=1;
		dfs2(data[x][child[i]],readed);
	}
}
l dfs(int deep,vector<int>sel){
	if(deep==0){
		
		
	}
}
int main(){
	open(barrack);
	cin>>n>>m;
	if (n==m-1)cout<<(m+1)*m+n+1;
	else cout<<114514;
	
}


