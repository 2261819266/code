#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
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
bool fle=File("plant");
typedef long long Type; // change here
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
const long long M=998244353;
// 你需要预处理 每个点向右最大距离 向下最大距离 
long long T=rd(),id=rd(),n,m,c,f;
int r[1001][1001],d[1001][1001];
int a[1001][1001];
void Init()
{
	// Hello
}
void Input()
{
	n=rd(),m=rd(),c=rd(),f=rd();
	if(id==1)
	{
		puts("0 0");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		int t=1;
		for(int j=1;j<=m;j++)
		{
			scanf("%1d",&a[i][j]);
			if(a[i][j]==1)
			{
				for(int k=1;k<=t;k++)
				r[i][j-k]=k-1;
				t=0;
			}
			else
			t++;
		}
		for(int k=1;k<=t;k++)
		r[i][m+1-k]=k-1;
	}
	for(int j=1;j<=m;j++)
	{
		int t=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]==1)
			{
				for(int k=1;k<=t;k++)
				d[i-k][j]=k-1;
				t=0;
			}
			else
			t++;
		}
		for(int k=1;k<=t;k++)
		d[n+1-k][j]=k-1;
	}
	long long vc=0,vf=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=i+2;k<=i+d[i][j];k++)
			{
				if(k<i+d[i][j])
				vf=(vf+r[i][j]*r[k][j]*d[k][j]%M)%M;
				vc=(vc+r[i][j]*r[k][j]%M)%M;
			}
		}
	}
	wr_space(vc*c),wr_endl(vf*f);
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
// 记住！！！！！！plant3.ans的输出是114 514!!!!!!11 
