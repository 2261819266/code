#include<cstdio>
#include<iostream>
#define re register
using namespace std;
const int S=2e6+5;;
int n,m,k;
int sta[305][20000];
int q1[305],q2[305];
int a[S];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		int op=0;
		for(re int i=0;i<=n;i++) {q1[i]=1;q2[i]=0;}
		for(re int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			int pd=(a[i]+1)/2;
			if(sta[pd][q1[pd]]==a[i]) 
			{
				sta[pd][q1[pd]]=0;
				q1[pd]++;
				op+=2;
			}
			else if(sta[pd][q2[pd]]==a[i])
			{
				sta[pd][q2[pd]]=0;
				q2[pd]--;
				op+=1;
			}
			else 
			{
				q2[pd]++;
				sta[pd][q2[pd]]=a[i];
				op+=1;
			}
		}
		printf("%d\n",op);
		for(re int i=0;i<=n;i++) {q1[i]=1;q2[i]=0;}
		for(re int i=1;i<=m;i++) 
		{
			
			int pd=(a[i]+1)/2;
			if(sta[pd][q1[pd]]==a[i]) 
			{
				sta[pd][q1[pd]]=0;
				q1[pd]++;
				printf("1 %d\n",n);
				printf("2 %d %d\n",pd,n);
			}
			else if(sta[pd][q2[pd]]==a[i])
			{
				sta[pd][q2[pd]]=0;
				q2[pd]--;
				printf("1 %d\n",pd);
			}
			else 
			{
				q2[pd]++;
				sta[pd][q2[pd]]=a[i];
				printf("1 %d\n",pd);
			}
		}
	}	
	return 0;
}
