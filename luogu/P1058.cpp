// #include <cstdio>
// #include <algorithm>
// #include <cstdlib>
// #include <synchapi.h>
// #include <windows.h>

// using std::max;

// const int maxn = 105 * 5;
// char a[maxn][maxn];
// const char s[6][8] = {
//   "\0\0+---+",
//    "\0/   /|",
//     "+---+ |",
//     "|   | +",
//     "|   |/",
//     "+---+"
// };

// void init() {
//     for (int i = 0; i < maxn; i++) {
//         for (int j = 0; j < maxn; j++) {
//             a[i][j] = '.';
//         }
//     }
// }

// int h, l;

// void draw(int x, int y) {
//     for (int i = 0; i < 6; i++) {
//         for (int j = 0; j < 8; j++) {
//             if (s[6 - i - 1][j]) {
//                 a[x + i][y + j] = s[6 - i - 1][j];
//                 h = max(h, x + i);
//                 l = max(l, y + j);
//             }
//         }
//     }
// }

// void print() {
//     for (int i = h; i >= 0; i--) {
//         for (int j = 0; j <= l; j++) {
//             printf("%c", a[i][j]);
//         }
//         putchar('\n');
//     }
//     putchar('\n');
// }

// void P1058() {
//     init();
//     int n, m;
//     scanf("%d%d", &n, &m);
//     // if (n > 10) return;
//     int x = 2 * (n - 1);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             int o;
//             scanf("%d", &o);
//             for (int k = 0; k < o; k++) {
//                 draw(x + k * 3, x + j * 4);
//             }
//         }
//         print();
//         Sleep(1000);
//         x -= 2;
//     }
//     print();
// }

// int main() {
// #ifdef LOCAL
//     LOCALfo
// #endif
//     freopen("con", "w", stdout);
//     P1058();
//     return 0;
// }
#include <cstdio>

struct SegTree {
#define ls (k << 1)
#define rs (ls | 1)
#define mid ((l + r) / 2)
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define pushup a[k] = a[ls] + a[rs];

    static const int maxn = 1e5 + 8;
    int a[maxn << 2], b[maxn << 2];
    int modify(int k, in tl, int r, int L, int R, int x) {

    }

};

