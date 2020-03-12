#ifndef __DATA_H__
#define __DATA_H__

#include <stdlib.h>
#include <string.h>
#define STRING_MAX 2048
#define BUFFER_SIZE 256

typedef struct {
  void *key;  
  char* (*toString)(void *);
} Data;

void createData(Data *data);
void setData(Data *data, void *key, size_t n);
void setToStringFunction(Data *data, char* (*toString)(void *));
void* getKey(Data *data);
void freeData(Data *data, void (*freeObject)(void *));

#endif