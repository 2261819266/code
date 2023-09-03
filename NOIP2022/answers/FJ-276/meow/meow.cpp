#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring> 
using namespace std;

const int M=2000010;
deque<int>q1,q2,q3;
int a[M];
int op[M*2][3],opn,temp[M*2];

inline void op1(int x)
{
	op[++opn][0]=1;op[opn][1]=x;
	return;
}
inline void op2(int x,int y)
{
	op[++opn][0]=2;op[opn][1]=x;op[opn][2]=y;
	return;
}

int cnt[1000];
int stk[310][20000],tail[310],head[310];
bool flag[310],vis[M];

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
	int T,n,m,k;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		opn=0;
		
		for(int i=1;i<=n;i++)head[i]=1,tail[i]=0;
		memset(vis,0,sizeof(vis));
		
		for(int i=1;i<=(m-1)/n+1;i++)
		{
			memset(flag,0,sizeof(flag));
			for(int j=(i-1)*n+1;j<=i*n&&j<=m;j++)
			{
				if(cnt[a[j]])
				{
					for(int k=1;k<=n;k++)
					{
						if(stk[k][tail[k]]==a[j]&&flag[k]==false)
						{
							cnt[a[j]]--;cnt[stk[k][tail[k]-1]]++;
							tail[k]--;
							temp[j]=k;
							flag[k]=true;vis[j]=true;
							break;
						}
					}
				}
			}
			bool hhh=false;
			for(int j=(i-1)*n+1,k=1;j<=i*n&&j<=m;j++)
			{
				if(vis[j])continue;
				for(int l=1;l<=n;l++)
					if(stk[l][tail[l]]==a[j]&&!flag[l])
					{
						cnt[a[j]]--;cnt[stk[l][tail[l]-1]]++;
						tail[l]--;
						temp[j]=l;
						hhh=true;break;
					}
				if(hhh)continue;
				while(flag[k])k++;
				cnt[stk[k][tail[k]]]--;cnt[a[j]]++;
				stk[k][++tail[k]]=a[j];
				temp[j]=k++;
			}
			for(int j=(i-1)*n+1;j<=i*n&&j<=m;j++)
				op1(temp[j]);
				
			for(int j=1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					while(stk[j][head[j]]==stk[k][head[k]])
						head[j]++,head[k]++,op2(j,k);
		}
		for(int j=1;j<=n-1;j++)
			for(int k=j+1;k<=n;k++)
				while(stk[j][head[j]]!=0&&stk[j][head[j]]==stk[k][head[k]])
					head[j]++,head[k]++,op2(j,k);
		for(int j=1;j<=n-1;j++)
			for(int k=j+1;k<=n;k++)
				while(stk[j][head[j]]!=0&&stk[j][head[j]]==stk[k][head[k]])
					head[j]++,head[k]++,op2(j,k);
		
		printf("%d\n",opn);
		for(int i=1;i<=opn;i++)
		{
			if(op[i][0]==1)printf("1 %d\n",op[i][1]);
			else printf("2 %d %d\n",op[i][1],op[i][2]);
		}
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
