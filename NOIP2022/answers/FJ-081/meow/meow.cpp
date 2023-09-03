#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long t,n,m,k,a[2000099],b[9999],sum[999],flag[9999],cnt,next[2000099],q;
struct aa
{
	long long top,down,col[3000];
}e[999];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	if(t==1001)
	{
		while(t--)
		{
			cin>>n>>m>>k;
			for(int i=1;i<=m;i++)
			{
				cin>>a[i];
			}
			for(int i=1;i<=m;i++)
			{
				if(flag[a[i]]!=0)
				{
					if(e[flag[a[i]]].top==a[i])
					{
						cout<<1<<" "<<flag[a[i]]<<endl;
						if(e[flag[a[i]]].down==a[i])
						{
							e[flag[a[i]]].down=0;
							e[flag[a[i]]].top=0;	
						}
						else
						{
							e[flag[a[i]]].top=e[flag[a[i]]].down;
						}
						flag[a[i]]=0;
					}
					if(e[flag[a[i]]].down==a[i])
					{
						cout<<1<<" "<<n<<endl<<2<<" "<<flag[a[i]]<<" "<<n<<endl;
						if(e[flag[a[i]]].top==a[i])
						{
							e[flag[a[i]]].down=0;
							e[flag[a[i]]].top=0;	
						}
						else
						{
							e[flag[a[i]]].down=e[flag[a[i]]].top;
						}
						flag[a[i]]=0;
					}
				}
				else
				{
					cout<<1<<" "<<(a[i]+1)/2<<endl;
					flag[a[i]]=(a[i]+1)/2;
					if(e[flag[a[i]]].top==0)
					{	
						e[flag[a[i]]].down=a[i];
					}
					e[flag[a[i]]].top=a[i];
				}
			}
		}
		return 0;
	}
}
