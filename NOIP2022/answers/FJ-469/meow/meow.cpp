#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(long long x){
	static char buf[64];
	static long long len=-1;
	if(x<0){
		putchar('-');
		x=-x;
	}
	do{
		buf[++len]=x%10;
		x/=10;
	}
	while(x);
	while(len>=0){
		putchar(buf[len--]+'0');
	}
	putchar('\n');
}
long long t,n,m,k,x,op;
deque<long long>q;
vector<long long>ans;
//push_back
//back
//1 pop_back
//2 pop_front
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	for(int T=1;T<=t;T++){
		n=read();
		m=read();
		k=read();
		q.clear();
		ans.clear();
		op=0;
		for(int i=1;i<=m;i++){
			x=read();
			if(!q.empty() && q.back()==x){
				q.pop_back();
			}
			if(n==1){
				if(q.empty() || q.back()!=x){
					op++;
					ans.push_back(1);
					ans.push_back(1);
					ans.push_back(-1);
					q.push_back(x);
				}
				else if(q.back()==x){
					op++;
					ans.push_back(1);
					ans.push_back(1);
					ans.push_back(-1);
					q.pop_back();
				}
			}
			else if(n>=2){
				if(q.empty() || (q.back()!=x && q.front()!=x)){
					op++;
					ans.push_back(1);
					ans.push_back(1);
					ans.push_back(-1);
					q.push_back(x);
				}
				else if(q.back()==x){
					op++;
					ans.push_back(1);
					ans.push_back(1);
					ans.push_back(-1);
					q.pop_back();
				}
				else if(q.front()==x){
					op++;
					ans.push_back(1);
					ans.push_back(2);
					ans.push_back(-1);
					op++;
					ans.push_back(2);
					ans.push_back(1);
					ans.push_back(2);
					ans.push_back(-1);
					q.pop_front();
				}
			}
		}
		write(op);
		for(long long i=0;i<(long long)ans.size();i++){
			if(ans[i]==-1){
				printf("\n");
			}
			else{
				printf("%lld ",ans[i]);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 10 5
1 2 3 4 5 2 3 4 5 1
*/