#include <cstdio>

const int maxn = 105;
struct student {
	const char *name = new char;
	int endScore, classScore;
	bool isStudentforce, isWestStudent;
	int num;

	void scan() {
		char k1[10], k2[10];
		scanf("%s%d%d%s%s%d", name, &endScore, &classScore, &k1, &k2, &num);
		isStudentforce = *k1 == 'Y' ? true : false;
		isWestStudent = *k2 == 'Y' ? true : false;
	}

	int getMoney() const {
		int money = 0;
		if (endScore > 80 && num)
			money += 8000;
		if (endScore > 85 && classScore > 80)
			money += 4000;
		if (endScore > 90)
			money += 2000;
		if (endScore > 85 && isWestStudent)
			money += 1000;
		if (classScore > 80 && isStudentforce)
			money += 850;
		return money;
	}

	bool operator>(const student &x) const { return getMoney() > x.getMoney(); }
} a[maxn], *maxx = a;

int n, sum;

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int c = 1; c <= n; c++) {
		(a + c)->scan();
		if (a[c] > *maxx)
			maxx = &a[c];
		sum += (a + c)->getMoney();
	}
	printf("%s\n%d\n%d", maxx->name, maxx->getMoney(), sum);
}
