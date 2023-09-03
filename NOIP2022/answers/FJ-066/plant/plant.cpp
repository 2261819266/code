#include <bits/stdc++.h>

const int kN = 1e3 + 10;
const int kMod = 998244353;

int t, id, n, m, c, f;
char mp[kN][kN];
int r[kN][kN];
long long sc[kN], sf[kN];
long long ansc, ansf;

int main() {
  freopen("plant.in", "r", stdin);
  freopen("plant.out", "w", stdout);

  scanf("%d%d", &t, &id);
  while (t--) {
    scanf("%d%d%d%d", &n, &m, &c, &f);
    ansc = ansf = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", mp[i] + 1);
    }
    for (int i = 1; i <= n; ++i) {
      r[i][m] = (mp[i][m] == '1' ? 0 : m);
      for (int j = m - 1; j >= 1; --j) {
        r[i][j] = (mp[i][j] == '1' ? 0 : std::max(r[i][j + 1], j));
      }
    }

//    printf("%d %d %d %d\n", n, m, c, f);
//    for (int i = 1; i <= n; ++i) {
//      printf("%s\n", mp[i] + 1);
//    }
//    printf("\n");

//    for (int i = 1; i <= n; ++i) {
//      for (int j = 1; j <= m; ++j) {
//        printf("%d ", r[i][j]);
//      }
//      printf("\n");
//    }
//    printf("\n");

    for (int j = 1; j <= m; ++j) {
      memset(sc, 0, sizeof(sc));
      memset(sf, 0, sizeof(sf));
      int c = 0;
//      printf("COLUMN %d:\n", j);
      for (int i = n; i >= 1; --i) {
        if (mp[i][j] == '1') {
          sc[i] = sf[i] = 0;
          sc[i + 1] = sf[i + 1] = 0;
          c = 0;
        } else if (r[i][j] > j) {
          int t = r[i][j] - j;
          ansc += sc[i + 2] * t % kMod;
          ansc %= kMod;
          ansf += sf[i + 2] * t % kMod;
          ansf %= kMod;
          sc[i] = (sc[i + 1] + t) % kMod;
          sf[i] = (sf[i + 1] + t * c % kMod) % kMod;
          c += 1;
        } else {
          sc[i] = sc[i + 1];
          sf[i] = sf[i + 1];
          c += 1;
        }
//        printf("%d(%d): %lld %lld %lld %lld\n", i, c, ansc, ansf, sc[i], sf[i]);
      }
    }
    printf("%lld %lld\n", ansc, ansf);
  }

  return 0;
}

