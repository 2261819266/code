#ifndef _auto

#define _auto
#include "const.cpp"
#include "func.cpp"
#include <conio.h>
#include <cstdio>
#include <cstring>
int auto_fill(char **str) {

    char s, c = 1, *s1 = new char;
    bool a[maxn];
    memset(a, true, sizeof(a));
    int x = getx(), y = gety();
    for (int c = 0;; c++) {
    label:
        s = getch();
        if (s == '#') {
            printf("%s", "%d");
            return -2;
        }
        if (s == ' ' || s == '\015') {
            s1[c] = '\0';
            printf(" ");
            for (int d = 0; d < maxin; d++) {
                if (Isxisy_str(s1, str[d]))
                    return d;
            }
            return -1;
        }
        if (s == Tab) {
            for (int d = 0; d < maxin; d++)
                if (a[d]) {
                    gotoxy(x, y);
                    printf("%s", str[d]);
                    return d;
                }
            return -1;
        }
        if (s == Esc)
            return -1;
        if (!Isletter(s)) {
            c++;
            goto label;
        }
        for (int d = 0; d < maxin; d++) {
            if (Isxisy(s, str[d][c]) && a[d]) {
                gotoxy(x, y + 1);
                printf(str[d]);
                gotoxy(x + c, y);
                printf("%c", s);
                s1[c] = s;
            } else
                a[d] = false;
        }
    }
}

#endif