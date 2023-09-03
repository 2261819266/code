#include <cstdio>
#include <cstring>
#include <windows.h>
#include <conio.h>

struct Node {
	static const int maxLetter = 128, maxLen = 100;
	Node *data[maxLetter];
	int cnt;

	Node() { memset(data, 0, sizeof(data)), cnt = 0; }

	Node *add(const char *str) {
		Node *i;
		for (i = this; *str; str++) {
			int c = *str;
			!i->data[c] ? i = i->data[c] = new Node : i = i->data[c];
		}
		i->cnt++;
		return i;
	}

	Node *find(const char *str) {
		Node *i;
		for (i = this; *str; str++) {
			int c = *str;
			if (i->data[c]) i = i->data[c];
			else return 0;
		}
		return i;
	}

	void print(Node *s, int l) {
		Node *i;
		for (i = s; )
	}

	Node *fill(char *str) {
		memset(str, 0, maxLen);
		char c = getch();
		while(c != ' ') {
			if (c != '\t')
				c = getch(),
				str[strlen(str)] = c;
			else {
				int i = 0;
				do {
					Node *k = find(str);
					for (i; i < maxLetter; i++) {
						if (k->data[i]) break;
					}

				} while((c = getch()) == '\t');
			}
		}
	}

	Node *operator+(const char *str) { return add(str); }
} s;