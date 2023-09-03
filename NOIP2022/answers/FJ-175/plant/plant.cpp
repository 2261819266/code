#include <bits/stdc++.h>
using namespace std;
int t,idd,n,m,c,f,g[1003][1003];
int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();} 
	return x;
}
void print(long long x)
{
	if(x>9) print(x/10);
	putchar('0'+(x%10));
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read(),idd=read();
	while(t--)
	{
		n=read(),m=read(),c=read(),f=read();
		for(int i=1;i<=n;i++)
		{
			char cc[1003];
			scanf("%s",cc);
			for(int j=1;j<=m;j++)	g[i][j]=cc[j-1]-'0';		
		}
		if(idd==1){printf("0 0\n");continue;}
		if(idd==2)
		{
			if(g[1][1]|g[1][2]|g[2][1]|g[3][1]|g[3][2]) printf("0 0\n");
			else printf("1 0\n");
			continue;
		}
		if(idd==3)
		{
			int cc=3,ff=1;
			if(g[1][1]|g[1][2]|g[2][1]|g[3][1]|g[3][2]) cc--;
			if(g[1][1]|g[1][2]|g[2][1]|g[3][1]|g[4][1]|g[4][2]) cc--;
			if(g[2][1]|g[2][2]|g[3][1]|g[4][1]|g[4][2]) cc--;
			if(g[1][1]|g[1][2]|g[2][1]|g[3][1]|g[3][2]|g[4][1]) ff--;
			printf("%d %d",cc,ff);continue;
		}
	}
	fclose(stdin);
    fclose(stdout);
	//system("pause");
	return 0;
}
