#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
int t,id,n,m,wi[1001][1001],wj[1001][1001],c,f;
ll vc,vf;
string s;
bool a[1001][1001];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--)
	{
		cin>>n>>m>>c>>f;vc=0;vf=0;
		memset(wi,0,sizeof(wi));
		memset(wj,0,sizeof(wj));
		for(int i=0;i<n;i++)
		{
			cin>>s;
			for(int j=0;j<m;j++)
				a[i][j]=s[j]-'0';
		}
		for(int i=n-1;i>-1;i--)
			for(int j=0;j<m;j++)
				if(!a[i][j])
					wi[i][j]=wi[i+1][j]+1;
		for(int i=0;i<n;i++)
			for(int j=m-1;j>-1;j--)
				if(!a[i][j])
					wj[i][j]=wj[i][j+1]+1;
		if(c)
		{
			vc=0;
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					if(wj[i][j]>1&&wi[i][j]>2)
					{
						ll w=wj[i][j]-1;
						for(int k=i+2;k<n&&wj[k][j];k++)
							if(wj[k][j]>1)
								vc=(vc+w*(wj[k][j]-1))%mod;
					}
			cout<<vc<<" ";
		}
		else
			cout<<"0 ";
		if(f)
		{
			vf=0;
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					if(wj[i][j]>1&&wi[i][j]>3)
					{
						ll w=wj[i][j]-1;
						for(int k=i+2;k<wi[i][j]+i-1&&!a[k][j];k++)
							if(wj[k][j]>1)
								vf=((vf+w*(wj[k][j]-1)*(wi[i][j]-k+i-1)))%mod;
					}
			cout<<vf<<endl;
		}
		else
			cout<<"0/n";
	}
}
