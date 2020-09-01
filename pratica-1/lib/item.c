#include "item.h"

int compare_data(Item a, Item b) {
  if (a > b) {
    return 1;
  } else if (a < b) {
    return -1;
  } else {
    return 0;
  }
}

void to_string_int(Item item) {
  printf("%d ", item);
}
