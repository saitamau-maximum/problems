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
  sort(s.begin(), s.end(), [](const string& a, const string& b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
      if (tolower(a[i]) != tolower(b[i])) {
        return tolower(a[i]) < tolower(b[i]);
      }
      if (a[i] != b[i]) {
        // 小文字優先
        return a[i] > b[i];
      }
    }
    return a.size() < b.size();
  });
  cout << s[0] << endl;
  return 0;
}