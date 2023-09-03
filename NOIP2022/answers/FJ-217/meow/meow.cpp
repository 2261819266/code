/*
k=6 n=4

cards:1 2 3 4 5 6
4 5 6
1 2 3 
*/
//15pts??? 
#include <bits/stdc++.h>
using namespace std;
const int maxn=1000;
deque<int>p[maxn];
const int maxm=2e6+10;
int a[maxm];
inline int read()
{
	char ch=getchar();
	int x=0;
	while(!isdigit(ch))
	ch=getchar();
	while(isdigit(ch))
	x=x*10+ch-'0',ch=getchar();
	return x;
}
vector<int>ans[maxm];
int cnt=0;
void add1(int l)
{
	ans[++cnt].push_back(l);
}
void add2(int l,int r)
{
	ans[++cnt].push_back(l);
	ans[cnt].push_back(r);
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,k;
		cnt=0;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
		p[i].clear();
		if(k==2*n-2)
		{
			for(int i=1;i<=m;i++)
			a[i]=read();
			for(int i=1;i<=m;i++)
			{
				bool ok=0;
				for(int ii=1;ii<n;ii++)
				if(!ok&&p[ii].size()&&p[ii].back()==a[i])
				{
				p[ii].pop_back(),ok=1;
				add1(ii);
				//cout<<"perform 1"<<'\n';
				}
				if(!ok)
				{
					bool ok2=0;
					for(int ii=1;ii<n;ii++)
					if(p[ii].size()!=2)
					{
					p[ii].push_back(a[i]),ok2=1;
					add1(ii);
					//cout<<"perform 2"<<'\n';
					}
					if(!ok2)
					{
						for(int ii=1;ii<n;ii++)
						if(p[ii].front()==a[i])
						{
							add1(n);
							add2(ii,n);
							//cout<<"perform 3"<<'\n';
							break;
						}
					}
				}
			}
			cout<<cnt<<'\n';
			for(int i=1;i<=cnt;i++)
			{
				cout<<ans[i].size()<<' ';
				for(auto x:ans[i])
				cout<<x<<' ';
				cout<<'\n';
				ans[i].clear();
			}
		}
	}
}
/*
2 
2 4 2
1 2 1 2
2 4 2
1 2 1 2
*/
