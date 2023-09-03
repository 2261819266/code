
//I AK IOI

#include<iostream>
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
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);

	rll T=R;
	for(rll kkk=1;kkk<=T;++kkk)
	{
		rll n=R,m=R,k=R,a[302],t[302][302],top[302],last[302],num=0,ans[1919810][3],cnt=0;
		for(rll i=1;i<=n;++i)a[i]=R,top[i]=0,last[i]=0;
		for(rll i=1;i<=m;++i)a[i]=R;
		for(rll i=1;i<=m;++i)
		{
			re bool fl=0;
			for(rll j=1;j<=num;++j)if(t[j][top[j]]==a[i]){--top[j],ans[++cnt][0]=1,ans[cnt][1]=j;fl=1;break;}
			if(!fl)
			{
				for(rll j=1;j<=num;++j)if(top[j]==last[j]){t[j][++top[j]]=a[i];ans[++cnt][0]=1,ans[cnt][1]=j;fl=0;break;}
				if(fl)
				{
					if(num<n)t[++num][++top[num]]=a[i],ans[++cnt][0]=1,ans[cnt][1]=num;
					else ans[++cnt][0]=1,ans[cnt][1]=1;
				}
			}
			for(rll i=1;i<=num;++i)for(rll j=i+1;j<=num;++j)
				if(t[j][last[j]]==t[i][last[j]])
				{
					last[i]++;last[j]++;
					ans[++cnt][0]=2,ans[cnt][1]=i,ans[cnt][2]=j;
				}
		}
		write(cnt);putchar(10);
		for(rll i=1;i<=cnt;++i)
		{
			if(ans[i][0]==1)
			{
				write(ans[i][1]);
			}
			else
			{
				write(ans[i][1]);
				putchar(32);
				write(ans[i][2]);
			}
			putchar(10);
		}
	}
	return 0;
}
