#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll id,T,n,m,C,F,v[2001][2001],ans_c,ans_f;
inline int check_x(ll x,ll y)
{
	int len=1;
	while(!v[x+1][y]&&x+1<=n)
	{
		len++;
		x++;
	}
	return len;
}
inline int check_y(ll x,ll y)
{
	int len=1;
	while(!v[x][y+1]&&y+1<=m)
	{
		len++;
		y++;
	}
	return len;
}
void ss(int x1,int y0,int len)
{
	int x2=x1+len-1;
	if(len-1>=3) ss(x1,y0,len-1);
	
	int len1=check_y(x1,y0);
	if(len1==1) return;
	int len2=check_y(x2,y0);
	if(len2==1) return;
	int len3=check_x(x2,y0);
	
	ans_c+=(len1-1)*(len2-1);
	ans_f+=(len1-1)*(len2-1)*(len3-1);
	ans_c%=998244353;
	ans_f%=998244353;
	return;
}
void sr()
{
	char s[10001];
	cin>>n>>m>>C>>F;
	 for(int i=1;i<=n;i++)
	 {
	 	scanf("%s",s+1);//cin>>s+1;
		for(int j=1;j<=m;j++)
		 v[i][j]=s[j]-'0';
     } 	 	 
}
void csh()
{
	memset(v,0,sizeof(v));
	ans_c=0;
	ans_f=0;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--)
	{
		csh();
		sr();
		if(C==0&&F==0)
		{
			cout<<"0 0"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=m;j++)
		  if(!v[i][j])
		  {
		  	int L=check_x(i,j);
		  	if(L>=3)
		  	ss(i,j,L);
		  }
		cout<<ans_c*C%998244353<<" "<<ans_f*F%998244353<<endl;
	}
	
	return 0;
}
/*
4 0
16 12 1 1
000000000001
011111111111
000000000011
011111111111
010011111111
010111100011
010011101111
011111100011
111111111111
000011111111
011111111111
000000111111
011111000111
011111011111
011111000111
011111011111
4 3 1 1
001
010
000
000
6 6 1 1
000010
011000
000110
010000
011000
000000
4 4 1 1
0000
0000
0000
0000
*/
