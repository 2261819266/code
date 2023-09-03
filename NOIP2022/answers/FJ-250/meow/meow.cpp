#include<cstdio>
#include<vector>
#include<queue>
#define ths ((cnt-1)%n+1)
using namespace std;
const int SIZE=310,EXTRA=2e6+10;
inline int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x*10)+(ch^48),ch=getchar();
	return x;
}
struct opra{int type,s1,s2;}opr[EXTRA];
deque<int>bin[SIZE];
int T,n,m,k,a[EXTRA],cnt,nw,step;
int low[EXTRA];
inline void pop(int x,int y)
{
//	printf("POP %d %d\n",x,y);
	opr[++step]={2,x,y};
	low[bin[x].front()]=low[bin[y].front()]=0;
	bin[x].pop_front(),bin[y].pop_front();
	if(!bin[x].empty())
	{
		if(low[bin[x].front()])pop(low[bin[x].front()],x);
		else low[bin[x].front()]=x;
	}
	if(!bin[y].empty())
	{
		if(low[bin[y].front()])pop(low[bin[y].front()],y);
		else low[bin[y].front()]=y;
	}
}
inline void push(int t)
{
//	printf("PUSH %d %d\n",t,a[nw]);
	opr[++step]={1,t,0};
	if(bin[t].size()&&bin[t].back()==a[nw])
	{
//		printf("SPJ %d\n",t);
		bin[t].pop_back();
		return;
	}
	if(!bin[t].size())
	{
		bin[t].push_back(a[nw]);
		if(low[a[nw]])
		{
			pop(low[a[nw]],t);
		}
		else low[a[nw]]=t;
	}
	else bin[t].push_back(a[nw]);
}
inline void solve()
{
	n=read(),m=read(),k=read(),step=0,nw=1;
	for(int i=1;i<=m;i++)a[i]=read(),low[a[i]]=0;
	push(cnt=1);
	for(nw=2;nw<=m;nw++)
	{
		if(low[a[nw]])
		{
			++cnt;
			if(cnt==ths)bin[cnt].clear();
			push(ths);
		}
		else push(ths);
	}
	printf("%d\n",step);
	for(int i=1;i<=step;i++)switch(opr[i].type)
	{
		case 1:printf("%d %d\n",1,opr[i].s1);break;
		case 2:printf("%d %d %d\n",2,opr[i].s1,opr[i].s2);
	}
}
int main()
{
	freopen("meow.in","r",stdin),freopen("meow.out","w",stdout);
	T=read();
	while(T--)solve();
	return 0;
}
