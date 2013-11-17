//
//  1030.cpp
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
const double PI = 3.14159265;
//Variable
int T, n, k, cnt;
bool vis[1008][1008];
vector< int > v[1008];
vector< int > s;
class D
{
public:
	int x, y;
	D(int _x = 0, int _y = 0): x(_x), y(_y){}
	void init()
	{
		scanf("%d%d", &x, &y);
	}
	D operator -(const D &o)const
	{
		return D(x - o.x, y - o.y);
	}
	int operator %(const D &o)const
	{
		return x * o.y - y * o.x;
	}
}dot[1008];
//Program
double Calc(D a, D b)
{
    double a1 = atan2(a.y, a.x);
    double a2 = atan2(b.y, b.x);
    if (a2 > a1) {
        return 2 * PI - (a2 - a1);
    } else {
        return -(a2 - a1);
    }
}
bool Check()
{
    double ret = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        ret += Calc(dot[s[i]] - dot[s[i + 1]], dot[s[i + 2]] - dot[s[i + 1]]);
    }
    return fabs(ret - PI * (k - 2)) < eps;
}
int Find(D c, int b)
{
    int minn = oo;
    int flag = 0;
    D d;
    for (auto &i : v[b]) {
		if (vis[b][i]) {continue;}
		d = dot[i] - dot[b];
		if (Calc(c, d) < minn) {
			minn = Calc(c, d);
			flag = i;
		}
	}
    return flag;
}
int Find2(D c, int b, int e)
{
    int minn = oo;
    int flag = 0;
    D d;
    for (auto &i : v[b]) {
		if (i == e) {continue;}
		d = dot[i] - dot[b];
		if (Calc(c, d) < minn) {
			minn = Calc(c, d);
			flag = i;
		}
	}
    return flag;
}
void DFS(int a, int b, int st)
{
	if (b == st) {
		if (s.size() == k) {
            s.push_back(s[0]);
            s.push_back(s[1]);
            if (Find2(dot[s[s.size() - 3]] - dot[s[0]], s[0], s[s.size() - 3]) == s[1] && Check()) {
                cnt++;
            }
            s.pop_back();
            s.pop_back();
			return;
		}
	}
	s.push_back(b);
    int flag = Find(dot[a] - dot[b], b);
    if (flag != 0) {
        vis[b][flag] = true;
        vis[flag][b] = true;
        DFS(b, flag, st);
        vis[b][flag] = false;
        vis[flag][b] = false;
    }
	s.pop_back();
}

void Work()
{
	cnt = 0;
	int x, y, d;
//    s.clear();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		dot[x].init();
		v[x].clear();
		scanf("%d", &d);
		for (int j = 1; j <= d; j++) {
			scanf("%d", &y);
			v[x].push_back(y);
		}
	}
	scanf("%d", &k);
	for (int i = 1; i <= n; i++) {
		for (auto &j : v[i]) {
			s.push_back(i);
			vis[i][j] = true;
            vis[j][i] = true;
			DFS(i, j, i);
			vis[i][j] = false;
            vis[j][i] = false;
			s.pop_back();
		}
	}
    s.push_back(10000);
	printf("%d\n", cnt / k);
    s.pop_back();
}
int main()
{
	for (scanf("%d", &T); T--;) {
		Work();
	}
    return 0;
}
