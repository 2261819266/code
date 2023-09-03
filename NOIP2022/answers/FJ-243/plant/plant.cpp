#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int t,id,n,m,c,f;
int a[2001][2001];
int h[4][4000001],s[4][4000001];
char b[2001];
int mp[2001][2001];
int ansc=0,ansf=0,p,q;
int Mod=998244353;
void doc()
{
	for (int i=1;i<=q;i++)
	{
		int ls[1000001],sum=0;
		for (int j=s[2][i];j<=s[3][i];j++)
		{
			if (mp[j][s[1][i]]!=0)
			{
				ls[++sum]=mp[j][s[1][i]];
			}
		}
		for (int j=1;j<=sum;j++)
		{
			for (int k=j+1;k<=sum;k++)
			{
				if (h[1][ls[k]]-h[1][ls[j]]>1)
				{
					ansc+=(h[3][ls[j]]-s[1][i])*(h[3][ls[k]]-s[1][i]);
					ansc%=Mod;
				}
			}
		}
	}
}
void dof()
{
	for (int i=1;i<=q;i++)
	{
		int ls[1000001],sum=0;
		for (int j=s[2][i];j<s[3][i];j++)
		{
			if (mp[j][s[1][i]]!=0)
			{
				ls[++sum]=mp[j][s[1][i]];
			}
		}
		for (int j=1;j<=sum;j++)
		{
			for (int k=j+1;k<=sum;k++)
			{
				if (h[1][ls[k]]-h[1][ls[j]]>1)
				{
					ansf+=(h[3][ls[j]]-s[1][i])*(h[3][ls[k]]-s[1][i])*(s[3][i]-h[1][ls[k]]);
					ansf%=Mod;
				}
			}
		}
	}
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while (t--)
	{
		cin>>n>>m>>c>>f;
		if (c==0 && f==0) {cout<<"0"<<endl;continue;}
		for (int i=1;i<=n;i++) 
		{
			cin>>b;
			for (int j=1;j<=m;j++)
			{
				if (b[j-1]=='0') a[i][j]=0;
				else a[i][j]=1;
			}
		}
		p=0;
		for (int i=1;i<=n;i++)
		{
			int flag=0,l=0,r=0; 
			for (int j=1;j<=m;j++)
			{
				if (flag==0 && a[i][j]==0) {flag=1;l=j;}
				if (flag==1 && a[i][j]==0) {r=j;}
				if (flag==1 && (a[i][j]==1 || j==m)) 
				{
					flag=0;
					if (r-l+1>=2) 
					{
						p++;	
						h[1][p]=i;
						h[2][p]=l;
						h[3][p]=r;
					}
				}
			}
		}
		q=0;
		for (int j=1;j<=m;j++)
		{
			int flag=0,l=0,r=0; 
			for (int i=1;i<=n;i++)
			{
				if (flag==0 && a[i][j]==0) {flag=1;l=i;}
				if (flag==1 && a[i][j]==0 && a[i-1][j]==0) {r=i;}
				if (flag==1 && (a[i][j]==1 || i==n)) 
				{
					flag=0;
					if (r-l+1>=3) 
					{
						q++;	
						s[1][q]=j;
						s[2][q]=l;
						s[3][q]=r;
					}
				}
			}
		}
		for (int i=1;i<=p;i++) for (int j=h[2][i];j<=h[3][i];j++) mp[h[1][i]][j]=i;
		/*for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++) 
			{
				cout<<mp[i][j]<<" ";
			}
			cout<<endl;
		}*/
		if (c==0) {dof();cout<<"0"<<" "<<ansf<<endl;continue;}
		if (f==0) {doc();cout<<ansc<<" "<<"0"<<endl;continue;}
		else {doc();dof();cout<<ansc<<" "<<ansf<<endl;continue;}
	}
	return 0;
}
