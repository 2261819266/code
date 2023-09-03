#include <bits/stdc++.h>
using namespace std;
int t, id;
bool w[1005][1005] = {0};
bool l[505][505][505] = {0};  //to mark 'i',means left-right lter
bool u[505][505][505] = {0};  //to mark 'j',means up-down lter
int n, m, c, f;
long long f_ans = 0;

long long work_C()
{
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (w[i][j]) continue;
			for (int k = i + 2; k <= n; k++)
			{
				if (u[j][i][k])
				{
					long long cnt1 = 0;
					for (int o = j + 1; o <= m; o++)
					{
						if (w[i][o]) break;
						if (l[i][j][o]) cnt1++;
						if (!l[i][j][o]) break;
//						cout << "FIR:" << o << endl;
					}
					long long cnt2 = 0;
					for (int o = j + 1; o <= m; o++)
					{
						if (w[k][o]) break;
						if (l[k][j][o]) cnt2++;
						if (!l[k][j][o]) break;
//						cout << "SEC:" << o << endl;
					}
					long long cnt3 = 0;
					for (int o = k + 1; o <= n; o++)
					{
						if (w[o][j]) break;
						if (u[j][i][o]) cnt3++;
						if (!u[j][i][o]) break;
					}
//					if (cnt1 * cnt2 > 0)
//					{
//						cout << i << ' ' << k << endl;
//					}
					ans += (cnt1 * cnt2);
					ans %= 998244353;
					f_ans += (cnt1 * cnt2 * cnt3);
					f_ans %= 998244353;
				}
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (w[i][j]) continue;
//			long long cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
//			int la = -1;
//			for (int k = i + 2; k <= n; k++)
//			{
//				if (w[k][j]) break;
//				if (u[j][i][k]) cnt1++;
//				else break;
//				la = k;
//			}
//			for (int k = j + 1; k <= m; k++)
//			{
//				if (w[i][k]) break;
//				if (l[i][j][k]) cnt2++;
//				else break;
//			}
//			for (int k = j + 1; k <= m; k++)
//			{
//				if (w)
//			}
//		}
//	}
	return ans;
}

void solve()
{
	cin >> n >> m >> c >> f;
	string s;
	memset(l, 0, sizeof(l));
	memset(u, 0, sizeof(u));
	f_ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
			w[i][j + 1] = s[j] - '0';
	}
	if (c == 0 && f == 0)
	{
		cout << 0 << ' ' << 0 << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//up,use 'u'
//			for (int k = i - 1; k >= 1; k--)
//			{
//				if (w[k][j]) break;
//				u[j][i][k] = 1;
//				u[j][k][i] = 1;
//			}
			
			//down,use 'u'
			for (int k = i + 1; k <= n; k++)
			{
				if (w[k][j]) break;
				u[j][i][k] = 1;
				u[j][k][i] = 1;
			}
			
			//left,use 'l'
//			for (int k = j - 1; k >= 1; k--)
//			{
//				if (w[i][k]) break;
//				l[i][j][k] = 1;
//				l[i][k][j] = 1;
//			}
			
			//right,use 'l'
			for (int k = j + 1; k <= m; k++)
			{
				if (w[i][k]) break;
				l[i][j][k] = 1;
				l[i][k][j] = 1;
			}
		}
	}
	if (c == 0)
	{
		cout << 0 << ' ' << endl;
		goto loop1;
	}
	cout << work_C() << ' ';
	loop1:;
	cout << f_ans * f << endl;
}

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t >> id;
	while (t--) solve();
	//I love PYL very much.
	return 0;
}
