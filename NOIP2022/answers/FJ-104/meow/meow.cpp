#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

const int S = 300, M = 1e5;

struct cmds{
	int opr, s1, s2, data;
};

vector<cmds> seq;//The sequence of operators.
int a[M+5];
int n, m, k;

class stack{
private:
	vector<int> nums;
public:
	bool empty(){
		return nums.empty();
	}
	void push(int n){
//		printf("77777\n");
//		if(n>10000){
//			printf("too_big_n:%d\n", n);
//		}
		if((!nums.empty()))
			if(*(--nums.end()) == n){
				nums.erase(--nums.end());
//				printf("88888\n");
			}else	nums.insert(nums.end(), n);
		else	nums.insert(nums.end(), n);
	}void push_tail(int n){
		nums.insert(nums.begin(), n);
	}
	friend bool pop(stack &s1, stack &s2);
	int top(){
		return *(--nums.end());
	}int tail(){
		return *nums.begin();
	}void print(){
		printf("\nstack:");
		for(int n : nums)
			printf("%d ", n);
		printf("\n");
	}void clear(){
		nums.clear();
	}
}s[S];

int dfs(int now);
bool pop(stack &s1, stack &s2);

signed main(){
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= m; i++)
			scanf("%d", &a[i]);
		dfs(1);
	}
	return 0;
}

int dfs(int i){
//	printf("now:%d    ", i);
//	s[1].print(), s[2].print();
	if(i > m){
//		printf("33333\n");
		for(cmds c : seq){
			if(c.opr == 1){
//				printf("55555\n");
//				printf("c.s1:%d\n", c.s1);
//				printf("c.data:%d\n", c.data);
				s[c.s1].push(c.data);
//				printf("66666\n");
			}else if(c.opr == 2){
//				if(s[c.s1].empty() || s[c.s2].empty())
//					return -1;
				pop(s[c.s1], s[c.s2]);
			}
		}
//		printf("44444\n");
		for(int i = 1; i <= n; i++)
			if(!s[i].empty()){
//				printf("-1\n");
				for(int j = 1; j <= n; j++)
					s[j].clear();
//				printf("%d\n", int(seq.size()));
//				for(cmds cc : seq)
//					if(cc.opr == 1)
//						printf("%d %d\n", cc.opr, cc.s1);
//					else
//						printf("%d %d %d\n", cc.opr, cc.s1, cc.s2);
				return -1;
			}
		
		//If this way works.
		printf("%d\n", int(seq.size()));
		for(cmds c : seq)
			if(c.opr == 1)
				printf("%d %d\n", c.opr, c.s1);
			else
				printf("%d %d %d\n", c.opr, c.s1, c.s2);
		return 1;
	}
//	for(int i = 1; i <= m; i++){
//		printf("11111\n");
		cmds c;
		c.opr = 1, c.data = a[i];
		for(int j = 1; j <= n; j++){
			c.s1 = j;
			int top;
			if(!s[c.s1].empty())
				top = s[c.s1].top();
			else
				top = -114514;
			seq.insert(seq.end(), c);
			if(dfs(i+1) == 1)	return 1;
			else{
				seq.erase(--seq.end());
//				printf("recovery:c.s1:%d\n", c.s1);
//				printf("top:%d\n", top);
				if(top != -114514)
					s[c.s1].push(top);
			}
		}
/*
//	}
//	for(int i = 1; i <= n; i++){
//		printf("22222\n");
		for(int k = 1; k <= n; k++){
//			cmds c;
//			printf("22222\n");
			c.opr = 2, c.s1 = k;
			for(int j = k+1; j <= n; j++){
				c.s2 = j;
//				if(s[c.s1].empty() || s[c.s2].empty())	continue;
//				printf("22222\n");
//				while(pop(s[c.s1], s[c.s2])){
//					printf("11111\n");
//					int tail_1 = s[c.s1].tail(), tail_2 = s[c.s2].tail();
					seq.insert(seq.end(), c);
					if(dfs(i) == 1)	return 1;
					else{
						if(!seq.empty()){
							seq.erase(--seq.end());
//							s[c.s1].push_tail(tail_1), s[c.s2].push_tail(tail_2);
						}
					}
//				}
			}
		}
//	}
*/
	return -1;
}

bool pop(stack &s1, stack &s2){
	if(s1.empty() || s2.empty())
		return false;
	if(*(s1.nums.begin()) == *(s2.nums.begin())){
		s1.nums.erase(s1.nums.begin());
		s2.nums.erase(s2.nums.begin());
		return true;
	}
	return false;
}
//bool pop(stack s1, stack s2){
//	if(*(s1.nums.begin()) == *(s2.nums.begin())){
//		s1.nums.erase(s1.nums.begin());
//		s2.nums.erase(s2.nums.begin());
//		return true;
//	}
//	return false;
//}
