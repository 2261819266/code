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

int T, id, n, m, c, f;
int a[1010][1010];
ll ansc, ansf;
const int mod=998244353;

void input() {
	n=read(), m=read(), c=read(), f=read(), ansc=0, ansf=0;
	for(int i=0;i<1010;i++) for(int j=0;j<1010;j++) a[i][j]=0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			char c=gc;
			a[i][j]=c^48;
		}
		gc;
	}
	/*//-----test----///
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			write(a[i][j]);
		}pte;
	}
	///-------------//*/
	return;
}

void work() {
	///---specal---///
	if(id==5) {
		int tim=1.0*m/3+0.5;
//		for(int i=n-2;i;i--) ansc=(ansc+i)%mod;
		ansc=((n-1)*(n-2)/2)%mod;
		ansc=(ansc*tim)%mod;
		for(int i=1;i<=n-3;i++) {
			ansf=(ansf+((n-1-i)*(n-2-i)/2))%mod;
		}
		ansf=(ansf*tim)%mod;
		return;
	}
	if(id==6) {
		int tim=1.0*n/4+0.5;
		for(int i=1;i<m;i++) {
			ansc=(ansc+(m-i)*(m-i))%mod;
		}
		ansc=(ansc*tim)%mod;
		ansf=0;
		return;
	}
	///-----------///
	
	if(c==1) {
		for(int i=1;i<n-1;i++) {
			for(int j=1;j<m;j++) {
				if(a[i][j])	continue;
				int sum=0;
				for(int x_2=i+1;x_2<=n;x_2++) {
					if(a[x_2][j])	break;
					if(x_2==i+1) continue;
					for(int y_1=j+1;y_1<=m;y_1++) {
						if(a[i][y_1])	break;
						for(int y_2=j+1;y_2<=m;y_2++) {
							if(a[x_2][y_2])	break;
							sum=(sum+1)%mod;
						//	write(i);pts;write(j);pts;write(y_1);pts;write(x_2);pts;write(y_2);pte;
						}
					}
				}
				ansc=(ansc+sum)%mod;
			}
		}
	} 
	if(f==1) {
		for(int i=1;i<n-2;i++) {
			for(int j=1;j<m;j++) {
				if(a[i][j])	continue;
				int sum=0;
				for(int x_3=i+1;x_3<=n;x_3++) {
					if(a[x_3][j])	break;
					if(a[x_3][j]==i+1||a[x_3][j]==i+2)	continue;
					for(int x_2=i+2;x_2<x_3;x_2++) {
						for(int y_1=j+1;y_1<=m;y_1++) {
							if(a[i][y_1])	break;
							for(int y_2=j+1;y_2<=m;y_2++) {
								if(a[x_2][y_2])	break;
								sum=(sum+1)%mod;
						//		write(i);pts;write(j);pts;write(y_1);pts;write(x_2);pts;write(y_2);pts;write(x_3);pte;
							}
						}
					}
				}
				ansf=(ansf+sum)%mod;
			}
		}
	} 
	return;
}

void output() {
	write(ansc);pts;
	write(ansf);pte;
	return;
}

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(), id=read();
	while(T--) {
		input();
		work();
		output();
	}
	fclose(stdin);
	fclose(stdout);
}
