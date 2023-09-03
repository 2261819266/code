#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,p=998244353;
int T,d;
int n,m,c,f,A[N][N],sumx[N][N],sumy[N][N];
string s[N];
long long ansc=0,ansf=0;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&d);
	while(T--)
	{
		ansc=0;
		ansf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++) cin>>s[i];
		if(c==0&&f==0)
		{
			printf("0 0\n");
			continue;
		}
		for(int i=1;i<=n;i++) 
		  for(int j=0;j<m;j++)
		    A[i][j+1]=s[i][j]-'0';
		for(int i=1;i<=n;i++) sumx[i][0]=0;
		for(int i=1;i<=m;i++) sumy[0][i]=0;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		    {
		    	sumx[i][j]=sumx[i][j-1]+A[i][j];
		    	sumy[i][j]=sumy[i-1][j]+A[i][j];
			}
		if(c)
		for(int a=1;a<=n;a++)//x1
		{
			for(int b=a+2;b<=n;b++)//x2
			{
				for(int x=1;x<=m;x++)//y0
				{
					if(sumy[b][x]-sumy[a-1][x]==0)
					for(int y=x+1;y<=m&&A[a][y]==0;y++)//y1
					{
						if(sumx[a][y]-sumx[a][x-1]==0)
						for(int z=x+1;z<=m&&A[b][z]==0;z++)//y2
						{
							if(sumx[b][z]-sumx[b][x-1]==0)
							{
								ansc++;
								if(ansc==p) ansc=0; 
							}
						}
					}
				}
			}
		}
		if(f)
		for(int a=1;a<=n;a++)//x1
		{
			for(int b=a+2;b<=n;b++)//x2
			{
				for(int c=b+1;c<=n;c++)//x3
				for(int x=1;x<=m;x++)//y0
				{
					if(sumy[c][x]-sumy[a-1][x]==0)
					for(int y=x+1;y<=m&&A[a][y]==0;y++)//y1
					{
						if(sumx[a][y]-sumx[a][x-1]==0)
						for(int z=x+1;z<=m&&A[b][z]==0;z++)//y2
						{
							if(sumx[b][z]-sumx[b][x-1]==0)
							{
								ansf++;
								if(ansf==p) ansf=0; 
							}
						}
					}
				}
			}
		}
		long long ccc,fff;
		ccc=(c*ansc)%p;
		fff=(f*ansf)%p;
		printf("%lld %lld\n",ccc,fff);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
