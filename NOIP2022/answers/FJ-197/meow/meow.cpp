#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int op[401050][3];
int n,m,k;
struct que
{
	int head,last;
	int q[200050];
}a[305];
inline ll Read()
{
	ll x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') { x=x*10+ch-48;ch=getchar(); }
	return x;
}
inline int Read1()
{
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') { x=x*10+ch-48;ch=getchar(); }
	return x;
}
bool en;
bool check()
{
	if(a[0].head!=a[0].last+1) return false;
	for(int i=1;i<=n;i++)
	  if(a[i].head>=a[i].last) return false;
	return true;
}
void dfs(int x)
{
	if(en||x>(m<<1)) return;
	if(check()){
		printf("%d\n",x-1);
		for(int i=1;i<=x-1;i++)
		if(op[i][0]==1) printf("%d %d\n",op[i][0],op[i][1]);
		else if(op[i][0]==2) printf("%d %d %d\n",op[i][0],op[i][1],op[i][2]);
		en=true;
		return;
	}
	for(int i=1;i<=n-1;i++)
	  for(int j=i+1;j<=n;j++)
	    if(a[i].head>=a[i].last&&a[j].head>=a[j].last)
	    if(a[i].q[a[i].last]==a[j].q[a[j].last])
	    {
	    	a[i].last++,a[j].last++;
	    	op[x][0]=2,op[x][1]=i,op[x][2]=j;
	    	dfs(x+1);
	    	a[i].last--,a[j].last--;
		}
	if(a[0].head<=a[0].last)
	for(int i=1;i<=n;i++)
	{
		a[i].head++;
		a[i].q[a[i].head]=a[0].q[a[0].head];
		a[0].head++;
		op[x][0]=1,op[x][1]=i;
		bool y=false;
		if(a[i].head>=a[i].last+1&&a[i].q[a[i].head]==a[i].q[a[i].head-1])
		a[i].head-=2,y=true;
		dfs(x+1);
		if(y) a[i].head+=2;
		a[i].head--;
		a[0].head--;
	}
	return;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
    int T=Read1();
    while(T--)
    {
    	n=Read1(),m=Read1(),k=Read1();
    	en=false;
    	a[0].head=1,a[0].last=m;
    	for(int i=1;i<=n;i++) a[i].head=0,a[i].last=1;
    	for(int i=1;i<=m;i++) a[0].q[i]=Read1();
    	for(int i=0;i<=m*2+50;i++) op[i][0]=op[i][1]=op[i][2]=0;
    	dfs(1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
