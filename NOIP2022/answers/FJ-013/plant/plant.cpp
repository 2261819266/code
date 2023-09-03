#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

#define mod  998244353
#define int long long

using namespace std;

string C;
int n,m,ans1,ans2;
bool c[1010][1010];
int cnt1[1010][1010],cnt2[1010][1010],cnt3[1010][1010];
int l[1010];

inline int rd()
{
	int s=0;char x='x';
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')s=s*10+(x^48),x=getchar();
	return s;
}

void readd()
{
	n=rd();m=rd();rd();rd();
	for(int i=1;i<=n;i++)
	{
		cin>>C;
		for(int j=1;j<=m;j++)
			c[i][j]=(C[j-1]^48);
	}
}

void working()
{
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	ans1=ans2=0;
	
	for(int i=n;i;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j])cnt2[i][j]=0;
			else cnt2[i][j]=cnt2[i+1][j]+1; 
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j])cnt3[i][j]=0;
			else cnt3[i][j]=cnt3[i-1][j]+1; 
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		memset(l,0,sizeof(l));
		for(int j=m,k;j;j--)
		{
			if(c[i][j])l[j]=0;
			else l[j]=l[j+1]+1;
			k=max(l[j]-1,0LL);
			
			if(cnt3[i][j]>=3)
			{
				//if((cnt1[i-1][j]-cnt1[i-cnt3[i][j]][j])*k)cout<<i<<' '<<j<<':'<< (cnt1[i-1][j]-cnt1[i-cnt3[i][j]][j])*k<<' '<<k<<endl;
				ans1=(ans1+(cnt1[i-2][j]-cnt1[i-cnt3[i][j]][j])*k%mod)%mod;//c
				ans2=(ans2+(cnt1[i-2][j]-cnt1[i-cnt3[i][j]][j])*k%mod*max(cnt2[i][j]-1,0LL)%mod)%mod;//f
			}   
			
			
			cnt1[i][j]=cnt1[i-1][j]+k;
		}
	}
	printf("%lld %lld\n",ans1,ans2);
}

void update()
{
	readd();
	working();
	//cout<<"!!!\n"; 
}

signed main()
{
	//freopen("plant4.in","r",stdin); 
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	int T=rd();rd();
	for(int i=1;i<=T;i++)update();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
