#include<bits/stdc++.h>
using namespace std;
int n,m,c,f;
int b1[1001][1001],b2[1001][1001];
int tot1,tot2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	cin>>T>>id;
	while(T--)
	{
		tot1=0;tot2=0;
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
		char a;
		cin>>a;
		b1[i][j]=b1[i][j-1]+(int)a-48;//ºá 
		b2[i][j]=b2[i-1][j]+(int)a-48;//Êú 
	    }
	    int i1=0,j1=0;
	    for(int i1=0;i1<=n;i1++)
	    for(int j1=0;j1<=m;j1++)
	    for(int i=1;i<=n;i++)
	    {
	    if(b2[i][j1+1]-b2[i1][j1+1]==0&&i-i1>=3) //Ã¶¾Ù 
	    {
	    int i2=i1+1;
	    for(int j=1;j<=m;j++)
	    for(int jp=1;jp<=m;jp++)
	    {
	    	if(b1[i2][j]-b1[i2][j1]==0&&b1[i][jp]-b1[i][j1]==0&&j-j1>=2&&jp-j1>=2)
	    	{
	    	tot1++;
	    	for(int i3=i+1;i3<=n;i3++)
	    	if(b2[i3][j1]-b2[i1][j1]==0&&i!=n)
	    	tot2++;
	        }
		}
//		tot2=tot2*tot1;
	}
	    }
	    cout<<tot1*c% 998244353<<" "<<tot2*f% 998244353<<endl;
	}
	return 0;
}
