#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define itn int 
inline int read(){
	int x = 0, f = 1;
	char ch;
	ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-f;
		}
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) +(ch - '0');
		ch = getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
		putchar(x%10+'0');
	}
	else putchar(x+'0');
}
int n,m,p,q,l,r,Q;
const int N = 0x3f3f3f;
ll a[N],b[N],ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	n = read();
	n = read();
	for(int i=1;i<=n;i++)
		a[i] = read();
	for(int i=1;i<=n;i++) b[i] = read();
	Q = read();
	while(Q--){
		l = read();
		r = read();
		for(p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				if(p==q) ans=(ans+a[p]*b[p])%((1ull<<64-1)+1);
				else {
					sort(a+p+1,a+q+1,cmp);
					sort(b+p+1,b+q+1,cmp);
					ans=(ans+a[p]*b[p])%((1ull<<64-1)+1);
				}
				
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
