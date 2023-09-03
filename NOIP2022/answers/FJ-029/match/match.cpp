#include<cstdio>
#include<cstring>
#include<algorithm>
//#define meow(seele...) fprintf(stderr,seele)
int T,n,a[500002],b[500002],q;
struct que
{
	int l,r,id;
	bool operator <(const que &b)const{return r<b.r;}
}line[500002];
unsigned long long f[3002][3002],res[500002],s[500002];
void W(unsigned long long x)
{
	if(x>9) W(x/10);
	putchar(x%10+'0');
}
unsigned long long max(unsigned long long x,unsigned long long y)
{
	return x>y?x:y;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=n;++i) scanf("%d",b+i);
	for(int i=1;i<=n;++i)
	{
		unsigned long long am=0,bm=0;
		for(int j=i;j<=n;++j)
		{
			am=max(am,a[j]);
			bm=max(bm,b[j]);
			f[i][j]=am*bm;
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",&line[i].l,&line[i].r);
		line[i].id=i;
	}
	std::sort(line+1,line+1+q);
	int p=1;
	for(int i=1;i<=n;++i)
	{
		unsigned long long sum=0;
		for(int j=i;j>0;--j)
		{
			sum+=f[j][i];
			s[j]+=sum;
		}
		while(p<=q&&line[p].r==i)
		{
			res[line[p].id]=s[line[p].l];
			++p;
		}
	}
	for(int i=1;i<=q;++i) W(res[i]),putchar('\n');
	return 0;
}
