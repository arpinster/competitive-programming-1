#include <bits/stdc++.h>

using namespace std;

const int N = 26;

int dua[N][N] = {0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,1,1,0,2,2,0,2,0,0,1,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,1,1,2,0,1,1,0,1,1,1,2,2,1,0,1,2,0,2,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,2,1,1,1,0,1,0,0,1,2,1,0,0,2,0,1,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,2,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,1,2,1,1,1,1,0,2,2,0,1,0,0,1,2,2,0,0,1,0,1,1,1,0,1,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1,1,1,0,0,2,0,1,1,1,0,1,0,1,2,1,1,0,1,0,1,1,0,1,0,1,1,2,1,0,1,1,1,2,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,2,2,0,1,1,1,1,2,0,1,0,1,2,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0};
int satu[] = {0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,0};
int rule[N][N][2] = {{{0,0},{0,1},{1,1},{0,0},{0,0},{0,1},{1,0},{0,1},{0,1},{0,0},{0,1},{1,0},{1,0},{0,1},{0,1},{0,1},{0,0},{1,0},{1,1},{1,0},{1,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{1,0},{0,1},{0,1},{0,0},{1,0},{0,1},{0,0},{1,1},{1,1},{0,0},{1,1},{0,0},{0,0},{0,1},{0,1},{0,1},{0,0},{1,0},{0,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{1,0},{0,1},{0,1},{1,0},{1,0},{1,1},{0,0},{0,1},{0,1},{0,0},{0,1},{1,0},{1,0},{1,1},{1,1},{0,1},{0,0},{1,0},{1,1},{0,0},{1,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{0,0},{1,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{0,1},{0,1},{0,1},{0,0},{0,0},{1,1},{0,0},{0,1},{0,1},{0,1},{0,0},{1,1},{0,0}}
,{{0,0},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{0,1},{0,1},{0,1},{0,0},{1,0},{1,1},{0,0},{1,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{0,0},{0,1},{0,1},{0,0},{1,0},{0,1},{0,0},{0,1},{0,1},{0,0},{0,1},{1,0},{1,0},{0,1},{0,1},{0,1},{0,0},{1,0},{0,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{1,0},{0,1},{0,1},{1,0},{1,0},{0,1},{0,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{0,1},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{0,0},{0,1},{0,1},{0,0},{1,0},{1,1},{1,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{0,1},{1,1},{0,1},{0,0},{0,0},{1,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{0,0},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{1,1},{0,1},{0,1},{0,0},{1,0},{0,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}}
,{{0,0},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{0,1},{0,1},{0,1},{0,0},{1,0},{0,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{1,0},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{1,1},{0,0},{0,1},{0,0},{0,0},{0,1},{0,1},{0,1},{0,0},{1,0},{0,1},{0,0},{1,1},{1,1},{0,1},{0,0},{0,1},{0,0}}
,{{0,0},{0,1},{1,1},{1,0},{0,0},{0,1},{1,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{1,1},{1,1},{0,1},{0,0},{0,0},{0,1},{1,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{1,0},{1,1},{0,1},{1,0},{1,0},{0,1},{0,0},{1,1},{1,1},{0,0},{0,1},{0,0},{0,0},{0,1},{1,1},{1,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{0,0},{0,1},{0,1},{0,0},{0,0},{0,1},{1,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{0,1},{0,1},{0,1},{0,0},{0,0},{1,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{1,0},{1,1},{0,1},{1,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,0},{0,1},{0,0},{1,0},{0,1},{1,1},{0,1},{0,0},{1,0},{0,1},{1,0},{1,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}}
,{{1,0},{1,1},{0,1},{0,0},{1,0},{1,1},{1,0},{1,1},{0,1},{0,0},{0,1},{0,0},{0,0},{1,1},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{1,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{0,0},{1,1},{1,1},{0,0},{1,0},{0,1},{1,0},{0,1},{1,1},{0,0},{0,1},{0,0},{1,0},{1,1},{0,1},{0,1},{0,0},{1,0},{0,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{1,0},{1,1},{1,1},{0,0},{1,0},{0,1},{0,0},{1,1},{1,1},{0,0},{0,1},{1,0},{1,0},{0,1},{0,1},{0,1},{0,0},{0,0},{1,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{0,0},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{0,1},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{0,0},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{0,1},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{0,0},{1,0},{1,0},{0,0},{0,0},{1,0},{0,0},{1,0},{1,0},{0,0},{1,0},{0,0},{0,0},{1,0},{1,0},{1,0},{0,0},{0,0},{1,0},{0,0},{1,0},{1,0},{1,0},{0,0},{1,0},{0,0}}
,{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{1, 0},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}}
,{{0,0},{1,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,0},{0,1},{0,0},{0,0},{0,1},{0,1},{0,1},{0,0},{0,0},{0,1},{0,0},{0,1},{0,1},{0,1},{0,0},{0,1},{0,0}}
,{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{1, 0},{-1,-1},{-1,-1},{-1,-1},{1,0},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}}
};

const int M = 3e6 + 6;
int dp[M];
string tes[M];

bool calc(string s) {
  int m = s.size();
  for (int j = 0; j < m; j++)
    s[j] -= 'a';
  dp[0] = 0;
  dp[1] = satu[s[0]];
  if (m > 1)
    dp[2] = dua[(s[0])][s[1]];
  for (int j = 3; j <= m; j++) {
    if (rule[s[j-2]][s[j-1]][0] == -1 || rule[s[j-2]][s[j-1]][1] == -1) dp[j] = 0;//return false;
    else
      dp[j] = dp[j-2] * rule[s[j-2]][s[j-1]][0] + dp[j-1] * rule[s[j-2]][s[j-1]][1];
  }
  // if (m < 2)
  //   return false;
  // return dp[m-1] > 0 && dp[m] > 0 && dp[m-1] != dp[m];
  return true;
}

void process(string s, int x) {
  string ss = s;
  ss.pop_back();
  assert(calc(ss));
  int m = s.size();
  int u = ss.back()-'a', v = s.back() - 'a';
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if ((i * dp[m-2] + j *dp[m-1]) == x) {
        assert(rule[u][v][0] == -1);
        rule[u][v][0] = i;
        rule[u][v][1] = j;
      }
    }
  }
}

void print_rule() {
  printf("{");
  for (int i = 0; i < 26; i++) {
    if (i)
      printf(",");
    printf("{");
    for (int j = 0; j < 26; j++) {
      if (j)
        printf(",");
      printf("{%d,%d}", rule[i][j][0], rule[i][j][1]);
    }
    printf("}\n");
  }
  printf("}\n");
}

int main() {
  // queue<string> que;
  // que.push("");
  // while (!que.empty()) {
  //   string now = que.front();
  //   int back = now.back()-'a';
  //   if (calc(now) && tes[back].empty())
  //     tes[back] = now;
  //   que.pop();
  //   if (now.size() > 5) continue;
  //   for (int i = 0; i < 26; i++) {
  //     string cur = now;
  //     cur.push_back('a' + i);
  //     que.push(cur);
  //   }
  // }
  // vector<string> ttes;
  // for (int i = 0; i < 26; i++) {
  //   if (tes[i].empty()) continue;
  //   for (int j = 0; j < 26; j++) {
  //     if (rule[i][j][0] != -1) continue;
  //     string now = tes[i];
  //     now.push_back(j + 'a');
  //     ttes.push_back(now); 
  //   }
  // }
  // printf("%d\n", ttes.size());
  // for (string s : ttes) {
  //   cout << s << endl;
  // }
  // int n = ttes.size();
  // for (int i = 0; i < n; i++) {
  //   int x;
  //   scanf("%d", &x);
  //   process(ttes[i], x);
  // }
  // print_rule();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    assert(calc(s));
    //   cerr << "wew" << endl;
    // else
      cout << dp[s.size()] << endl;
  }
  return 0;
}