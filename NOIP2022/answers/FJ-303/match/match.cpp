#include<bits/stdc++.h>
#define IL inline
#define reg register
#define ull unsigned long long
#define N 3030
IL int read()
{
	reg int x=0; reg char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}

int n,q,a[N],b[N];
ull s[N][N];

main()
{
	freopen("match.in","r",stdin),freopen("match.out","w",stdout);
	read(),n=read();
	for(reg int i=1;i<=n;++i)a[i]=read();
	for(reg int i=1;i<=n;++i)b[i]=read();
	for(reg int l=1,r,v1,v2;l<=n;++l)for(r=l,v1=v2=0;r<=n;++r)
		v1=std::max(v1,a[r]),v2=std::max(v2,b[r]),s[l][r]=1ull*v1*v2;
	for(reg int l=1,r;l<=n;++l)for(r=l;r<=n;++r)s[l][r]+=s[l][r-1];
	for(reg int r=1,l;r<=n;++r)for(l=r;l;--l)s[l][r]+=s[l+1][r];
	q=read();
	for(reg int l,r;q--;)l=read(),r=read(),printf("%llu\n",s[l][r]);
}
