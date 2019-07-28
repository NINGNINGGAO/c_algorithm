/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:07:39 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:07:39 
 */
#ifndef _LINK_H
#define _LINK_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
Position FindKth(int Key, List L);
void Delete(ElementType X, List L);
int DeleteKth(int Key, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
int InsertKth(ElementType X, List L, int Key);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
ElementType Retrieve(Position P);

#endif

struct Node {
          ElementType Element;
          Position Next;
};