#include<bits/stdc++.h>
#define int long long
#define pu push
#define pb push_back
#define ob pop_back
#define of pop_front
#define fr front
#define em empty
#define bk back
using namespace std;
struct cz{int op,a,b;}nm;
int d[310]={0},t[310]={0};
queue<int>ky;
queue<cz>ans;
stack<int>k1,k;
deque<int>q[310];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("meow1.in","r",stdin);//freopen("meow.out","w",stdout);
	int t1;cin>>t1;
	while(t1--)
	{
		int n,m,p;cin>>n>>m>>p;
		while(m--)
		{
			int a;cin>>a;
			k1.pu(a);
		}
		while(!k1.em())k.pu(k1.top()),k1.pop();
		if(n==2&&p==n*2-1)
		{
			for(int i=1;q[1].size()+q[2].size()<2;i++)
			{
				if(k.em())break;
				int a=k.top();k.pop();
				if(d[a])
				{
					nm.op=1;nm.a=1;ans.pu(nm);
					nm.op=2;nm.a=1;nm.b=d[a];ans.pu(nm);
					q[d[a]].of();
					if(q[d[a]].size()==1)
					{
						d[q[d[a]].front()]=d[a];
						t[q[d[a]].front()]=0;
					}
					d[a]=0;i--;
					continue;
				}
				if(t[a])
				{
					nm.op=1;nm.a=t[a];ans.pu(nm);
					q[t[a]].ob();t[a]=0;i--;
					continue;
				}
				if(q[1].size()==1)nm.op=1,nm.a=1,ans.pu(nm);
				else nm.op=1,nm.a=2,ans.pu(nm);
			}
			while(!k.em())
			{
				int a=k.top();k.pop();
				int b=k.top();k.pop();
				if(a==b)
				{
					nm.op=1;nm.a=1;ans.pu(nm);ans.pu(nm);
					continue;
				}
				if(!q[1].em()&&a==q[1].bk())
				{
					nm.op=1;nm.a=1;ans.pu(nm);ans.pu(nm);
					q[1].bk()=b;continue;
				}
				if(!q[2].em()&&a==q[2].bk())
				{
					nm.op=1;nm.a=2;ans.pu(nm);ans.pu(nm);
					q[2].bk()=b;continue;
				}
				if(!q[1].em()&&b==q[1].bk())
				{
					nm.op=1;nm.a=2;ans.pu(nm);
					nm.op=1;nm.a=1;ans.pu(nm);
					q[2].pb(a);q[1].ob();
				}
				if(!q[2].em()&&b==q[2].bk())
				{
					nm.op=1;nm.a=1;ans.pu(nm);
					nm.op=1;nm.a=2;ans.pu(nm);
					q[1].pb(a);q[2].ob();
				}
			}
			if(!q[1].em())nm.op=2,nm.a=1,nm.b=2,ans.pu(nm);
			cout<<ans.size()<<endl;
			while(!ans.em())
			{
				nm=ans.fr();ans.pop();
				if(nm.op==1)cout<<1<<' '<<nm.a<<endl;
				else cout<<2<<' '<<nm.a<<' '<<nm.b<<endl;
			}
			continue;
		}
		for(int i=2;i<=n;i++)ky.pu(i);
		while(!k.em())
		{
			int a=k.top();k.pop();
			if(d[a])
			{
				nm.op=1;nm.a=1;ans.pu(nm);
				nm.op=2;nm.a=1;nm.b=d[a];ans.pu(nm);
				q[d[a]].of();
				if(q[d[a]].size()==1)
				{
					d[q[d[a]].front()]=d[a];
					t[q[d[a]].front()]=0;
				}
				d[a]=0;ky.pu(d[a]);
				continue;
			}
			if(t[a])
			{
				nm.op=1;nm.a=t[a];ans.pu(nm);
				q[t[a]].ob();t[a]=0;
				ky.pu(t[a]);continue;
			}
			nm.op=1;nm.a=ky.fr();
			q[ky.fr()].pb(a);
			if(q[ky.fr()].size()==2)t[a]=ky.fr(),ky.pop();
			else d[a]=ky.fr();
		}
		cout<<ans.size()<<endl;
		while(!ans.em())
		{
			nm=ans.fr();ans.pop();
			if(nm.op==1)cout<<1<<' '<<nm.a<<endl;
			else cout<<2<<' '<<nm.a<<' '<<nm.b<<endl;
		}
	}
	return 0;
}
