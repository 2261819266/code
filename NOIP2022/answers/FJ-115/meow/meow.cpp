#include<bits/stdc++.h>
#define Maxm 2000007
#define Maxn 307
using namespace std;
set<int> C1, C2, C0;
int a[Maxm], stk[Maxn][2], spe, n, m, T, k, from[Maxn << 1], sum[Maxn];
struct Node {int opt, s1, s2;} ans[Maxm << 1];
struct My {int u, v;} Find[Maxm << 1];
void solve(){
	cin >> n >> m >> k; int cnt = 0, lst = -1; spe = -1; 
	for(int i = 1; i <= m; i ++) cin >> a[i];
	for(int i = 1; i <= m; i ++) ans[i] = {-1, -1, -1};
	// 以下是为了我看起来比较呆的spj，提交务必删除，切记，切记。
	//cout << n << " " << m << " " << k << "\n"; 
	//for(int i = 1; i <= m; i ++) cout << a[i] << " ";
	//puts("");
	// 以上是为了我看起来比较呆的spj，提交务必删除，切记，切记。
	for(int i = 1; i <= n; i ++) stk[i][0] = stk[i][1] = -1, sum[i] = 0, Find[i] = {i * 2 - 1, i * 2};
	for(int i = 1; i <= k; i ++) {from[i] = (i - 1) / 2 + 1; sum[from[i]] += i; }
	for(int i = 1; i < n; i ++) C0.insert(i); if(from[k] >= n) spe = k, from[k] = -1;
	//for(int i = 1; i <= m; i ++) if(! from[a[i]]) puts("!!!");
	for(int i = 1; i <= m; i ++){
		//cout << spe << " " << from[spe] << " " << from[5] << "??\n";
		//if(cnt == 3651) cout << spe << " " << from[spe] << " " << lst << " " << a[i] << " " << from[a[i]] << " " << stk[7][0] << " " << stk[7][1] << "!!!!!\n";
		//if(spe == 4) cout << "??\n";
		//if(!from[a[i]]) cout << i << " " << a[i] << " " << spe << "!!!\n";
		//cout << spe << "!!?\n";
		if(a[i] != spe){ 
			if(stk[from[a[i]]][1] == -1){
				if(stk[from[a[i]]][0] == a[i]){
					ans[++ cnt] = {1, from[a[i]], -1};
					stk[from[a[i]]][0] = -1; C1.erase(from[a[i]]); C0.insert(from[a[i]]);
				}else if(stk[from[a[i]]][0] == -1){
					ans[++ cnt] = {1, from[a[i]], -1};
					stk[from[a[i]]][0] = a[i]; C0.erase(from[a[i]]); C1.insert(from[a[i]]);
				}else{
					ans[++ cnt] = {1, from[a[i]], -1};
					stk[from[a[i]]][1] = a[i]; C1.erase(from[a[i]]); C2.insert(from[a[i]]);
				}
			}else{
				//cout << i << "!!\n";
				if(stk[from[a[i]]][1] == a[i]){
					ans[++ cnt] = {1, from[a[i]], -1};
					stk[from[a[i]]][1] = -1; C2.erase(from[a[i]]); C1.insert(from[a[i]]);
				}else{
					ans[++ cnt] = {1, n, -1}; ans[++ cnt] = {2, from[a[i]], n};
					//为什么是 0 10. 
					if(lst != -1){
						if(Find[from[a[i]]].u == stk[from[a[i]]][0]) Find[from[a[i]]].u = spe; else Find[from[a[i]]].v = spe;
						stk[from[a[i]]][0] = stk[from[a[i]]][1], stk[from[a[i]]][1] = spe;
						ans[lst] = {1, from[a[i]], -1}; lst = -1; sum[from[a[i]]] -= -spe + a[i]; swap(a[i], spe);
						swap(from[a[i]], from[spe]);
						//C2.erase(from[a[i]]); C1.insert(from[a[i]]);
					}else{
						stk[from[a[i]]][0] = stk[from[a[i]]][1], stk[from[a[i]]][1] = -1;
						C2.erase(from[a[i]]); C1.insert(from[a[i]]);						
					}
				}
			}
		}else{
			if(lst != -1){
				ans[lst] = {1, n, -1}; ans[++ cnt] = {1, n, -1}; lst = -1;
			}else if(C1.size()){
				//cout << i << "ffff\n";
				//if(! from[spe]) puts("!!!"); //if(spe == 4) cout << from[23] << "??\n";
				int temp = *C1.begin(); int OthEr;
				if(Find[temp].u == stk[temp][0]) OthEr = Find[temp].v; else OthEr = Find[temp].u;
				//if(OthEr > k) cout << stk[temp][0] << " " << sum[temp] << "\n", puts("!!!!?");
				if(Find[temp].u == OthEr) Find[temp].u = spe; else Find[temp].v = spe;
				C1.erase(temp); stk[temp][1] = spe; sum[temp] = stk[temp][0] + spe;
				from[spe] = temp; from[OthEr] = -1; swap(OthEr, spe); 
				ans[++ cnt] = {1, temp, -1}; C2.insert(temp);
				//if(! from[OthEr]) cout << from[spe] << " " << spe << " " << OthEr << " " , puts("!!!");
			}
			else if(C0.size()){
				//cout << i << "ffff\n";
				int temp = *C0.begin(); int OthEr = Find[temp].u; //if(! OthEr) puts("!!!");
				C0.erase(temp); stk[temp][0] = spe; sum[temp] = sum[temp] - OthEr + spe;
				from[spe] = temp; from[OthEr] = -1; Find[temp].u = spe; swap(OthEr, spe); 
				ans[++ cnt] = {1, temp, -1}; C1.insert(temp);
				//if(! from[OthEr]) puts("!!!");
			}else {lst = ++ cnt;}
		}
	} cout << cnt << "\n";
	for(int i = 1; i <= cnt; i ++){
		if(ans[i].opt & 1) {cout << "1 " << ans[i].s1 << "\n";}
		else {cout << "2 " << ans[i].s1 << " " << ans[i].s2 << "\n";}
	}
}
int main(){
	freopen("meow.in", "r", stdin); freopen("meow.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T; 
	// 以下是为了我看起来比较呆的spj，提交务必删除，切记，切记。
	//cout << T << "\n"; 
	
	// 以上是为了我看起来比较呆的spj，提交务必删除，切记，切记。	
	while(T --) solve();
	
}
