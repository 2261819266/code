#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,cnts,cntans,maxn;
long long a[1000001],pstart[1000001];
long long bj[1000001];
vector<long long> p[1000001];
vector<long long> ans;
bool flag;
long long read()
{
	int sum=0,w=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*w;
}
void eraser(int k)
{
	bj[k]=0;
	pstart[k]=0;
	while(!p[k].empty())
		p[k].pop_back();
	cnts--;
}
void check(int k,int j)
{
	if(p[k][pstart[k]]==p[j][pstart[j]])
	{
		ans.push_back(2);
		ans.push_back(k);
		ans.push_back(j);
		pstart[k]++;
		pstart[j]++;
		maxn+=1;
		if(p[k].size()==pstart[k]||p[k].empty())
			eraser(k);
	}
}
void op1(int j)
{
	ans.push_back(1);
	ans.push_back(j);
	p[j].pop_back();
	if(p[j].size()-1==pstart[j]||p[j].empty())
		eraser(j);
	maxn++;
	flag=1;
	for(int k=1;k<=n;k++)
		if(k!=j&&!p[k].empty())
			check(k,j);
}
void op2(int j)
{
	for(int i=1;i<=n;i++)
		if(bj[i]==0)	
		{
			ans.push_back(1);
			ans.push_back(i);
			ans.push_back(2);
			ans.push_back(j);
			ans.push_back(i);
			pstart[j]++;
			flag=1;
			maxn+=2;
			for(int k=1;k<=n;k++)
				if(k!=j)
					check(k,j);
		}
}

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(bj,0,sizeof(bj));
		memset(pstart,0,sizeof(pstart));
		maxn=0;
		cnts=0;
		while(!ans.empty())
			ans.pop_back();
		for(int i=1;i<=n;i++)
			while(!p[i].empty())
				p[i].pop_back();
		n=read();
		m=read();
		k=read();
		for(int i=1;i<=m;i++)
			a[i]=read();
		for(int i=1;i<=m;i++)
		{
			flag=0;
			if(i==1)
			{
				ans.push_back(1);
				cnts++;
				ans.push_back(cnts);
				p[1].push_back(a[1]);
				flag=1;
				maxn++;
				bj[1]=1;
			}
			else
			{
				for(int j=1;j<=n;j++)
				{
					if(p[j].empty())
						continue;
					if(p[j][p[j].size()-1]==a[i])
					{
						op1(j);
						break;
					}
					else if(p[j][pstart[j]]==a[i]&&cnts!=n)
					{
						op2(j);
						break;
					}
				}
			}
			if(!flag)
			{
				ans.push_back(1);
				if(cnts==n)
				{
					ans.push_back(1);
					p[1].push_back(a[i]);
					maxn++;
				}
				else
					for(int k=1;k<=n;k++)
						if(bj[k]==0)
						{
							cnts++;
							ans.push_back(k);
							p[k].push_back(a[i]);
							maxn++;
							bj[k]=1;
							break;
						}
			}
		}
		cout<<maxn;
		for(int i=0;i<ans.size();i++)	
		{
			if(cntans==0)
			{
				printf("\n");
				if(ans[i]==1)
				{
					printf("1 ");
					cntans=1;
				}
				if(ans[i]==2)
				{
					printf("2 ");
					cntans=2;
				}
			}
			else
			{
				printf("%d ",ans[i]);	
				cntans--;
			}
		}
		cout<<endl;
	}
	return 0;
}
