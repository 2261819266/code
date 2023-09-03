#include <bits/stdc++.h>
using namespace std;
const int N = 300 + 5;
const int M = 2e6 + 5;
int c[N]={0},s1[N]={0},s2[N]={0};			//card pos | stack 1 | stack 2 
int q[M]={0},a[M];							//empty pos
int op1[2*M],op2[2*M],op3[2*M];
void solve1()
{
	int n,m,i,k,ta,he,x,tp=0;
	cin>>n>>m>>k;
	he=1,ta=0;
	for(i=1;i<n;i++)	q[++ta]=i;
	for(i=1;i<=m;i++)	cin>>a[i];
	for(i=1;i<=m;i++)
	{
		x=c[a[i]];
		if(x)
		{
			if(s2[x]==0)	
			{
				op1[++tp]=1;op2[tp]=x;
				s1[x]=0;	
			}
			else if(s1[x]==a[i])
			{
				op1[++tp]=1;op2[tp]=n;
				op1[++tp]=2;op2[tp]=x;
				s1[x]=s2[x];s2[x]=0;
				q[++ta]=x;
			}
			else 
			{
				op1[++tp]=1;op2[tp]=x;
				q[++ta]=x;	s2[x]=0;
			}
			c[a[i]]=0;
		}
		else
		{
			x=q[he++];		c[a[i]]=x;
			if(s1[x]==0)	s1[x]=a[i],q[++ta]=x;
			else			s2[x]=a[i];
			op1[++tp]=1;	op2[tp]=x;
		}
	}
	cout<<tp<<endl;
	for(i=1;i<=tp;i++)	
	{
		if(op1[i]==1)	cout<<1<<" "<<op2[i]<<endl;
		else			cout<<2<<" "<<op2[i]<<" "<<n<<endl;
	}
}
int se[20];							//xulie
deque <int> st[5];					//stack
bool flag;
bool check(int m)
{
	int i,j,l,t,tp=0,sum=0,tr;
	st[1].clear();
	st[2].clear();
	st[3].clear();
	for(i=1;i<=m;i++)
	{
		t=se[i];	
		op1[++tp]=1;	op2[tp]=t;
		if(st[t].empty())				st[t].push_front(a[i]);		
		else if(st[t].front()==a[i])	st[t].pop_front(),sum+=2;
		else st[t].push_front(a[i]);
		tr=1;
		while(tr)
		{
			tr--;
			for(j=1;j<=3;j++)
			for(l=1;l<=3;l++)
				if(j!=l)
					if((!st[j].empty())&&(!st[l].empty()))
						if(st[j].back()==st[l].back())
			{st[j].pop_back(),st[l].pop_back(),sum+=2;op1[++tp]=2;op2[tp]=j;op3[tp]=l;tr++;}
		}	
	}
	if(sum==m)
	{
		cout<<tp<<endl;
		for(i=1;i<=tp;i++)
		{
			cout<<op1[i]<<" "<<op2[i]<<" ";
			if(op1[i]==2)	cout<<op3[i];
			cout<<endl;
		}
		return true;
	}
	return false;
}
void dfs(int pos,int lim)
{
	if(flag)	return;
	if(pos==lim+1){flag=check(lim);return;}
	se[pos]=1;	dfs(pos+1,lim);
	se[pos]=2;	dfs(pos+1,lim);
	se[pos]=3;	dfs(pos+1,lim);
}
void solve3()
{
	int i,n,m,k;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)	cin>>a[i];
	flag=false;	dfs(1,m);
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int ti,ty;
	for(cin>>ti,ty=ti;ti;ti--)	
	{
		if(ty%10==1)	solve1();
		if(ty%10==3)	solve3();
	}
	return 0;
}
