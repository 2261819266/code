#include<iostream>
using namespace std;

int t, n;
int a[250001], b[250001];
int q;
long long k = 0;

void search()
{
	int l, r, num1, num2;
	cin >> l >> r;
	
	for(int i = l; i <= r; i ++ )
	{
		num1 = a[i];
		num2 = b[i];
		for(int j = i; j <= r; j ++ )
		{
			k += max(num1, a[j]) * max(num2, b[j]);
			num1 = max(num1, a[j]);
			num2 = max(num2, b[j]);
		}
	}
	cout << k << endl;
	k = 0;
	return;
}

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);

	cin >> t >> n;
	for(int i = 1; i <= n; i ++)
		cin>> a[i];
	for(int i = 1; i <= n; i ++)
		cin>> b[i];
	cin >> q;

	for(int asdf = 1; asdf <= q; asdf ++)
	{
		search();
	}
	return 0;
}