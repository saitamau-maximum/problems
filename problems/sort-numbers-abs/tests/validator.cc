#include "testlib.h"

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int testcases = 0;
  while (true) {
    int n = inf.readInt(0, 100, "n");  // 0 <= n <= 100
    inf.readEoln();                    // 改行
    if (n == 0) break;
    testcases++;
    for (int i = 0; i < n; i++) {
      if (i > 0) inf.readSpace();                  // 空白
      inf.readInt(-100, 100, format("a[%d]", i));  // 1 <= a[i] <= 100
    }
    inf.readEoln();  // 改行
  }
  ensuref(1 <= testcases && testcases <= 100, "testcases = %d", testcases);
  inf.readEof();
}