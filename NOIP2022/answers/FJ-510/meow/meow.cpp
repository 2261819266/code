//noip rp+++++;
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int n , m , k;
bool awa = false;
int a[2000005];
int ans[2000005][3];
vector <int> qwq[305];

void dfs(int num , int sum , int p_sum){
	if(sum > 2 * m) return ;
	if(awa) return ;
	if(num == 0 && p_sum == 0){
		printf("%d\n" , sum);
		for(int i = 1;i <= sum;i++){
			if(ans[i][0] == 1)
				printf("1 %d\n" , ans[i][1]);
			else
				printf("2 %d %d\n" , ans[i][1] , ans[i][2]);
		}
		awa = true;
		return ;
	}
	for(int i = 1;i <= n && num;i++){
		ans[sum + 1][0] = 1;
		ans[sum + 1][1] = i;
		qwq[i].push_back(a[num]);
		bool flag = false;
		int len = qwq[i].size();
		if(len >= 2 && qwq[i][len - 1] == qwq[i][len - 2]) {
			qwq[i].erase(qwq[i].begin() + len - 1);
			qwq[i].erase(qwq[i].begin() + len - 2);
			flag = true;
		}
		if(!flag){
			dfs(num - 1 , sum + 1 , p_sum + 1);
			if(awa) return ;
			qwq[i].erase(qwq[i].begin() + len - 1);
		}
		else{
			dfs(num - 1 , sum + 1 , p_sum - 2);
			if(awa) return ;
			qwq[i].push_back(a[num]);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(qwq[i].size() > 0 && qwq[j].size() > 0 && qwq[i][0] == qwq[j][0]){
				ans[sum + 1][0] = 2;
				ans[sum + 1][1] = i;
				ans[sum + 1][2] = j;
				int tmp = qwq[i][0];
				qwq[i].erase(qwq[i].begin());
				qwq[j].erase(qwq[j].begin());
				dfs(num , sum + 1 , p_sum - 2);
				if(awa) return ;
				qwq[i].insert(qwq[i].begin() , tmp);
				qwq[j].insert(qwq[j].begin() , tmp);
			}
		}
	}
}

int main(void){
	freopen("meow.in" , "r" , stdin);
	freopen("meow.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--){
		awa = false;
		scanf("%d%d%d" , &n , &m , &k);
		for(int i = 1;i <= m;i++)
			scanf("%d" , &a[i]);
		dfs(m , 0 , 0);
		for(int i = 1;i <= n;i++)
			qwq[i].clear();
	}
	return 0;
}