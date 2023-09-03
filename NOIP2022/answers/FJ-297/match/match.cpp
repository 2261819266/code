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
bool fle=File("match");
typedef unsigned long long Type; // change here
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
int T=1;
unsigned long long t=rd(),n=rd(),a[3001],b[3001],ans=0;
void Init()
{
	for(int i=1;i<=n;i++)
	a[i]=rd();
	for(int i=1;i<=n;i++)
	b[i]=rd();
	int Q=rd();
	while(Q--)
	{
		ans=0;
		int l=rd(),r=rd();
		for(int p=l;p<=r;p++)
		{
			for(int q=p;q<=r;q++)
			{
				unsigned long long aa=0,bb=0;
				for(int i=p;i<=q;i++)
				aa=max(aa,a[i]),bb=max(bb,b[i]);
				ans+=aa*bb;
			}
		}
		wr_endl(ans);
	}
}
void Input()
{
	// Hello
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
// 没时间推式子了 
