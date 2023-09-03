#include<iostream>
#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;
struct otpt{
	int tp,x,y;
	inline void clear()
	{tp=x=y=0;}
	inline void out()
	{
		if(tp==1) printf("1 %d\n",x);
		else printf("2 %d %d\n",x,y);
	}
};
otpt a[4000001];
int T,n,m,k,id,op,bn,d[4000001];
deque<int> s[301];
inline int CP(int x)
{if(x&1) return x+1;return x-1;}
inline void ad1(int x)
{
	op++;a[op].tp=1;a[op].x=x;
	id++;
	if(s[x].front()==d[id]) s[x].pop_front(),bn--;
	else s[x].push_front(d[id]),bn++;
}
inline void ad2(int x,int y)
{
	if(s[x].back()!=s[y].back()) return;
	op++;a[op].tp=2;a[op].x=x;a[op].y=y;
	s[x].pop_back();
	s[y].pop_back();
	bn-=2;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	while(T--)
	{
		op=id=bn=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++) scanf("%d",&d[i]);
		if(k==2*n-2)
		{
			for(int i=1;i<=m;i++)
			{
				int nm=(d[i]+1)/2;
				if(!s[nm].empty()&&s[nm].back()==d[i])
					ad1(n),ad2((d[i]+1)/2,n);
				else ad1((d[i]+1)/2);
			}
		}
		for(int i=1;i<=op;i++)
			a[i].out(),a[i].clear();
	}
	return 0;
}
