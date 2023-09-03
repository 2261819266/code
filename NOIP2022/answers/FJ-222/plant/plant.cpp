#include <cstdio>
#include <iostream>
#include <cstring>
#define ax 1008
#define M 998244353
using namespace std;
int t,d;
int n,m,c,f;
int vc,vf,ls;
string str[ax];
char ch[ax][ax];
//int a[ax][ax];//真->有坑 , 假->无坑 
int s[ax][ax];//s[][]=0 ->无地可种， s[][]=1 ->有地可种
int ln[ax][ax];
void dsc(int x,int y)
{
	//printf("%d %d\n",x,y);
	if(s[x][y]>=2)
	{
		for(int i=x+1;s[i][y]>=1&&i<=n;i++)
		{
			if(i==x+1)
				continue;
			vc+=(long long)(s[x][y]-1)*(s[i][y]-1)%M;
				vc=vc%M;
		}
	}
	//printf("ans[%d][%d]->%d\n",x,y,vc);
}

void dsf(int x,int y)
{
	if(s[x][y]>=2)
	{
		if(s[x+1][y]>=1)
		{
			int i=x+2;
			while(i<=n)
			{
				if(s[i][y]<2||ln[i][y]<1)
					return ;
				if(ln[i][y]>=1)
				{
					vf+=(long long) (s[x][y]-1)*(s[i][y]-1)*(ln[i][y]-1)%M;
					vf=vf%M;
				}
				i++;
			}
		}
	}
}

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&d);
	for(int tt=1;tt<=t;tt++)
	{
		vc=0,vf=0;
		memset(s,0,sizeof(s));
		
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if(c==0&&f==0)
		{
			printf("%d%d\n",vc,vf);
			continue;		
		}
		for(int i=1;i<=n;i++)
		{
			cin>>str[i];
			//cout<<str[i]<<endl;
		}
		for(int i=1;i<=n;i++)//横 
		{
			int ls=str[i].size()-1;
			if(str[i][ls]=='0') s[i][m]=1;
			else s[i][m]=0;
			for(int j1=ls-1,j2=m-1;j1>=0;j1--,j2--)
			{
				if(str[i][j1]=='0')
					s[i][j2]=s[i][j2+1]+1;
				else
					s[i][j2]=0;
			}
		}
		
		for(int j=0;j<m;j++)
		{
			if(str[n][j]=='0')
				ln[n][j+1]=1;
			else
				ln[n][j+1]=0;
		}
		for(int i1=n-1,i2=n-1;i1>=1;i1--,i2--)
		{
			ls=str[i1].size()-1;
			for(int j1=0,j2=1;j1<m;j1++,j2++)
				if(str[i1][j1]=='0')
					ln[i2][j2]=1+ln[i2+1][j2];
				else
					ln[i2][j2]=0;
		}

		if(c)
		{
			for(int i=1;i<=n-2;i++)
			{
				for(int j=1;j<=m-1;j++)
				{
					if(s[i][j]>=2)
						dsc(i,j);
				}
			}
		}
		if(f)
		{
			for(int i=1;i<=n-3;i++)
			{
				for(int j=1;j<=m-1;j++)
				{
					if(s[i][j]>=2)
						dsf(i,j);
				}
			}
		}
		
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				//cout<<s[i][j];
				printf("%d ",s[i][j]);
			}
			cout<<endl;
		}
		cout<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				//cout<<s[i][j];
				printf("%d ",ln[i][j]);
			}
			cout<<endl;
		}
		*/
		printf("%d %d\n",vc,vf); 
		
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
/*
4 3 2 1 0 1 
1 0 0 3 2 1 
3 2 1 0 0 1 
1 0 4 3 2 1 
1 0 0 3 2 1 
6 5 4 3 2 1 

6 1 1 2 0 6 
5 0 0 1 1 5 
4 1 2 0 0 4 
3 0 1 3 3 3 
2 0 0 2 2 2 
1 1 1 1 1 1 
*/ 

