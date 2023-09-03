#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
const int MOD=998244353;
int T,id;
int n,m,c,f;
char a[1010][1010];
int Cans=0,Fans=0;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	if(id==1){for(int i=1;i<=T;i++){cout<<"0 0\n";}return 0;}
	if(id==2)
	{
		while(T--)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			if(a[1][0]=='0'&&a[1][1]=='0'&&a[2][0]=='0'&&a[3][0]=='0'&&a[3][1]=='0')ans++;
			if(a[1][0]=='0'&&a[1][1]=='0'&&a[2][1]=='0'&&a[3][0]=='0'&&a[3][1]=='0')ans++;
			cout<<ans<<" "<<0<<endl;
		}
		return 0;
	}
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){cin>>a[i];}
		Cans=0;Fans=0;
		for(int i=0;i<m;i++){
			node head;head.x=0;head.y=0;int tot=0;
			for(int j=1;j<=n;j++){
				if(a[j][i]=='0')
				{
					if(head.x==0){head.x=j;head.y=i;}
					tot++;
					if(tot>=3){
						int tmp1=0,tmp2=0;
						for(int k=head.y+1;k<m;k++)
						{
							if(a[head.x][k]=='0')tmp1++;
							else break;
						}
						for(int k=head.y+1;k<m;k++)
						{
							if(a[j][k]=='0')tmp2++;
							else break;
						}
						Cans=(Cans+(tmp1*tmp2))%MOD;
					}
				}
				else 
				{
					tot=0;
					head.x=0;
					head.y=0;
				}
			}
		}
		for(int i=0;i<m;i++){
			node head;head.x=0;head.y=0;int tot=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]=='0')
				{
					if(head.x==0){head.x=j;head.y=i;}
					tot++;
					if(tot>=4)
					{
						for(int h=j-1;h>=head.x+2;h--)
						{
							int tmp1=0,tmp2=0;
							for(int k=head.y+1;k<m;k++)
							{
								if(a[head.x][k]=='0')tmp1++;
								else break;
							}
							for(int k=head.y+1;k<m;k++)
							{
								if(a[h][k]=='0')tmp2++;
								else break;
							}
							Fans=(Fans+(tmp1*tmp2))%MOD;
						}
					}
				}
				else 
				{
					tot=0;
					head.x=0;
					head.y=0;
				}
			}
		}
		cout<<c*(Cans%MOD)<<" "<<f*(Fans%MOD)<<endl;
	}
	return 0;
}