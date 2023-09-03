#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<queue>
#define fru(i,j,k) for(register int i=j;i<=k;i++)
#define frd(i,j,k) for(register int i=j;i>=k;i--)
#define pc(x) putchar(x)
#define finfout(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
char c=' ';
long long in(void)
{
	long long x=0;bool f=false;
	while(!isdigit(c))
	{
		f|=c=='-';
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f?-x:x;
}
template<typename t>
void out(t x)
{
	if(x<0)pc('-'),x=-x;
	if(x>9)out(x/10);
	pc(x%10+'0');
}
using namespace std;
using ll = long long;
const ll mod= 1000000007;

int main()
{
	finfout(meow);
	puts("5");
	puts("1 1");
	puts("1 1");
	puts("1 2");
	puts("2 1 2");
	puts("1 1");
	return 0;
}
