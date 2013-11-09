//
//  1423.cpp
//  Workspace
//
//  Created by Orpine on 13-11-9.
//  Copyright (c) 2013年 Orpine. All rights reserved.
//

//Header
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>

using namespace std;

//Macro
#define rep(i, a, b) for (size_t i = a; i <= b; ++i)
#define drep(i, a, b) for (size_t i = a; i >= b; --i)
#define irep(i, e, x) for (size_t i = x; i; i = e[i].next)
#define sqr(x) ((x) * (x))

typedef long long ll;
const int oo = ~0u>>2;
const double inf = 1e300;
const double eps = 1e-6;

//Variable
int n, T;
char s[300];
//Program
string Convert(char s[], int l, int r)
{
    string ss = "";
    int tot = l;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(') {
            int cnt = 1;
            for (int j = i + 1; j <= r; j++) {
                if (s[j] == '(') {
                    cnt++;
                }
                if (s[j] == ')') {
                    cnt--;
                }
                if (cnt == 0) {
                    string temp = Convert(s, i + 1, j - 1);
                    if (s[i - 1] != '-' || temp.length() == 1) {
                        char tmp = s[i];
                        s[i] = 0;
                        ss += s + tot;
                        s[i] = tmp;
                        ss += Convert(s, i + 1, j - 1);
                        i = j;
                        tot = j + 1;
                    }
                    break;
                }
            }
        }
    }
    char tmp = s[r + 1];
    s[r + 1] = 0;
    ss += s + tot;
    s[r + 1] = tmp;
    return ss;
}
void Work()
{
    int len = 0;
    char tmp[300];
    gets(tmp + 1);
    for (int i = 1; i <= strlen(tmp + 1); ++i) {
        if (tmp[i] != ' ') {
            s[++len] = tmp[i];
        }
    }
    string ss = Convert(s, 1, len);
    cout << ss << endl;
}
int main()
{
    for (scanf("%d\n", &T); T; T--) {
        Work();
    }
    return 0; 
}
