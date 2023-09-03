#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3000 + 5;
int ma[N][N]={0},mb[N][N]={0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int i,j,n,m,Q,t,l,r,p,q;
	unsigned ll ans=0;
	cin>>t>>n;
	for(i=1;i<=n;i++)	cin>>ma[i][i];
	for(i=1;i<=n;i++)	cin>>mb[i][i];
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			ma[i][j]=max(ma[j][j],ma[i][j-1]),
			mb[i][j]=max(mb[j][j],mb[i][j-1]);
	cin>>Q;
	while(Q--)
	{
		cin>>l>>r;ans=0;
		for(p=l;p<=r;p++)
			for(q=l;q<=r;q++)
				ans+=ma[p][q]*mb[p][q];
		cout<<ans<<endl;
	}			
	return 0;
}
//希望 CCF 的机子跑的过 O(qn^2) TAT  
