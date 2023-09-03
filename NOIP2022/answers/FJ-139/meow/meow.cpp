#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*y;
}
int v[306][3],ans;
int t,n,m,k;
int main()
{
    freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--)
	{
		ans=0;
		n=read();m=read();k=read();
		int x[2*m+1],o[2*m+1];
		memset(v,0,sizeof(v));
		memset(x,0,sizeof(x));
		memset(o,0,sizeof(o));
			for(int i=1;i<=m;i++)
			{
				int c;
				c=read();int bj=0;
				for(int j=1;j<=n;j++)
				{
					if(v[j][2]&&v[j][1]==c)
					{
						bj=1;
						v[j][1]=v[j][2];
						v[j][2]=0;
						o[++ans]=1;
						x[ans]=n; 
						o[++ans]=2;
						x[ans]=j;
						break;
					}
					if(v[j][2]==c)
					{
						v[j][2]=0;
						o[++ans]=1;
						x[ans]=j;
						bj=1;
						break;
					}
					if(v[j][2]==0&&v[j][1]==c)
					{
						v[j][1]=0;
						o[++ans]=1;
						x[ans]=j;
						bj=1;
						break;
					}
				}
				if(bj) continue;
				for(int j=1;j<n;j++)
				{
					if(v[j][2]==0)
				    {
					   if(v[j][1]==0)
				      {
					   v[j][1]=c;
					   o[++ans]=1;
					   x[ans]=j;
					   break;
				      }
				      if(v[j][1]==c)
				      {
				  	    v[j][1]=0;
				  	    o[++ans]=1;
				  	    x[ans]=j;
				  	    break;
				      }
				      v[j][2]=c;
				      o[++ans]=1;
				      x[ans]=j;
				      break;
				    }
				    if(v[j][2]==c)
				    {
				    	v[j][2]=0;
				    	o[++ans]=1;
				    	x[ans]=j;
				    	break;
					}
					
					if(v[j][1]==c)
					{
						v[j][1]=v[j][2];
						v[j][2]=0;
						o[++ans]=1;
						x[ans]=n; 
						o[++ans]=2;
						x[ans]=j;
						break;
					}
				}


			}
		printf("%d\n",ans);
		for(int i=1;i<=ans;i++)
		{
			if(o[i]==1) printf("%d %d\n",o[i],x[i]);
			else printf("%d %d %d\n",o[i],x[i],n);
		}
	}
	return 0;
}
