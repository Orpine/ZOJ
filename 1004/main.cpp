//
//  main.cpp
//  zoj1004
//
//  Created by Orpine on 13-5-26.
//  Copyright (c) 2013年 Orpine. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int oo = 1e9;
const double eps = 1e-6;

string a, b;
int i, j;
vector<char> ans;
stack<char> s;

void Output()
{
    for (vector<char>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void Work()
{
    if (j == b.size()) {
        Output();
        return;
    }
    if (i < a.size()) {
        s.push(a[i]);
        ans.push_back('i');
        ++i;
        Work();
        --i;
        ans.pop_back();
        s.pop();
    }
    if (!s.empty()) {
        char tmp = s.top();
        if (tmp == b[j]) {
            s.pop();
            ans.push_back('o');
            ++j;
            Work();
            --j;
            ans.pop_back();
            s.push(tmp);
        }
    }
}

int main(int argc, const char * argv[])
{
    while (cin >> a >> b) {
        cout << "[" << endl;
        Work();
        cout << "]" << endl;
    }
    
    return 0;
}

