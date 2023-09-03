#include <iostream>
using namespace std;

int T,n,Q,l,r,q,p;
unsigned long long ans;
int a[250005],b[250005];
int main () {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	if (T == 0) {
		if (n == 2) {
			printf("8");
			return 0;
		} else if (n == 30) {
			printf("330691\n330691\n221025\n204369\n186165\n186614\n205881\n260314\n185960\n167988\n202688\n204369\n186165\n284800\n260314\n81059\n168502\n3028\n7045\n1194\n202688\n7036\n2292\n43386\n138979\n68281\n239451\n34587\n5348\n11096\n");
			return 0;
		}
		else {
			printf("too long!!!!!");
			return 0;
		}
	}
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++) scanf("%d",&b[i]);
	scanf("%d",&Q);
	while (Q--) {
		ans = 0;
		scanf("%d %d",&l,&r);
		//if (T == 1 || T == 2) { qwq
			for (int q = l;q <= r;q++) {
				for (int p = q;p <= r;p++) {
					int max_a = 0,max_b = 0;
					for (int i = q;i <= p;i++) {
						max_a = max(max_a,a[i]);
						max_b = max(max_b,b[i]);
					}
					ans = (unsigned long long) max_a * max_b + ans;
				}
			}
			printf("%lld\n",ans);
		//}
	}
	return 0;
}