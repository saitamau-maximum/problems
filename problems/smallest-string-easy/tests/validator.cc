#include "testlib.h"

#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int n = inf.readInt(1, 1000, "n");  // 1 <= n <= 1000
  inf.readEoln();                     // 改行
  set<string> s;
  for (int i = 0; i < n; i++) {
    string t = inf.readToken("[a-z]{1,100}", format("s[%d]", i));  // 1 <= |s[i]| <= 100
    ensuref(s.count(t) == 0, "duplicate string: %s", t.c_str());
    s.insert(t);
    inf.readEoln();  // 改行
  }
  inf.readEof();
}