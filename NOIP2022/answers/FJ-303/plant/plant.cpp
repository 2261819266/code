#include<bits/stdc++.h>
#define IL inline
#define reg register
#define mod 998244353
#define N 1010
IL int read()
{
	reg int x=0; reg char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}

IL int Add(reg int x,reg int y){return x+y<mod?x+y:x+y-mod;}
IL int Sub(reg int x,reg int y){return x<y?x-y+mod:x-y;}
IL void Pls(reg int &x,reg int y){x=Add(x,y);}
IL int Mul(reg int x,reg int y){reg long long r=1ll*x*y; return r<mod?r:r%mod;}

int n,m,c,f,x[N][N],ansc,ansf;
char s[N][N];

IL void work()
{
	n=read(),m=read(),c=read(),f=read(),ansc=ansf=0;
	for(reg int i=1;i<=n;++i)scanf("%s",s[i]+1),x[i][m+1]=-1;
	for(reg int i=1,j;i<=n;++i)for(j=m;j;--j)if(s[i][j]=='0')x[i][j]=x[i][j+1]+1; else x[i][j]=-1;
	for(reg int i=1,l,r,j,w;i<=m;++i)
	{
		for(l=1;l<=n;l=r)if(s[l][i]=='0')
		{
			for(r=l;r<=n&&s[r][i]==s[l][i];++r);
			for(j=l,w=0;j<r;++j)
			{
				if(j>l)Pls(ansc,Mul(x[j][i],Sub(w,x[j-1][i])));
				Pls(w,x[j][i]);
			}
			for(j=l,w=0;j<r;++j)
			{
				if(j>l)Pls(ansf,Mul(Mul(x[j][i],r-j-1),Sub(w,x[j-1][i])));
				Pls(w,x[j][i]);
			}
		}else r=l+1;
	}
	printf("%d %d\n",Mul(ansc,c),Mul(ansf,f));
}

main()
{
	freopen("plant.in","r",stdin),freopen("plant.out","w",stdout);
	reg int t=read();
	for(read();t--;work());
}
