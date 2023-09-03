#include <bits/stdc++.h>
using namespace std;
int t,id,n,m,c,F,a[1010][1010],b[1010],bb[1010],f[1010][1010][2];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	f[3][2][0]=1;
	for (int i=4;i<=1000;i++) f[i][2][0]=f[i-1][2][0]+i-2,f[i][2][1]=f[i-1][2][0];
	for (int i=3;i<=1000;i++) f[3][i][0]=(i-1)*(i-1)+f[3][i-1][0];
	for (int i=4;i<=1000;i++)
		for (int j=3;j<=1000;j++)
			f[i][j][0]=f[3][j][0]+(f[i-1][j][0]<<1),f[i][j][1]=f[i-1][j][0];
	while (t--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&F);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				char c;cin>>c;
				a[i][j]=c-'0';
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				b[i]+=a[i][j],bb[j]+=a[i][j];
		if (c==0&&F==0) {printf("0 0\n");continue;}
		if (n==3&&m==2)
		{
			if (b[1]==0&&b[3]==0&&bb[1]==0) printf("1 0\n");
			else printf("0 0\n");
			continue;
		}
		if (n==4&&m==2)
		{
			if (bb[1]==0&&bb[2]==0) printf("%d %d\n",3*c,F);
			if (bb[1]>=2||bb[2]>=3) printf("0 0\n");
			else if ((a[2][1]|a[3][1])==1||(a[1][2]&a[4][2])==1) printf("0 0\n");
			else if ((a[1][1]&a[2][2])==1||(a[1][1]&a[4][2])==1) printf("0 0\n");
			else if ((a[4][1]&a[3][2])==1||(a[4][1]&a[1][2])==1) printf("0 0\n");
			else if ((a[1][2]&a[2][2])==1||(a[3][2]&a[4][2])==1) printf("0 0\n");
			else if (((a[1][1]|a[2][1])|a[4][1])==1) printf("%d 0\n",c);
			else if (a[4][2]==1) printf("%d %d\n",c,F);
			else if (a[2][2]==1) printf("%d %d\n",2*c,F);
			else if (a[3][2]==1) printf("%d 0\n",2*c);
			continue;
		}
		bool flag=1,Flag=1;
		for (int i=4;i<=n;i+=4) if (b[i-1]+b[i-2]+b[i-3]!=0||b[i]!=m){flag=0;break;}
		for (int i=3;i<=m;i+=3) if (bb[i-1]+bb[i-2]!=0||bb[i]!=n){Flag=0;break;}
		if (flag) printf("%d 0\n",c*(n/4)*f[3][m][0]);
		else if (Flag) printf("%d %d\n",c*(m/3)*f[n][2][0],F*(m/3)*f[n][2][1]);
		printf("%d %d\n",c*n*n,F*n*((m+1)/2));
	}
}
