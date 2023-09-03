#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
const int maxx=998244353;
using namespace std;
bool a[1001][1001];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	int m,n,c,f,vc=0,vf=0;
	int va[1001][1001],vaf[1001][1001];
	string s;
	scanf("%d%d",&T,&id);
	scanf("%d%d%d%d",&n,&m,&c,&f);
	memset(va,-1,sizeof(va));
	memset(vaf,-1,sizeof(vaf));
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=0;j<m;j++)
		{
			if(s[j]=='0')
			{
				a[i][j+1]=0;
				va[i][j+1]=0;
				vaf[i][j+1]=0;
			}
			else
			a[i][j+1]=1;	
		}
	}
	if(c==0&&f==0)
	{
		printf("%d %d",vc,vf);
	}
	else
	{
		for(int i=1;i<=n;i++)
	    {
	    	for(int j=m-1;j>=1;j--)
	    	{
	    		if((!a[i][j])&&(!a[i][j+1])) va[i][j]=va[i][j+1]+1;
			}
		}
		for(int i=n-1;i>=1;i--)
		{
			for(int j=1;j<=m;j++)
			{
				if(((!a[i][j])&&(!a[i+1][j]))) vaf[i][j]=vaf[i+1][j]+1;
			}
		}
		for(int i=1;i<=n-2;i++)
	    {
	    	for(int j=1;j<=m;j++)
	    	{
	    		if(va[i][j]>0&&a[i+1][j]==0) 
				{
					for(int z=i+2;z<=n;z++)
					{
						if(!a[z][j])
						{
							vc+=(va[i][j]*va[z][j])%maxx;
						    vf+=(va[i][j]*va[z][j]*vaf[z][j])%maxx;
						}
						else break;
					}
				}
			}
		}
		printf("%d %d",vc*c,vf*f);
	}
	return 0;
}
