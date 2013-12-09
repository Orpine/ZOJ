//
//  main.cpp
//  Code For ZOJ
//
//  Created by Orpine on 12/4/13.
//  Copyright (c) 2013 Orpine. All rights reserved.
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
typedef long long ll;
const int oo = ~0u>>2;
const double inf = 1e300;
const double eps = 1e-6;

//Variable
class Union
{
public:
	static const int length = 1008;
	int f[length], size[length];
	void initialize()
	{
		for (int i = 1; i <= length; i++) {
			f[i] = i;
			size[i] = 1;
		}
	}
	int& operator[](const int i)
	{
		f[i] = find(f[i]);
		return f[i];
	}
	int find(int x)
	{
		if (x == f[x]) {
			return x;
		} else {
			size[f[x]] += size[x];
			size[x] = 0;
			return f[x] = find(f[x]);
		}
	}
	void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if (x != y) {
			f[x] = y;
			size[y] += size[x];
			size[x] = 0;
		}
	}
};
Union U, A;
int anti[1008];
bool vis[1008];
pair<int, int> sentence[1008];
//Program
int work(int n)
{
	int x, y, ret = 0;
	char s[100];
	memset(vis, 0, sizeof vis);
	memset(anti, 0, sizeof anti);
	U.initialize();
	for (int i = 1; i <= n; i++) {
		scanf("%*s %d %*s %s", &sentence[i].first, s);
		if (s[0] == 't') {
			sentence[i].second = 1;
		} else {
			sentence[i].second = 0;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (sentence[i].second) {
			U.merge(i, sentence[i].first);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (sentence[i].second == 0) {
			x = U[i];
			y = U[sentence[i].first];
			if (x == y) {
				return 0;
			}
			if (anti[x] == 0) {
				anti[x] = y;
			}
			if (anti[y] == 0) {
				anti[y] = x;
			}

			U.merge(x, anti[y]);
			U.merge(y, anti[x]);
		}
	}
	
	U.size[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		anti[i] = anti[U[i]];
	}
	for (int i = 1; i <= n; i++) {
		anti[i] = U[anti[i]];
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && i == U[i]) {
			ret += max(U.size[i], U.size[anti[i]]);
			vis[i] = vis[anti[i]] = true;
		}
	}
	return ret;
}
int main()
{
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		int ans = work(n);
		if (ans == 0 ) {
			printf("Inconsistent\n");
		} else {
			printf("%d\n", ans);
		}
	}
}
