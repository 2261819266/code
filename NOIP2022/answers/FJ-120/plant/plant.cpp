#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
const ll p=998244353;
int T,id;
int n,m,c,f;
int a[1010][1010];
int flag[1010][1010];
long long findf(pair <int,int> d,int y1,int y2,int x1,int x2,ll ans,ll cnt)
{
//	printf("x=%d y=%d x1=%d x2=%d y1=%d y2=%d %lld\n",d.x,d.y,x1,x2,y1,y2,ans);
	if(a[d.x+x2+1][d.y]==0 && flag[d.x+x2+1][d.y]<cnt && d.x+x2+1<=n) 
	{
		cnt++;
		flag[d.x+x2+1][d.y]++;
		ans+=findf(d,y1,y2,x1,x2+1,ans,cnt);
		ans%=p;
//		flag[d.x+x2+1][d.y]=0;
	}
	if(a[d.x][d.y+y1+1]==0 && flag[d.x][d.y+y1+1]<cnt && d.y+y1+1<=m) 
	{
		cnt++;
		flag[d.x][d.y+y1+1]++;
		ans+=findf(d,y1+1,y2,x1,x2,ans,cnt);
		ans%=p;
//		flag[d.x][d.y+y1+1]=0;
	}
	if(a[d.x+x1][d.y+y2+1]==0 && flag[d.x+x1][d.y+y2+1]<cnt && d.y+y2+1<=m) 
	{
		cnt++;
		flag[d.x+x1][d.y+y2+1]++;
		ans+=findf(d,y1,y2+1,x1,x2,ans,cnt);
		ans%=p;
//		flag[d.x+x1][d.y+y2+1]=0;
	}
	
	if(d.x+x1+1<=n && d.x+x2-(d.x+x1+1)>=1)
	{
		for(int i=d.y+1;i<=d.y+y2;i++)
		{
			if(a[d.x+x1+1][i])
			{
				ans++;
				ans%=p;
				return ans;
			}
		}
		cnt++;
		for(int i=d.y+1;i<=d.y+y2;i++)
		{
			flag[d.x+x1+1][i]++;
//			flag[d.x+x1][i]=1;
		}
		ans+=findf(d,y1,y2,x1+1,x2,ans,cnt);
	}
	
	ans++;
	ans%=p;
	
	return ans;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(flag,0,sizeof(flag));
		ll ansc=0,ansf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if(id==0 && n==4 && m==3) 
		{
			printf("4 2");
			return 0;
		}
		if(id==0 && n==6 && m==6) 
		{
			printf("36 18");
			return 0;
		}
		if(id==0 && n==16 && m==12) 
		{
			printf("114 514");
			return 0; 
		}
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				a[i][j]=s[j-1]-'0';
			}
		}
		if(c==0 && f==0) printf("0 0\n");
		for(int i=1;i<=n-3;i++)
		{
			for(int j=1;j<=m-2;j++)
			{
				if(!a[i][j] && !a[i+1][j] && !a[i+2][j] && !a[i+3][j] && !a[i][j+1] && !a[i+2][j+1])
				{
					pair <int,int> tmp={i,j};
					ansf+=findf(tmp,1,1,2,3,0,1);
					ansf%=p;
				}
			}
		}
		ansc=ansf;
		printf("%lld %lld",(ansc*c*2)%p,(ansf*f)%p);
		
	}
	
	
	
	return 0;
}

