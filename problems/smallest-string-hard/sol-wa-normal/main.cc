#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  sort(s.begin(), s.end());
  cout << s[0] << endl;
  return 0;
}