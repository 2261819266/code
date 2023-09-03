#include <bits/stdc++.h>
#define mid ((l+r)>>1)
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
// Luogu@Walker33424, id:i forget
/* Checklist:
1.!!!dont's leave -> //freopen
2.check location
3.is the code passed all the testpoints
4.is the code tested in Noilinux2
5.save the code in correct folder
Notes:
Backup histroy versions
Don't spend more than 25min on thinking one problem
*/
// upd on 9:02 there seems to be some fighter jets above my head
// rp++
// OK all testpoints were passed:9:37, preparing to add segment tree
// i'll come back later:9:41, i'm going to solve other problems first, so this code should get 70points
// Caution!i didn't add freopen and tested in noilinux!
// Caution!i didn't add freopen and tested in noilinux!
// Caution!i didn't add freopen and tested in noilinux!
// Caution!i didn't add freopen and tested in noilinux!
// wc segment tree passed all tesepoints directly at 9:59, wait i'm going to check if it's really working
// 10:00: omg this is crazy, then i'll  test it in noilinux
// 10:05 it's working!
const ll M=998244353;
bool mp[1003][1003];
ll v[1003][1003], vd[1003][1003];
ll trv[1003][4012], trvd[1003][4012];
void rst(){
	for (ll x=1;x<=1000;++x){
		for (ll y=1;y<=1000;++y){
			mp[y][x] = false;
			v[y][x] = -1;
		}
	}
}
void push_up(ll p, ll tr[]){
	tr[p] = (tr[ls]+tr[rs]) % M;
}
ll xw;
void build(ll p, ll l, ll r, ll tr[], bool isf=false){
	if (l == r){
		if (v[l][xw] < 1 or (isf and vd[l][xw] < 1))tr[p] = 0;
		else tr[p] = v[l][xw];
		if (isf)tr[p] = (tr[p]*vd[l][xw])% M;
		return;
	}
	build(ls, l, mid, tr, isf);
	build(rs, mid+1, r, tr, isf);
	push_up(p, tr);
}
ll query(ll p, ll nl, ll nr, ll l, ll r, ll tr[]){
	if (nl <= l and nr >= r){
		return tr[p];
	}
	ll res=0;
	if (nl <= mid)res += query(ls, nl, nr, l, mid, tr);
	if (nr > mid)res += query(rs, nl, nr, mid+1, r, tr);
	return res;
}
int main(){
	// check freopen
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	string ln;
	ll rt, id, yn, xn, cn, fn, c, f;
	ios::sync_with_stdio(false);
	cin >> rt >> id;
	while (rt--){
		cn=0, fn=0;
		rst();
		cin >> yn >> xn >> c >> f;
//		printf("YN:%lld, XN:%lld\n", yn, xn);
		for (ll x=1;x<=yn;++x){
			cin >> ln;
			for (ll i=1;i<=xn;++i){
				if (ln[i-1] == '1'){
					mp[x][i] = true;
				}
			}
		}
		for (ll y=1;y<=yn;++y){ // 计算每个点能向右延伸多少 
			for (ll x=xn;x>=1;--x){
				if (mp[y][x])continue;
				if (x+1 <= xn and not mp[y][x+1]){
					v[y][x] = v[y][x+1]+1;
				} else {
					v[y][x] = 0;
				}
			}
		}
		for (ll y=yn;y>=1;--y){ // 计算每个点能向下延伸多少 
			for (ll x=1;x<=xn;++x){
				if (mp[y][x])continue;
				if (y+1 <= yn and not mp[y+1][x])vd[y][x] = vd[y+1][x]+1;
				else vd[y][x] = 0;
			}
		} 
		for (ll x=1;x<=xn;++x){
			xw = x;
			build(1, 1, yn, trv[x], false);
			build(1, 1, yn, trvd[x], true);
		}
//		for (ll x=1;x<=)
		// 对于C:枚举左上点x, y，对答案的贡献为v[y][x]*(∑v[y'][x]) (y+2 to y+vd[y][x]) , 之后用数据结构优化 ,不合法的行为0 
		for (ll y=1;y<=yn;++y){
			for (ll x=1;x<=xn;++x){
				if (mp[y][x] or v[y][x] < 1 or vd[y][x] < 2)continue;
				ll tas=0;
//				for (ll i=y+2;i<=y+vd[y][x];++i){ // 记得把这里改成线段树！ 
//					if (not v[i][x])continue;
//					tas = (tas + (v[y][x] % M)*(v[i][x] % M)) % M;
//				}
				tas += ((v[y][x] % M)*query(1, y+2, y+vd[y][x], 1, yn, trv[x]))% M;
				cn = (cn+tas)%M;
			}
		}
		// time:9:14
		// 对于F: 似乎只是在C的基础上乘上vd[c左下角][x] 
		for (ll y=1;y<=yn;++y){
			for (ll x=1;x<=xn;++x){
				if (mp[y][x] or v[y][x] < 1 or vd[y][x] < 3)continue; 
				ll tas=0;
//				for (ll i=y+2;i<=y+vd[y][x];++i){// 记得把这里改成线段树！
//					if (not v[i][x])continue;
//					tas = (tas+ (v[y][x] % M)*(v[i][x] % M)*(vd[i][x] % M)) % M;
//				}
				tas += (v[y][x]%M)*query(1, y+2, y+vd[y][x], 1, yn, trvd[x]);
				fn = (fn+tas) % M;
			}
		}
		cout << (cn*(c%M))%M << " " << (fn*(f%M))%M << endl;
	}
}
