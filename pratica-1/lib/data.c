#include "data.h"

void createData(Data *data) {
  data = (Data*) malloc (sizeof(Data));
  data->key = NULL;
  data->toString = NULL;
}

void setData(Data *data, void *key, size_t n) {
  data->key = malloc(n);
  memcpy(data->key, key, n); 
}

void setToStringFunction(Data *data, char* (*toString)(void *)) {
  data->toString = toString;
}

void* getKey(Data *data) {
  return data->key;
}

void freeData(Data *data, void (*freeObject)(void *)) {
  if (data == NULL) return;
  freeObject(data->key);
  free(data);
}