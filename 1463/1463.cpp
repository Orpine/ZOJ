//
//  1463.cpp
//  Code for ZOJ
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
char s[108];
int f[108][108], g[108][108];
char tmp[10];
int n, T;
//Program
string Gets(int l, int r, int k)
{
	if (l > r) return "";
	if (k == 0) {
        char str[10] = {0};
		if (s[r] == '(') {
			str[1] = s[r];
			str[2] = s[r] + 1;
		} else if (s[r] == ')') {
			str[1] = s[r] - 1;
			str[2] = s[r];
		} else if (s[r] == '[') {
			str[1] = s[r];
			str[2] = s[r] + 2;
        } else {
			str[1] = s[r] - 2;
			str[2] = s[r];
        }
		return Gets(l, r - 1, g[l][r - 1]) + (str + 1);
	} else {
        string ret = Gets(l, k - 1, g[l][k - 1]);
        char tmp[2] = {0};
        tmp[0] = s[k];
        ret += tmp;
        ret += Gets(k + 1, r - 1, g[k + 1][r - 1]);
        tmp[0] = s[r];
        ret += tmp;
		return ret;
	}
}
void Work()
{
    memset(f, 0 ,sizeof f);
    memset(g, 0, sizeof g);
    getchar();
    gets(s + 1);
	n = strlen(s + 1);
	
	for (int i = 1; i <= n; i++) {
		f[i][i] = 1;
		g[i][i] = 0;
	}
	
	for (int l = 1; l <= n - 1; l++) {
		for (int i = 1; i + l <= n; i++) {
			int j = i + l;
			f[i][j] = f[i][j - 1] + 1;
			g[i][j] = 0;
			for (int k = i; k < j; k++) {
				if ((s[j] == ')' && s[k] == '(') || (s[j] == ']' && s[k] == '[')) {
					if (f[i][j] > f[i][k - 1] + f[k + 1][j - 1]) {
                        f[i][j] = f[i][k - 1] + f[k + 1][j - 1];
						g[i][j] = k;
					}
                    //					f[i][j] = min(f[i][j], f[i][k - 1] + f[k + 1][j - 1]);
				}
			}
		}
	}
	cout << Gets(1, n, g[1][n]) << endl;
}
int main()
{
    scanf("%d%*c", &T);
	for(int i = 0; i < T; i++) {
        if (i) {
            cout << endl;
        }
		Work();
	}
    return 0; 
}
