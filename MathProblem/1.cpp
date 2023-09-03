// 对于集合 [1, n] 
// 有多少子集满足这一子集中所有数之和能被m整除

#include <cstdio>
#include <iostream>
#include <vector>
#include <BigInteger>
#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

using std::cerr;

bool St;
int n;
const int m = 5;
typedef unsigned long long ull;
ull ans;

using std::vector;
using std::string;
// using std::cin;

vector<BigInteger> a[m];



// void dfs(int i = 0, ull sum = 0) {
//     if (i == n) {
//         if (!(sum % m)) {
//             ans++;
//         }
//         return;
//     }
//     i++;
//     dfs(i, sum);
//     dfs(i, sum + i);
// }

// void P1() {
//     scanf("%d", &n);
//     dfs();
//     printf("%llu\n%x", ans, ans);
// }   

// void P1() {
//     int l, r;
//     scanf("%d%d", &l, &r);
//     for (n = l; n <= r; n++) {
//         ans = 0;
//         dfs();
//         printf("%llu %x %lf\n", ans, ans, ans * 1.0 / (1 << n));
//     }
// }  

vector<BigInteger> pow2;

void P1() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < m; i++) {
        a[i].assign(n + 1, 0);
    }
    a[0][0] = 1;
    BigInteger ans;
    pow2.push_back(1);
    rep(i, 1, n) {
        rep(j, 0, m - 1) {
            a[j][i] = a[j][i - 1];
        }
        rep(j, 0, m - 1) {
            a[(i + j) % 5][i] += a[j][i - 1];
        }
        ans = 0ull;
        rep(j, 1, m) {
            ans += a[0][i];
        }
        pow2.push_back(pow2[i - 1] + pow2[i - 1]);
        // a[0][i].print();
        // printf(" %.32lf ", a[0][i].back() * 1.0 / pow2.back());
        
    }
    ans.print();
    putchar(10);
    (pow2[2000] + pow2[402]).print();
    putchar(10);
    // a[0][n].print();
}

bool Ed;

int main() {
    // 1 - 0x7fffffff;
	cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
	cerr << (double)std::abs(&Ed - &St) / 1024.0 << "Kb\n";
	cerr << (double)std::abs(&Ed - &St) << "B\n";
    P1();
	cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
