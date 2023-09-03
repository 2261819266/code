#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m,k,a,dwn[601],top[601],o,op[4000001],x[4000001],y[4000001];
list<int>li[301];
set<int>dn[601],tp[601];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		o=0;
		for(int i=1;i<=n;i++)
		{
			li[i].clear();
			dwn[i]=top[i]=0;
			dn[i].clear();
			tp[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			cin>>a;
			if(top[a])
			{
				top[a]--;
				int u=*(tp[a].begin());
				li[u].pop_back();
				tp[a].erase(tp[a].begin());
				if(li[u].size())
				{
					int v=li[u].back();
					top[v]++;
					tp[v].insert(u);
				}
				else
				{
					dwn[a]--;
					dn[a].erase(u);
				}
				op[++o]=1;
				x[o]=u;
			}
			else if(dwn[a])
			{
				dwn[a]--;
				int u=*(dn[a].begin());
				li[u].pop_front();
				dn[a].erase(dn[a].begin());
				if(li[u].size())
				{
					int v=li[u].front();
					dwn[v]++;
					dn[v].insert(u);
				}
				else
				{
					top[a]--;
					tp[a].erase(u);
				}
				op[++o]=1;
				x[o]=u+1;
				op[++o]=2;
				x[o]=u;
				y[o]=u+1;
			}
			else
			{
				if(li[1].size())
				{
					int u=li[1].back();
					top[u]--;
					tp[u].erase(1);
					top[a]++;
					tp[a].insert(1);
					li[1].push_back(a);
				}
				else
				{
					top[a]++;
					tp[a].insert(1);
					dwn[a]++;
					dn[a].insert(1);
					li[1].push_back(a);
				}
				op[++o]=1;
				x[o]=1;
			}
		}
		cout<<o<<'\n';
		for(int i=1;i<=o;i++)
		{
			cout<<op[i]<<' '<<x[i]<<' ';
			if(op[i]==2)
				cout<<y[i];
			cout<<'\n';
		}
	}
	return 0;
}
//1
//1
//4
//5
//1
//4
//
//1
//9
//1
//9
//8
//1
//0
//
//xzh AK NOIp
//hyx AK NOIp
//wkc AK NOIp
//jxw AK NOIp
//wk AK NOIp
//sbh AK NOIp
//cyc AK NOIp
//ycz AK NOIp
