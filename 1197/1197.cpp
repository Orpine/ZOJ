//
//  .cpp
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
struct R
{
	int x1, x2, y1, y2;
	void init()
	{
		scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
	}
	bool checkin(int x, int y)
	{
		return x1 <= x && x <= x2 && y1 <= y && y <= y2;
	}
}rect[1008];
int n;
vector< pair< char, int > > ans;
int num[1008][2];
bool checked[2008];
vector< int > v[2008];
//Program
void Work() {
	
	ans.clear();
    memset(checked, false , sizeof checked);
	queue<int> q;
    for (int i = 1; i <= n * 2; i++) {
        v[i].clear();
    }
	
	for (int i = 1; i <= n; i++) {
		rect[i].init();
        v[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &num[i][0], &num[i][1]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (rect[i].checkin(num[j][0], num[j][1])) {
                v[i].push_back(j + n);
                v[j + n].push_back(i);
			}
		}
	}
    
    for (int i = 1; i <= n * 2; i++) {
        if (v[i].size() == 1) {
            q.push(i);
        }
    }
    
    int x;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        if (checked[x]) {
            continue;
        }
        ans.push_back(make_pair(min(x, v[x][0]) + 'A' - 1, max(x, v[x][0]) - n));
        checked[x] = true;
        checked[v[x][0]] = true;
        int a = v[x][0], b = x;
        for (int i = 1; i <= n * 2; i++) {
            if (checked[i]) {
                continue;
            }
            auto it = find(v[i].begin(),v[i].end(),a);
            if (it != v[i].end()) {
                v[i].erase(it);
                if (v[i].size() == 1) {
                    q.push(i);
                }
            }
            it = find(v[i].begin(),v[i].end(),b);
            if (it != v[i].end()) {
                v[i].erase(it);
                if (v[i].size() == 1) {
                    q.push(i);
                }
            }
        }
    }
    
	if (ans.size() == 0) {
		printf("none\n\n");
	} else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size() - 1; i++) {
			printf("(%c,%d) ", ans[i].first, ans[i].second);
		}
        printf("(%c,%d)\n\n", ans[ans.size() - 1].first, ans[ans.size() - 1].second);
	}
}
int main()
{
    for (int i = 0; ; i++) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        printf("Heap %d\n", i + 1);
        Work();
    }
    return 0;
}
