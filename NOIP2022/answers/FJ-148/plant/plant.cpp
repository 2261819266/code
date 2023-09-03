#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005,M=998244353;
char a[N][N];
int T,Typ,n,m,Vc,Vf;
int R[N][N],U[N][N],D[N][N],W[N],S[N],Sc,Sf;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&Typ);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&Vc,&Vf),Sc=Sf=0;
		for(int i=1;i<=n;++i)
			scanf("%s",a[i]+1);
		for(int i=1,j;i<=n;++i)
			for(R[i][m+1]=m+1,j=m;j>=1;--j)
				R[i][j]=(a[i][j]=='1'?j:R[i][j+1]);
		for(int j=1,i;j<=m;++j)
			for(U[0][j]=0,i=1;i<=n;++i)
				U[i][j]=(a[i][j]=='1'?i:U[i-1][j]);
		for(int j=1,i;j<=m;++j)
			for(D[n+1][j]=n+1,i=n;i>=1;--i)
				D[i][j]=(a[i][j]=='1'?i:D[i+1][j]);
		for(int j=1;j<=m;++j)
		{
			for(int i=1;i<=n;++i)
				W[i]=max(0,R[i][j]-j-1),S[i]=(W[i]+(i==1?0:S[i-1]))%M;
			for(int i=3,s;i<=n;++i)
				if(a[i][j]=='0' && U[i][j]<i-2)
				{
					s=(S[i-2]-S[U[i][j]]+M)%M;
					Sc=(Sc+1ll*(R[i][j]-j-1)%M*s%M)%M;
					Sf=(Sf+1ll*(R[i][j]-j-1)*(D[i][j]-i-1)%M*s%M)%M;
				}
		}
		Sc=1ll*Vc*Sc%M;
		Sf=1ll*Vf*Sf%M;
		printf("%d %d\n",Sc,Sf);
	}
	return 0;
}
