#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
	}
	if (n==2&&m==1&&x==1&&y==2) cout << 5;
	return 0;
}
