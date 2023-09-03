
//   *Determinations =)

#include<iostream>
#include<cstring>
#include<cstdio>
#define re register
#define ll long long
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
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);

	rll T=R,id=R,a[1002][1002],fi[1002][1002],ff[1002][1002],fs[1002][1002];
	for(rll kkk=1;kkk<=T;++kkk)
	{
		memset(fi,0,sizeof(fi));memset(a,1,sizeof(a));memset(ff,0,sizeof(ff));memset(fs,0,sizeof(fs));
		rll n=R,m=R,c=R,f=R,ac=0,af=0;
		if(c==0&&f==0)write(0),putchar(32),write(0),putchar(10);
		else
		{
			for(rll i=1;i<=n;++i){string s;cin>>s;for(rll j=1;j<=m;++j)a[i][j]=s[j-1]^48;}
			for(rll i=1;i<=n;++i)for(rll j=1;j<=m;++j)if(!a[i][j]&&!a[i][j-1])for(rll k=1;k<i&&!a[i-k][j-1];++k)if(!a[i-k-1][j]&&!a[i-k-1][j-1])
			{
				++fi[i][j];
				if(!a[i+1][j-1])
				{
					ff[i][j]=1;
					for(rll x=i+1;x<=n;++x)if(!a[x][j-1])++fs[i][j];
				}
			}
			for(rll i=1;i<=n;++i)for(rll j=1;j<=m;++j)if(!a[i][j-1]&&!a[i+1][j-2])for(rll x=2;x<=n&&!a[i+x][j-2];++x)if(fi[i+x][j-1])for(rll k=0;k+j<=m&&!a[i][j+k];++k)++fi[i+x][j-1];
			for(rll i=1;i<=n;++i)for(rll j=1;j<=m;++j)if(!a[i][j]&&fi[i][j-1])
			{
				fi[i][j]+=fi[i][j-1];
				if(ff[i][j-1])ff[i][j]=1,fs[i][j]+=fs[i][j-1];
			}
			for(rll i=1;i<=n;++i)for(rll j=1;j<=m;++j)if(!a[i][j]){ac+=fi[i][j];if(ff[i][j])af+=fi[i][j]*(fs[i][j]==0?1:fs[i][j]);}
			write(ac*c);putchar(32);write(af*f);putchar(10);
		}
	}
	return 0;
}

/*

1 0
4 3 1 1
001
010
000
000

*/
