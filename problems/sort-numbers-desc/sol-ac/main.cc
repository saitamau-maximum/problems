#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; i++) cout << v[i] << " \n"[i == n - 1];
  }
  return 0;
}