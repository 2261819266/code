#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define L l,m,rt<<1
#define R m+1,r,rt<<1|1
using namespace std;
__int128 m,n,a[1000001],b[1000001],sum[1000001],summ[1000001],c,f,t,d,p=0,q=0,l,r,op;
inline __int128 rd()
{
	__int128 l=1,r=0;
	char s=getchar();
	while(s<'0'||s>'9')
	{
		if(s=='-')l=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		r=r*10+s-'0';
		s=getchar();
	}
	return l*r;
}
inline void cwx(__int128 l,__int128 r,__int128 rt)
{
	if(l==r)
	{
		sum[rt]=a[op];
		summ[rt]=b[op];
		op++;
		return;
	}
	__int128 m=(l+r)>>1;
	cwx(L);
	cwx(R);
	sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
	summ[rt]=max(summ[rt<<1],summ[rt<<1|1]);
}
inline __int128 nsn(__int128 a,__int128 b,__int128 l,__int128 r,__int128 rt)
{
	if(l>=a&&r<=b)return sum[rt];
	__int128 m=(l+r)>>1;
	__int128 ss=0;
	if(a<=m)ss=max(ss,nsn(a,b,L));
	if(b>m)ss=max(ss,nsn(a,b,R));
	return ss;
}
inline __int128 wyl(__int128 a,__int128 b,__int128 l,__int128 r,__int128 rt)
{
	if(l>=a&&r<=b)return summ[rt];
	__int128 m=(l+r)>>1;
	__int128 ss=0;
	if(a<=m)ss=max(ss,wyl(a,b,L));
	if(b>m)ss=max(ss,wyl(a,b,R));
	return ss;
}
inline void print(__int128 k)
{
	if(k==0)return;
	print(k/10);
	putchar(k%10+'0');
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	d=rd();
	n=rd();
	op=1;
	for(__int128 i=1;i<=n;i++)
	{
		a[i]=rd();
	}
	for(__int128 i=1;i<=n;i++)
	{
		b[i]=rd();
	}
	cwx(1,n,1);
	m=rd();
	for(__int128 o=1;o<=m;o++)
	{
		__int128 s=0;
		l=rd();
		r=rd();
		for(__int128 i=l;i<=r;i++)
		for(__int128 j=i;j<=r;j++)
		{
			s+=(nsn(i,j,1,n,1)*wyl(i,j,1,n,1))%8446744073709551616;
			s%=8446744073709551616;
		}
		print(s);
		printf("\n");
	}
	return 0;
}
