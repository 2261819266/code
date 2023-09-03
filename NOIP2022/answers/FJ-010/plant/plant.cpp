#include<cstdio>
using namespace std;
const int N=1010;
const int mod=998244353;
int read()
{
	int s=0,b=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') b=-1; c=getchar();}
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*b;
}
int T,id,n,m,c,f;
bool a[N][N];
long long s1,s2;
void init()
{
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			a[i][j]=0;
	n=read(),m=read(),c=read(),f=read();
	for(int i=1;i<=n;getchar(),i++)
		for(int j=1;j<=m;j++)
			a[i][j]=(getchar()=='1');
	s1=s2=0;
	return ;
}
void find()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!a[i][j]&&!a[i][j+1]&&!a[i+1][j])
			{
				int curx=i,cury=j,down=0;
				long long l1=0;
				for(int k=cury+1;k<=m&&!a[curx][k];k++) l1++;
				for(int k=curx;k<=n&&!a[k][j];k++) down++;
				if(down>=3)
				{
					for(int k=curx+2;k<=n&&!a[k][j];k++)
						if(!a[k][cury+1])
						{
							long long l2=0;
							for(int l=cury+1;l<=m&&!a[k][l];l++) l2++;
							s1+=l1*l2%mod*c%mod;
							if(k<curx+down-1) s2+=l1*l2%mod*(curx+down-1-k)%mod*f%mod;
						}
				}
			}
	return ;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	T=read(),id=read();
	while(T--)
	{
		init();
		find();
		printf("%lld %lld\n",s1,s2);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
