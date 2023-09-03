#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0;char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())
		s=s*10+c-'0';
	return s;
}
int t;
int n,m,k;
int cnt1,cnt2;
int pos1[2000005],pos2[2000005];//pos1[x]表示第1层数字x所在的地方 
int val1[305],val2[305];//val1[i]表示第一层第i个栈所放的数 
int lj,lit[305],lj2,lit2[305];
set<int>s;//表示第二层有谁还可以放 
int tot;
struct ans{
	int op;
	int s,s1,s2;
}ans[4000005];
int temp[2000005];//temp[x]表示第二层数字x是第几次操作放进去的 
inline int New()
{
	if(lj==0)return ++cnt1;
	return lit[lj--];
}
inline int New2()
{
	if(lj2==0)return ++cnt2;
	return lit2[lj2--];
}
void clear()
{
	cnt1=cnt2=tot=0;
	memset(val1,0,sizeof(val1));
	memset(val2,0,sizeof(val2));
	memset(lit,0,sizeof(lit));
	memset(lit2,0,sizeof(lit2));
	lj=lj2=0;
	for(int i=1;i<=m;i++)
		pos1[i]=pos2[i]=temp[i]=0;
	for(int i=1;i<=tot;i++)
		ans[i].op=ans[i].s=ans[i].s1=ans[i].s2=0;
	s.clear();
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--)
	{
		
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;i++)
			s.insert(i);
		for(int i=1;i<=m;i++)
		{
			int a=read();
			if(pos1[a]&&val2[pos1[a]]==0)//只有一层，能消，直接放 
			{
				tot++;
				ans[tot].op=1,ans[tot].s=pos1[a];
				val1[pos1[a]]=0;
				lit[++lj]=pos1[a];
				pos1[a]=0;
			}
			else if(pos2[a])//有两层，放第三层能消，直接放 
			{
				tot++;
				ans[tot].op=1,ans[tot].s=pos2[a];
				val2[pos2[a]]=0;
				lit[++lj]=pos2[a];
				s.insert(pos2[a]);
				pos2[a]=0;
			}
			else if(lj&&pos1[a])//放到第一层去和别的消 
			{
				tot++;
				ans[tot].op=2;
				int pos=lit[lj];
				ans[tot].s=ans[tot].s1=pos,ans[tot].s2=pos1[a];
				int up=val2[pos1[a]];
				val2[pos1[a]]=0,pos2[up]=0;
				val1[pos1[a]]=up,pos1[up]=pos1[a];
				s.insert(pos1[a]);
				val1[pos1[a]]=0,pos1[a]=0;
			}
			else if(pos1[a])//有两层，先移再放
			{
				int kong=*s.begin(),pos=pos1[a],up=val2[pos];
				
				tot++;
				ans[tot].op=1;
				ans[tot].s=ans[temp[up]].s;
				ans[temp[up]].s=kong;
				
				val2[kong]=up,pos2[up]=kong;
				val2[up]=0;
				val1[pos]=0,pos1[a]=0,lit[++lj]=pos;
				lit2[++lj2]=pos;
				temp[up]=tot;
				s.erase(kong);
				s.insert(pos);
			}
			else if(!pos1[a]&&cnt1<n)//只有一层，且不能消，直接放 
			{
				pos1[a]=New();
				val1[pos1[a]]=a;
				tot++;
				ans[tot].op=1,ans[tot].s=pos1[a];
			}
			else if(!pos1[a]&&cnt1==n)//来到第二层，直接放 
			{
				pos2[a]=New2();
				val2[pos2[a]]=a;
				tot++;
				s.erase(pos2[a]);
				ans[tot].op=1,ans[tot].s=pos2[a];
				temp[a]=tot;
			}
		}
		int now=0;
		for(int i=1;i<=tot;i++)
			now+=ans[i].op;
		printf("%d\n",now);
		for(int i=1;i<=tot;i++)
			if(ans[i].op==1)
				printf("1 %d\n",ans[i].s);
			else
			{
				printf("1 %d\n",ans[i].s);
				if(ans[i].s1>ans[i].s2)swap(ans[i].s1,ans[i].s2);
				printf("2 %d %d\n",ans[i].s1,ans[i].s2);
			}
		clear();
	}
	return 0;
}
/*
1
3 10 5
1 2 3 4 5 1 2 3 4 5
2 4 2
1 2 1 2
*/
