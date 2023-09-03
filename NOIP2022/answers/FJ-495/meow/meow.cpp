#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m,k,a[2000005],bak,tot1,tot2,ans1[4000005],ans2[4000005],head1,tail[305],top[305],head[305],cnt;
int q[305][100005],mod=1000;
bool flag;
int main()
{
	srand(114514);
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(head,1,sizeof head);
		tot1=tot2=head1=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		for(int i=1,j;i<=m;i++)
		{
			j=((ll)a[i]*998244353ll)%n+1;
			ans1[++tot1]=1,ans2[++tot2]=j;
			if(top[j]&&q[j][top[j]]==a[i])
				top[j]--,cnt--;
			else
				q[j][++top[j]]=a[i],cnt++;
		}
		while(cnt)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i!=j)
						while((head[i]<=top[i])&&(head[i]<=top[j])&&q[i][head[i]]==q[j][head[j]])
							ans1[++tot1]=2,ans2[++tot2]=min(i,j),ans2[++tot2]=max(i,j),cnt-=2;
		printf("%d\n",tot1);
		for(int i=1;i<=tot1;i++)
			if(ans1[i]==1)
				printf("%d %d\n",1,ans2[++head1]);
			else
				printf("%d %d %d\n",2,ans2[++head1],ans2[++head1]);
	}
}
/*
1
2 4 2
1 2 1 2

2
2 6 3
1 2 3 2 3 1 

3
3 8 4
*/
