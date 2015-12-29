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
//ǰ�����
void PreOrder(SearchTree T);
//�������
void InOrder(SearchTree T);
//�������
void PostOrder(SearchTree T);
//���
int CalHeight(SearchTree T);

#endif  