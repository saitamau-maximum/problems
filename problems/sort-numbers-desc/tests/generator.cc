#include "testlib.h"

#include <vector>
using namespace std;

void dataset() {
  int n = rnd.next(1, 100);  // 1 <= n <= 100
  // int n = 1;  // 1 <= n <= 100
  println(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) a[i] = rnd.next(1, 100);  // 1 <= a[i] <= 100
  println(a);
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  const int t = 100;  // データセット数
  for (int i = 0; i < t; i++) dataset();
  println(0);  // 最後に 0 を出力
  return 0;
}