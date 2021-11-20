#include "stdio.h"
#include "string.h"

void printHelp()
{
    printf("This program only supports '+', '-', '*', '/', '(', ')' and single digit.\n");
    printf("Type 'h' or 'help' to show this help information.\n");
    printf("Type 'q' or 'quit' to quit the program.\n");
}

int calculate(char* s, int* t)
{
    char el = s[--(*t)];
    if (el >= '0' && el <= '9') {
        return el - '0';
    } else {
        int a, b;
        a = calculate(s, t);
        b = calculate(s, t);
        switch (el) {
        case '+':
            return a + b;
        case '-':
            return b - a;
        case '*':
            return a * b;
        case '/':
            return b / a;

        default:
            return 0;
        }
    }
}

int calc(char* formula, int l)
{
    char s1[1024], s2[1024];
    int t1, t2;
    t1 = t2 = 0;
    for (int i = 0; i < l; i++) {
        if (formula[i] >= '0' && formula[i] <= '9') {
            s2[t2++] = formula[i];
        } else {
            switch (formula[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
            loop:
                if (t1 == 0 || s1[t1 - 1] == '(' || formula[i] == '(') {
                    s1[t1++] = formula[i];
                } else if (formula[i] == ')') {
                    while (s1[t1 - 1] != '(') {
                        s2[t2++] = s1[--t1];
                    }
                    t1--;
                } else if ((formula[i] == '*' || formula[i] == '/') && (s1[t1 - 1] == '+' || s1[t1 - 1] == '-')) {
                    s1[t1++] = formula[i];
                } else {
                    s2[t2++] = s1[--t1];
                    goto loop;
                }
            default:
                break;
            }
        }
    }
    while (t1) {
        s2[t2++] = s1[--t1];
    }

    return calculate(s2, &t2);
}

int main(int argc, char* argv[])
{
    char buf[1025];
    int len;

    printHelp();
    while (1) {
        len = read(0, buf, 1024);
        buf[len] = 0;
        if (!strcmp(buf, "q") || !strcmp(buf, "quit")) {
            break;
        }
        if (!strcmp(buf, "h") || !strcmp(buf, "help")) {
            printHelp();
            continue;
        }
        printf("= %d\n", calc(buf, len));
    }

    return 0;
}
