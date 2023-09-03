#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c,f,predown[1010][1010],prebe[1010][1010];//sum记录后缀和,上缀和，下坠和 
char ccc;
bool a[1010][1010];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T,id;
	int p;
	int ansc,ansf;
	cin>>T>>id;
	while(T--)
	{
		cin>>n>>m>>c>>f;
		//初始化 
		for(int j=0;j<=m+1;j++)
			predown[n+1][j]=prebe[n+1][j]=0;
		for(int i=0;i<=n+1;i++)
			predown[i][m+1]=prebe[i][m+1]=0;
		//---------
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>ccc;
				a[i][j]=ccc-'0';
			}
		if(c==0&&f==0)
		{
			cout<<"0 0"<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=m;j;j--)//后缀和 
			{
				if(a[i][j])
					predown[i][j]=prebe[i][j]=0;
				else
					prebe[i][j]=prebe[i][j+1]+1;
			}
		for(int j=1;j<=m;j++)//下缀和 
			for(int i=n;i;i--)	
				if(!a[i][j])
					predown[i][j]=predown[i+1][j]+1;
					
		ansc=ansf=0;
		for(int j=1;j<=m;j++)//按列扫
		{
			p=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i][j])//有坑 
					p=0;
				if(p==0)
				{
					while(i<n&&(a[i][j]||a[i+1][j]))//找合格c
						i++;
					p=0;
					i+=2; 
					if(i>n)	break;
				}
				
				p+=(prebe[i-2][j]-1);
				ansc=(ansc+1ll*p*(prebe[i][j]-1)%mod)%mod;
				ansf=(ansf+1ll*p*(prebe[i][j]-1)%mod*(predown[i][j]-1)%mod)%mod;
			}
		}
		cout<<c*ansc<<" "<<f*ansf<<'\n';
	}
	return 0;
}
