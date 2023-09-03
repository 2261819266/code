#include<bits/stdc++.h>
using namespace std;
const int P(998244353),N(1e3);
int T,id,n,m,c,f,ansc,ansf,lst[N+5];
char s[N+5][N+5];
void inc(int &x,int y) {(x+=y)>=P?x-=P:1;}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	for(scanf("%d%d",&T,&id);T--;)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i(1);i<=n;++i) scanf("%s",s[i]+1),lst[i]=m;
		for(int i(m);i;--i)
		{
			for(int j(1),pc(0),ph(0);j<=n;++j)
			{
				if(s[j][i]=='1') pc=ph=0,lst[j]=i-1;
				else
				{
					inc(ansf,pc);
					inc(ansc,1ll*ph*(lst[j]-i)%P);
					inc(pc,1ll*ph*(lst[j]-i)%P);
					if(j>1&&s[j-1][i]=='0')inc(ph,lst[j-1]-i);
				}
			}
		}
		printf("%lld %lld\n",1ll*ansc*c%P,1ll*ansf*f%P);
	}
	return 0;
}//±ð¹Ò·Öqwq
