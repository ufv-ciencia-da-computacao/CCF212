#include <stdio.h>
#include <stdlib.h>
#include "./lib/patricia.h"

int main () {
  char strings[6] = {'A', 'E', 'H', 'D', 'S', '2'};
  Patricia patricia;

  pat_init(&patricia);

  int i=0;
  for (i=0; i<6; i++) {
    pat_insert(&patricia, strings[i]);
  }

  printf(pat_search(patricia, 'M') ? "YES\n":"NO\n");
  printf(pat_search(patricia, '2') ? "YES\n":"NO\n");
  printf(pat_search(patricia, 'D') ? "YES\n":"NO\n");

  return 0;
}
