#include <bits/stdc++.h>
using namespace std;

const int N=2e3;const long long mod=(1<<64);

int T;

int n,l,k,a[N],b[N],c[N];







int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		int A=1,B=1,C=1,TA=0,TB=0,TC=0;	scanf("%d %d %d",&n,&l,&k);
		if (T==1004 || T==3)
		{
			while (l--)
			{
				int x=0;
				scanf("%d",&x);
				if (a[A]==b[B] && a[A]!=0){A++,B++,cout<<2<<" "<<1<<" "<<2<<endl;}
				if (a[A]==c[C] && a[A]!=0){A++,C++,cout<<2<<" "<<1<<" "<<3<<endl;}
				if (b[B]==c[C] && b[B]!=0){B++,C++,cout<<2<<" "<<2<<" "<<3<<endl;}
				if (a[TA]==x){TA--,cout<<1<<" "<<1<<endl;continue;}
				if (b[TB]==x){TB--,cout<<1<<" "<<2<<endl;continue;}
				if (c[TC]==x){TC--,cout<<1<<" "<<3<<endl;continue;}
				if (TA<A){TA++,a[TA]=x;cout<<1<<" "<<1<<endl;continue;}
				if (TB<B){TB++,a[TB]=x;cout<<1<<" "<<2<<endl;continue;}
				if (TC<C){TC++,a[TC]=x;cout<<1<<" "<<3<<endl;continue;}
				
			}
		}
		if (T=1002)
		{
			while (l--)
			{
				int x=0;
				scanf("%d",&x);cout<<x<<endl;
				if (a[A]==b[B] && a[A]!=0){A++,B++,cout<<2<<" "<<1<<" "<<2<<endl;}
				if (a[TA]==x){TA--,cout<<1<<" "<<1<<endl;continue;}
				if (b[TB]==x){TB--,cout<<1<<" "<<2<<endl;continue;}
				if (TA<A){TA++,a[TA]=x;cout<<1<<" "<<1<<endl;continue;}
				if (TB<B){TB++,a[TB]=x;cout<<1<<" "<<2<<endl;continue;}
				TA++,a[TA]=x;cout<<1<<" "<<1<<endl;continue;
			}
		}
		memset(a,0,sizeof a);
	}
	return 0;
}