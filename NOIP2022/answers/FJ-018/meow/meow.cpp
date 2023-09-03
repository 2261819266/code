#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,p,a,t[1010],s[310][310];
int head[310],tail[310],num,mun,tmp;
int shu[2010],sc[2010][2];
bool chu[2010];
bool chk(int x)
{
	for(int i=1;i<=p;i++)
	{
		if(s[i][tail[i]]==x)
		{
			shu[++num]=i;
			chu[num]=false;
			tail[i]--;tmp-=2;
			return true;
		}
		if(s[i][head[i]]==x)
		{
			shu[++num]=n;
			chu[num]=false;
			shu[++num]=i;
			chu[num]=true;
			head[i]++;tmp-=2;
			return true;
		}
	}
	return false;
}
void work()
{
	scanf("%d%d%d",&n,&m,&k); tmp=m;
	for(int i=1;i<=n;i++) head[i]=1,tail[i]=0;
	p=num=mun=0;
	bool fl; int mn=m/n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a);
		fl=true;
		if(chk(a)) continue;
		for(int j=1;j<=p;j++)
		{
			if(tail[j]-head[j]+1<mn)
			{
				shu[++num]=j;
				chu[num]=false;
				s[j][++tail[j]]=a;
				fl=false;break;
			}
		}
		if(fl)
		{
			p++;
			shu[++num]=p;
			chu[num]=false;
			s[p][++tail[p]]=a;
		}
	}
	while(tmp)
		for(int i=1;i<=n;i++)
			while(head[i]<=tail[i])
				for(int j=1;j<=n;j++)
				{
					if(i==j) continue;
					if(s[i][head[i]]==s[j][head[j]])
					{
						sc[++mun][0]=i;sc[mun][1]=j;
						head[i]++;head[j]++;
						tmp-=2;
					}
				}
	printf("%d\n",num+mun);
	for(int i=1;i<=num;i++)
		if(chu[i]) printf("2 %d %d\n",shu[i],n);
		else printf("1 %d\n",shu[i]);
	for(int i=1;i<=mun;i++)
		printf("2 %d %d\n",sc[i][0],sc[i][1]);
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--) work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
