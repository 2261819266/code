#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char ch;
	int s=1;
	while((ch=getchar())<'0' || ch>'9')
	  if(ch=='-')
	    s=-1;
	int res=ch-'0';
	while((ch=getchar())>='0' && ch<='9')
	  res=(res<<3)+(res<<1)+ch-'0';
	return res*s;
}
int t;
int n,m,k;
int a[2000001];
struct haha
{
	int op,s1,s2;
}ans[4000001];
int num=0;
int nxt[2000001];
int b[10001];
void print()
{
	printf("%d\n",num);
	for(int i=1;i<=num;i++)
	{
		if(ans[i].op==1)
		  printf("1 %d\n",ans[i].s1);
		else
		  printf("2 %d %d\n",ans[i].s1,ans[i].s2);
	}
}
int dl[1000001],top=1,rear=1;
vector<int> st[501];
int to[501];
int re[501];
void go1()
{
	for(int i=1;i<=m;i++)
	{
		if(top<rear && dl[rear-1]==a[i])
		{
			ans[++num].op=1;
			ans[num].s1=1;
			rear--;
			continue;
		}
		if(top<rear && dl[top]==a[i])
		{
			ans[++num].op=1;
			ans[num].s1=2;
			ans[++num].op=2;
			ans[num].s1=1;
			ans[num].s2=2;
			top++;
			continue;
		}
		if(nxt[i]-i==2)
		{
			if(top<rear && dl[top]==a[i+1])
			{
				ans[++num].op=1;
				ans[num].s1=1;
				ans[++num].op=1;
				ans[num].s1=2;
				ans[++num].op=1;
				ans[num].s1=1;
				ans[++num].op=2;
				ans[num].s1=1;
				ans[num].s2=2;
				top++;
				i++;
				i++;
			}
			else
			{
				ans[++num].op=1;
				ans[num].s1=2;
				ans[++num].op=1;
				ans[num].s1=1;
				ans[++num].op=1;
				ans[num].s1=2;
				dl[rear++]=a[i+1];
				i++;
				i++;
			}
		}
		else
		  ans[++num].op=1,ans[num].s1=1,dl[rear++]=a[i];
		while(rear-top>=2 && dl[rear-1]==dl[rear-2])
		  rear-=2;
	}
	if(top!=rear)
	{
		int now=0;
		num=0;
		top=1,rear=1;
		for(int i=1;i<=m;i++)
		{
			if(a[i]==3)
			{
				ans[++num].op=1;
				ans[num].s1=2;
				now++;
				now%=2;
			}
			else
			{
				if(now==0 && top<rear && dl[top]==a[i])
				{
					ans[++num].op=1;
					ans[num].s1=2;
					ans[++num].op=2;
					ans[num].s1=1;
					ans[num].s2=2;
					top++;
				}
				else
				{
					ans[++num].op=1;
					ans[num].s1=1;
					dl[rear++]=a[i];
				}
			}
			while(rear-top>=2 && dl[rear-1]==dl[rear-2])
			  rear-=2;
		}
	}
}
void go2()
{
	for(int i=1;i<=n;i++)
	{
		vector<int>q;
		swap(q,st[i]);
		to[i]=re[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int wz=(a[i]-1)/2+1;
		if(to[wz]<re[wz] && st[wz][to[wz]]==a[i] && to[n]==re[n])
		{
			ans[++num].op=1;
			ans[num].s1=n;
			ans[++num].op=2;
			ans[num].s1=wz;
			ans[num].s2=n;
			to[wz]++;
		}
		else
		{
			ans[++num].op=1;
			ans[num].s1=wz;
			st[wz].push_back(a[i]);
			st[wz][re[wz]++]=a[i];
			if(re[wz]-to[wz]>=2 && st[wz][re[wz]-1]==st[wz][re[wz]-2])
			  re[wz]-=2;
		}
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)
		  a[i]=read();
		for(int i=1;i<=k;i++)
		  b[i]=0;
		for(int i=m;i>=1;i--)
		{
			nxt[i]=b[a[i]];
			b[a[i]]=i;
		}
		num=0;
		if(n==2)
		  go1();
		else
		  go2();
		print();
	}
}
/*
1
2 16 5
1 2 3 4 5 3 4 5 1 2 3 4 5 3 4 5

1
3 16 5
1 2 3 4 5 3 4 5 1 2 3 4 5 3 4 5

1
2 8 3
1 3 2 2 2 3 1 2
*/
