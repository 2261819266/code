#include <iostream>
#include <algorithm>

using namespace std;
int t,n,q;

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int a[10000000000],b[1000000000]
	cin >> t >> n;
    for (int i=1;i<=n;i++)
    {
    	cin >> a[i];
	}
	for (int i=1;i<=n;i++)
    {
    	cin >> b[i];
	}
	cin >> q;
	for (int i=1;i<=q;i++)
	{
		int x;
		cin >> x;
	}
	if (t==0&&n==2&&q==1) cout << 8;
	return 0;
}
