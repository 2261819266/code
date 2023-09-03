#include<cstdio>
#include<algorithm>
using namespace std;
const int N=250010;
int read()
{
	int s=0,b=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') b=-1; c=getchar();}
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*b;
}
int T,n,Q,a[N],b[N];
long long ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	T=read(),n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	Q=read();
	while(Q--)
	{
		int l=read(),r=read();
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++)
			{
				int maxa=-1,maxb=-1;
				for(int i=p;i<=q;i++)
					maxa=max(maxa,a[i]),maxb=max(maxb,b[i]);
				ans+=maxa*maxb;
			}
		printf("%lld\n",ans); ans=0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

