/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 17:46:50 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-07-29 10:30:36
 */
#ifndef _HashSep_H
#define _HashSep_H

typedef int ElementType;
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);

#endif 

struct ListNode {
          ElementType Element;
          Position Next;
};

typedef Position List;

struct  HashTbl {
          int TableSize;
          List *TheLists;
};
