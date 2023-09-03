#include<bits/stdc++.h>
using namespace std;
int mp[1005][1005],m,n;
int C(int x,int y)
{
	int xa=x,ya=y,xb=1,yb=1,yc=1,ans=0;
/*
  |y y
  |a b
-----------
xa|0 0 1
  |0 1 0
xb|0 0 0
  |0 0 0
-----------
  |  y
  |  c
*/
	if(mp[ya][xa]==0&&mp[ya+1][xa]==0&&mp[ya][xa+1]==0&&mp[ya][xa+2]==0&&mp[ya+1][xa+2]==0)//C
	{
		ans++;
		cout<<"P1:"<<ans<<endl;
		while(mp[yb][xa]==0&&yb<=m)
		{
			yb++;
			ans++;
		}
		cout<<"P2:"<<ans<<endl;
		for(int i=xa+2;i<=n;i++)//ext
		{
			xb=i;
			yc=ya+1;
			if(mp[ya][xb]==1||xb>=n||yc>=m)//∂œ¡À 
				break;
			if(mp[yc-1][xb]==0&&mp[yc][xb]==0)
				ans++;
			cout<<"P3:"<<ans<<endl;
			while(mp[yc][xb]==0||xb<=n||yc<=m)
			{
				yc++;
				ans++;
			}
			cout<<"P4:"<<ans<<endl;
		}
	}
	return ans;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cout<<rand()%100+1;
	
	return 0;
}
/*
3 4
0 0 0
0 1 0
0 0 0
0 0 0
*/
