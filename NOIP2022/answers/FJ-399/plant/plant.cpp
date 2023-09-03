#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define int long long
using namespace std;

const int N = 1005, MOD = 998244353;

int T, id;
int n, m, c, f, a[N][N];
int len[N][N], het[N][N];
int VC, VF;

//void init();

signed main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%lld%lld", &T, &id);
	while(T -- )
	{
		VC = 0; VF = 0;
		scanf("%lld%lld%lld%lld", &n, &m, &c, &f);
		for(int i = 1; i <= n; i ++ )
		{
			char s[N]; scanf("%s", s + 1);
			for(int j = 1; j <= m; j ++ ) a[i][j] = s[j] - '0';
		}
		for(int i = 1; i <= n; i ++ ) len[i][m + 1] = -1;
		for(int j = 1; j <= m; j ++ ) het[n + 1][j] = -1;
		for(int i = 1; i <= n; i ++ )
			for(int j = m; j >= 1; j -- )
				if(a[i][j]) len[i][j] = -1;
				else len[i][j] = len[i][j + 1] + 1;
		for(int j = 1; j <= m; j ++ )
			for(int i = n; i >= 1; i -- )
				if(a[i][j]) het[i][j] = -1;
				else het[i][j] = het[i + 1][j] + 1;
		for(int j = 1; j <= m; j ++ )
		{
			int sum = 0, prv = 0, pos = -1;
			for(int i = 1; i <= n; i ++ )
			{
				//cout << pos << " "  << prv << " " << sum << endl;
				if(a[i][j]) sum = 0;
				else
				{
					int tmp = 0;
					if(i - pos <= 1) tmp = (sum - prv) * len[i][j] % MOD;
					else tmp = sum * len[i][j] % MOD;
					VC = (VC + tmp) % MOD;
					VF = (VF + tmp * het[i][j] % MOD) % MOD;
					if(len[i][j]) sum += len[i][j], pos = i, prv = len[i][j];
				}
			}
			/*cout << VC - LAST << endl;
			LAST = VC;*/
		}
		/*for(int i = 1; i <= n; i ++ )
		{
			for(int j = 1; j <= m; j ++ ) cout << len[i][j] << " ";
			cout << endl;
		}
		puts("--------");
		for(int i = 1; i <= n; i ++ )
		{
			for(int j = 1; j <= m; j ++ ) cout << het[i][j] << " ";
			cout << endl;
		}*/
		//cout << endl << "^^^^^" << endl;
		printf("%lld %lld\n", c * VC % MOD, f * VF % MOD);
		//cout << endl << "^^^^^" << endl;
	}
	return 0;
}
