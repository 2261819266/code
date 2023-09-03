#include <cstdio>
#include <cstring>
#define IsOperator(X) ((X) == '+' || (X) == '-')
#define IsNumber(X) ((X) >= '0' && (X) <= '9')
#define IsLetter(X) ((X) >= 'a' && (X) <= 'z')
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

struct expression {
	char letter;
	int letterCoefficient;
	int constant;
	int read(const char *str) {
		letter = letterCoefficient = constant = 0;
		int n = strlen(str), x = 0, c;
		bool k = false, letterK = false;
		for (c = 0; c < n; c++) {
			if (IsOperator(str[c])) {
				if (letterK && x == 0)
					x = 1;
				x = k ? -x : x;
				(letterK ? letterCoefficient : constant) += x;
				x = 0;
				k = str[c] == '-' ? true : false;
				letterK = false;
				continue;
			}
			if (IsNumber(str[c])) {
				x = x * 10 + str[c] - 48;
				continue;
			}
			if (IsLetter(str[c])) {
				letter = str[c];
				letterK = true;
				continue;
			}
			break;
		}
		{
			x = k ? -x : x;
			(letterK ? letterCoefficient : constant) += x;
			x = 0;
			k = str[c] == '-' ? true : false;
		}
		return c;
	}
};

struct equation {
	expression equationLeft, equationRight;
	void read(const char *str) {
		int x = equationLeft.read(str);
		equationRight.read(str + x + 1);
	}
	double solveEquation() {
		return (equationRight.constant - equationLeft.constant) * 1.0 /
			   (equationLeft.letterCoefficient - equationRight.letterCoefficient);
	}
	void read() {
		char *str = new char;
		scanf("%s", str);
		read(str);
	}
};

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	equation a;
	a.read();
	double x = a.solveEquation();
	printf("%c=%.3lf\n", max(a.equationLeft.letter, a.equationRight.letter),
		   ((0 - x) < 0.0005 && x < 0.0005) ? 0 : x);
}