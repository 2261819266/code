#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, k;
int card[2500000];

struct Ans{
	int op;
	int n1;
	int n2;
};
deque <int> cardlist[400];
deque <Ans> ansqueue;

bool flag;
void dfs(int now, int opcnt){
	if(flag) return;
	if(opcnt > 2*m) return;
	if(now > m){
		bool bflag;
		bflag = 1;
		for(int i = 1; i <= n; ++i){
			if(!cardlist[i].empty()){
				bflag = 0;
				break;
			} 
		}
		if(bflag){
			flag = 1;
			printf("%d\n", opcnt);
			while(!ansqueue.empty()){
				Ans k;
				k = ansqueue.front();
				ansqueue.pop_front();
				if(k.op == 1)
					printf("1 %d\n", k.n1);
				else if(k.op == 2)
					printf("2 %d %d\n", k.n1, k.n2);
			}
		}
	}
	
	if(now <= m){
		for(int i = 1; i <= n; ++i){
			if(cardlist[i].empty()){
				Ans k;
				k.op = 1;
				k.n1 = i;
				ansqueue.push_back(k);
				
				cardlist[i].push_back(card[now]);
				
				dfs(now + 1, opcnt + 1);
				
				cardlist[i].pop_back();
				
				ansqueue.pop_back();
				
				break;
			}
			else{
				Ans k;
				k.op = 1;
				k.n1 = i;
				ansqueue.push_back(k);
				
				int z;
				z = cardlist[i].back();
				if(z == card[now])
					cardlist[i].pop_back();
				else
					cardlist[i].push_back(card[now]);
					
				dfs(now + 1, opcnt + 1);
				
				if(z == card[now])
					cardlist[i].push_back(z);
				else
					cardlist[i].pop_back();
				
				ansqueue.pop_back();
			}
		}
	}
	
	
	for(int i = 1; i <= n; ++i){
		if(cardlist[i].empty()) break;
		for(int j = i + 1; j <= n; ++j){
			if(cardlist[j].empty()) break;
			if(cardlist[i].front() == cardlist[j].front()){
				Ans k;
				k.op = 2;
				k.n1 = i;
				k.n2 = j;
				ansqueue.push_back(k);
				
				int f1 = cardlist[i].front();
				int f2 = cardlist[j].front();
				cardlist[i].pop_front();
				cardlist[j].pop_front();
				
				dfs(now, opcnt + 1);
				
				cardlist[i].push_front(f1);
				cardlist[j].push_front(f2);
				
				ansqueue.pop_back();
			}
			else continue;
		}
	}
	
	return;
}

int main(){
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	
	scanf("%d", &T);
	while(T--){
		for(int i = 1; i <= 350; ++i)
			cardlist[i].clear();
		memset(card, 0, sizeof(card));
		ansqueue.clear();
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= m; ++i){
			scanf("%d", &card[i]);
		}
		flag = 0;
		dfs(1, 0);
	}

return 0;
}

