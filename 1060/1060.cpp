//
//  1060.cpp
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
int n, m;
int in[30], indeg[30], seq[30];
vector<int> v[30];
//Program
int Topo()
{
	queue<int> q;
	int cnt = 0, x, ret = 0;
	memcpy(in, indeg, sizeof indeg);
	for (int i = 0; i < n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		if (q.size() > 1) ret = q.size();
		x = q.front();
		q.pop();
		seq[++cnt] = x;
		for (int i = 0; i < v[x].size(); i++) {
			in[v[x][i]]--;
			if (in[v[x][i]] == 0) {
				q.push(v[x][i]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (in[i] > 0) {
			return -1;
		}
	}
	return ret;
}
void Work()
{
    for (int i = 0; i < n; i++) {
        v[i].clear();
    }
    memset(indeg, 0, sizeof indeg);
	char x, y;
    int ret;
	for (int i = 1; i <= m; i++) {
		scanf("%c<%c%*c", &x, &y);
		x -= 'A', y -= 'A';
		indeg[y]++;
		v[x].push_back(y);
        ret = Topo();
		if (ret == -1) {
			printf("Inconsistency found after %d relations.\n", i);
			for (int j = i + 1; j <= m; j++) {
                scanf("%c<%c%*c", &x, &y);
            }
            return;
		} else if (ret == 0) {
            printf("Sorted sequence determined after %d relations:", i);
            for(int i = 1; i <= n; i++) {
                printf("%c", seq[i] + 'A');
            }
            printf(".\n");
			for (int j = i + 1; j <= m; j++) {
                scanf("%c<%c%*c", &x, &y);
            }
            return;
        }
	}
	printf("Sorted sequence cannot be determined.\n");
}
int main()
{
	while(1)
	{
		scanf("%d%d%*c", &n, &m);
		if(n == 0 && m == 0)
			break;
		Work();
	}
    return 0;
}
