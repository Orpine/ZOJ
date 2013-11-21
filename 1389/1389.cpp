//
//  1389.cpp
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
class T
{
public:
	int s, d, h;
	void init()
	{
		int l, r;
		scanf("%d%d%d%d", &d, &h, &l, &r);
		s = l * r;
	}
};
T tank[50008];
int n, v;
//Program
double Calc(double height)
{
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		if (tank[i].d <= height) {
			sum += min(height - tank[i].d, (double)tank[i].h) * tank[i].s;
		}
	}
	return v - sum;
}
void Work()
{
	int sum = 0, maxx = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		tank[i].init();
		maxx = max(maxx, tank[i].d + tank[i].h);
		sum += tank[i].h * tank[i].s;
	}
	scanf("%d", &v);
	if (v > sum) {
		puts("OVERFLOW");
		return;
	}
	double l = 0, r = maxx, mid;
	while (fabs(r - l) >= eps) {
		mid = (l + r) / 2;
		if (Calc(mid) > 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("%.2lf\n", r);
}
int main()
{
    int T;
	scanf("%d", &T);
	while (T--) {
		Work();
	}
    return 0;
}
