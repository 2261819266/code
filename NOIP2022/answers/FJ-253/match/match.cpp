#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int a[250000],b[250000];
struct tree1
{
	int la,ra;
	int maxna;
}treea[250000];
struct tree2
{
	int lb,rb;
	int maxnb;
}treeb[250000];
int na,nb;
void builda(int p,int ll,int rr)
{
	treea[p].la=ll;
	treea[p].ra=rr;
	if(ll==rr)
	{
		treea[p].maxna=a[ll];
		return;
	}
	int z=(ll+rr)/2;
	builda(p*2,ll,z);
	builda(p*2+1,z+1,rr);
	na=max(na,p*2+1);
	treea[p].maxna=max(treea[p*2].maxna,treea[p*2+1].maxna);
}
void buildb(int p,int ll,int rr)
{
	treeb[p].lb=ll;
	treeb[p].rb=rr;
	if(ll==rr)
	{
		treeb[p].maxnb=b[ll];
		return;
	}
	int z=(ll+rr)/2;
	buildb(p*2,ll,z);
	buildb(p*2+1,z+1,rr);
	nb=max(nb,p*2+1);
	treeb[p].maxnb=max(treeb[p*2].maxnb,treeb[p*2+1].maxnb);
}
long long aska(int ll,int rr)
{
	for(int i=1;i<=na;i++)
	{
		if(treea[i].la==ll&&treea[i].ra==rr)
		{
			return treea[i].maxna;		
		}
	}
}
long long askb(int ll,int rr)
{
	for(int i=1;i<=nb;i++)
	{
		if(treeb[i].lb==ll&&treeb[i].rb==rr)
		{
			return treeb[i].maxnb;		
		}
	}
}
int main(int argc, char** argv) 
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int id,n;
	scanf("%d%d",&id,&n);
	memset(treea,0,sizeof(treea));
	for(int i=1;i<=n;i++)
		a[i]=read();
	builda(1,1,n);		
	for(int i=1;i<=n;i++)
		b[i]=read();
	buildb(1,1,n);
	
	int q;
	scanf("%d",&q);
	int reall,rearr;
	for(int i=1;i<=q;i++)
	{
		unsigned long long ans=0;
		scanf("%d%d",&reall,&rearr);
		for(int p1=reall;p1<=rearr;p1++)
		{
			for(int p2=p1;p2<=rearr;p2++)
			{
				ans+=aska(p1,p2)*askb(p1,p2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
