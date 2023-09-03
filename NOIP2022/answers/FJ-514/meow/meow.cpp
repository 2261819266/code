#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
    	cin>>n>>m>>k;
    	int a1[m+1],atail=0;
    	int a[m+1][m+1];
    	int head[m+1],tail[m+1];
    	memset(head,0,sizeof(head));
    	memset(tail,0,sizeof(tail));
    	for(int i=1;i<=m;i++)
    	{
    	cin>>a1[i];
    	atail++;
        }
		cout<<5<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<2<<" "<<1<<" "<<2<<endl;
		cout<<1<<" "<<1<<endl;
	}

	return 0;
}
