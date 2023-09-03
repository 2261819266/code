#include<iostream>
#include<cstdio>

using namespace std;

const int N = 2.5e5 + 10;

int T, n;
int a[N], b[N];
int ayd[N], byd[N];
int stk[N], top;
int Q, l, r;
int maxa, maxb;
unsigned long long ans;
int x, y, z;

int main(){
	
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	
	scanf("%d%d", &T, &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	a[n+1] = n+2;
	stk[++top] = n+1;
	for(int i = n; i; i--){
		while(top && a[i] > a[stk[top]]){
			top--;
		}
		ayd[i] = stk[top];
		stk[++top] = i;
	}
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
	}
	top = 0;
	b[n+1] = n+2;
	stk[++top] = n+1;
	for(int i = n; i; i--){
		while(top && b[i] > b[stk[top]]){
			top--;
		}
		byd[i] = stk[top];
		stk[++top] = i;
	}
	a[n+1] = b[n+1] = 0;
	scanf("%d", &Q);
	while(Q--){
		scanf("%d%d", &l, &r);
		ans = 0;
		for(int i = l; i <= r; i++){
			maxa = maxb = i;
			x = i;
			y = i;
			while(x <= r && y <= r){
				z = min(ayd[maxa], byd[maxb]);
				z = min(z, r+1);
				ans += (unsigned long long)(z-x)*(unsigned long long)a[maxa]*(unsigned long long)b[maxb];
				if(a[z] > a[maxa]){
					maxa = z;
				}
				if(b[z] > b[maxb]){
					maxb = z;
				}
				x = y = z;
//				printf("%d %d %d %d %llu\n", x, y, maxa, maxb, ans);
				
//				x = z;
//				y = z;
			}
		}
		printf("%llu\n", ans);
	}
	
	
	
	return 0;
}
