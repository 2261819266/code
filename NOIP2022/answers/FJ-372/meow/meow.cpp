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

int n, m, k, a[1000010], st[310][100010][3], ans[2000010][3], und[310], tp[310], cnt[310], aw;
bool flag=0;

void input() {
	n=read(), m=read(), k=read();
	for(int i=1;i<=m;i++) a[i]=read();
	return;
}

void solve(int step) {
	if(aw==m+1) {
		for(int i=1;i<=n;i++) {
			if(und[i]!=0 || tp[i]!=0) return;
		}
		write(step-1);pte;
		for(int i=1;i<step;i++) {
			write(ans[i][0]);pts;
			if(ans[i][0]==1) {write(ans[i][1]); pte;}
			else {write(ans[i][1]); pts; write(ans[i][2]); pte;}
		}
		flag=1;
		return;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(i==j) continue;
			if(st[i][und[i]][0]==0 || st[j][und[j]][0]==0) continue;
			if(st[i][und[i]][0]==st[j][und[j]][0]) {
				ans[step][0]=2;
				ans[step][1]=i;
				ans[step][2]=j;
				int l=und[i];
				und[i]=st[i][l][2];
				st[i][st[i][l][2]][1]=0;
				int r=und[j];
				und[j]=st[j][r][2];
				st[j][st[j][r][2]][1]=0;
				solve(step+1);
				if(flag)	return;
				st[j][st[j][r][2]][1]=r;
				und[j]=r;
				st[i][st[i][l][2]][1]=l;
				und[i]=l;
			}
		}
	}
	for(int i=1;i<=n;i++) {
		if(st[i][tp[i]][0]==a[aw]) {
			ans[step][0]=1;
			ans[step][1]=i;
			int l=tp[i];
			tp[i]=st[i][l][1];
			st[i][st[i][l][1]][2]=0;
			aw++;
			solve(step+1);
			if(flag)	return;
			st[i][st[i][l][1]][2]=l;
			tp[i]=l;
			aw--;
		}
		else{
			ans[step][0]=1;
			ans[step][1]=i;
			int l=tp[i];
			st[i][++cnt[i]][0]=a[aw];
			aw++;
			st[i][l][2]=cnt[i];
			tp[i]=cnt[i];
			st[i][cnt[i]][1]=l;
			if(und[i]==0) und[i]=cnt[i];
			solve(step+1);
			if(flag)	return;
			tp[i]=l;
			st[i][l][2]=0;
			aw--;
		}
	}
}

void work() {
	solve(1);
	return;
}

void output() {
	//empty;
	return;
}

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	while(T--) {
		input();
		work();
		output();
	}
	fclose(stdin);
	fclose(stdout);
}
