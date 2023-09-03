// koruneko!
#include <bits/stdc++.h>
#define M 2000010
using namespace std;

int n,m,k,a[M];
map<int,int> l,r,s1;
map<int,bool> s2;
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	l.clear(),r.clear();
	s1.clear();
	s2.clear();
	for (int i = 1;i <= m;i++){
		scanf("%d",&a[i]);
		if (s2[a[i]]){
			r[s1[a[i]]] = i;
			l[i] = s1[a[i]];
			s2[a[i]] = 0;
		}
		else{
			s2[a[i]] = 1;
			s1[a[i]] = i;
		}
	}
	int mi = 1e9,cnt = 0;
	deque<int> q[310];
	cout << m << endl;
	for (int i = 1;i <= m;i++){
		if (l[i]){
			bool check = 0;
			for (int j = 1;j <= n;j++){
				if (q[j].front() == a[i]){
					printf("1 %d\n",j);check = 1;
					break;
				}
			}
			if (!check) q[1].push_back(a[i]),puts("1 1");
		}
		else{
			if (r[i] < mi){
				mi = r[i];
				cnt++;cnt %= n;
				q[cnt].push_back(a[i]);
				printf("1 %d\n",cnt);
			}
			else{
				q[cnt].push_back(a[i]);
				printf("1 %d\n",cnt);
			}
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;cin >> T;
	while (T--) solve();
	return 0;
}

