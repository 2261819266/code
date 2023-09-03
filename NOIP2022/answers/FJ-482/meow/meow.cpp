#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a[10000001],st1[1001],st2[1001],he1=1,he2=1,ta1,ta2;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int lst=0;
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)
		{
			int x;
			cin>>x;
			if(i==1)
			{
				st1[++ta1]=x;
				a[i]=1;
			}
			else
			{
				if(st1[ta1]==x)
				{
					if(lst)
					{
						st2[++ta2]=lst;
						lst=0;
						a[i-1]=2;
					}
					ta1--;
					a[i]=1;
				}
				else if(st2[ta2]==x)
				{
					if(lst)
					{
						st1[++ta1]=lst;
						lst=0;
						a[i-1]=1;
					}
					ta2--;
					a[i]=2;
				}
				else if(ta1==0)
				{
					st1[++ta1]=x;
					a[i]=1;
				}
				else if(ta2==0)
				{
					st2[++ta2]=x;
					a[i]=2;
				}
				else
				{
					lst=x;
				}
			}
		}
		while(ta1>0)
		{
			ta1--;
			a[++m]=3;
		}
		for(int i=1;i<=m;i++)
		{
			if(a[i]==1)
			{
				cout<<"1 1"<<endl;
			}
			if(a[i]==2)
			{
				cout<<"1 2"<<endl;
			}
			if(a[i]==3)
			{
				cout<<"2 1 2"<<endl;
			}
		}
	}
	return 0;
}
