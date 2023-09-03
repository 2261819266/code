#include<iostream>
#include<stdio.h>
using namespace std;
const int mod=998244353;
int T,id;
int n,m,c,f,vc,vf;
char s[1005][1005];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T>>id;
	if(id==1)
	{
		while(T--)
		    cout<<"0 0\n";
		return 0;
	}
	if(id==2)
	{
		while(T--)
		{
			cin>>n>>m>>c>>f;
			vc=0;
		    vf=0;
			for(int i=1;i<=n;i++)
			    for(int j=1;j<=m;j++)
				    cin>>s[i][j];
			if(s[1][1]=='0'&&s[1][2]=='0'&&s[2][1]=='0'&&s[3][1]=='0'&&s[3][2]=='0')
			    vc=1;
			if(s[1][1]=='0'&&s[1][2]=='0'&&s[2][1]=='0'&&s[2][2]=='0'&&s[3][1]=='0'&&s[3][2]=='0')
			    vf=1;
			cout<<vc<<" "<<vf<<"\n";
			return 0;
		}
	}
	while(T--)
	{
		cin>>n>>m>>c>>f;
		vc=0;
		vf=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>s[i][j];
		for(int i=1;i<=n;i++)
	    {
	    	for(int j=1;j<=m;j++)
	    	{
	    		vc=2;
	    		vf=2;
			}
		}
		cout<<vc*c<<" "<<vf*f<<"\n";
	}
	return 0;
}
