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

const int kN = 310;
const int kK = kN * 2;
const int kM = 2e6 + 10;
const int kOp = kM * 2;

using Pair = std::pair<int, int>;

int t, n, m, k, a[kM];
int cnt, tot, op[kOp], x[kOp], y[kOp];
std::deque<int> q[kN];
std::set<Pair> frt, bck;
std::unordered_set<int> fre, one;
bool vis[kN];
int loc[kM];

void Init() {
  cnt = tot = 0;
  a[m + 1] = 0;
  fre.clear();
  one.clear();
  frt.clear();
  bck.clear();
  for (int i = 1; i <= n; ++i) {
    fre.insert(i);
    q[i].clear();
  }
}

void Push(int t) {
  ++cnt;
  op[cnt] = 1;
  x[cnt] = t;
  int v = a[++tot];
//  printf("???? %d %d %d  %d\n", t, cnt, tot, v);
//  printf("PUSH %d -> %d    ", v, t);
//  std::cout << q[t].size() << "\n";
//  if (q[t].size() > m) {
//    printf("ERR\n");
//    exit(0);
//  }
  if (!q[t].empty() && q[t].back() == v) {
//    printf("ERASE\n");
    bck.erase(Pair(v, t));
//    printf("1\n");
    q[t].pop_back();
//    printf("2\n");
    if (q[t].empty()) {
//      printf("3\n");
      one.erase(t);
      fre.insert(t);
      frt.erase(Pair(v, t));
    } else {
//      printf("4: ");
//      std::cout << q[t].size() << "\n";
      bck.insert(Pair(q[t].back(), t));
//      printf("5\n");
      if (q[t].size() == 1) one.insert(t);
    }
  } else {
    if (q[t].empty()) {
      frt.insert(Pair(v, t));
      fre.erase(t);
      one.insert(t);
    } else {
      bck.erase(Pair(q[t].back(), t));
      if (q[t].size() == 1) one.erase(t);
    }
    q[t].push_back(v);
    bck.insert(Pair(v, t));
  }
}

void Merge(int tx, int ty) {
  ++cnt;
  op[cnt] = 2;
  x[cnt] = tx;
  y[cnt] = ty;
  int v = q[tx].front();

//  if (q[tx].empty() || q[ty].empty()) {
//    printf("666\n");
//    exit(0);
//  }
  frt.erase(Pair(v, tx));
  q[tx].pop_front();
  if (q[tx].empty()) {
    one.erase(tx);
    fre.insert(tx);
    bck.erase(Pair(v, tx));
  } else {
    frt.insert(Pair(q[tx].front(), tx));
    if (q[tx].size() == 1) one.insert(tx);
  }

  frt.erase(Pair(v, ty));
  q[ty].pop_front();
  if (q[ty].empty()) {
    one.erase(ty);
    fre.insert(ty);
    bck.erase(Pair(v, ty));
  } else {
    frt.insert(Pair(q[ty].front(), ty));
    if (q[ty].size() == 1) one.insert(ty);
  }
}

int Work(int id) {
  int now = a[id];
//  printf("%d: %d\n", id, now);

  auto lb = bck.lower_bound(Pair(now, 0));
  auto lf = frt.lower_bound(Pair(now, 0));
  if (lb != bck.end() && lb->first == now) {
    int t = lb->second;
//    printf("BACK %d    %d %d\n", t, lb->first, lb->second);
    Push(t);
    return 1;
  }
  if (lf != bck.end() && lf->first == now) {
    int t = lf->second;
    int emp = *fre.begin();
//    printf("FRONT %d    %d %d    %d(%lu)\n", t, lf->first, lf->second, emp, fre.size());
//    printf("%d %d: %lu %lu\n", t, emp, q[t].size(), q[emp].size());
    Push(emp);
//    printf("%d %d: %lu %lu\n", t, emp, q[t].size(), q[emp].size());
    Merge(t, emp);
    return 1;
  }

//  printf("ONE: ");
//  for (int i : one) {
//    printf("%d ", i);
//  }
//  printf("\n");
//  printf("FREE: ");
//  for (int i : fre) {
//    printf("%d ", i);
//  }
//  printf("\n");

  if (!one.empty()) {
    int t = *one.begin();
//    printf("CHOOSE %d\n", t);
    Push(t);
    return 1;
  }
  if (fre.size() > 1) {
    int t = *fre.begin();
//    printf("CHOOSE %d\n", t);
    Push(t);
    return 1;
  }

  int mx = id, num = 0;
  bool flag = false;
  for (int i = id + 1; i <= m; ++i) {
    int x = a[i];
    lb = bck.lower_bound(Pair(x, 0));
    if (lb != bck.end() && lb->first == x) {
      int t = lb->second;
      loc[i] = t;
      if (vis[t]) {
        vis[t] = false;
      } else {
        vis[t] = true;
      }
    } else {
      mx = i;
      if (x == now) {
        flag = true;
      } else {
        num = frt.lower_bound(Pair(x, 0))->second;
      }
      break;
    }
  }

  bool tmp = flag || vis[num];
  int emp = *fre.begin();
  Push(tmp ? emp : num);
  for (int i = id + 1; i < mx; ++i) {
    int t = loc[i];
    Push(t);
    vis[t] = false;
//    if (vis[t]) {
//      vis[t] = false;
//      bck.erase(Pair(q[t].back(), t));
//      q[t].pop_back();
//      bck.insert(Pair(q[t].back(), t));
//      if (q[t].size() == 1) one.insert(t);
//    }
  }

//  printf("???\n");
  if (flag) {
    Push(emp);
  } else if (tmp) {
    Push(num);
  } else {
    Push(emp);
    Merge(emp, num);
  }

//  if (mx == id || mx > m) {
//    printf("ERROR\n");
//    exit(0);
//  }
  return mx - id + 1;
}

int main() {
  freopen("meow.in", "r", stdin);
  freopen("meow.out", "w", stdout);

  t = Read();
  while (t--) {
    n = Read();
    m = Read();
    k = Read();
    for (int i = 1; i <= m; ++i) {
      a[i] = Read();
    }

//    if (t == 1) continue;
//    printf("1 %d %d %d\n", n, m, k);
//    for (int i = 1; i <= m; ++i) {
//      printf("%d ", a[i]);
//    }
//    printf("\n");
//    return 0;

    Init();
    for (int i = 1; i <= m; ) {
      i += Work(i);
//      printf("FINISH %d\n", i);
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i) {
      if (op[i] == 1) {
        printf("%d %d\n", op[i], x[i]);
      } else {
        printf("%d %d %d\n", op[i], x[i], y[i]);
      }
    }
  }

  return 0;
}

