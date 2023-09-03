#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int read()
{
	int res=0,flag=1;
	char ch=getchar();
	while(!('0'<=ch&&ch<='9'))
		flag=(ch=='-')?-1:1,ch=getchar();
	while('0'<=ch&&ch<='9')
		res=res*10+ch-'0',ch=getchar();
	return res*flag;
}
int val[1010][1010],col[1010][1010];;
int line[1010][1010];
void solve()
{
	int n=read(),m=read(),C=read(),F=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&val[i][j]);
	for(int i=1;i<=n;i++)
	{
		int cnt=0,las=0;
		for(int j=1;j<=m;j++)
		{
			if(val[i][j]==1)
			{
				if(cnt!=0) col[i][las]=cnt-1,las=0,cnt=0;
				continue;
			}
			if(las==0) las=j;
			++cnt;
		}
		if(cnt!=0) col[i][las]=cnt-1;
	}
	for(int j=1;j<=m;j++)
	{
		int cnt=0,las=0;
		for(int i=1;i<=n;i++)
		{
			if(val[i][j]==1)
			{
				if(cnt!=0)
				{
					line[las][j]=cnt-1;
					//cout<<"line:"<<j<<" "<<las<<" "<<col[las][j]<<endl;
					cnt=0,las=0;
				}
				continue;
			}
			if(las==0) las=i;
			++cnt;
		}
		if(cnt!=0)
			line[las][j]=cnt-1;
		//cout<<"line:"<<j<<" "<<las<<" "<<line[las][j]<<endl;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(line[i][j]==0&&line[i-1][j]!=0)
				line[i][j]=line[i-1][j]-1;
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)	
			if(col[i][j]==0&&col[i][j-1]!=0)
				col[i][j]=col[i][j-1]-1;
	int cans=0,fans=0;
	for(int j=1;j<=m;j++)
	{
		int cnt=0,las=0;
		for(int i=1;i<=n;i++)
		{
			if(val[i][j]==1)
			{
				cnt=0;
				las=0;
				continue;
			}
			//cout<<i<<" "<<j<<" "<<las<<" "<<cnt<<endl;
			//cout<<"cans:"<<cans<<" "<<col[las][j]<<" "<<col[i][j]<<endl;
			cans=cans+(cnt-col[las][j])*col[i][j]%mod;
			if(las!=i-1)
				cans=cans+col[las][j]*col[i][j]%mod;
			cans%=mod;
			cnt+=col[i][j];
			las=i;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int cnt=0,las=0,fst=0;
		for(int i=1;i<=n;i++)
		{
			if(val[i][j]==1||col[i+1][j]==1||i==n)
			{
				cnt=0;
				las=0;
				fst=0;
				continue;
			}
			//cout<<i<<" "<<j<<" "<<las<<" "<<cnt<<endl;
			//cout<<"fans:"<<fans<<" "<<col[las][j]<<" "<<col[i][j]<<endl;
			if(fst==0)
				fst=i;
			int tmp=1;
			if(fst!=i)
				tmp=line[i][j]-1;
			//cout<<"tmp:"<<tmp<<" "<<fst<<" "<<line[i][fst]<<" "<<line[i][j]<<endl;
			fans=fans+(cnt-col[las][j])*col[i][j]*tmp%mod;
			if(las!=i-1)
				fans=fans+col[las][j]*col[i][j]*(line[i][j]-line[i][fst])*tmp%mod;
			fans%=mod;
			cnt+=col[i][j];
			las=i;
		}
	}
	printf("%d %d\n",cans*C%mod,fans*F%mod);
	return ;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read();
	while(T--)
		solve();
	return 0;
}
