#include<bits/stdc++.h>
using namespace std;

long long int s=0,t,n;
int q;
struct lb
{
	int x;
	int y;
};

lb g,a1[2500003],a2[2500003],b[2500003];

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	cin>>t>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a1[i].x;
		a1[i].y=i+1;
		a2[a1[i].x]=a1[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>b[i].x;
		b[i].y=i+1;
		a1[b[i].x]=b[i];
	}
	
	cin>>q;
	
	for(int i=0;i<q;i++)
	{
		cin>>b[i].x;
		cin>>b[i].y;
	}
	
	for(int i=0;i<q;i++)
	{
		for(int w=b[i].x;w<=b[i].y;w++)
		{
			for(int e=w;e<=b[i].y;e++)
			{	
				for(int o=n;o>=0;o--)
				{
					if(e>=a2[o].y&&a2[o].y>=w)
					{
						g.y=a2[o].x;
					}
				}
				
				for(int o=n;o>=0;o--)
				{
					if(e>=a1[o].y&&a1[o].y>=w)
					{
						g.x=a1[o].x;
					}
				}
				s=s+g.x*g.y;
				s=s%4611686018427387904; 
			}
		}
		cout<<s<<endl;
	}
	
	
	return 0;
}
















