//MOD 998244353, ans*c,f
#include <bits/stdc++.h>

using namespace std;

const int N=1000;
const int MOD=998244353;

int n, m;
long long C, F;
string str[N+10];
int nxtX[N+10][N+10];
int nxtX_sum[N+10][N+10];
int nxtY[N+10][N+10];
int nxtY_sum[N+10][N+10];

int find_c() {

	int now_ans=0;

	for(int y=1; y<=m; y++)
		for(int i=1; i<=n; i++)
			for(int j=i+2; j<=n; j++)
				if(nxtY[i][y]==nxtY[j][y] && nxtY[i][y]!=0) {

					now_ans+=(nxtX_sum[i][y]-1)*(nxtX_sum[j][y]-1);
					now_ans%=MOD;

//					cout<<y<<" "<<i<<" "<<j<<" "<<(nxtX_sum[i][y]-1)*(nxtX_sum[j][y]-1)<<" "<<nxtY[i][y]<<" "<<nxtY[j][y]<<endl;

				}

	return now_ans;
}

int find_f() {

	int now_ans=0;

	for(int y=1; y<=m; y++)
		for(int i=1; i<=n; i++)
			for(int j=i+2; j<=n; j++)
				if(nxtY[i][y]==nxtY[j][y] && nxtY[i][y]!=0) {

					now_ans+=(nxtX_sum[i][y]-1)*(nxtX_sum[j][y]-1)*(nxtY[j][y]-j);
					now_ans%=MOD;

				}

	return now_ans;
}

void init() {

	int now_nxt, now_sum;

	for(int i=1; i<=n; i++) {

		now_nxt=m, now_sum=0;

		for(int j=m; j>=1; j--) {

			if(str[i][j]=='0') {

				now_sum++;
				nxtX[i][j]=now_nxt;
				nxtX_sum[i][j]=now_sum;

			} else {

				now_sum=0;
				now_nxt=j-1;

			}

		}

	}

	for(int i=1; i<=m; i++) {

		now_nxt=n, now_sum=0;

		for(int j=n; j>=1; j--) {

			if(str[j][i]=='0') {

				now_sum++;
				nxtY[j][i]=now_nxt;
				nxtY_sum[j][i]=now_sum;

			} else {

				now_sum=0;
				now_nxt=j-1;

			}

		}

	}

//	for(int i=1; i<=n; i++) {
//
//		for(int j=1; j<=m; j++)
//			cout<<nxtX[i][j]<<" ";
//
//		cout<<endl;
//
//	}
//
//	cout<<endl;
//
//	for(int i=1; i<=n; i++) {
//
//		for(int j=1; j<=m; j++)
//			cout<<nxtX_sum[i][j]<<" ";
//
//		cout<<endl;
//
//	}
//
//	cout<<endl;
//
//	for(int i=1; i<=n; i++) {
//
//		for(int j=1; j<=m; j++)
//			cout<<nxtY[i][j]<<" ";
//
//		cout<<endl;
//
//	}
//
//	cout<<endl;
//
//	for(int i=1; i<=n; i++) {
//
//		for(int j=1; j<=m; j++)
//			cout<<nxtY_sum[i][j]<<" ";
//
//		cout<<endl;
//
//	}
//
//	cout<<endl;
//	cout<<endl;

	return;
}

int main() {

	int T, id;

	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);

	scanf("%d%d", &T, &id);

	while(T--) {

		scanf("%d%d%lld%lld", &n, &m, &C, &F);

		for(int i=1; i<=n; i++)
			cin>>str[i];

		for(int i=1; i<=n; i++) str[i]=" "+str[i];

		init();

		int c_ans=0;
		int f_ans=0;
		if(C) c_ans=find_c();
		if(F) f_ans=find_f();

		printf("%d %d\n", c_ans, f_ans);

	}

	return 0;
}
