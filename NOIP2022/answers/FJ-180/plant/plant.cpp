#include <cstdio>
#include <algorithm>

const int N = 1024,p = 998244353;
int a[N][N];
int n,m,id,c,f,t,c_cnt,f_cnt;

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d %d",&t,&id);
	getchar();
	while (t--){
		scanf("%d %d %d %d",&n,&m,&c,&f);
		getchar();
		for (int i = 1;i <= n;++i){
			for (int j = 1;j <= m;++j)
				a[i][j] = getchar()-'0';
			getchar();
		}
		
		for (int i = 1;i <= n-2;++i){
			for (int j = 1;j <= m-1;++j){
				int k = 0,j_1 = j+1,w = 0,i_1 = i+3,l = 0;
				if (a[i+1][j] || a[i][j+1] || a[i+2][j] || a[i][j]) continue;
				while (j_1 <= m && a[i][j_1] == 0) ++j_1,++l;
				while (i_1 <= n && a[i_1][j] == 0) ++i_1,++w;
				j_1 = j+1;
				i_1 = i+2;
				for (;i_1 <= n && a[i_1][j] == 0;++i_1,j_1 = j+1){
					k = 0;
					while (j_1 <= m && a[i_1][j_1] == 0)++j_1,++k;
					if (k == 0) continue;
					c_cnt = (c_cnt + l*k%p)%p;
					f_cnt = (f_cnt + l*k*(w-i_1+i+2)%p)%p;
				}
			}
		}
	}
			
		printf("%d %d\n",c*c_cnt,f*f_cnt);
}
