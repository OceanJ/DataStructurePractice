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
	SearchTree TestTree=NULL;
	for (int i = 0; i < 10; i++)
	{

		TestTree=Insert(i, TestTree);
		cout << "Find Succeed? " << Retrieve(Find(i, TestTree))<<endl;
	}
	cout << "The Min is " << Retrieve(FindMin(TestTree)) << endl;
	cout << "The Max is " << Retrieve(FindMax(TestTree))<<endl;
	for (int i = 5; i < 10; i++)
	{
		cout << "Delete " << i << endl;
		TestTree = Delete(i, TestTree);
		cout << "Find Succeed? " << Retrieve(Find(i, TestTree)) << endl;
	}
	TestTree = Delete(9, TestTree);
	cout << "Find Succeed? " << Retrieve(Find(9, TestTree)) << endl;
	cout << "Make empty!" << endl;
	TestTree=MakeEmpty(TestTree);
	
	cout << "Succeed? " << Retrieve(TestTree)<< endl;
	cout << "Good bye!" << endl;
	cout<<Retrieve(TestTree);
	getchar();
}