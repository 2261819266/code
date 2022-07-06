#ifndef _list

#define _list
template <class _T> class list {
  private:
    static const int maxn_list = 101;
    _T a[maxn_list];
    int top;

  public:
    _T &operator[](int x) { return a[x]; }
    list() { top = 0; }
    void push(_T x) { a[top++] = x; }
    bool empty() { return top == 0; }
    void pop(int add) {
        top--;
        for (int c = add; c < top; c++) {
            a[c] = a[c + 1];
        }
    }
    void print(const char *str1 = "%d ", const char *str2 = "\n") {
        for (int c = 0; c < top; c++)
            printf(str1, a[c]);
        printf(str2);
    }
    int size() { return top; }
};

#endif