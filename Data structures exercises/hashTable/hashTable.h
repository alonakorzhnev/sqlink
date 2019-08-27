#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdlib.h>
#include "linkedList.h"

typedef struct HashTable HashTable;
typedef unsigned long (*hashFunction)(void *key);
typedef void (*elementDestroy)(void *key, void *context);

AdtStatus hashTableCreate(HashTable **hashT, size_t size, hashFunction hashF, elementCompare compF);

AdtStatus hashTableDestroy(HashTable *hashT, elementDestroy destroyF);

AdtStatus hashTableInsert(HashTable *hashT, void *key, void *value);

AdtStatus hashTableFind(HashTable *hashT, void *key, void **foundValue);

AdtStatus hashTableForEach(HashTable *hashT, forEachFunction func);

AdtStatus hashTableRemove(HashTable *hashT, void *key, void **value);

#endif