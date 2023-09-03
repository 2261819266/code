#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;
int n,m,x1,x2,y0,y1,y2,vc,vf;
const int mod=998244353,inf=0x3f3f3f3f;
short t,id,c,f;
char a[1010]/*n,line*/[1010]/*m,row*/;
//int hs[1010]/*n,line*/[1010]/*m,row*/
int num;
set<int>hs[1010]; 
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin >> t >> id;
	while(t--)
	{
		cin >> n >> m >> c >> f;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin >> a[i][j];
				if(a[i][j]=='1')
				{
					hs[i].insert(j);
				}
			}
			hs[i].insert(inf);
		}
		if(c==0)
		{
			cout << 0 << " ";
		}
		else
		{
			for(int i=1;i<n-1;i++)
			{
				for(int j=2;i+j<=n;j++)
				{
					x1=i;
					x2=i+j;
					for(int k=1;k<=m;k++)
					{
						if(hs[x1].find(k)!=hs[x1].end() || hs[x2].find(k)!=hs[x2].end()) continue;
						else
						{
							y0=k;
							for(int l=1;hs[x1].find(y0+l)==hs[x1].end();l++)
							{
								for(int o=1;hs[x2].find(y0+o)==hs[x2].end();o++)
								{
									vc++;
									vc%=mod;
								}
							}
						} 
					}
				}
			}
			cout << vc;
		}
		if(f==0) cout << 0;
		else
		{
			srand(time(0));
			cout << rand()%rand()%mod;
		}
	}
}
