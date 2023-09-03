#include <iostream>
#include <cstdio>
using namespace std;
struct node {
	int x,y,z;
};
class stack {
	private:
		int a[100001];
		int last=0,first=0;
	public:
		bool empty() {
			return last==first;
		}
		void push(int x) {
			a[last++]=x;
		}
		void pop(bool x) {
			if (!empty()) {
				if (x) {
					last--;
				} else {
					first++;
				}
			}
		}
		int size() {
			return last-first;
		}
		int top() {
			return a[last-1];
		}
		int down() {
			return a[first];
		}
		void aos () {
			first--;
		}
		void soa() {
			last++;
		}
};
bool ok (int n,stack a[]) {
	for (int i=1; i<=n; i++) {
		if (!a[i].empty()) {
			return 0;
		}
	}
	return 1;
}
bool flag=0;
void dfs (int dep,int depth,int m,int n,stack a[],node l[],int uj[]) {
	if (flag) return;
	if (dep>2*m) {
		return;
	}
	if (dep>=m&&ok(n,a)&&depth>m) {
		cout << dep-1 << endl;
		for (int i=1; i<dep; i++) {
			cout << l[i].x << ' ';
			if (l[i].x==1) {
				cout << l[i].y << endl;
			} else {
				cout << l[i].y << ' ' << l[i].z << endl;
			}
		}
		flag=1;
		return;
	}
	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			if (!a[i].empty()&&!a[j].empty()&&a[i].down()==a[j].down()) {
				a[i].pop(0);
				a[j].pop(0);
				l[dep].x=2;
				l[dep].y=i;
				l[dep].z=j;
				dfs(dep+1,depth,m,n,a,l,uj);
				a[i].aos();
				a[j].aos();
				if (flag) return;
			}
		}
	}
	if (depth<=m)
		for (int i=1; i<=n; i++) {
			if (uj[depth]==a[i].top()){
				a[i].pop(1);
				l[dep].x=1;
				l[dep].y=i;
				dfs(dep+1,depth+1,m,n,a,l,uj);
				a[i].soa();
				if (flag) return;
			}
			a[i].push(uj[depth]);
			l[dep].x=1;
			l[dep].y=i;
			dfs(dep+1,depth+1,m,n,a,l,uj);
			a[i].pop(1);
			if (flag) return;
		}
}
int main() {
//	freopen("meow.in","r",stdin);
//	freopen("meow.out","w",stdout);
	int t;
	cin >> t;
	for (int i=1; i<=t; i++) {
		int n,m,v;
		cin >> n >> m >> v;
		const int wuhu=n+1,yehe=m*2+1,wuhe=m+1;
		int uj[wuhe];
		stack a[wuhu];
		node l[yehe];
		for (int i=1; i<=m; i++) cin >> uj[i];
		dfs(1,1,m,n,a,l,uj);
		flag=0;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
