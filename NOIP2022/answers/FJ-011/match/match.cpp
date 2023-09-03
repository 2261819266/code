#include<bits/stdc++.h>
using namespace std;
const long long MAXN=250005;
long long T,n,q,l,r;
long long st1[MAXN][26],st2[MAXN][26],log_2[MAXN];
unsigned long long ans;
long long op;
char ch;
inline void read(long long &x)
{
	op=1,x=0,ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')op=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=op;
}
inline void out(long long x)
{
	if(x>9)
		out(x/10);
	putchar(x%10+48);
}
int x;
inline unsigned long long query1(int l,int r)
{
	x=log_2[r-l+1];
	return max(st1[l][x],st1[r-(1<<x)+1][x]);
}
inline unsigned long long query2(int l,int r)
{
	x=log_2[r-l+1];
	return max(st2[l][x],st2[r-(1<<x)+1][x]);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(T),read(n);
	for(int i=2;i<=n;i++)
	{
		log_2[i]=log_2[i>>1]+1;
	}
	for(int i=1;i<=n;i++)
	{
		read(st1[i][0]);
	}
	for(int i=1;i<=n;i++)
	{
		read(st2[i][0]);
	}
	for(int i=1;i<26;i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			st1[j][i]=max(st1[j][i-1],st1[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<26;i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			st2[j][i]=max(st2[j][i-1],st2[j+(1<<(i-1))][i-1]);
		}
	}
	read(q);
	while(q--)
	{
		read(l),read(r);
		ans=0;
		for(int i=l;i<=r;i++)
		{
			for(int j=i;j<=r;j++)
			{
				ans+=query1(i,j)*query2(i,j);
			}
		}
		out(ans),putchar('\n');
	}
	return 0;
}
