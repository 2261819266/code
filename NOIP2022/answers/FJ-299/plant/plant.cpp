#include<bits/stdc++.h>
using namespace std;
long long a,id,b,c,d,e,hs[2010][2010],ls[2010][2010],hs2[2010][2010],hs3[2010][2010],outc,outf,m=998244353;
string as[1001];

void dfs(long long h,long long l)
{
	if(hs[h][l]!=-1)return;
	if(l<c&&as[h][l]=='0'&&as[h][l-1]=='0')
	{
		dfs(h,l+1);
		hs[h][l]=hs[h][l+1]+1;
	}
	else hs[h][l]=0;
	if(h<b&&as[h+1][l-1]=='0'&&as[h][l-1]=='0')
	{
		dfs(h+1,l);
		ls[h][l]=ls[h+1][l]+1;
	}
	else ls[h][l]=0;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>a>>id;
	for(long long i=1;i<=a;i++,outc=outf=0)
	{
		cin>>b>>c>>d>>e;
		for(long long j=1;j<=b;j++)
		{
			cin>>as[j];
			for(long long k=1;k<=c;k++)
			{
				hs[j][k]=ls[j][k]=-1;
				hs2[j][k]=hs3[j][k]=0;
			}
		}
		for(long long j=1;j<=b;j++)
		{
			for(long long k=1;k<=c;k++)
			{
				dfs(j,k);
			}
		}
		for(long long j=b;j>=1;j--)
		{
			for(long long k=c;k>=1;k--)
			{
				hs2[j][k]=hs2[j+1][k]+hs[j][k];
				hs2[j][k]%=m;
				hs3[j][k]=hs3[j+1][k]+hs[j][k]*ls[j][k]%m;
				hs3[j][k]%=m;
				if(ls[j][k]>=2&&as[j][k-1]=='0')
				{
					outc+=(((hs2[j][k]-hs2[j+ls[j][k]+1][k])%m-hs[j][k])%m-hs[j+1][k])%m*hs[j][k]%m;
					outf+=(((hs3[j][k]-hs3[j+ls[j][k]+1][k])%m-hs[j][k]*ls[j][k]%m)-hs[j+1][k]*ls[j+1][k]%m)*hs[j][k]%m;
					outc%=m;outf%=m;
				}
			}
		}
		cout<<(outc*d%m+m)%m<<' '<<(outf*e%m+m)%m<<endl;
	}
	return 0;
}
