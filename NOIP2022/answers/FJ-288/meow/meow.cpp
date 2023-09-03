#include<bits/stdc++.h>
using namespace std;
int rd(){char c;bool f(1);while(!isdigit(c=getchar()))f=c!='-';int x(c-48);while(isdigit(c=getchar()))x=x*10+(c-48);return f?x:-x;}
const int M(2e6),N(300),K(N*2);
int T,n,m,k,a[M+5],oL,tp;
deque<int> stk[N+5];
array<int,3> o[M*2+5];

void solve1()
{
	for(int i(1);i<=m;++i)
	{
		bool tag(0);
		for(int j:stk[a[i]+1>>1])if(j==a[i]){tag=1;break;}
		if(tag)
		{
			if(stk[a[i]+1>>1].back()==a[i])
			{
				o[++oL]={1,a[i]+1>>1};
				stk[a[i]+1>>1].pop_back();
			}
			else if(stk[a[i]+1>>1].front()==a[i])
			{
				o[++oL]={1,n},o[++oL]={2,a[i]+1>>1,n};
				stk[a[i]+1>>1].pop_front();
			}
		}
		else o[++oL]={1,a[i]+1>>1},stk[a[i]+1>>1].push_back(a[i]);
		
	}
	for(int i(1);i<=n;++i)stk[i].clear();
}
void solve2()
{
	//human intelligence 
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	for(T=rd();T--;oL=0)
	{
		n=rd(),m=rd(),k=rd();
		for(int i(1);i<=m;++i) a[i]=rd();
		k==n+n-2?solve1():solve2();
		printf("%d\n",oL);
		for(int i(1);i<=oL;++i)
		{
			if(o[i][0]==1) printf("1 %d\n",o[i][1]);
			else printf("2 %d %d\n",o[i][1],o[i][2]);
		}
	}
	return 0;
}

