#include<bits/stdc++.h>
using namespace std;
struct tmp
{
	int typ,x;
};
struct ct
{
	int typ,a,b;
};
int T,n,m,k;
int a[2000010];
vector <int> q[305];
vector <ct> ans;
map <int,tmp> mp;
void slove1()
{
	int cnt=1,op=0;
	while(m--)
	{
		if(mp.find(a[m])==mp.end())
		{
			ans.push_back(ct{1,cnt,0});
			op++;
			mp[a[m]]=tmp{q[cnt].empty()?0:1,cnt};
			q[cnt].push_back(a[m]);
			while(q[cnt].size()>1)
			{
				cnt++;
				if(cnt==n) 
				{
					cnt=1;
					break;
				}
			}
			continue;
		}
		if(mp[a[m]].typ==1 || q[mp[a[m]].x].size()==1)
		{
			ans.push_back(ct{1,mp[a[m]].x,0});
			op++;
			q[mp[a[m]].x].pop_back();
			mp.erase(a[m]);
			cnt=mp[a[m]].x;
		}
		if(mp[a[m]].typ==0)
		{
			ans.push_back(ct{1,n,0});
			ans.push_back(ct{2,mp[a[m]].x,n});
			op+=2;
			int xb=mp[a[m]].x;
			int zhuan=q[xb].back();
			q[xb].clear();
			q[xb].push_back(zhuan);
			mp[zhuan].typ=0;
			mp.erase(a[m]);
			cnt=xb;
			continue;
		}
	}
	printf("%d\n",op);
	for(auto i=ans.begin();i!=ans.end();i++)
	{
		ct tpp=*i;
		if(tpp.typ==1) printf("1 %d\n",tpp.a);
		if(tpp.typ==2) printf("2 %d %d\n",tpp.a,tpp.b);
	}
	ans.clear();
}
void slove2()
{
	int op=0,cntm=m;
	m++;
	while(cntm--)
	{
		m=cntm+1;
//		cout<<a[m]<<" ";
//		cout<<m<<endl;
		if(q[1].empty() && q[2].empty())
		{
			ans.push_back(ct{1,1,0});
			op++;
			mp[a[m]]=tmp{0,1};
			q[1].push_back(a[m]);
			continue;
		}
		
		if(mp.find(a[m])!=mp.end())
		{	
//			printf("a=%d wei=%d typ=%d\n",a[m],mp[a[m]].x,mp[a[m]].typ);
			if(mp[a[m]].typ==1 || q[mp[a[m]].x].size()==1)
			{
				ans.push_back(ct{1,mp[a[m]].x,0});
				op++;
				q[mp[a[m]].x].pop_back();
				mp.erase(a[m]);
				continue;
			}
			if(mp[a[m]].typ==0)
			{
				ans.push_back(ct{1,mp[a[m]].x==1?0:1,0});
				ans.push_back(ct{2,mp[a[m]].x,mp[a[m]].x==1?0:1});
				op+=2;
				q[3].push_back(q[mp[a[m]].x].back());
				q[mp[a[m]].x]=q[3];
				mp[q[3].back()].typ=0;
				q[3].clear();
				mp.erase(a[m]);
				continue;
			}
		}
		else
		{
			if((q[1].size()+q[2].size())==1)
			{
				int weiz=q[1].size()==0?1:2;
//				printf("a=%d weiz=%d\n",a[m],weiz);
				ans.push_back(ct{1,weiz,0});
				op++;
				mp[a[m]]=tmp{0,weiz};
				q[weiz].push_back(a[m]);
				continue;
			}
			if(a[m]==a[m-1])
			{
				ans.push_back(ct{1,1,0});
				ans.push_back(ct{1,1,0});
				op+=2;
				m--;
				continue;
			}
			if(q[1].size()!=q[2].size())
			{
				if(mp[a[m-1]].typ==0)
				{
					int weiz=mp[a[m-1]].x;
					ans.push_back(ct{1,weiz,0});
					ans.push_back(ct{1,weiz==1?2:1,0});
					ans.push_back(ct{2,weiz,weiz==1?2:1});
					op+=3;
					int Tmp=q[weiz].back();
					q[weiz].clear();
					q[weiz].push_back(Tmp);
					q[weiz].push_back(a[m]);
					mp[Tmp].typ=0;
					mp[a[m]].typ=1;
					mp[a[m]].x=weiz;
					mp.erase(a[m-1]);
					m--;
					continue;
				}
				if(mp[a[m-1]].typ==1)
				{
					int weiz=mp[a[m-1]].x==1?2:1;
					ans.push_back(ct{1,weiz,0});
					op++;
					mp[a[m]]=tmp{q[weiz].size()==0?0:1,weiz};
					q[weiz].push_back(a[m]);
					continue;
				}
			}
			else
			{
				int weiz=mp[a[m-1]].x==1?2:1;
				ans.push_back(ct{1,weiz,0});
				op++;
				mp[a[m]]=tmp{1,weiz};
				q[weiz].push_back(a[m]);
				continue;
			}
		}
	}
	printf("%d\n",op);
	for(auto i=ans.begin();i!=ans.end();i++)
	{
		ct tpp=*i;
		if(tpp.typ==1) printf("1 %d\n",tpp.a);
		if(tpp.typ==2) printf("2 %d %d\n",tpp.a,tpp.b);
	}
	ans.clear();
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	int t=T;
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		mp.clear();
		for(int i=1;i<=n;i++) q[i].clear();
		for(int i=m;i>=1;i--) scanf("%d",&a[i]);
		if(T%10==1) 
		{
			slove1();
			continue;
		}
		if(T%10==2) 
		{
			slove2();
			continue;
		}
		slove1();
		
	}
	
	
	
	return 0;
}

