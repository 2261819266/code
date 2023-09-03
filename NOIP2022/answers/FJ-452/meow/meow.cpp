#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
int T, n, m, k, a[2000005];
int mode, p;
int u[2000005], v[2000005];
int hu, hv, tu, tv;
int main(){
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> T;
	mode = T % 10;
	while(T--){
		cin >> n >> m >> k;
		for(int i = 1; i <= m; i++) cin >> a[i];
		if(mode == 2)
			p = 1;
			hu = hv = 1;
			tu = tv = 0;
			while(p != m){
				if(p < m && a[p] == a[p + 1]){//"AA" 
					cout << "1 1\n1 1\n"; 
					p += 2;
				}
				else if(hu <= tu && a[p] == u[hu]){//"A<-A"
					hu++;
					cout << "1 1\n";
					p++;
				}
				else if(hv <= tv && a[p] == v[hv]){//"B<-B"
					hv++;
					cout << "1 2\n";
					p++;
				}
				else if(hu > tu && a[p] == v[tv]){//"B B"
					tv--;
					cout << "1 1\n2 1 2\n";
					p++;
				}
				else if(hv > tv && a[p] == u[tu]){//"A A"
					tu--;
					cout << "1 2n2 1 2\n";
					p++;
				}
			}
	}
	return 0;
}
