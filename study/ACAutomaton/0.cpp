#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

struct Node {
	std::vector<int> exits;
	Node *fail;
	Node *child[26];
};

const char *p[] = {"he", "she", "hers", "his"};
const char *t = "ahishers";

void insert(Node *root, const char *str) {
	if (!*str) return;
	if (!root->child[*str - 'a']) 
		root->child[*str - 'a'] = new Node();
	insert(root->child[*str - 'a'], str + 1);
}

void build(Node *root, int n) {
	for (int i = 0; i < n; i++) {
		insert(root, p[i]);
	}
	std::queue<Node *> q;
	for (int i = 0; i < 26; i++) {
		if (root->child[i]) {
			q.push(root->child[i]);
			root->child[i]->fail = root;
		}
	}
	while (!q.empty()) {
		Node *x = q.front();
		q.pop();
		for (int i = 0; i < 26; i++) {
			if (x->child[i]) {
				Node *y = x->child[i];
				Node *fafail = x->fail;
				while (fafail && fafail->child[i] == NULL) {
					fafail = fafail->fail;
				}
				if (fafail == NULL) {
					y->fail = root;
				} else {
					y->fail = fafail->child[i];
				}
				if (y->fail->exits.size()) {
					for (int j = 0; j < y->fail->exits.size(); j++) {
						y->exits.push_back(y->fail->exits[j]);
					}
				}
				q.push(y);
			}
		}
	}
} 

void print(const char *str, int n) {
	for (int i = 0; i < n; i++) {
		putchar(str[i]);
	}
}

void query(Node *root, int n) {
	Node *tmp = root;
	for (int i = 0; i < strlen(t); i++) {
		int c = t[i] - 'a';
		while (tmp->child[c] == NULL && tmp->fail) {
			tmp = tmp->fail;
		}
		if (tmp->child[c]){
			tmp = tmp->child[c];
		} else {
			continue;
		}
		if (tmp->exits.size()) {
			for (int j = 0; j < tmp->exits.size(); j++) {
				int len = tmp->exits[j];
				print(t + i - len + 1, len);
			}
		}
	}
}

int main() {
	Node *root = new Node();
	build(root, 4);
	query(root, 4);
}
