#include<bits/stdc++.h>

#define rep(i,j,k) for(int i=j;i<=k;i++)
#define drp(i,j,k) for(int i=j;i>=k;i--)

using namespace std;
const int N=2e6+10;
int n,m,k,t,a[N],t1[N],t1l=1,t1r,t2[N],t2l=1,t2r,ans[N][4],ansx;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		ansx=0;
		scanf("%d%d%d",&n,&m,&k);
		rep(i,1,m) scanf("%d",&a[i]);
		t2[0]=-1,t2[1]=-1,t1l=1,t1r=0;
		t1[0]=0,t1[1]=0,t2l=1,t2r=0;
		rep(i,1,m)
		{
			if(t1l-1==t1r||a[i]==t1[t1r]) 
			{
				t1[++t1r]=a[i];
				ans[++ansx][1]=1,ans[ansx][2]=1;
				while(t1[t1r-1]==t1[t1r]&&t1r>0) 
				t1r-=2;
			}
			else
			{
				t2[++t2r]=a[i];
				ans[++ansx][1]=1,ans[ansx][2]=2;
				while(t2[t2r-1]==t1[t2r]&&t2r>0) 
				t2r-=2;
			}
			while(t1[t1l]==t2[t2l]&&t1l!=t1r+1&&t2l!=t2r+1) 
			{
				t1l++,t2l++;
				ans[++ansx][1]=2, ans[ansx][2]=1,ans[ansx][3]=2;
			}
		}
		printf("%d\n",ansx);
		rep(i,1,ansx) 
		{
			printf("%d ",ans[i][1]);
			if(ans[i][1]==1) printf("%d\n",ans[i][2]);
			else printf("%d %d\n",ans[i][2],ans[i][3]);
		}
	}
	
	return 0;
} 
