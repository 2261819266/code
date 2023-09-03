#include <bits/stdc++.h>
using namespace std;

int T,id,n,m,c,f,csum,fsum;
bool yard[4005][4005];
int rn[4005][4005];
int bn[4005][4005];
#define reg register
bool ck(reg int x,reg int y)
{
	return x>=1 && x <= n && y >= 1&&y <= m && !yard[x][y];
}
void init()
{
	for(reg int i = 1;i <= n;i++)
		rn[i][m+1]= -1;
	for(reg int i = 1;i <= m;i++)
	{
		bn[n+1][i] = -1;
	}
	for(reg int i = 1;i <= n;i++)
	{
		for(reg int j = m;j >= 1;j--)
		{
			if(ck(i,j)) rn[i][j]=rn[i][j+1]+1;
			else rn[i][j] = -1;
		}
	} 
	for(reg int i = 1;i <= m;i++)	//col
	{
		for(reg int j = n;j >=1;j--)	//row
		{
			if(ck(j,i)) bn[j][i] = bn[j+1][i]+1;
			else bn[j][i] = -1;
		}
	}
	/*
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <=m;j++)
		{
			cout<<bn[i][j];
		}
		cout<<endl;
	} 
	*/
}
int dfsc(reg int x,reg int y)
{
	int cnt = 0;
	if(rn[x][y]<1) return 0;
	if(!ck(x+1,y)) return 0;
	int cl = 1;
	//满足基本c要求
	while(ck(x+1+cl,y))
	{
		//cout<<"pos:"<<x+1+cl<<"  "<<y+1<<endl;
		if(rn[x+1+cl][y]>=1)
		{
			cnt += (rn[x][y+1]+1)*(rn[x+1+cl][y+1]+1);
			if(cnt >= 998244353) cnt -= 998244353;
		}
		cl++;
	}
	//cout<<"Pos "<<x<<" "<<y<<" "<<cnt<<endl;
	return cnt;
}
int dfsf(reg int x,reg int y)
{
	int cnt = 0;
	if(rn[x][y]<1) return 0;
	if(!ck(x+1,y)) return 0;
	int cl = 1;
	//满足基本c要求
	while(ck(x+1+cl,y))
	{
		//cout<<"pos:"<<x+1+cl<<"  "<<y+1<<endl;
		if(rn[x+1+cl][y]>=1&&bn[x+1+cl][y]>=1)
		{
			cnt += (rn[x][y+1]+1)*(rn[x+1+cl][y+1]+1)*bn[x+1+cl][y];
			if(cnt >= 998244353) cnt -= 998244353;
		}
		cl++;
	}
	//cout<<"Pos "<<x<<" "<<y<<" "<<cnt<<endl;
	return cnt;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	for(reg int t = 1;t <= T;t++)
	{
		csum=0;fsum=0;
		cin>>n>>m>>c>>f;
		for(reg int i = 1;i <= n;i++)
		{
			for(reg int j = 1;j <= m;j++)
			{
				char c = 0;
				cin>>c;
				yard[i][j] = (c=='1');
			}
		}
		
		if(c==0&&f==0)
		{
			cout<<"0 0"<<endl;
			continue;
		}
		init();
		for(reg int i = 1;i <= n;i++)
		{
			for(reg int j = 1;j <= m;j++)
			{
				if(c==1){
					csum += dfsc(i,j);
					while(csum >= 998244353) csum -= 998244353;
				}
				if(f==1){
					fsum += dfsf(i,j);
					while(fsum >= 998244353) fsum -= 998244353;
				}
			}
		}
		cout<<csum<<" "<<fsum<<endl;
	}

	return 0;
}
