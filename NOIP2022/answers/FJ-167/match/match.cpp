#include<bits/stdc++.h>
#define int long long
#define rint register int
#define f(X,Y,Z) for(int X=Y;X<=Z;++X)
using namespace std;
const int maxn=2.5e5+2;
int T,n,a[maxn],b[maxn],Q,l,r;
struct node{
	int i,v;
}ta[maxn],tb[maxn];int pa,pb;
int ans;
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T>>n;
	f(i,1,n) cin>>a[i];
	f(i,1,n) cin>>b[i];
	cin>>Q;
	while(Q--)
	{
		cin>>l>>r,ans=0;
		f(i,l,r)
		{
			ta[i]=(node){i,a[i]},
			tb[i]=(node){i,b[i]};
		}
		sort(ta+l,ta+l+r,[](node x,node y)->bool{return x.v>y.v;});
		sort(tb+l,tb+l+r,[](node x,node y)->bool{return x.v>y.v;});
//		f(i,l,r) cout<<ta[i].v<<" "<<tb[i].v<<endl;
		f(i,l,r)
		{
			pa=pb=l;
			f(j,l,i)
			{
				while(ta[pa].i<j||ta[pa].i>i) ++pa;
				while(tb[pb].i<j||tb[pb].i>i) ++pb;
//				cout<<j<<" "<<i<<" "<<ta[pa].v*tb[pb].v<<endl;
				ans+=ta[pa].v*tb[pb].v;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
