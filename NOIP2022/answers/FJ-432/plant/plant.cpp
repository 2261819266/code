#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+15,MOD=998244353;
int T,id,n,m,c,f;
int mes[MAXN],sum[MAXN],tit;
unsigned long long Cans,Fans;
char mep[MAXN][MAXN];
vector<int> p1[MAXN],p2[MAXN];
vector<int>::iterator iter;
int main()
{
	ios::sync_with_stdio(false);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--)
	{
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				cin>>mep[i][j];
				if(mep[i][j]=='1') 
				{
					p1[i].push_back(j);
					p2[j].push_back(i);
				}
			}
		}
		if(c==0&&f==0)
		{
			cout<<"0 0\n";
			continue;
		}
		for(int i=1;i<=m;++i) p2[i].push_back(n+1);
		Cans=Fans=0;
		for(int j=1;j<m;++j)
		{
			for(int i=1;i<=n;++i)
			{
				if(mep[i][j]=='1'||mep[i][j+1]=='1') mes[i]=0;
				else
				{
					iter=upper_bound(p1[i].begin(),p1[i].end(),j);
					if(iter==p1[i].end()) mes[i]=m-j;
					else mes[i]=*iter-j-1;
				}
				sum[i]=sum[i-1]+mes[i];
//				cout<<i<<" "<<j<<" ";
//				cout<<mes[i]<<endl;
			}
			tit=1;
			for(int k=0;k<p2[j].size();++k)
			{
				if(p2[j][k]>tit+2)
					for(int i=tit+2;i<p2[j][k];++i)
					{
						Cans+=(mes[i]*(sum[i-2]-sum[tit-1]))%MOD;
						if(p2[j][k]-i-1>=1) Fans+=((((mes[i]*(sum[i-1]-sum[tit-1]))%MOD)*(p2[j][k]-i-1))%MOD);
						Cans%=MOD;
						Fans%=MOD;			
					}
				tit=p2[j][k]+1;
			}
			for(int i=1;i<=n;++i) mes[i]=sum[i]=0;
		}
		cout<<Cans*c<<" "<<Fans*f<<endl;
		for(int i=1;i<=n;++i) p1[i].clear();
		for(int i=1;i<=m;++i) p2[i].clear();
	}
	return 0;
}
