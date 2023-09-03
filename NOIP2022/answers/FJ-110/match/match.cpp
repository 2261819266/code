#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 250005;
int id, n, log2n, q;
int a[N], b[N];
int sta[N][21];
#define stb sta
ull ans[N];
struct Matrix{
	ull a[5][5];
	Matrix(){
		memset(a, 0, sizeof(a));
	}
	const ull* operator [] (const int &x) const{return a[x];}
	ull* operator [] (const int &x){return a[x];}
	friend Matrix operator + (const Matrix &x, const Matrix &y){
		Matrix res;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				res[i][j] = x[i][j] + y[i][j];
		return res;
	}
	friend Matrix operator * (const Matrix &x, const Matrix &y){
		Matrix res;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) if (x[i][j])
				for (int k = 0; k < 5; k++)
					res[i][k] += x[i][j] * y[j][k];
		return res;
	}
	friend bool operator == (const Matrix &a, const Matrix &b){
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (a[i][j] != b[i][j])
					return 0;
		return 1;
	}
}M, Z;
struct question{
	int i, l, r, type, x;
	friend bool operator < (question q1, question q2){return q1.i < q2.i;}
};
struct question2{
	int i, l, r, id, k;
	friend bool operator < (question2 q1, question2 q2){return q1.i < q2.i;}
};
vector<question> ad;
vector<question2> as;
int getmaxa(int i, int j){
	return a[i] > a[j] ? i : j;
}
int getmaxb(int i, int j){
	return b[i] > b[j] ? i : j;
}
int getmaxaa(int l, int r){
	int t = log2(r - l + 1);
	return getmaxa(sta[l][t], sta[r - (1 << t) + 1][t]);
}
int getmaxbb(int l, int r){
	int t = log2(r - l + 1);
	return getmaxb(stb[l][t], stb[r - (1 << t) + 1][t]);
}
Matrix adda(int x){
	Matrix res;
	res[0][0] = res[1][1] = res[2][2] = res[3][3] = res[4][4] = 1;
	res[3][0] = (ull)x;
	res[1][2] = (ull)x;
	return res;
}
Matrix addb(int x){
	Matrix res;
	res[0][0] = res[1][1] = res[2][2] = res[3][3] = res[4][4] = 1;
	res[3][1] = (ull)x;
	res[0][2] = (ull)x;
	return res;
}
void builda(int l, int r){
	int p = getmaxaa(l, r);
	question ques; ques.i = l;
	ques.l = p, ques.r = r, ques.type = 0, ques.x = a[p];
	ad.push_back(ques);
	ques.x *= -1; ques.i = p + 1;
	ad.push_back(ques);
	if (l < p) builda(l, p - 1);
	if (p < r) builda(p + 1, r);
}
void buildb(int l, int r){
	int p = getmaxbb(l, r);
	question ques; ques.i = l;
	ques.l = p, ques.r = r, ques.type = 1, ques.x = b[p];
	ad.push_back(ques);
	ques.x *= -1; ques.i = p + 1;
	ad.push_back(ques);
	if (l < p) buildb(l, p - 1);
	if (p < r) buildb(p + 1, r);
}
struct tree{
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)
	Matrix a[N << 2], tag[N << 2];
	void build(int now, int l, int r){
		tag[now] = Z;
		if (l == r){
			a[now][0][3] = 1;
			return;
		}
		build(ls, l, mid);
		build(rs, mid + 1, r);
		a[now] = a[ls] + a[rs];
	}
	void update(int now, Matrix k){
		a[now] = a[now] * k;
		tag[now] = tag[now] * k;
	}
	void down(int now){
		if (tag[now] == Z) return;
		update(ls, tag[now]);
		update(rs, tag[now]);
		tag[now] = Z;
	}
	void add(int now, int l, int r, int s, int t, Matrix k){
		if (s <= l && r <= t)
			return update(now, k);
		down(now);
		if (s <= mid) add(ls, l, mid, s, t, k);
		if (t > mid) add(rs, mid + 1, r, s, t, k);
		a[now] = a[ls] + a[rs];
	}
	ull ask(int now, int l, int r, int s, int t){
		if (s <= l && r <= t)
			return a[now][0][4];
		down(now);
		ull res = 0;
		if (s <= mid) res += ask(ls, l, mid, s, t);
		if (t > mid) res += ask(rs, mid + 1, r, s, t);
		return res;
	}
#undef mid
#undef ls
#undef rs
}T;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	M[0][0] = M[1][1] = M[2][2] = M[3][3] = M[4][4] = 1;
	Z = M;
	M[2][4] = 1;
	cin >> id >> n;
	log2n = log2(n);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		sta[i][0] = i;
	for (int j = 1; j <= log2n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			sta[i][j] = getmaxa(sta[i][j - 1], sta[i + (1 << (j - 1))][j - 1]);
	builda(1, n);
	for (int i = 1; i <= n; i++)
		stb[i][0] = i;
	for (int j = 1; j <= log2n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			stb[i][j] = getmaxb(stb[i][j - 1], stb[i + (1 << (j - 1))][j - 1]);
	buildb(1, n);
	cin >> q;
	for (int i = 1; i <= q; i++){
		int l, r;
		cin >> l >> r;
		question2 ques;
		ques.l = l, ques.r = r, ques.id = i, ques.k = 1; ques.i = r;
		as.push_back(ques);
		ques.k = -1; ques.i = l - 1;
		as.push_back(ques);
	}
	sort(ad.begin(), ad.end());
	sort(as.begin(), as.end());
	T.build(1, 1, n);
	for (int i = 1, j = 0, k = 0; i <= n; i++){
		for (; j < (int)ad.size() && ad[j].i == i; j++){
			question ques = ad[j];
			if (ques.type == 0) T.add(1, 1, n, ques.l, ques.r, adda(ques.x));
			else T.add(1, 1, n, ques.l, ques.r, addb(ques.x));
		}
		T.add(1, 1, n, 1, n, M);
		for (; k < (int)as.size() && as[k].i < i; k++);
		for (; k < (int)as.size() && as[k].i == i; k++){
			question2 ques2 = as[k];
			ans[ques2.id] += ques2.k * T.ask(1, 1, n, ques2.l, ques2.r);
		}
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
	return 0;
}
