#include "BinarySearchTree.h"
//void PrintTree(SearchTree T)
//{
//	if (!T)
//	{
//		cout << "\t\t"<<T->Element<<"\t\t";
//		PrintTree(T->Left);
//		PrintTree(T->Right);
//	}
//}
int main()
{
	SearchTree TestTree=new TreeNode;
	for (int i = 0; i < 10; i++)
	{
		cout << "Insert " << i<<endl;
		Insert(i, TestTree);
		int succeed = Find(i, TestTree)!=NULL;
		cout << "Succeed? " << succeed;
	}
	cout << "The Min is " << FindMin(TestTree)<<endl;
	cout << "The Max is " << FindMax(TestTree);
	for (int i = 5; i < 10; i++)
	{
		cout << "Delete " << i << endl;
		Insert(i, TestTree);
		int succeed = Find(i, TestTree) == NULL;
		cout << "Succeed? " << succeed;
	}
	cout << "Make Empty!" << endl;
	MakeEmpty(TestTree);
	cout << "Succeed! Good bye!" << endl;

}