#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int> 
#define mk make_pair
using namespace std;
const int N=310,K=610,M=2.001e6;
int n,m,k,anses;
stack <pii> st[N];
pii ans[M][2];
inline void ddd(int& x){
	x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
}
inline void shu(int x){
	if(x<10){
		putchar(x%10+'0');
		return ;
	}
	shu(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	ddd(T);
	if(T%100==1){
		while(T--){
			ddd(n),ddd(m),ddd(k);
			for(int i=1,col,s;i<=m;++i){
				ans[i][0]=ans[i][1]=mk(0,0);
				ddd(col);
//				col=1;
				s=(col-1)/2+1;
				ans[i][0]=mk(s,0);
				++anses;
//				cout<<i<<" "<<st[s].empty()<<" "<<col<<endl;	
				if(!st[s].empty()&&st[s].top().second==col){
					st[s].pop();
				}
				else
					st[s].push(mk(i,col));
			}
			for(int i=1;i<=n;++i){
				while(!st[i].empty()){
					ans[st[i].top().first][0]=mk(n,0);
					ans[st[i].top().first][1]=mk(i,n);
					st[i].pop();
					ans[st[i].top().first][0]=mk(n,0);
					ans[st[i].top().first][1]=mk(i,n);
					st[i].pop();
					st[i].pop();
					st[i].pop();
					anses+=2;
				}
			}
			shu(anses);
			putchar('\n');
			for(int i=1;i<=m;++i){
				putchar('1');putchar(' ');
				shu(ans[i][0].first);
				puts("");
				if(ans[i][1].second){
					putchar('2');putchar(' ');
					shu(ans[i][1].first);
					putchar(' ');
					shu(ans[i][1].second);
					puts("");
				}
			}
			anses=0;
		}
	}
	else{
		while(T--){
			ddd(n),ddd(m),ddd(k);
			for(int i=1,col;i<=m;++i){
				ddd(col);
				puts("1 1");
			}
		}
	}
	return 0;
}
