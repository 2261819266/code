#include<bits/stdc++.h>
using namespace std;
int n,m,x1,x2,x3,totalc,totalf,c,f;
char a[1001][1001];
int e1(int x,int y)
{
	int s=0;
	for(int u=y;u<=m;u++)
	{
		if(a[x][u]=='0')s++;
		else break;
	}
	return s;
}
int e2(int x,int y)
{
	int s=0;
	for(int j=x;j<=n;j++)
	{
		if(a[j][y]=='0')s++;
		else break;
	}
	return s;
}
int e4(int x,int y)
{
	int s=0;
	for(int j=x+1;j<=e2(x,y)+x-1;j++)
	{
		if(a[j][y]=='0')s++;
		else break;
	}
	return s;
}
int e3(int x,int y,int x1,bool f)
{
	int sum=0,sun=0;
	for(int i=x+2;i<=x1;i++)
	{
		sum+=e1(i,y)-1;
		sun+=(e1(i,y)-1)*e4(i,y);
//		cout<<e4(i,y)<<" ";
	}
	return f!=1? sum:sun;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,f;
	memset(a,1,sizeof(a));
	cin>>t>>f>>n>>m>>c>>f;
	for(int x=1;x<=t;x++)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if((e1(i,j)-1)*e3(i,j,e2(i,j)+i-1,0)>=0)totalc+=((e1(i,j)-1)*e3(i,j,e2(i,j)+i-1,0))%998244353;
				if((e1(i,j)-1)*e3(i,j,e2(i,j)+i-1,1)>=0)totalf+=((e1(i,j)-1)*e3(i,j,e2(i,j)+i-1,1))%998244353;
//				cout<<i+3<<" "<<e2(i,j)+i-1<<endl;
			}
		}
		}
	cout<<totalc<<' '<<totalf<<endl;
}
/*
1 0
4 3 1 1 
001
010
000
000
*/