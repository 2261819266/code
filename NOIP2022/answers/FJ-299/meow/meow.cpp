#include<bits/stdc++.h>
using namespace std;
int a,b,c,as[301],cs[301],d,e,ci,f,onum;
deque<int>bs[301];
struct onode
{
	int op,s1,s2;
	void make(int o,int s,int ss=0)
	{
		op=o;
		s1=s;
		s2=ss;
		return;
	}
	void out()
	{
		cout<<op<<' '<<s1;
		if(op==2)cout<<' '<<s2;
		cout<<endl;
		return;
	}
}outs[2000001];

void do1(int c,int s)
{
	outs[++onum].make(1,s);
	if(bs[s].front()!=c)bs[s].push_front(c);
	else bs[s].pop_front();
	return;
}

void do2(int s1,int s2)
{
	outs[++onum].make(2,s1,s2);
	bs[s1].pop_back();bs[s2].pop_back();
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++,ci=onum=0)
	{
		for(int j=1;j<=b;j++)
		{
			for(;bs[j].size();)bs[j].pop_back();
		}
		for(int j=1;j<=d;j++)
		{
			cs[j]=0;
		}
		cin>>b>>c>>d;
		switch(a%10)
		{
			case 1:
				for(int j=1;j<=c;j++)
				{
					cin>>e;
					if(!cs[e])do1(e,(e+1)/2),cs[e]=1,ci++;
					else
					{
						cs[e]=0;
						if(bs[(e+1)/2].front()==e)do1(e,(e+1)/2),ci++;
						else
						{
							ci+=2;
							do1(e,b);
							do2((e+1)/2,b);
						}
					}
				}
				break;
			case 2:
				for(int j=1;j<=c;j++)
				{
					cin>>e;
					if(e<3)
					{
						if(bs[1].size()==0)do1(e,1),ci++;
						if(e==bs[1].front())do1(e,1),ci++;
						else if(e==bs[1].back())do1(e,2),do2(1,2),ci+=2;
						else do1(e,1),ci++;
					}
					else
					{
						j++;
						cin>>f;
						if(f==3)do1(e,1),do1(f,1),ci++;
						break;
					}
				}
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
		}
		cout<<ci<<endl;
		for(int j=1;j<=onum;j++)
		{
			outs[j].out();
		}
	}		
	return 0;
}
