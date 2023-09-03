#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int p;
int op[2000005][3];
int a[2000005];
void f(){
	queue<int> t[1005];
	int w[1005] = {0};
	int num[305] = {0};
	deque<int>adj[305];
	for(int i = 1;i<=m;i++){
		if(!w[a[i]]){
			w[a[i]]++;
			t[a[i]].push(i);
			adj[1].push_back(a[i]);
			op[p][0] = op[p][1] = 1;
			p++;
//			cout<<a[i]<<"push into the first deque"<<adj[1].front()<<endl;
		}else{
			w[a[i]]--;
			if(a[i] == adj[1].back()){
				op[p][0] = op[p][1] = 1;
				p++;
//				cout<<a[i]<<"and the top of the first deque pop!"<<endl;
				t[a[i]].pop();
				adj[1].pop_back();
				continue;
			}
			int j = 2;
			for(;j<=n;j++){
				if(t[a[i]].front()>num[j]){
					adj[j].push_back(a[i]);
					num[j] = t[a[i]].front();
					op[p][0] = 1;
					op[p][1] = j;
					p++;
//					cout<<a[i]<<"push into the "<<j<<"th. deque"<<endl;
//					cout<<adj[j].front()<<" "<<adj[1].front()<<endl;
					break;
				}
			}
//			if(j == n+1){
//				for(int k = 1;k<=n;k++){
//					cout<<adj[k].size()<<" ";
//				}
//				cout<<endl;
//				for(int k = 1;k<=n;k++){
//					cout<<num[k]<<" ";
//				}
//				cout<<endl;
//				cout<<t[6].size()<<" "<<t[11].size()<<endl;
//				cout<<endl;
//				cout<<a[i]<<" "<<i<<"th. WA!"<<endl;
//			}
		}
		while(true){
			bool ch = false;
			for(int j = 2;j<=n;j++){
				if(adj[j].front() == adj[1].front()&&adj[j].size()&&adj[1].size()){
					op[p][0] = 2;
					op[p][1] = 1,op[p][2] = j;
					p++;
//					cout<<adj[j].front()<<"and the back of the first deque pop!"<<endl;
					t[adj[1].front()].pop();
					adj[1].pop_front();
					adj[j].pop_front();
					if(adj[j].size() == 0)num[j] = 0;
					else num[j] = t[adj[j].back()].front();
					ch = true;
				}
			}
			if(!ch)break;
		}
	}
}
void solve1(){
	deque<int>t[305];
	for(int i = 1;i<=m;i++){
		int x = a[i]/2+a[i]%2;
		if(t[x].size() == 0){
			op[p][0] = 1;
			op[p][1] = x;
			p++;
			t[x].push_back(a[i]);
		}else if(a[i] == t[x].front()){
			op[p][0] = 1;
			op[p][1] = n;
			p++;
			op[p][0] = 2;
			op[p][1] = x;
			op[p][2] = n;
			p++;
			t[x].pop_front();
		}else if(a[i] == t[x].back()){
			op[p][0] = 1;
			op[p][1] = x;
			p++;
			t[x].pop_back();
		}else{
			op[p][0] = 1;
			op[p][1] = x;
			p++;
			t[x].push_back(a[i]);
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	int K = T%10;
	while(T--){
		p = 0;
		scanf("%d %d %d",&n,&m,&k);
		for(int i = 1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		if(K == 1){
			solve1();
		}else{
			f(); 
		}
		printf("%d\n",p);
		for(int i = 0;i<p;i++){
			printf("%d ",op[i][0]);
			if(op[i][0] == 1)printf("%d",op[i][1]);
			else printf("%d %d",op[i][1],op[i][2]);
			printf("\n");
		}
	}
	return 0;
}
/*
9:30开T2 
看复杂度不会是O(NM)吧 
如果有连续两张是一样的，那么它们无法造成影响，直接放入同一个栈里面即可 
如果中间有间隔几张捏
最后一步肯定是把一张牌放入一个空栈，然后和另一个栈的栈底消除，那不然怎么消
那么中间的牌放到哪些栈里？ 
不知道
那先看看两个栈的情况
那这个就很好想了，要么连着直接消掉，要么放另一个栈和栈底消掉，感性理解一下正确性应该是可以保证的
三个栈呢
谔谔，好像有一个想法了
就是只用一个栈专门装卡，就用编号为1的栈罢，另外的所有栈用来放和第一个栈消除的牌
然后保证其他栈消除顺序是递增的，不能有逆序，那不然消不掉了好像
理论可行，实践开始(10:12)
不是？你大样例不给check什么鬼
11:14，做法好像出锅了，悲
11:43，开暴力吧 ，没调出来，悲 
12:15:
思路错了！！！
颜色！！！
颜色只会比栈多n+1种！！！
关键在于处理那最后一种颜色！！！ 
估分30~45pts 
*/

