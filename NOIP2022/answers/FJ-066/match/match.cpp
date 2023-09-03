#include <bits/stdc++.h>

char ReadChar() {
  static const int kBufSize = 1e6;
  static char inbuf[kBufSize + 10];
  static char* now = inbuf;
  static char* lim = inbuf;
  if (now == lim) {
    lim = fread(inbuf, sizeof(char), kBufSize, stdin) + inbuf;
    now = inbuf;
  }
  return now == lim ? EOF : *(now++);
}

int Read() {
  int res = 0;
  bool neg = false;
  char ch;
  while (!isdigit(ch = ReadChar())) neg |= (ch == '-');
  do {
    res = res * 10 + ch - '0';
  } while (isdigit(ch = ReadChar()));
  return neg ? -res : res;
}

const int kN = 2.5e5 + 10;
const int kQ = 2.5e5 + 10;

int t, n, q, l, r;
unsigned long long a[kN], b[kN];

int main() {
  freopen("match.in", "r", stdin);             //////////////////  CHANGE
  freopen("match.out", "w", stdout);

  t = Read();
  n = Read();
  for (int i = 1; i <= n; ++i) {
    a[i] = Read();
  }
  for (int i = 1; i <= n; ++i) {
    b[i] = Read();
  }

  q = Read();
  while (q--) {
    l = Read();
    r = Read();
    unsigned long long ans = 0;
    for (int p = l; p <= r; ++p) {
      for (int q = p; q <= r; ++q) {
        unsigned long long ma = 0, mb = 0;
        for (int x = p; x <= q; ++x) {
          ma = std::max(ma, a[x]);
          mb = std::max(mb, b[x]);
        }
        ans += ma * mb;
      }
    }
    printf("%llu\n", ans);
  }

  return 0;
}

