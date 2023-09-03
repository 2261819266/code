#include <cstdio>
#include <iostream>
using namespace std;

int T,n,m,k,t;
int a[2333333],la[666],pp[2333333];
int st[333][33],top[333],bot[333];
int ans[2333333][3],op;

inline void op1(int s)
{
	ans[op][0]=1;
	ans[op][1]=s;
	op++;
}

inline void op2(int s1,int s2)
{
	ans[op][0]=2;
	ans[op][1]=s1;
	ans[op][2]=s2;
	op++;
}

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	if (T%10==1)
	while (T--)
	{
		op=0;
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1; i<=m; i++)
			scanf("%d",a+i);
		//第k种放在第k%(n-1)个栈，最后一个用来消 
		for (int i=1; i<=m; i++)
		{
			t=a[i]%(n-1)+1;
			if (top[t]==bot[t])
				op1(t),st[t][top[t]++]=a[i];
			else if (st[t][top[t]-1]==a[i])
				op1(t),top[t]--;
			else if (top[t]==1)
				op1(t),st[t][top[t]++]=a[i];
			else
				op1(n),op2(t,n),bot[t]++;
		}
		printf("%d\n",op);
		for (int i=0; i<op; i++)
			if (ans[i][0]==1)
				printf("1 %d\n",ans[i][1]);
			else
				printf("2 %d %d\n",ans[i][1],ans[i][2]);
	}
	else
	while (T--)
	{
		op=0;
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1; i<=m; i++)
		{
			scanf("%d",a+i);
			if (la[a[i]]) pp[i]=la[a[i]],pp[la[a[i]]]=i;
			else la[a[i]]=i;
		}
		for (int i=1; i<=m; i++)
		{
			
		}
		printf("%d\n",op);
		for (int i=0; i<op; i++)
			if (ans[i][0]==1)
				printf("1 %d\n",ans[i][1]);
			else
				printf("2 %d %d\n",ans[i][1],ans[i][2]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
