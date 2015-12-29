#include <iostream>
using namespace std;

#ifndef Binary_Search_Tree_H
#define Binary_Search_Tree_H
typedef int ElementType;
struct TreeNode
{
	ElementType Element;
	TreeNode * Left;
	TreeNode  * Right;
};
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);
//前序遍历
void PreOrder(SearchTree T);
//中序遍历
void InOrder(SearchTree T);
//后序遍历
void PostOrder(SearchTree T);
//求高
int CalHeight(SearchTree T);

#endif  