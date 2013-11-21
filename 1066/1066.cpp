//
//  1066.cpp
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
int mat[108][108];
int n;
//Program
void Work()
{
    memset(mat, 0, sizeof mat);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &mat[i][j]);
            if (mat[i][j] == 1) {
                mat[i][j] = -1;
            } else if (mat[i][j] == -1) {
                mat[i][j] = -2;
            }
		}
	}
    for (int i = 1; i <= n; i++) {
        mat[0][i] = -2;
        mat[n + 1][i] = -2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mat[i][j] != 0) {
                continue;
            }
            if (j != n && mat[i][j - 1] != -1 &&
                mat[i][j - 1] != 1  &&
                mat[i][j - 1] != 4  &&
                mat[i - 1][j] != -2 &&
                mat[i - 1][j] != 3  &&
                mat[i - 1][j] != 4) { // 2
                mat[i][j] = 2;
            } else if (j != 1 && mat[i][j + 1] != -1 &&
                          mat[i - 1][j] != -2 &&
                          mat[i - 1][j] != 3  &&
                          mat[i - 1][j] != 4) { // 1
                mat[i][j] = 1;
            } else if (j != n && mat[i][j - 1] != -1 &&
                                 mat[i][j - 1] != 1  &&
                                 mat[i][j - 1] != 4  &&
                                 mat[i + 1][j] != -2 &&
                                 mat[i + 1][j] != 1  &&
                                 mat[i + 1][j] != 2) { // 3
                mat[i][j] = 3;
            } else if (j != 1 && mat[i][j + 1] != -1 &&
                                 mat[i][j + 1] != 2  &&
                                 mat[i][j + 1] != 3  &&
                                 mat[i + 1][j] != -2 &&
                                 mat[i + 1][j] != 1  &&
                                 mat[i + 1][j] != 2) { // 4
                mat[i][j] = 4;
            }
        }
    }
    

/*    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", mat[i][j]);
        }
        puts("");
    }*/

    
	for (int i = 1; i <= 4 * n + 3; i++) {
        printf("*");
    }
    puts("");
    
    for (int i = 1; i <= n; i++) {
        printf("*");
        for (int j = 1; j <= n; j++) {
            if (mat[i][j] == -1) {
                printf("H-O-H");
            } else if (mat[i][j] == -2) {
                printf("O");
            } else if (mat[i][j] == 2 || mat[i][j] == 3) {
                printf("H-O");
            } else if (mat[i][j] == 1 || mat[i][j] == 4) {
                printf("O-H");
            }
            if (j != n) {
                printf(" ");
            }
        }
        printf("*\n");
        if (i != n) {
            printf("*");
            for (int j = 1; j <= n; j++) {
                if (mat[i][j] == -1) {
                    printf("     ");
                } else if (mat[i][j] == -2) {
                    printf("|");
                } else if (mat[i][j] == 1 || mat[i][j] == 2) {
                    printf("   ");
                } else if (mat[i][j] == 3) {
                    printf("  |");
                } else if (mat[i][j] == 4) {
                    printf("|  ");
                }
                if (j != n) {
                    printf(" ");
                }
            }
            printf("*\n");
            printf("*");
            for (int j = 1; j <= n; j++) {
                printf("  H ");
            }
            printf(" *\n");
//            printf("*  H   H   H   H  *\n");
            printf("*");
            for (int j = 1; j <= n; j++) {
                if (mat[i + 1][j] == -1) {
                    printf("     ");
                } else if (mat[i + 1][j] == -2) {
                    printf("|");
                } else if (mat[i + 1][j] == 1) {
                    printf("|  ");
                } else if (mat[i + 1][j] == 2) {
                    printf("  |");
                } else if (mat[i + 1][j] == 3) {
                    printf("   ");
                } else if (mat[i + 1][j] == 4) {
                    printf("   ");
                }
                if (j != n) {
                    printf(" ");
                }
            }
            printf("*\n");
        }
    }
    
	for (int i = 1; i <= 4 * n + 3; i++) {
        printf("*");
    }
    printf("\n\n");
}
/*1 2 3 4 象限
-1 -2 平行，垂直

1 : 右边不为-1, 2, 3,上面不为-2, 3, 4, 自己不在第一行，不在第一列
2 : 左边不为-1, 1, 4 上面不为-2, 3, 4, 自己不在第一行，不在最后一列
3 : 左边不为-1, 1, 4 下面不为-2, 1, 2, 自己不在最后一行，不在最后一列
4 : 右边不为-1, 2, 3 下面不为-2, 1, 2, 自己不在最后一行，不在第一列
*/
int main()
{
	for (int i = 1; ; i++) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		printf("Case %d:\n\n", i);
		Work();
	}
    return 0;
}
