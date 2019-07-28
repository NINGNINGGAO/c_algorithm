/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:18 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:18 
 */
#ifndef _Tree_H
#define _Tree_H

typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#endif

struct TreeNode {
          ElementType Element;
          SearchTree Left;
          SearchTree Right;
};