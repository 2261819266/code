#include <cstdio>
#include <cstring>
#define print \
	for(int i = 1; i <= 32; i++) {\
		printf("a[%d] = %d\n", i, sgt.a[i]);\
	}\
	puts("");

const int maxn = 2e5 + 8;
int n, m;

class SegTree {
private:
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define form int k, int l, int r
#define form2 int L, int R
#define form3 form2, int x
#define form11 form, int i, int x
#define form12 form, form2
#define num (r - l + 1)
#define lm (mid - l + 1)
#define rm (num - lm)
#define p1 L, R
#define p2 p1, x
#define k0 (l == r)
#define k1 (l >= L && r <= R)
#define k2 (l > R || L > r)
#define updata a[k] = a[ls] + a[rs];
#define passk pass(k, l, r);
public:
	int a[maxn << 2];
	bool b[maxn << 2];
	void pass(form) {
		if (b[k]) {
			Def
			b[ls] ^= 1, b[rs] ^= 1;
			a[ls] = lm - a[ls];
			a[rs] = rm - a[rs];
			updata
			b[k] = false;
		}
	}
	int modify(form11) {
		if k0 return a[k] = x;
		Def
		if(i <= mid)
			modify(Ls, i, x);
		else
			modify(Rs, i, x);
		updata
		return a[k];
	}

	int Xor(form12) {
		if k1 {
			b[k] ^= (bool)(1 * (r - l));
			return a[k] = num - a[k];
		}
		if k2 return 0;
		Def passk
		Xor(Ls, p1) + Xor(Rs, p1);
		return updata;
	}

	int query(form12) {
		if k1 return a[k];
		if k2 return 0;
		Def passk
		return query(Ls, p1) + query(Rs, p1);
	}

	int modify(int i, int x) { return modify(1, 1, n, i, x); }
	int Xor(form2) { return Xor(1, 1, n, p1); }
	int query(form2) {return query(1, 1, n, p1); }
} sgt;


bool read(char s) { return s - '0'; }

void read(const char *str) {
    for (int i = 0; i < n; i++) {
		sgt.modify(i + 1, read(str[i]));
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	char *str = new char[maxn];
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	read(str);
	for (int i = 1; i <= m; i++) {
		// print
		int kk, x, y;
		scanf("%d%d%d", &kk, &x, &y);
		if (kk == 0) 
			sgt.Xor(x, y);
		else 
			printf("%lld\n", sgt.query(x, y));
	}
	return 0;
}

