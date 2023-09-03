#include <cstdio>

const int maxn = 32768 + 8;
int a[maxn][4], ans[maxn];

// void P1586() {
//     a[0][0] = 1;
//     for (int i = 1; i < maxn; i++) {
//         for (int j = i * i; j < maxn; j++) {
//             for (int k = 1; k < 5; k++) {
//                 a[j][k] += a[j - i * i][k - 1];
//             }
//         }
//     }
//     for (int i = 1; i < maxn; i++) {
//         for (int j = 1; j <= 4; j++) {
//             ans[i] += a[i][j];
//         }
//         printf("%d %d\n", i, ans[i]);
//     }
// }

// void P1586() {
    // int t;
    // for (int i = 0; i * i < maxn; i++) {
    //     is[i * i] = true;
    // }
    // scanf("%d", &t);
    // while (t--) {
    //     int n, ans = 0;
    //     scanf("%d", &n);
    //     for (int i = 0; i * i < n; i++) {
    //         for (int j = i; j * j + i * i < n; j++) {
    //             for (int k = j; ; k++) {
    //                 int x = n - k * k - i * i - j * j;
    //                 if (k * k > x) break;
    //                 if (is[x]) 
    //                     ans++;
    //             }
    //         }
    //     }
    //     printf("%d\n", ans);
    // }
// }

#include<bits/stdc++.h>
using namespace std;

const int M=32768; 
int t,n;
int dp[33000][5]={1};//注意，dp[0][0]要设为1，否则会全输出0 

int main()
{
    LOCALfo
	for (int i=1;i*i<=M;i++)//枚举所有平方数 
		for (int j=i*i;j<=M;j++)//因为j-i*i要>=0(否则会RE)，所以直接从i*i开始 
			for (int sum=1;sum<=4;sum++)//枚举使用次数 
				dp[j][sum]+=dp[j-i*i][sum-1];//计算 
	cin>>t;
	while(t--)//循环t次 
	{
		int n,ans=0;
		cin>>n;
		for (int i=1;i<=4;i++)
            printf("%d\t", dp[n][i]),
			ans+=dp[n][i];
		cout<<n<<"\t"<<ans<<endl;
	}
	return 0;
}

// int main() {
// #ifdef LOCAL
//     LOCALfo
// #endif
//     P1586();
//     return 0;
// }