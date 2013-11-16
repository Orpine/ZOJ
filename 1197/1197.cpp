//
//  1197.cpp
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
	void checkin(int x, int y)
	{
		return x1 <= x && x <= x2 && y1 <= y && y <= y2;
	}
}rect[1008];
int n;
vector< pair< char, int > > ans;
int in[1008];
//Program
void Work() {
	
	ans.clear();
	memset(in, 0, sizeof in);
	queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		rect[i].init();
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &num[i][0], &num[i][1]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (rect[j].checkin(num[i][0], num[i][1])) {
				in[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 1) {
			q.push(i);
		}
	}
	
	int x;
	while(!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (checked[i]) continue;
			if (rect[i].checkin(num[x][0], num[x][1])) {
				ans.push_back(make_pair(i + 'A' - 1, x));
				checked[i] = true;
				for (int j = 1; j <= n; j++) {
					if (rect[i].checkin(num[j][0], num[j][1])) {
						in[j]--;
						if (in[j] == 1) {
							q.push(j);
						}
					}
				}
				break;
			}
		}
	}
	if (ans.size() == 0) {
		printf("none\n\n");
	} else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			printf("(%c,%d)", ans[i].first, ans[i].second);
		}
	}
}
int main()
{
	while (scanf("%d", &n), n != 0) {
		Work();
	}
    return 0; 
}
