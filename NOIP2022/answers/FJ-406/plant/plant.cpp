#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int T, ID;
int n, m, c, f;
int a[1005][1005];
int vc, vf;

void slove1(){//当 c=0,f=0时两个答案均为0 
	printf("0 0\n");
}

void slove2_4(){//枚举第一列，在头和尾向右边延伸 
	int aa[1005];
	scanf("%d%d%d%d", &n, &m, &c, &f);vc=vf=0;
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%1d", &a[i][j]);
		}
	} 
	for(int i = 1; i <= n; i++){
		aa[i]=aa[i-1]+a[i][1];
	}
	for(int i = 1; i <= n-2; i++){
		for (int j = i+2; j <= n; j++){
			if (aa[j]-aa[i-1] || a[i][2] || a[j][2]) continue ;
			vc++;vc%=mod;
			for (int k = j+1; k <= n; k++){
				if (aa[k]-aa[j-1]) continue ;
				vf++;vf%=mod;
			}
		}
	}
	printf("%d %d", vc*c%mod, vf*f%mod);
}

void slove5(){//枚举每个0出现的位置，套用slove2_4的做法 
	scanf("%d%d%d%d", &n, &m, &c, &f);vc=vf=0;
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%1d", &a[i][j]);
		}
	} 
	for(int j = 1; j < m; j+=3){
		for (int i = 1; i <= n-2; i++){
			vc+=n-i-1, vc%=mod;
			vf+=(n-i-2)*(n-i-1)/2, vf%=mod;
		}
	}
	printf("%d %d\n", vc*c%mod, vf*f%mod);
}

void slove6(){//
	scanf("%d%d%d%d", &n, &m, &c, &f);vc=vf=0;
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%1d", &a[i][j]);
		}
	} 
	for (int i = 1; i <= n-2; i+=4){
		for (int j = 1; j < m; j++){
			vc+=(m-j)*(m-j), vc%=mod;
		}
	}
	printf("%d 0\n", vc*c%mod);
}

void slove(){
	int s1[1005][1005], s2[1005][1005], x3, y1, y2, l, r, mid;
	scanf("%d%d%d%d", &n, &m, &c, &f);vc=vf=0;
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%1d", &a[i][j]);
		}
	} 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			s1[i][j]=s1[i][j-1]+a[i][j];
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			s2[i][j]=s2[i-1][j]+a[i][j];
		}
	}
	for (int x1 = 1; x1 <= n; x1++){
		for (int x2 = x1+2; x2 <= n; x2++){
			for (int y0 = 1; y0 <= m; y0++){
				if (s2[x2][y0]-s2[x1-1][y0]) continue ;
				l = y0, r = m;
				while(l <= r){
					int mid = (l+r)/2;
					if (s1[x1][mid]-s1[x1][y0-1]) r = mid-1;
					else l = mid+1;
				}
				y1 = l-y0-1;
				l = y0, r = m;
				while(l <= r){
					int mid = (l+r)/2;
					if (s1[x2][mid]-s1[x2][y0-1]) r = mid-1;
					else l = mid+1;
				}
				y2 = l-y0-1;
				vc+=(y1)*(y2), vc%=mod;
				for (int i = x2+1; i <= n; i++){
					if (a[i][y0]) break ;
					vf++, vf%=mod;
				}
			}
		}
	}
	printf("%d %d\n", vc*c%mod, vf*f%mod);
}

int main(){
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d", &T, &ID);
	if (ID == 1){
		while(T--){
			slove1();
		}
		return 0;
	}
	if (2 <= ID && ID <=4){
		while(T--){
			slove2_4();
		}
		return 0;
	}
	if (ID == 5){
		while(T--){
			slove5();
		}
		return 0;
	}
	if (ID == 6){
		while(T--){
			slove6();
		}
		return 0;
	} 
	while(T--){
		slove();
	}
	return 0;
}
