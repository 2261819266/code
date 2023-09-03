#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a[3000000],last[1000],pre[3000000],nex[3000000],top[1000],di[1000],jjx[3000000],s[5000000][2];
inline int read()
{
	int x=0;
	char c;
	while(c=getchar())if(c>='0'&&c<='9')break;
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		k=read();
		for(int i=1;i<=m;++i)
		{
			a[i]=read();
			last[a[i]]=i;
		}
		int ans=0,sum=0;
		if(k==2*n-2)
		{
			memset(top,0,sizeof(top));
			memset(di,0,sizeof(di));
			int tot=0;
			for(int i=1;i<=m;++i)
			{
				int id=(a[i]+1)/2;
				if(!top[id])
				{
					++tot;
					top[id]=tot;
					di[id]=tot;
					pre[tot]=nex[tot]=0;
					jjx[tot]=a[i];
					++ans;
					s[ans][0]=id,s[ans][1]=0;
				}
				else
				{
					if(jjx[top[id]]==a[i])
					{
						top[id]=pre[top[id]];
						nex[top[id]]=0;
						if(!top[id])di[id]=0;
						++ans;
						s[ans][0]=id,s[ans][1]=0;
						sum+=2;
					}
					else if(jjx[di[id]]==a[i])
					{
						di[id]=nex[di[id]];
						pre[di[id]]=0;
						if(!di[id])top[id]=0;
						++ans;
						s[ans][0]=n,s[ans][1]=0;
						++ans;
						s[ans][0]=id,s[ans][1]=n;
						sum+=2;
					}
					else
					{
						++tot;
						nex[top[id]]=tot;
						pre[tot]=top[id];
						top[id]=tot;
						nex[tot]=0;
						jjx[tot]=a[i];
						++ans;
						s[ans][0]=id,s[ans][1]=0;
					}
				}
			}
		}
		else
		{
			memset(top,0,sizeof(top));
			memset(di,0,sizeof(di));
			int tot=0;
			for(int i=1;i<=m;++i)
			{
				int id=(a[i]+1)/2;
				if(id==n)--id;
				if(!top[id])
				{
					++tot;
					top[id]=tot;
					di[id]=tot;
					pre[tot]=nex[tot]=0;
					jjx[tot]=a[i];
					++ans;
					s[ans][0]=id,s[ans][1]=0;
				}
				else
				{
					if(jjx[top[id]]==a[i])
					{
						top[id]=pre[top[id]];
						nex[top[id]]=0;
						if(!top[id])di[id]=0;
						++ans;
						s[ans][0]=id,s[ans][1]=0;
					}
					else if(jjx[di[id]]==a[i])
					{
						di[id]=nex[di[id]];
						pre[di[id]]=0;
						if(!di[id])top[id]=0;
						++ans;
						s[ans][0]=n,s[ans][1]=0;
						++ans;
						s[ans][0]=id,s[ans][1]=n;
					}
					else
					{
						++tot;
						nex[top[id]]=tot;
						pre[tot]=top[id];
						top[id]=tot;
						nex[tot]=0;
						jjx[tot]=a[i];
						++ans;
						s[ans][0]=id,s[ans][1]=0;
					}
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=ans;++i)
		{
			if(s[i][1]==0)printf("1 %d\n",s[i][0]);
			else printf("2 %d %d\n",s[i][0],s[i][1]);
		}
	}
}