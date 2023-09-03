#include<bits/stdc++.h>
using namespace std;
int tt,n,m,k,s[2000001],net[2000001],cl[601],d[601],t[601],cn[4000001][3],tot;
bitset<601>ss;
bitset<2000001>sou;
deque<int>sk[601];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&tt);
	while(tt--)
	{
		tot=0;
		priority_queue< pair<int,int> >qq;
		set<int>q[3];
		ss.reset();
		sou.reset();
		fill(net+1,net+1+m,0);
		fill(cl+1,cl+1+k,0);
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;++i)
	    {	 
			q[0].insert(i);
			sk[i].clear();
		}
		for(int i=1;i<=k;++i)
		t[i]=d[i]=0;
		for(int i=1;i<=m;++i)
		{
			scanf("%d",&s[i]);
			if(cl[s[i]]&&ss[s[i]]==1)
			net[cl[s[i]]]=i;
			cl[s[i]]=i;
			ss[s[i]]=ss[s[i]]^1;
		}
		for(int i=1;i<=m;++i)
		{
			if(net[i]==0)
			{
				if(t[s[i]])
				{
					cn[++tot][0]=1;
					cn[tot][1]=t[s[i]];
					if(sk[t[s[i]]].size()==1)
					sou[net[sk[t[s[i]]][0]]]=1;
					else
					qq.push({net[sk[t[s[i]]][0]],t[s[i]]});
					q[sk[t[s[i]]].size()].erase(t[s[i]]);
					q[sk[t[s[i]]].size()-1].insert(t[s[i]]);
					sk[t[s[i]]].pop_back();
					if(sk[t[s[i]]].size()==0)
					d[s[i]]=t[s[i]]=0;
					else
					{
						t[s[sk[t[s[i]]][0]]]=t[s[i]];
						t[s[i]]=0;
					}
				}
				else if(d[s[i]])
				{
					cn[++tot][0]=1;
					cn[tot][1]=*q[0].begin();
					cn[++tot][0]=2;
					cn[tot][1]=d[s[i]];
					cn[tot][2]=*q[0].begin();
					qq.push({net[sk[d[s[i]]][1]],d[s[i]]});
					q[sk[d[s[i]]].size()].erase(d[s[i]]);
					q[sk[d[s[i]]].size()-1].insert(d[s[i]]);
					sk[d[s[i]]].pop_front();
					d[s[sk[d[s[i]]][0]]]=d[s[i]];
					d[s[i]]=0;
				}
			}
			else
			{
				if(q[0].size()>0)
				{
					int tp=*q[0].begin();
					sk[tp].push_back(i);
					d[s[i]]=tp;
					t[s[i]]=tp;
					qq.push({net[i],tp});	
					q[0].erase(tp);
					q[1].insert(tp);
					cn[++tot][0]=1;
					cn[tot][1]=tp;
				}
				else
				{
					while(sou[qq.top().first])
					qq.pop();
					int tp=qq.top().second;
					sk[tp].push_back(i);
					qq.pop();
					t[s[sk[tp][sk[tp].size()-2]]]=0;
					t[s[i]]=tp;
					q[1].erase(tp);
					q[2].insert(tp);
					cn[++tot][0]=1;
					cn[tot][1]=tp;
				}
			}
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;++i)
		if(cn[i][0]==1)
		printf("1 %d\n",cn[i][1]);
		else
		printf("2 %d %d\n",cn[i][1],cn[i][2]);
	}
	return 0;
}