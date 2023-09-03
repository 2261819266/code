
//Âå¹È½«»á³ôÃûÕÑÖø£¡ 

#include<iostream>
#include<cstdio>
#define re register
#define ll unsigned long long
#define rll re ll
inline void write(rll x)
{
	if(x<0)putchar(45),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
inline ll read()
{
	rll x=0,c=0;re char a=getchar();
	for(;a<'0'||a>'9';a=getchar())c|=a==45;
	for(;a>='0'&&a<='9';a=getchar())x=(x<<3)+(x<<1)+(a^48);
	return c?-x:x;
}
#define R read()
using namespace std;

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);

	rll T=R,n=R,a[1919810],b[1919810];
	for(rll i=1;i<=n;++i)a[i]=R;
	for(rll i=1;i<=n;++i)b[i]=R;
	rll q=R;
	for(rll kkk=1;kkk<=q;++kkk)
	{
		rll l=R,r=R,ans=0;
		for(rll p=l;p<=r;++p)for(rll q=p;q<=r;++q)
		{
			rll maxa=0,maxb=0;
			for(rll i=p;i<=q;++i)maxa=max(maxa,a[i]),maxb=max(maxb,b[i]);
			ans+=maxa*maxb;
		}
		write(ans),putchar(10);
	}
	return 0;
}
