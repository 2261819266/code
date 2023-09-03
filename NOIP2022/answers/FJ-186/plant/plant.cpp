#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=1010,mod=998244353;
ll t,id,n,m,c,f,ansc,ansf;
bool a[maxn][maxn];

void find(int x,int y){
	int i=x,j=y,abo;
	while(j<=m&&a[x][j]!=1)
		j++;
	if(j-y<2)
		return ;
	abo=j-1-y;
	while(i<=n&&a[i][y]!=1)
	{
		if(i-x>1)
		{
			int k=y;
			while(k<=m&&a[i][k]!=1)
				k++;
			ansc+=(k-1-y)*abo,ansc%=mod;
			if(f!=0)
			{
				int l=i+1;
				while(l<=n&&a[l][y]!=1)
					ansf+=(k-1-y)*abo,ansf%=mod,l++;
			}
		}
		i++;
	}
//	cout<<x<<" "<<y<<" "<<i<<" "<<j<<" |";
	return ;
}
void solve(){
	if(c==0&&f==0)
		return ;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]!=1)
				find(i,j)
				//,cout<<ansc<<" "<<ansf<<"\n"
				; 
	return ;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);			 cout.tie(0);
	
	cin>>t>>id;
	while(t--)
	{
		ansc=0,ansf=0;
		memset(a,0,sizeof(a));
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				char c;
				cin>>c,a[i][j]=c-'0';
			}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//				cout<<a[i][j]<<" ";
//			cout<<"\n";
//		}
		solve();
		ansc=(ansc*c)%mod;
		ansf=(ansf*f)%mod;
		cout<<ansc<<" "<<ansf<<"\n";
	}
	
	return 0;
}
