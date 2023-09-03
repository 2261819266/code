#include<bits/stdc++.h>
using namespace std;
const int N=250000;
int n,a[N],b[N],Q,l,r;
int p,q,tot;
priority_queue<int> a1,b1;
int finda(int l1,int r1)
{
	int max=0;
	for(int i=l1;i<=r1;i++)
	if(a[i]>max) max=a[i];
	return max;
}
int findb(int l1,int r1)
{
	int max=0;
	for(int i=l1;i<=r1;i++)
	if(b[i]>max) max=b[i];
	return max;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;
	cin>>T>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	a1.push(a[i]);
    }
	for(int i=1;i<=n;i++)
	{
	cin>>b[i];
	b1.push(b[i]);
    }
	cin>>Q>>l>>r;
	for(int i=l;i<=r;i++)
	for(int j=i;j<=r;j++)
	{
		tot+=finda(i,j)*findb(i,j);
	}
	cout<<tot<<endl;
	return 0;
}
