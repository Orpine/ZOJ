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

//Variable
int T, n, k;
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
bool Check(int a, int b, int c)
{
	return (dot[c] - dot[b]) % (dot[b] - dot[a]) >= 0;
}
void DFS(int a, int b, int st)
{
	if (b == st) {
		if (s.size() == k) {
			for (int i = 0; i < s.size() - 2; i++) {
				if (Check(i, i + 1, i + 2) == false) {
					return;
				}
			}
			if (Check(s.size() - 2, s.size() - 1, s[0]) && Check(s.size() - 1, s[0], s[1])) {
				cnt++;
			}
			return;
		}
	}
	s.push_back(b);
	D c = dot[b] - dot[a], d;
	int maxx = -oo;
	for (auto &i : v[b]) {
		if (vis[b][i]) {continue;}
		d = dot[i] - dot[b];
		if (c % d > maxx) {
			maxx = c % d;
			flag = i;
		}
	}
	vis[b][i] = true;
	DFS(b, i, st);
	vis[b][i] = false;
	s.pop_back();
}

void Work()
{
	cnt = 0;
	int x, y, d;
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
			DFS(i, j, i);
			vis[i][j] = false;
			s.pop_back();
		}
	}
	printf("%d\n", cnt);
}
int main()
{
	for (scanf("%d", &T); T--;) {
		Work();
	}
    return 0; 
}
