#include<bits/stdc++.h>
using namespace std;
unsigned long long id,a,as[100001],bs[100001],b,c,d;

unsigned long long q(unsigned long long l,unsigned long long r)
{
	unsigned long long m1=0,m2=0,re=0;
	for(int i=l;i<=r;i++)
	{
		for(int j=i;j<=r;j++,m1=m2=0)
		{
			for(int k=i;k<=j;k++)
			{
				m1=max(m1,as[k]);
				m2=max(m2,bs[k]);
			}
			re+=m1*m2;
		}
	}
	return re;
}

int main()
{
	ios::sync_with_stdio(0);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>id>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>as[i];
	}
	for(int i=1;i<=a;i++)
	{
		cin>>bs[i];
	}
	cin>>b;
	for(int i=1;i<=b;i++)
	{
		cin>>c>>d;
		cout<<q(c,d)<<endl;
	}
	return 0;
}
