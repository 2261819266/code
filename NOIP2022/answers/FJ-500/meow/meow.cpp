#include<bits/stdc++.h>
using namespace std;
const int N=500,M=2e6+50;
int read(){
	int x=0,hhh=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') hhh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*hhh;
}
int n,m,k,az,step;
int sta[4][M],l[3],r[3];
int op[M<<1],ao[M<<1],at[M<<1];
bool vis[N];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read(),m=read(),k=read(),step=1;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i) l[i]=r[i]=1;
		int a=read();
		sta[1][1]=a,op[1]=ao[1]=1,vis[1]=1;
		for(int k=1;k<m;++k)
		{
			a=read(),az=0;			
			for(int i=1;i<=n;++i)
			{
				if(sta[i][r[i]]==a&&vis[i])
				{
//					cout<<step<<" ";
					++step,--r[i];
					op[step]=1,ao[step]=i;
					if(r[i]<l[i]) r[i]=l[i]=1,vis[i]=0,sta[i][1]=sta[i][2]=0;
					az=1;
					break;
				}
				if(sta[i][l[i]]==a&&vis[i])
				{
					for(int j=1;j<=n;++j)
						if(j!=i&&!vis[j])
						{
							++step,op[step]=1,ao[step]=j;
							++step,op[step]=2,ao[step]=i,at[step]=j;
							++l[j];
							if(r[j]<l[j]) r[j]=l[j]=1,vis[j]=0,sta[j][1]=sta[j][2]=0;
							break;
						}
					az=1;
					break;
				}
			}
			if(az) continue;
			for(int i=1;i<=n;++i)
			{
				if(vis[i])
				{
					sta[i][++r[i]]=a;
					++step;
					op[step]=1,ao[step]=i;
					az=1;
					break;
				}
			}
			if(az) continue;
			sta[1][1]=a,op[1]=ao[1]=1,vis[1]=1;
		}
		printf("%d\n",step);
		for(int i=1;i<=step;++i)
		{
			printf("%d %d",op[i],ao[i]);
			if(op[i]==2) printf(" %d",at[i]);
			putchar('\n');
		}
	}
	return 0;
}
/*
2
2 4 2
1 2 1 2
3 4 2
1 2 1 2
*/
