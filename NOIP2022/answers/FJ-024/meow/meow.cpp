#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x;
}
const int maxN=310;
const int maxM=1000010;
const int maxK=maxN*2;
int n,m,K;
int a[maxM];
int cnt,op[maxM*2],s[maxM*2][2];
vector<int> stk;
int t[maxN][3];
int c[maxK],d[maxK];
void del(int x)
{
	int y=c[x];
	if(t[y][0]==2) stk.push_back(y);
	if(d[x]==2) t[y][0]--;
	else if(t[y][0]==1) t[y][0]=0;
	else
	{
		t[y][0]=1;
		t[y][1]=t[y][2];
		d[t[y][1]]=1;
	}
	c[x]=0;
	d[x]=0;
}
void op1(int x)
{
	cnt++;
	op[cnt]=1;
	s[cnt][0]=x;
}
void op2(int x,int y)
{
	cnt++;
	op[cnt]=2;
	s[cnt][0]=x;
	s[cnt][1]=y;
}
void print()
{
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d ",op[i]);
		if(op[i]==1) printf("%d\n",s[i][0]);
		else printf("%d %d\n",s[i][0],s[i][1]);
	}
}
void add(int x,int y)
{
	t[y][0]++;
	t[y][t[y][0]]=x;
	c[x]=y;
	d[x]=t[y][0];
	if(t[y][0]==2) stk.pop_back();
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		m=read();
		K=read();
		for(int i=1;i<=m;i++) a[i]=read();
		cnt=0;
		if(n==1) for(int i=1;i<=m;i++) op1(1);
		else
		{
			stk.clear();
			int p=n;
			for(int i=1;i<=n-1;i++) stk.push_back(i);
			for(int i=1;i<=m;i++)
			{
				int x=a[i];
				if(c[x]!=0)
				{
					int y=c[x];
					if(d[x]==2)
					{
						op1(y);
						del(x);
					}
					else
					{
						op1(p);
						op2(y,p);
						del(x);
					}
				}
				else if(!stk.empty())
				{
					int y=stk.back();
					op1(y);
					add(x,y);
				}
				else
				{
					int j=i+1;
					while(j<=m&&a[j]!=x&&d[a[j]]==2) j++;
					if(a[j]==x)
					{
						op1(p);
						for(int k=i+1;k<=j-1;k++)
						{
							if(c[a[k]]!=0)
							{
								op1(c[a[k]]);
								del(a[k]);
							}
							else
							{
								int y=stk.back();
								op1(y);
								add(a[k],y);
							}
						}
						op1(p);
					}
					else
					{
						int y=c[a[j]];
						int z=t[y][2];
						int cntz=0;
						for(int k=i+1;k<=j-1;k++) if(a[k]==z) cntz++;
						if(cntz==0)
						{
							op1(y);
							for(int k=i+1;k<=j-1;k++)
							{
								if(c[a[k]]!=0)
								{
									op1(c[a[k]]);
									del(a[k]);
								}
								else
								{
									int y=stk.back();
									op1(y);
									add(a[k],y);
								}
							}
							op1(p);
							op2(y,p);
							del(a[j]);
							add(x,y);
						}
						else
						{
							op1(p);
							for(int k=i+1,fl=0;k<=j-1;k++)
							{
								if(a[k]==z)
								{
									if(fl==0)
									{
										op1(c[y]);
										fl=1;
									}
									else op1(p);
								}
								else
								{
									if(c[a[k]]!=0)
									{
										op1(c[a[k]]);
										del(a[k]);
									}
									else
									{
										int y=stk.back();
										op1(y);
										add(a[k],y);
									}
								}
							}
							op1(y);
							del(z);
							del(a[j]);
							stk.pop_back();
							add(x,p);
							if(!(cntz&1)) add(z,p);
							if(t[p][0]!=2) stk.push_back(p);
							p=y;
						}
					}
					i=j;
				}
			}
		}
		print();
	}
	return 0;
}
