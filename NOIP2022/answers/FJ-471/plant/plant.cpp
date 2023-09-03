#include<bits/stdc++.h>
using namespace std;
int ans1,ans2,T,id,n,m,c,f,qk[1050][1050];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	for(int t=1;t<=T;t++)
	{
		cin>>n>>m>>c>>f;
		if(c==0&&f==0)
		{
			cout<<"0 0"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>qk[i][j];
		if(c!='0')
		{
			
		}
		else ans1=0;
		if(f!=0)
		{
			
		}
		else ans2=0;
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
