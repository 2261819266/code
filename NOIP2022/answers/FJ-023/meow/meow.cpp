#include<iostream>
#include<cstdio>
using namespace std;
const int N=10001;
int n,m,k;
int t;
int a[N];
int h[301];
int d[301][1001];
int num;
struct node
{
	int type;
	int s,s1,s2;
}ans1[3001];
bool ans;
void search(int x)
{
	if(x==m+1)
	{
		int i,j,k;
		bool flag=1;
		while(flag==1)
		{
			flag=0;
			k=num;
			for(i=1;i<=n;i++)
				for(j=i+1;j<=m;j++)
					if(h[i]<=d[i][0]&&h[j]<=d[j][0]&&d[i][h[i]]==d[j][h[j]])
					{
						h[i]++;
						h[j]++;
						ans1[++num].type=2;
						ans1[num].s1=i;
						ans1[num].s2=j;
						flag=1;
					}
		}
		for(i=1;i<=n;i++)
		{
			if(h[i]<=d[i][0])
				break;
		}
		if(i==n+1)
			ans=1;
		else
			num=k;
		return;
	}
	//枚举放到哪个堆里
	int i;
	for(i=1;i<=n;i++)
	{
		bool flag=false;
		if(d[i][d[i][0]]==a[x])
		{
			d[i][0]--;
			flag=1;
		}
		else
			d[i][++d[i][0]]=a[x];
		ans1[++num].s=i;
		ans1[num].type=1;
		search(x+1);
		if(flag==true)
		{
			d[i][0]++;
			d[i][d[i][0]]=a[x];
		}
		else
			d[i][0]--;
		if(ans==1)
			return;
		num--;
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int i,j;
	scanf("%d",&t);
	while(t--)
	{
		num=0;
		ans=0;
		scanf("%d%d%d",&n,&m,&k);
		for(j=1;j<=m;j++)
			scanf("%d",&a[j]);
		for(j=1;j<=n;j++)
			h[j]=1;
		search(1);
		printf("%d\n",num);
		for(i=1;i<=num;i++)
		{
			if(ans1[i].type==1)
				printf("1 %d\n",ans1[i].s);
			else
				printf("2 %d %d\n",ans1[i].s1,ans1[i].s2);
		}
	}
	return 0;
}
