#include<bits/stdc++.h>
using namespace std;
const int N=306,M=2e6+5;
struct node
{
	int x,y,z;
}ans[M*2];
int T,n,m,k,x,b[N][3],c[N*2],op;
void solve1()
{
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=op;i++) ans[i].x=ans[i].y=ans[i].z=0;
		op=0;
		for(int i=1;i<=m;i++)
		{
		    scanf("%d",&x);
			if(c[x])
			{
				if(b[c[x]][1]==x)
				{
					ans[++op].x=1,ans[op].y=n,ans[++op].x=2,ans[op].y=c[x],ans[op].z=n;
					b[c[x]][1]=b[c[x]][2],b[c[x]][2]=0;
				}
				else ans[++op].x=1,ans[op].y=c[x],b[c[x]][2]=0;
				c[x]=0;
			}
			else
			{
				for(int j=1;j<n;j++) if(!b[j][1]) b[j][1]=x,c[x]=j,ans[++op].x=1,ans[op].y=j;
				if(!c[x])
				{
				    for(int j=1;j<n;j++) if(!b[j][2]) b[j][2]=x,c[x]=j,ans[++op].x=1,ans[op].y=j;
				}
			}
		}	
		printf("%d\n",op);
	    for(int i=1;i<=op;i++)
	    {
	    	printf("%d %d",ans[i].x,ans[i].y);
	    	if(ans[i].z) printf(" %d",ans[i].z);
	    	puts("");
		}
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	if(T%10==1) solve1();
	return 0;
}
