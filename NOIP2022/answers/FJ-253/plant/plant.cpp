#include <bits/stdc++.h>
using namespace std;
int n,m,c,f;
int idn;
int num[10005][1005];
int ln[1005][1005];
int lm[1005][1005];
int main(int argc, char** argv) 
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t;
	scanf("%d%d",&t,&idn);
	while(t--)
	{
		memset(ln,0,sizeof(ln));
		memset(lm,0,sizeof(lm));
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if(c==0&&f==0)
		{
			cout<<0<<" "<<0;
			continue;	
		}
		bool isnm[1005][1005];
		memset(isnm,true,sizeof(isnm));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char temp;
				cin>>temp;
				num[i][j]=temp-'0';
				if(num[i][j]==0)
				{
					for(int k=j-1;k>=1;k--)
					{
						if(isnm[i][k]==true)
							ln[i][k]++;		
						else 
						{
							ln[i][k]++;
							break;
						}
					}
					for(int k=i-1;k>=1;k--)			
					{
						if(isnm[k][j]==true)
							lm[k][j]++;	
						else
						{
							lm[k][j]++;
							break;	
						}
					}
				}
				else if(num[i][j]==1)
					isnm[i][j]=false;	
			}
		}
		unsigned long long nc=0,nf=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				//c
				if(c!=0)
				{
					unsigned long long tempc=0;
					if(ln[i][j]>=1&&lm[i][j]>=2&&num[i][j]==0)
					{
						for(int k=i+2;k<=i+lm[i][j];k++)
						{
							if(ln[k][j]>=1)
								tempc+=ln[i][j]*ln[k][j]%998244353;
						}
						nc+=tempc%998244353;
					}	
				}
				//f
				if(f!=0)
				{
					unsigned long long tempf=0;
					if(ln[i][j]>=1&&lm[i][j]>=3&&num[i][j]==0)
					{
						for(int k=i+2;k<=i+lm[i][j]-1;k++)
						{
							for(int z=k+1;z<=i+lm[i][j];z++)
							{
								if(ln[k][j]>=1)
									tempf+=ln[i][j]*ln[k][j]%998244353;
							}
						}
						nf+=tempf%998244353;
					}	
				}
			}
		}
		cout<<nc*c%998244353<<" "<<nf*f%998244353<<endl;
	}
	return 0;
}
