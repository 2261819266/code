#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
const int N=250000+10;
unsigned long long ans=0;
int la[N],ra[N],lb[N],rb[N],T,n,a[N],b[N],Q,l,r;
stack <int> ma;
int main()
{
	//freopen("match.in","r",stdin);
	//freopen("match.out","w",stdout);
	T=read();n=read();
	memset(la,-1,sizeof(la));
	memset(ra,-1,sizeof(ra));
	memset(lb,-1,sizeof(lb));
	memset(rb,-1,sizeof(rb));
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		while(!ma.empty()&&a[ma.top()]<=a[i])
		{
			ra[ma.top()]=i;
			ma.pop();
		}
		ma.push(i);
	}
	while(!ma.empty())ma.pop();
	for(int i=n;i>=1;--i)
	{
		while(!ma.empty()&&a[ma.top()]<=a[i])
		{
			la[ma.top()]=i;
			ma.pop();
		}
		ma.push(i);
	}
	while(!ma.empty())ma.pop();
	for(int i=1;i<=n;++i)
	{
		b[i]=read();
		while(!ma.empty()&&b[ma.top()]<=b[i])
		{
			rb[ma.top()]=i;
			ma.pop();
		}
		ma.push(i);
	}
	while(!ma.empty())ma.pop();
	for(int i=n;i>=1;--i)
	{
		while(!ma.empty()&&b[ma.top()]<=b[i])
		{
			lb[ma.top()]=i;
			ma.pop();
		}
		ma.push(i);
	}
	Q=read();
	while(Q--)
	{
		l=read();r=read();
		unsigned long long aa=0,bb=0;
		for(int i=l;i<=r;++i)
		{
			aa+=(min(max(ra[i]-1,n),r)-max(l,la[i]+1)+1)*a[i];
			bb+=(min(max(rb[i]-1,n),r)-max(l,lb[i]+1)+1)*b[i];
		}
		ans+=aa*bb;
	}
	cout<<ans;
	return 0;
 } 
