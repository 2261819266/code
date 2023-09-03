#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
unsigned long long CF=998244353;
int t,n,m,c,fk;
bool b[1001][1001];
int f[1001][1001],fl[1001][1001];
inline long long read()
{
	long long s=0;
	char ch[11];
	cin>>ch;
	for(int i=0;i<strlen(ch);i++)s=s*10+ch[i]-'0';
	return s;
}
void fdh(int x,int y)
{
	if(f[x][y-1]-1>=0)
	{
		f[x][y]=f[x][y-1]-1;
		return;
	}
	for(int i=y+1;i<=m;i++)
		if(!b[x][i])f[x][y]++;
		else break;
	return;
}
void fdl(int x,int y)
{
	if(fl[x-1][y]-1>=0)
	{
		fl[x][y]=fl[x-1][y]-1;
		return;
	}
	for(int i=x+1;i<=n;i++)
		if(!b[i][y])fl[x][y]++;
		else break;
	return;
}
int main()
{
	int noip;
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read();
	noip=read();
	while(t--)
	{
		unsigned long long ans1=0,ans2=0;
		n=read();m=read();c=read();fk=read();
		c%=CF;
		fk%=CF;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)b[i][j]=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!b[i][j])fdh(i,j);
				else f[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!b[i][j])fdl(i,j);
				else f[i][j]=0;
		
		for(int x=1;x<=n-2;x++)
			for(int y=1;y<m;y++)
				if(!b[x][y]&&f[x][y]>=1)
				{
					//cout<<x<<" "<<y<<" "<<ans1<<" "<<ans2<<endl;
					if(b[x+1][y])continue;
					for(int i=x+2;i<=n;i++)
						if(!b[i][y])ans1+=f[x][y]*f[i][y];
						else break;
					for(int i=x+2;i<n;i++)
						if(!b[i][y])ans2+=f[x][y]*f[i][y]*fl[i][y];
						else break;
				}	
		//cout<<ans1*c<<" "<<ans2*fk<<endl;
		ans1%=CF;
		ans2%=CF;		
		cout<<(ans1*c)%CF<<" "<<(ans2*fk)%CF<<endl;			
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

