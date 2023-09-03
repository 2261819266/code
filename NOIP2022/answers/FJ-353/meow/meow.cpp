#include<bits/stdc++.h>
#define M 2100000
#define N 310
#define K 610
using namespace std;
int n,m,k,T;
struct oj{
	bool wei;
	int p;
}t[K];
struct cz{
	int a,x;
}print[M*2];
int a[M],nxt[N],head[K],lie[K],num,di[3][N];
void shu()
{
	printf("%d\n",num);
	for(int i=1;i<=num;i++)
	{
		if(print[i].a==1)
		printf("1 %d\n",print[i].x);
		else
		printf("2 %d %d\n",print[i].x,n);
	}
	num=0;
}
void jiandan()
{
	while(T--)
	{
		memset(nxt,0,sizeof(nxt));
		memset(head,0,sizeof(head));
		memset(lie,0,sizeof(lie));
		for(int i=1;i<=m;i++)
		print[i].a=print[i].x=t[i].p=t[i].wei=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=m;i>=1;i--)
		{
			scanf("%d",&a[i]);
			if(head[a[i]])
			{
				nxt[head[a[i]]]=i;
				head[a[i]]=0;
			}
			else
			head[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
			if(nxt[i])
			{
				if(t[nxt[i]].wei)
				{
					print[++num].a=1;
					print[num].x=n;
					print[++num].a=2;
					print[num].x=t[nxt[i]].p;
					di[0][t[nxt[i]].p]=0;
				}
				else
				{
					print[++num].a=1;
					print[num].x=t[nxt[i]].p;
					di[1][t[nxt[i]].p]=0;
				}
			}
			else
			{
				for(int j=1;j<=n;j++)
				{
					if(!di[0][j])
					{
						print[++num].a=1;
						print[num].x=j;
						di[0][j]=i;
						t[i].wei=1;
						t[i].p=j;
						break;
					}
					if(!di[1][j])
					{
						print[++num].a=1;
						print[num].x=j;
						di[1][j]=i;
						t[i].wei=0;
						t[i].p=j;
						break;
					}
				}
			}
		}
		shu();
	}
}
signed main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	bool pan;
	scanf("%d",&T);
	if(T==1001)
	{
		jiandan();
		return 0;
	}
	while(T--)
	{
		memset(nxt,0,sizeof(nxt));
		memset(head,0,sizeof(head));
		memset(lie,0,sizeof(lie));
		memset(di,0,sizeof(di));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
		t[i].wei=t[i].p=0;
		for(int i=m;i>=1;i--)
		{
			scanf("%d",&a[i]);
			if(head[a[i]])
			{
				nxt[head[a[i]]]=i;
				lie[head[a[i]]]=++lie[0];
				head[a[i]]=0;
			}
			else
			head[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
		{
			if(nxt[i])
			{
				if(t[nxt[i]].wei)
				{
					print[++num].a=1;
					print[num].x=n;
					print[++num].a=2;
					print[num].x=t[nxt[i]].p;
					di[0][t[nxt[i]].p]=0;
				}
				else
				{
					print[++num].a=1;
					print[num].x=t[nxt[i]].p;
					if(di[1][t[nxt[i]].p]==nxt[i])
					di[1][t[nxt[i]].p]=0;
					else
					di[2][t[nxt[i]].p]=0;
				}
			}
			else
			{
				pan=false;
				for(int j=1;j<=n;j++)
				{
					if(di[0][j]&&!di[2][j])
					{
						if(di[1][j]&&lie[i]<lie[di[1][j]])
						{
							print[++num].a=1;
							print[num].x=j;
							di[2][j]=i;
							t[i].wei=0;
							t[i].p=j;
							pan=true;
							break;
						}
						else if(lie[i]>lie[di[0][j]])
						{
							print[++num].a=1;
							print[num].x=i;
							di[2][j]=i;
							t[i].wei=0;
							t[i].p=i;
							pan=true;
							break;
						}
					}
					if(pan)break;
				}
				if(pan)continue;
				for(int j=1;j<=n;j++)
				{
					if(!di[0][j])
					{
						print[++num].a=1;
						print[num].x=j;
						di[2][j]=i;
						t[i].wei=1;
						t[i].p=j;
						pan=true;
						break;
					}
				}
			}
		}
		shu();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}