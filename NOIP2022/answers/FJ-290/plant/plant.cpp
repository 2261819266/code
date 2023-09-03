#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int N = 1e3 + 10, P = 998244353;

int T, id, n, m, c, f;
char t;
bool a[N][N];
int sum[N][N];
long long ans1, ans2;

int sfqk(int x1, int y1, int x2, int y2){
	return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}

int erfeny(int x, int y1){
	int l = y1, r = m, mid = 0;
	while(l < r){
		mid = (l + r + 1) >> 1;
		if(sfqk(x, y1, x, mid) == 0){
			l = mid;
		}else{
			r = mid - 1;
		}
	}
//	printf("%d %d: %d\n", x, y1, l);
	return l;
}

struct node{
	int nx, len;
}slcans[N];
int slccnt = 0;

void solvec(int y1, int x1, int x2){
	int y2 = 0;
	slccnt = 0;
	for(int i = x1; i <= x2; i++){
		y2 = erfeny(i, y1);
		if(y2 - y1 >= 1){
			slcans[++slccnt].nx = i;
			slcans[slccnt].len = y2 - y1;
		}
	}
	long long slsum = 0;
//	long long dbc = 0;
	for(int i = 1; i <= slccnt; i++){
		if(slcans[i-1].nx + 1 < slcans[i].nx){
			slsum += slcans[i-1].len;
		}
		if(slcans[i-2].nx + 1 == slcans[i-1].nx && slcans[i-2].nx + 1 < slcans[i].nx){
			slsum += slcans[i-2].len;
		}
		ans1 += ((slsum * slcans[i].len) % P);
		ans2 += ((((slsum * slcans[i].len) % P) * (x2-slcans[i].nx)) % P);
//		dbc += ((slsum * slcans[i].len) % P);
		ans1 %= P;
		ans2 %= P;
//		printf("%d\n", slcans[i].len);
	}
//	printf("%d %d %d: %d\n", y1, x1, x2, dbc);
}

int main(){
	
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	scanf("%d%d", &T, &id);
	while(T--){
		scanf("%d%d%d%d", &n, &m, &c, &f);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin>>t;
				if(t == '1'){
					a[i][j] = 1;
				}else{
					a[i][j] = 0;
				}
				sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
			}
		}
		
		for(int i = 1; i <= m; i++){
			int bej = 1;
			int j = 1;
			for(; j <= n; j++){
				if(a[j][i] == 1){
					if(bej != j){
						solvec(i, bej, j-1);
					}
					bej = j+1;
				}
			}
			if(bej < n){
				solvec(i, bej, n);
			}
		}
		
		printf("%lld %lld\n", ans1*c, ans2*f);
		
	}
	
	
	return 0;
}
