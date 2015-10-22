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
		cout << "Insert " << i << " and " << -i << endl;
		TestTree=Insert(i, TestTree);
		TestTree = Insert(-i, TestTree);
		bool Success = Retrieve(Find(i, TestTree)) == i&&
			Retrieve(Find(-i, TestTree)) == -i;
		cout << "Find Succeed? " << Success<<endl;
	}
	cout << "The Min is " << Retrieve(FindMin(TestTree))<<endl;
	cout << "The Max is " << Retrieve(FindMax(TestTree))<<endl;
	for (int i = 5; i < 10; i++)
	{
		cout << "Delete " << i << endl;
		TestTree = Delete(i, TestTree);
		bool Success = Retrieve(Find(i, TestTree)) == i;
		cout << "Find Succeed? " << Success<< endl;
	}

	cout << "Make empty!" << endl;
	TestTree=MakeEmpty(TestTree);
	int Succes = TestTree == NULL;
	cout << "Succeed? " << endl;
	cout << "Good bye!" << endl;
	getchar();
}