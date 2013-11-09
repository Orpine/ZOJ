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
char s[300][300];
int n;
//Program
int DFS1(int x, int l, int r, int sum)
{
	if (x <= 0 || x >= n || l <= x - 1 || r >= 2 * n - x)
		return sum;
	for (int i = l; i <= r; i++)
	{
		if (s[x][i] != '-')
			return sum;
	}
	return DFS1(x - 1, l - 1, r + 1, sum + r - l + 1);
}
int DFS2(int x, int l, int r, int sum)
{
	if (x <= 0 || x >= n || l <= x - 1 || r >= 2 * n - x)
		return sum;
	for (int i = l; i <= r; i++)
	{
		if (s[x][i] != '-')
			return sum;
	}
	return DFS1(x + 1, l - 1, r + 1, sum + r - l + 1);
}
void Work(int T)
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		gets(s[i] + 1);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (s[i][j] == '-')
			{
				ans = max(ans, DFS1(i, j - 1, j + 1, 1));
				ans = max(ans, DFS2(i, j - 1, j + 1, 1));
			}
		}
	}
	printf("Triangle #%d\n", T);
	printf("The largest triangle area is %d.\n", ans);
}
int main()
{
	int T = 0;
	while(scanf("%d\n", &n), n != 0)
	{
		Work(++T);
	}
    return 0; 
}
