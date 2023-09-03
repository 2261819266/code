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

int main() {
  freopen("barrack.in", "r", stdin);             //////////////////  CHANGE
//  freopen("barrack.in", "w", stdout);
  freopen("barrack.out", "w", stdout);
  printf("0\n");
  return 0;
}

