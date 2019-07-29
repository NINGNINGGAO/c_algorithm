/*
 * @Author: AGOGIN 
 * @Date: 2019-07-29 11:04:18 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-07-29 17:50:50
 */

#ifndef _HashQuad_H
#define _HashQuad_H

typedef int ElementType;
typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable ReHash(HashTable H);

#endif

enum KindOfEntry {Legitimate, Empty, Deleted};
struct HashEntry {
          ElementType Element;
          enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl {
          int TableSize;
          Cell* TheCells;
};