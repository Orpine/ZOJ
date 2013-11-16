//
//  1298.cpp
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
vector<pair<int,int> > v[508];
int n, m;
int dis[508];
bool vis[508];
//Program
double Calc(int x, int y, int l) {
    if (abs(x - y) == l) return -1;
	return (l - abs(x - y)) / 2.0 + max(x, y);
}
void Work()
{
    
	queue<int> q;
    for (int i = 1; i <= n; i++) {
        dis[i] = oo;
        vis[i] = false;
    }
	int x, y, z, flag = 1;
	double ans = 0.0, ret;
	
	for (int i = 1; i <= n; i++) {
		v[i].clear();
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, z));
	}
	dis[1] = 0;
	q.push(1);
	while (!q.empty()) {
		x = q.front();vis[x] = false;
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			y = v[x][i].first;
			z = v[x][i].second;
			if (dis[y] > dis[x] + z) {
				dis[y] = dis[x] + z;
				if (!vis[y]) {
					vis[y] = true;
					q.push(y);
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (dis[i] > ans) {
			flag = i;
			ans = dis[i];
		}
		for (int j = 0; j < v[i].size(); j++) {
			ret = Calc(dis[v[i][j].first], dis[i], v[i][j].second);
			if (ret > ans) {
				ans = ret;
				flag = -1;
				x = min(v[i][j].first, i);
				y = max(v[i][j].first, i);
			}
		}
	}
    if (n == 1) {
		printf("The last domino falls after 0.0 seconds, at key domino 1.\n\n");
        return;
    }
	if (flag == -1) {
		printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n", ans, x, y);
	} else {
		printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n", ans, flag);
	}
}
int main()
{
	for (int i = 1; ; i++) {
		scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }
		printf("System #%d\n", i);
		Work();
	}
    return 0;
}
