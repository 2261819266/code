#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1001;
int t,n,m,id,ansc,ansf,c,f;
bool a[MAXN][MAXN];

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin >> t >> id;
	for (int i=1;i<=t;i++)
	{
		ansc=0,ansf=0;
		cin >> n >> m >> c >> f;
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=m;k++)
			{
				cin >> a[j][k]; 
			}
		}
		for (int j=1;j<=n-2;j++)//ansc
		{
			for (int k=1;k<=m-1;k++)
			{
				if (a[j+1][k]==0&&a[j][k]==0&&a[j][k+1]==0&&a[j+2][k]==0&&a[j+2][k+1]==0)
				{//基础图形 
				    int c=1,d=1;
					for (int g=k+2;g<=m;g++)
					{
						if (a[j][g]==0) c++;
						else break;
					} 
					for (int g=k+2;g<=m;g++)
					{
						if (a[j+2][g]==0) d++;
						else break;
					}
					ansc+=c*d; 
					for (int g=j+3;g<=n;g++)
					{
					    if (a[g][1]==0&&a[g][2]==0&&a[g-1][1]==0)
					    {
					    	int d=1;
					    	for (int q=3;q<=m;q++) 
					    	{
					    		if (a[g][q]==0) d++;
					    		else break;
							}
							ansc+=c*d;
						}
					}  
				}
			}
		}
		for (int j=1;j<=n-3;j++)//ansf
		{
			for (int k=1;k<=m-1;k++)
			{
				if (a[j+1][k]==0&&a[j][k]==0&&a[j][k+1]==0&&a[j+2][k]==0&&a[j+2][k+1]==0
				   &&a[j+3][k]==0)
				{//基础图形 
				    int c=1,d=1;
					for (int g=k+2;g<=m;g++) 
					{
						if (a[j][g]==0) c++;
						else break;
					}
					for (int g=k+2;g<=m;g++) 
					{
						if (a[j+2][g]==0) d++;
						else break;
					}
					ansf+=c*d; 
//					for (int g=j+4;g<=n;g++)
//					{
//					    if (a[g][1]==0) ansf++;
//						else break;   
//					}  
				}
			}
		}
		cout << ansc*c%998244353 << ' ' << ansf*f%998244353 << endl; 
	}
	return 0;
}
