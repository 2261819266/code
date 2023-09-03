#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=5010,mod=1e9+7;
ll n,m,ans=0;
ll ch[maxn],rh[maxn],f[maxn];
struct node{
	ll x,y;
};
node e[maxn];

ll find(ll x){
	if(f[x]!=x)
		f[x]=find(f[x]);
	return f[x];
}
void chooseroad(int y,int chx){
//	for(int i=1;i<=y;i++)
//		cout<<rh[i]<<" ";
//	cout<<"\n";
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=y;i++)
		f[find(e[rh[i]].x)]=find(e[rh[i]].y);
	for(int i=1;i<=n;i++)
		find(i);	
	bool ye=true;
	for(int i=1;i<=chx;i++)
		if(f[ch[1]]!=f[ch[i]])
			ye=false;
	if(ye==true)
	{
		ans++;
//		for(int i=1;i<=chx;i++)
//			cout<<ch[i]<<" ";
//		cout<<"\n";
//		for(int i=1;i<=y;i++)
//			cout<<e[rh[i]].x<<" "<<e[rh[i]].y<<"\n";
//		cout<<"\n";
	}
	for(int i=rh[y]+1;i<=m;i++)
		rh[y+1]=i,chooseroad(y+1,chx);
	return ;
}
void choosepoint(int x){
	if(x>0)
	{
		chooseroad(0,x);
//		for(int i=1;i<=x;i++)
//			cout<<ch[i]<<" ";
//		cout<<"\n";
	}
	for(int i=ch[x]+1;i<=n;i++)
		ch[x+1]=i,choosepoint(x+1);
	return ;
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);			 cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].x>>e[i].y;
		if(e[i].x>e[i].y)
			swap(e[i].x,e[i].y);
	}
	choosepoint(0);
	cout<<ans;
	
	return 0;
}
