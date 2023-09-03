#include<bits/stdc++.h>
using namespace std;
const int N=1000001;
int n,m,ans;
int tot,he[N],ver[N],ne[N];
int a[N];
void add(int x,int y)
{
	ver[++tot]=y;
	ne[tot]=he[x];
	he[x]=tot;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
		a[x]++;a[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		tot+=1<<a[i];
	}
	cout<<tot-m<<endl;
	
	return 0;
}
