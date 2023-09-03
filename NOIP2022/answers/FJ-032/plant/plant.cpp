#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
const int N = 1005;
const int P = 998244353;
int n, m, c, ff;
char s[N][N];
int f[N][N];
int sum[N]; 
int up[N][N];
int main() {
    freopen("plant.in", "r", stdin);
    freopen("plant.out", "w", stdout);
    int T, ID;
    scanf("%d%d", &T, &ID);
    while(T--) {
        scanf("%d%d%d%d", &n, &m, &c, &ff);
        for(int i=1; i<=n; ++i) {
            scanf("%s", s[i]+1);  
            f[i][m+1]=0;
            for(int j=m; j; --j) {
                if(s[i][j]=='1') f[i][j]=0;
                else f[i][j]=f[i][j+1]+1;
            }
        }
        for(int j=1; j<=m; ++j) {
            up[n+1][j]=0;
            for(int i=n; i; --i) up[i][j]=(s[i][j]=='0'?up[i+1][j]+1:0);
        }
//        for(int i=1; i<=n; ++i) {
//            for(int j=1; j<=m; ++j) printf("%d ", f[i][j]);
//            puts("");
//        }
        long long ans=0, ans2=0 ;
        for(int j=1; j<=m; ++j) {
            for(int i=1; i<=n; ++i) {
                if(s[i][j]=='0') {  
                    sum[i]=(sum[i-1]+f[i][j]-1)%P;
                    if(i>=3 && s[i-1][j]=='0' && s[i-2][j]=='0') {
                        (ans+=(long long)(f[i][j]-1)*sum[i-2])%=P;
                        (ans2+=(long long)(f[i][j]-1)*sum[i-2]%P*(up[i][j]-1))%=P;
                    }
                }
                else sum[i]=0;
//                meow("sum[%d][%d] = %d\n", i, j, sum[i]);
            }   
//            meow("ans = %lld, %lld\n", ans, ans2);
        }
        printf("%lld %lld\n", ans*c%P, ans2*ff%P);
    }
    return 0;  
} 
