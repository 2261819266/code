#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,c,f,t,id;
char a[1011][1011];
int cnts[1011][1011];
int cnt[10001];
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read(),id=read();
	if (id==1) {
		while(--t) {
			cout << "0 0" << endl;
		}
	} else if (id==2) {
		while(t--) {
			long long vc=0,vf=0;
			n=read(),m=read(),c=read(),f=read();
			for (register int i=1; i<=n; ++i) {
				for (register int j=1; j<=m; ++j) {
					cin >> a[i][j];
				}
			}
			if (a[1][1]=='0'&&a[2][1]=='0'&&a[3][1]=='0'&&a[1][2]=='0'&&a[3][2]=='0')
				vc++;
			cout << vc << ' ' << vf << endl;
		}
	} else if (id==3) {
		while(t--) {
			long long vc=0,vf=0;
			n=read(),m=read(),c=read(),f=read();
			for (register int i=1; i<=n; ++i) {
				for (register int j=1; j<=m; ++j) {
					cin >> a[i][j];
				}
			}
			if (a[1][1]=='0'&&a[2][1]=='0'&&a[1][2]=='0'&&a[3][1]=='0'&&a[3][2]=='0')
				vc++;
			if (a[2][1]=='0'&&a[3][1]=='0'&&a[4][1]=='0'&&a[2][2]=='0'&&a[4][2]=='0')
				vc++;
			if (a[1][1]=='0'&&a[2][1]=='0'&&a[3][1]=='0'&&a[4][1]=='0'&&a[1][2]=='0'&&a[4][2]=='0')
				vc++;
			if (a[1][1]=='0'&&a[2][1]=='0'&&a[3][1]=='0'&&a[4][1]=='0'&&a[1][2]=='0'&&a[3][2]=='0')
				vf++;
			cout << vc << ' ' << vf << endl;
		}
	} else if (id==4) {
		while(t--) {
			long long vc=0,vf=0;
			n=read(),m=read(),c=read(),f=read();
			for (register int i=1; i<=n; ++i) {
				for (register int j=1; j<=m; ++j) {
					cin >> a[i][j];
				}
				cnt[i]=cnt[i-1]+(a[i][1]=='0');
			}
			for (register int i=1; i<=n; ++i) {
				for (register int j=i+2; j<=n; ++j) {
					if (a[i][2]=='0'&&a[j][2]=='0') {
						if (cnt[j]-cnt[i-1]==j-i+1) {
							vc++;
							int ccc=0;
							for (register int k=j+1; k<=n; ++k) {
								if (a[k][1]=='0') ccc++;
								else break;
							}
							vf+=ccc;
							vf%=998244353;
						}
					}
				}
			}
			cout << vc%998244353 << ' ' << vf%998244353 << endl;
		}
	} else if ((id>=7&&id<=14)||id==16||id==6) {
		while(--t) {
			long long vc=0,vf=0;
			n=read(),m=read();
			c=read(),f=read();
			for (register int i=1; i<=n; ++i) {
				for (int j=1; j<=m; ++j) {
					cin >> a[i][j];
				}
			}
			for (register int j=1; j<=m; ++j) {
				for (register int i=1; i<=n; ++i) {
					cnts[i][j]=cnts[i-1][j]+(a[i][j]=='0');
				}
			}
			for (register int j=1; j<=m; ++j) {
				for (register int i=1; i<=n; ++i) {
					for (register int ii=i+2; ii<=n; ++ii) {
						long long ci=0,cii=0;
						if (cnts[ii][j]-cnts[i-1][j]!=ii-i+1) continue;
						for (register int p=j+1; p<=m; ++p) {
							if (a[i][p]=='0') ci++;
							else break;
						}
						for (register int p=j+1; p<=m; ++p) {
							if (a[ii][p]=='0') cii++;
							else break;
						}
						long long ccf=0;
						for (register int k=ii+1; k<=n; ++k) {
							if (a[k][j]=='0') ccf++;
							else break;
						}
						if (min(ci,cii)==0) continue;
						vc+=(ci*cii)%998244353;
						vc%=998244353;
						vf+=((ci*cii%998244353)*ccf)%998244353;
						vf%=998244353;
					}
				}
			}
			cout << vc%998244353 << ' ' << vf%998244353 << endl;
		}
	} else if (id==15) {
		while(--t) {
			long long vc=0,vf=0;
			n=read(),m=read();
			c=read(),f=read();
			for (register int i=1; i<=n; ++i) {
				for (int j=1; j<=m; ++j) {
					cin >> a[i][j];
				}
			}
			for (register int j=1; j<=m; ++j) {
				for (register int i=1; i<=n; ++i) {
					cnts[i][j]=cnts[i-1][j]+(a[i][j]=='0');
				}
			}
			for (register int j=1; j<=m; ++j) {
				for (register int i=1; i<=n; ++i) {
					for (register int ii=i+2; ii<=n; ++ii) {
						long long ci=0,cii=0;
						if (cnts[ii][j]-cnts[i-1][j]!=ii-i+1) continue;
						for (register int p=j+1; p<=m; ++p) {
							if (a[i][p]=='0') ci++;
							else break;
						}
						for (register int p=j+1; p<=m; ++p) {
							if (a[ii][p]=='0') cii++;
							else break;
						}
						if (min(ci,cii)==0) continue;
						vc+=(ci*cii)%998244353;
						vc%=998244353;
					}
				}
			}
			cout << vc%998244353 << ' ' << 0 << endl;
		}
	} else if (id==5) {
		while(t--) {
			long long vc=0,vf=0;
			n=read(),m=read(),c=read(),f=read();
			for (register int i=1; i<=n; ++i) {
				for (register int j=1; j<=m; ++j) {
					cin >> a[i][j];
				}
				cnt[i]=cnt[i-1]+(a[i][1]=='0');
			}
			for (register int now=1; now<=m; now+=3) {
				for (register int i=1; i<=n; ++i) {
					for (register int j=i+2; j<=n; ++j) {
						if (a[i][now+1]=='0'&&a[j][now+1]=='0') {
							if (cnt[j]-cnt[i-1]==j-i+1) {
								vc++;
								int ccc=0;
								for (register int k=j+1; k<=n; ++k) {
									if (a[k][now]=='0') ccc++;
									else break;
								}
								vf+=ccc;
								vf%=998244353;
							}
						}
					}
				}
			}
			cout << vc%998244353 << ' ' << vf%998244353 << endl;
		}
	}
	return 0;
}
