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
string Morse[] = {
    ".-","-...","-.-.","-..",
    ".","..-.","--.","....",
    "..",".---","-.-",".-..",
    "--","-.","---",".--.",
    "--.-",".-.","...","-",
    "..-","...-",".--","-..-",
    "-.--","--.."};

char s[20008];
ll f[20008];
int T, m, len;
string word[10008];
//Program
void Work()
{
	scanf("%s", s + 1);
	len = strlen(s + 1);
	scanf("%d", &m);
	char tmp[30];
	for (int i = 1; i <= m; i++)
	{
		scanf("%s", tmp + 1);
		string temp = "";
		for(int j = 1; j <= strlen(tmp + 1); j++)
		{
			temp += Morse[tmp[j] - 'A'];
		}
		word[i] = temp;
	}
	
	memset(f, 0, sizeof f);
	f[0] = 1;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(i >= word[j].length())
			{
				char tmp = s[i + 1];
				s[i + 1] = 0;
				if (s + (i - word[j].length() + 1) == word[j])
					f[i] += f[i - word[j].length()];
				s[i + 1] = tmp;
			}
		}
	}
    cout << f[len] << endl;
}
int main()
{
	for (scanf("%d", &T); T--;)
	{
		Work();
	}
    return 0; 
}
