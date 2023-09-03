

#ifndef _IS

#define _IS
// #define min(X, Y) X < (Y) ? (X) : (Y)
// #define max(X, Y) X > (Y) ? (X) : (Y)
#define Isxisy(X, Y) (((X) - 'A') % 32 == ((Y) - 'A') % 32)
#define Isnumber(X) ((X) >= '0' && (X) <= '9')
#define Isletter(X) (((X) >= 'A' && (X) <= 'Z') || (X) >= 'a' && (X) <= 'z')
#include <windows.h>
#define pause system("pause")
#define Backspace '\010'
#define Tab '\011'
#define Esc '\033'
#define R "r"
COORD coordScreen = {0, 0};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

bool Isxisy_str(const char *str1, const char *str2) {
    int n1 = strlen(str1), n2 = strlen(str2);
    if (n1 != n2)
        return false;
    for (int c = 0; c < n1; c++)
        if (!Isxisy(str1[c], str2[c]))
            return false;
    return true;
}

int getx() {
    // 获取光标位置X
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    return csbi.dwCursorPosition.X;
}

int gety() {
    // 获取光标位置Y
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    return csbi.dwCursorPosition.Y;
}

void gotoxy(int x, int y) {
    coordScreen.X = x;
    coordScreen.Y = y;
    SetConsoleCursorPosition(hConsole, coordScreen);
}

void gotoaddxy(int x, int y) {
    gotoxy(getx() + x, gety() + y);
    return;
}

void format_str(char *str) {
    for (int c = 0; c < strlen(str); c++)
        if (!Isletter(str[c]) && !Isnumber(str[c])) {
            str[c] = '\0';
            break;
        }
}

void make_top() {
    HWND hWnd = ::GetForegroundWindow();
    ::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 100, 100,
                   SWP_NOMOVE | SWP_NOSIZE); //窗口置顶
}

#endif