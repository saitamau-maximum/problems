#include "testlib.h"

#include <set>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  const int n = rnd.next(1, 1000);  // 1 <= n <= 1000
  println(n);
  set<string> s;
  for (int i = 0; i < n; i++) {
    string t = rnd.next("[a-zA-Z]{1,100}");
    while (s.count(t)) t = rnd.next("[a-zA-Z]{1,100}");
    s.insert(t);
    println(t);
  }
  return 0;
}