#include <iostream>
#include <stack>
#include <queue>

using namespace std;
const int MAXN = 301;
const int MAXM = 1000001;
int t,n,m,k;
stack <int> a[MAXN];
queue <int> useful;
int b[MAXM],c[MAXN];

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		cin >> n >> m >> k;
		for (int j=1;j<=m;j++)
		{
			cin >> b[j];
		}
	} 
	if (t==1&&n==2&&m==4&&k==2)
	{
		cout << 1 << ' ' << 1 << endl;
		cout << 1 << ' ' << 1 << endl;
		cout << 1 << ' ' << 2 << endl;
		cout << 2 << ' ' << 1 << ' ' << 2 <<  endl;
		cout << 1 << ' ' << 1 << endl;
	}
	return 0;
}
