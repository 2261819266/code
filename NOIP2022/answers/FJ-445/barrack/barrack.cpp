#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("bsrrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int m,n,a;
	cin>>m>>n;
	for(int i=0;i<=n;i++)
	{
		a=m*(m+n)/2;
		cout<<a;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
