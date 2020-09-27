#include <stdio.h>
#include <stdlib.h>
#include "./lib/tst.h"

int main () {
  char strings[8][20] = {"agreement", "cat", "visible", "bean", "charter", "continuation", "charm", "ground"};
  TST tst;

  int i=0;
  for (i=0; i<8; i++) {
    tst_insert(&tst, strings[i]);
  }

  printf(tst_search(&tst, "visible") ? "YES\n":"NO\n");
  printf(tst_search(&tst, "charm") ? "YES\n":"NO\n");
  printf(tst_search(&tst, "germano") ? "YES\n":"NO\n");

  return 0;
}
