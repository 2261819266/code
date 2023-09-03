#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
bool Mbe;
bool File(string Name)
{
	string In=Name+".in",Out=Name+".out";
	freopen(In.c_str(),"r",stdin);
	freopen(Out.c_str(),"w",stdout);
	return true;
}
bool fle=File("meow");
typedef int Type; // change here
Type rd()
{
	Type s=0;
	int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void wr(Type x)
{
	if(x<0)
	putchar('-'),x=-x;
	if(x>9)
	wr(x/10);
	putchar(x%10+'0');
}
void wr_space(Type x)
{
	wr(x);
	putchar(' ');
}
void wr_endl(Type x)
{
	wr(x);
	putchar('\n');
}
int T=rd(),TT=T;
int num=0,n,m,k,a[1000001];
int addr[1001],st[1001][2];
vector<int> Spare;
vector<pair<pair<int,int>,int> > Step;
void Init()
{
	// Hello
}
void Input()
{
	memset(st,0,sizeof(st));
	memset(addr,-1,sizeof(addr));
	n=rd(),m=rd(),k=rd();
	if(TT%10==1)
	{
		num=0;
		for(int i=1,t;i<=m;i++)
		{
			t=rd();
			if(~addr[t])
			{
				if(addr[t]&1 || st[addr[t]/2+1][1]==0)
				{
					Step.push_back(make_pair(make_pair(1,addr[t]/2+1),0)),
					Spare.push_back(addr[t]);
					if(st[addr[t]/2+1][1]==0)
					st[addr[t]/2+1][0]=0,Spare.push_back(addr[t]-1);
					else
					st[addr[t]/2+1][1]=0;
				}
				else
				Step.push_back(make_pair(make_pair(1,n),0)),
				Step.push_back(make_pair(make_pair(2,n),addr[t]/2+1)),
				Spare.push_back(addr[t]),st[addr[t]/2+1][0]=st[addr[t]/2+1][1],addr[st[addr[t]/2+1][0]]--,st[addr[t]/2+1][1]=0;
				addr[t]=-1;
			}
			else
			{
				if(Spare.empty())
				addr[t]=num,st[num/2+1][num&1]=t,num++;
				else
				addr[t]=Spare.back(),st[Spare.back()/2+1][Spare.back()&1]=t,Spare.pop_back();
				Step.push_back(make_pair(make_pair(1,addr[t]/2+1),0));
			}
		}
		wr_endl((int)Step.size());
		for(int i=0;i<Step.size();i++)
		{
			if(Step[i].first.first==1)
			wr_space(1),wr_endl(Step[i].first.second);
			else
			wr_space(2),wr_space(Step[i].first.second),wr_endl(Step[i].second);
		}
	}
	else
	{
		num=0;
		for(int i=1,t;i<=m;i++)
		{
			a[i]=rd();t=a[i];
			if(~addr[t])
			{
				if(addr[t]&1 || st[addr[t]/2+1][1]==0)
				{
					Step.push_back(make_pair(make_pair(1,addr[t]/2+1),0));
					if(st[addr[t]/2+1][1]==0)
					st[addr[t]/2+1][0]=0,Spare.push_back(addr[t]);
					else
					st[addr[t]/2+1][1]=0,Spare.push_back(addr[t]);
				}
				else
				{
					if(Spare.empty() && num/2+1==n)
					Step.back().first.second=addr[t]/2+1,addr[st[n][0]]=addr[t],
					Step.push_back(make_pair(make_pair(1,n),0)),
					Step.push_back(make_pair(make_pair(2,n),addr[t]/2+1)),
					addr[st[addr[t]/2+1][0]]--,
					st[addr[t]/2+1][0]=st[addr[t]/2+1][1],st[addr[t]/2+1][1]=st[n][0],st[n][0]=0;
					else
					Step.push_back(make_pair(make_pair(1,n),0)),
					Step.push_back(make_pair(make_pair(2,n),addr[t]/2+1)),
					Spare.push_back(addr[t]),st[addr[t]/2+1][0]=st[addr[t]/2+1][1],addr[st[addr[t]/2+1][0]]--,st[addr[t]/2+1][1]=0;
					addr[t]=-1;
				}
			}
			else
			{
				if(Spare.empty())
				addr[t]=num,st[num/2+1][num&1]=t,num++;
				else
				addr[t]=Spare.back(),st[Spare.back()/2+1][Spare.back()&1]=t,Spare.pop_back();
				Step.push_back(make_pair(make_pair(1,addr[t]/2+1),0));
			}
		}
		wr_endl((int)Step.size());
		for(int i=0;i<Step.size();i++)
		{
			if(Step[i].first.first==1)
			wr_space(1),wr_endl(Step[i].first.second);
			else
			wr_space(2),wr_space(Step[i].first.second),wr_endl(Step[i].second);
		}
	}
}
void Solve()
{
	// Hello
}
void Output()
{
	// Hello
}
bool Med;
int main()
{
	fprintf(stderr,"%0.3lf MiB\n",(&Mbe-&Med)/1048576.0);
	time_t st=clock();
	Init();
	while(T--)
	{
		Input();
		Solve();
		Output();
	}
	time_t ed=clock();
	fprintf(stderr,"%0.1lf ms\n",(double)(ed-st));
	return 0;
}
// ίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχίχ
