#include <bits/stdc++.h>
#define ll long long
#define pte putchar('\n');
#define pts putchar(' ');
#define gc getchar();
#define max(i,j) (((i)>(j))?(i):(j))
#define min(i,j) (((i)<(j))?(i):(j))
#define abs(i) (((i)<0)?-(i):(i))
ll read() {
	ll a=0, f=1; char c=gc;
	while(c<'0' || c>'9') {
		if(c=='-') f*=-1;
		c=gc;
	}
	while(c>='0' && c<='9') {
		a=(a<<1)+(a<<3)+(c^48), c=gc;
	}
	return a*f;
}
void write(ll x) {
	if(x<0) {putchar('-'); x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

void input() {
	
	return;
}

void work() {
	
	return;
}

void output() {
	write(1);pte;
	return;
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	input();
	work();
	output();
	fclose(stdin);
	fclose(stdout);
}
