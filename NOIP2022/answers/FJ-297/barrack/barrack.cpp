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
bool fle=File("barrack");
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
const long long M=1000000007;
int T=1;
long long n=rd(),m=rd();
long long qpow(long long b,long long p)
{
	long long res=1;
	while(p)
	{
		if(p&1)
		res=res*b%M;
		b=b*b%M;
		p>>=1;
	}
	return res;
}
void Init()
{
	wr_endl((m*(m+1)%M*qpow(2,M-2)%M*qpow(2,m-1)%M+n*qpow(2,m)%M)%M);
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
// 好饿好饿好饿我真的好饿 
