#include <bits/stdc++.h>
#define Md 1000000007
using namespace std;
int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();} 
	return x;
}
void print(long long x)
{
	if(x>9) print(x/10);
	putchar('0'+(x%10));
}
int n,m;
vector<int> e[500002];
long long qpow(int x,int m)
{
	bool res=0;
	if(m==1) return x%Md;
	if(m%2) res=1;
	long long tmp=qpow(x,m>>1);
	long long ans=tmp*tmp%Md;
	if(res) ans=ans*x%Md;
	return ans;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) e[read()].push_back(read());
	if(m==n-1)
	{
		long long ans=0;
		ans=qpow(3,n)%Md;
		ans=((ans-qpow(2,n))%Md+Md)%Md;
		printf("%lld",ans);
	}
	fclose(stdin);
    fclose(stdout);
	//system("pause");
	return 0;
}
