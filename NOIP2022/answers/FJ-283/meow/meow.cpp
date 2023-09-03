#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int t,n,m,k,a[1000005],pd,ans[4000005][3],cnt;
int p[605],z[305][15];
void work1()
{
	for(int i=1;i<=m;i++) 
		if(!p[a[i]]) 
		{
			if(!z[a[i]%(n-1)][0]) z[a[i]%(n-1)][0]=a[i];
			else z[a[i]%(n-1)][1]=a[i];
			p[a[i]]=1;
			ans[++cnt][0]=1;
			ans[cnt][1]=a[i]%(n-1);
		}
		else
		{	
			if(z[a[i]%(n-1)][0]==a[i]) 
			{
				ans[++cnt][0]=1;
				ans[cnt][1]=n-1;	
				ans[++cnt][0]=2;
				ans[cnt][1]=a[i]%(n-1);	
				ans[cnt][2]=n-1;
				if(z[a[i]%(n-1)][1]) z[a[i]%(n-1)][0]=z[a[i]%(n-1)][1],z[a[i]%(n-1)][1]=0;
			}
			else 
			{
				ans[++cnt][0]=1;
				ans[cnt][1]=a[i]%(n-1);	
				z[a[i]%(n-1)][0]=0;				
			}
			p[a[i]]=0;
		}
}
void work2()
{
	int now=0;
	for(int i=1;i<=m;i++) 
	{
		if(now==0) 
		{
			ans[++cnt][0]=1;
			ans[cnt][1]=0;
			z[0][0]=a[i],now=1;
		}
		else if(now==1) 
		{
			if(z[0][0]) 
			{
				if(z[0][0]==a[i]) 
				{
					ans[++cnt][0]=1;
					ans[cnt][1]=0;
					z[0][0]=now=0;
				}
				else
				{
					ans[++cnt][0]=1;
					ans[cnt][1]=1;
					z[0][1]=a[i];
					now=2;					
				}
			}
			else
			{
				if(z[0][1]==a[i]) 
				{
					ans[++cnt][0]=1;
					ans[cnt][1]=1;
					z[0][1]=now=0;
				}
				else
				{
					ans[++cnt][0]=1;
					ans[cnt][1]=0;	
					z[0][0]=a[i];
					now=2;				
				}				
			}
		}
		else if(now==2)
		{
			if(z[0][0]&&z[1][0])
			{
				if(a[i]==z[0][0])
				{
					ans[++cnt][0]=1;
					ans[cnt][1]=0;
					z[0][0]=0;now=1;
				}
				else if(a[i]==z[1][0])
				{
					ans[++cnt][0]=1;
					ans[cnt][1]=1;
					z[1][0]=0;now=1;					
				}
				else if(a[i]==a[i+1]) 
				{
					ans[++cnt][0]=1;
					ans[cnt][1]=1;
					z[1][1]=a[i];now=3;			
				}
				else
				{
					if(z[0][0]==a[i+1])
					{
						ans[++cnt][0]=1;
						ans[cnt][1]=1;
						z[1][1]=a[i];now=3;	
					}
					else
					{
						ans[++cnt][0]=1;
						ans[cnt][1]=0;
						z[0][1]=a[i];now=3;						
					}
				}
			}
			else
			{
					if(a[i]==z[1][0])
					{
						ans[++cnt][0]=1;
						ans[cnt][1]=0;
						ans[++cnt][0]=2;
						ans[cnt][1]=0;
						ans[cnt][2]=1;
						z[1][0]=z[1][1];z[1][1]=0;now=1;
					}
					else if(a[i]==z[1][1])
					{
						ans[++cnt][0]=1;
						ans[cnt][1]=1;
						z[1][1]=0;now=1;					
					}
					else if(a[i]==a[i+1]) 
					{
						ans[++cnt][0]=1;
						ans[cnt][1]=0;
						z[0][0]=a[i];now=3;			
					}
					else
					{
						if(z[1][0]==a[i+1])
						{
							ans[++cnt][0]=1;
							ans[cnt][1]=1;
							z[1][2]=a[i];now=3;	
						}
						else
						{
							ans[++cnt][0]=1;
							ans[cnt][1]=0;
							z[1][0]=a[i];now=3;						
						}
					}	
		}}
		else
		{
			if(!z[0][0]) 
			{
				ans[++cnt][0]=1;
				ans[cnt][1]=0;
				ans[++cnt][0]=2;
				ans[cnt][1]=0;	
				ans[cnt][2]=1;
				z[1][1]=z[1][2];
				z[1][0]=z[1][1];
				now=2;
			}
			else if(!z[1][0])
			{
				ans[++cnt][0]=1;
				ans[cnt][1]=1;
				ans[++cnt][0]=2;
				ans[cnt][1]=0;	
				ans[cnt][2]=1;
				z[0][1]=z[0][2];
				z[0][0]=z[0][1];
				now=2;					
			}
			else if(a[i]==z[0][1])
			{
				ans[++cnt][0]=1;
				ans[cnt][1]=0;	
				now=2;
				z[0][1]=0;		
			}
			else if(a[i]==z[1][1])
			{
				ans[++cnt][0]=1;
				ans[cnt][1]=1;	
				now=2;
				z[1][1]=0;		
			}
			else if(a[i]==z[0][2])
			{
				ans[++cnt][0]=1;
				ans[cnt][1]=0;	
				now=2;
				z[0][2]=0;		
			}
			else if(a[i]==z[1][2])
			{
				ans[++cnt][0]=1;
				ans[cnt][1]=1;	
				now=2;
				z[1][2]=0;		
			}
		}
		//cout<<now<<endl;
	}
}
int jl=0,ppp;
void dfs(int x)
{
	if(x>m)
	{
		if(!jl) ppp=1;
		return;
	}
	int cs=cnt,cjl=jl,jjl[15];
	for(int i=0;i<n;i++) jjl[i]=z[i][0];
	for(int ii=0;ii<n;ii++) 
	{
		z[ii][++z[ii][0]]=a[x];
		ans[++cnt][0]=1;
		ans[cnt][1]=ii;
		jl++;
		for(int i=0;i<n;i++) if(z[i][0]>1&&z[i][z[i][0]]==z[i][z[i][0]-1]) z[i][0]-=2,jl-=2;
		for(int i=0;i<n;i++) 
			for(int j=i+1;j<n;j++) 
			{
				if(z[i][1]==z[j][1]&&z[i][1]!=0) 
				{
					ans[++cnt][0]=2;
					ans[cnt][1]=i;
					ans[cnt][2]=j;
					for(int k=1;k<z[i][0];k++) z[i][k]=z[i][k+1];
					for(int k=1;k<z[j][0];k++) z[j][k]=z[j][k+1];
				}
				z[i][0]--;
				z[j][0]--;
				jl-=2;
			}
		dfs(x+1);
		if(ppp) return;
		cnt=cs;
		jl=cjl;
		for(int i=0;i<n;i++) z[i][0]=jjl[i];
	}
}
void work3()
{
	dfs(1);
}
int main ()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	int pd=t%10;
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		if(pd==1) work1();
		if(pd==2) work2();
		else work3();
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)
		{
			printf("%d ",ans[i][0]);
			if(ans[i][0]==1) printf("%d\n",ans[i][1]+1);
			else printf("%d %d\n",ans[i][1]+1,ans[i][2]+1);
		}
	}
	 
}
