/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:07:22 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:07:22 
 */
#ifndef _AvlTree_H
#define _AvlTree_H

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);

#endif

struct AvlNode {
          ElementType Element;
          AvlTree Left;
          AvlTree Right;
          AvlTree Parents;
          int Height;
};