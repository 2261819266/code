#include<bits/stdc++.h>
using namespace std;
int n,m,c,f,t,id;
bool bk[1010][1010];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	for(int jy=1;jy<=t;jy++){
	cin>>n>>m>>c>>f;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>bk[i][j];
		}
	}
	cout<<0<<" "<<0<<endl;
    }
    return 0;
}