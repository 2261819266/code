#include<bits/stdc++.h>
using namespace std;

int t,id,m,n,c1,f1,c2=0,f2=0,p1,p2,p3,q1,q2,q3;
int a[1003][1003];
char b[1003][1003];

int ftt(int p4,int p5,int p6,int q4,int q5,int q6)
{
	int w1=1;
	
	if(p6>=n)
	{
		w1=0;
	}
	
	if(p4>=p5)
	{
		w1=0;
	}
	
	if(p5>=p6)
	{
		w1=0;
	}
	
	if(q4>=q5)
	{
		w1=0;
	}
	
	if(q4>=q6)
	{
		w1=0;
	}

	for(int i=q4;i<=q5;i++)
	{
		if(a[p4][i]==1)
		{
			w1=0;
		}
	}
	
	for(int i=q4;i<=q6;i++)
	{
		if(a[p5][i]==1)
		{
			w1=0;
		}
	}
	
	for(int i=p4;i<=p6;i++)
	{
		if(a[i][q4]==1)
		{
			w1=0;
		}
	}
	
	if(w1==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int mcc(int p4,int p5,int q4,int q5,int q6)
{
	int w1=1;
	
	if(p5>=n)
	{
		w1=0;
	}
	
	if(p4>=p5)
	{
		w1=0;
	}
	
	if(q4>=q5)
	{
		w1=0;
	}
	
	if(q4>=q6)
	{
		w1=0;
	}
	
	for(int i=q4;i<=q5;i++)
	{
		if(a[p4][i]==1)
		{
			w1=0;
		}
	}
	
	for(int i=q4;i<=q6;i++)
	{
		if(a[p5][i]==1)
		{
			w1=0;
		}
	}
	
	for(int i=p4;i<=p5;i++)
	{
		if(a[i][q4]==1)
		{
			w1=0;
		}
	}
	
	if(w1==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	cin>>t>>id;
	
	while(t)
	{
		t--;
		
		cin>>n>>m>>c1>>f1;
		
		c1=c1%998244353;
		f1=f1%998244353;
		
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				a[i][j]=b[i][j]-48;
			}
		}
	
		for(int i=0;i<n-3;i++)
		{
			p1=i;
			for(int o=i+2;o<n-1;o++)
			{
				p2=o;
				for(int u=o+1;u<n;u++)
				{
					p3=u;
					for(int j=0;j<m-1;j++)
					{
						q1=j;
						for(int e=j+1;e<m;e++)
						{
							q2=e;
							for(int v=j+1;v<m;v++)
							{
								q3=v;
								
								if(ftt(p1,p2,p3,q1,q2,q3)==1)
								{
									f2++;
								}
							}
						}
						f2=f2%998244353;
					}
				}
			}
		}
		
		for(int i=0;i<n-2;i++)
		{
			p1=i;
			for(int o=i+2;o<n;o++)
			{
				p2=o;
					for(int j=0;j<m-1;j++)
					{
						q1=j;
						for(int e=j+1;e<m;e++)
						{
							q2=e;
							for(int v=j+1;v<m;v++)
							{
								q3=v;
								
								if(mcc(p1,p2,q1,q2,q3)==1)
								{
									c2++;
								}
							}
						}
						c2=c2%998244353;
					}
			}
		}
		
		cout<<c1*c2%998244353;
		cout<<" ";
		cout<<f1*f2%998244353;
		cout<<endl;
	
	}
	return 0;
}
















