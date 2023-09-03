#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,id,n,m,c,f,vc,vf;
char a[1005][1005];
const int Mod=998244353;
bool flag=0;
void checkC()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=2+i;j<=n;j++)
   		{
   			for(int k=1;k<=m;k++)
   			{
   				for(int l=k+1;l<=m;l++)
   				{
   					for(int p=k+1;p<=m;p++)
   					{
   						flag=0;
   						for(int q=k;q<=l;q++)
   						{
   							if(a[i][q]=='1')
							{
								flag=1;
							   	break;
							} 
						   }
						for(int q=k;q<=p;q++)
						{
							if(a[j][q]=='1')
							{
								flag=1;
								break;
							 } 
						}
						for(int q=i;q<=j;q++)
						{
							if(a[q][k]=='1')
							{
								flag=1;
								break;
							}
						}
						if(flag==0)
						{
							vc++;
							vc%=Mod;
						}
					   }
				   }
			   }
		   }
	   }
	}
void checkF()
{
   for(int i=1;i<=n;i++)
	{
		for(int j=2+i;j<=n;j++)
   		{
   			for(int r=j+1;r<=n;r++)
   			{
   				for(int k=1;k<=m;k++)
   			   {
   				for(int l=k+1;l<=m;l++)
   				{
   					for(int p=k+1;p<=m;p++)
   					{
   						flag=0;
   						for(int q=k;q<=l;q++)
   						{
   							if(a[i][q]=='1')
							{
								flag=1;
							   	break;
							} 
						   }
						for(int q=k;q<=p;q++)
						{
							if(a[j][q]=='1')
							{
								flag=1;
								break;
							 } 
						}
						for(int q=i;q<=r;q++)
						{
							if(a[q][k]=='1')
							{
								flag=1;
								break;
							}
						}
						if(flag==0)
						{
							vf++;
							vf%=Mod;
						}
					   }
				   }
			   }
		   }
		    }
	   }
	}
signed main()
{
  freopen("plant.in","r",stdin);
  freopen("plant.out","w",stdout);
   cin>>t>>id;
   for(int i=1;i<=t;i++)
   {
   	cin>>n>>m>>c>>f;
   	for(int j=1;j<=n;j++)
   	{
   		for(int k=1;k<=m;k++)
   		{
   			cin>>a[j][k];
		   }
	   }
   	if(c==0&&f==0) cout<<0<<" "<<0<<endl;
   	else
   	{
   		checkC();
   		checkF();
   		vc=(vc*c)%Mod;
   		vf=(vf*f)%Mod;
   		cout<<vc<<" "<<vf<<endl;
   	}
   	
   }
   return 0;
}


