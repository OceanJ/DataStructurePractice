#include "AvlTree.h"

void PrintTree(AvlTree T)
{
	if (T)
	{
		cout << T->Element << "  ";
		PrintTree(T->Left);
		PrintTree(T->Right);
	}
}

int main()
{
	AvlTree TestTree = NULL;
	TestTree = Insert(9, TestTree);
	TestTree = Insert(5, TestTree);
	TestTree = Insert(10, TestTree);
	TestTree = Insert(0, TestTree);
	TestTree = Insert(6, TestTree);
	TestTree = Insert(11, TestTree);
	TestTree = Insert(-1, TestTree);
	TestTree = Insert(1, TestTree);
	TestTree = Insert(2, TestTree);
	cout << "This is the test for Avl Tree." << endl;
	cout << "Notice:The print method is preorder traversal " << endl;
	cout << "First,insert some datas..." << endl;
	PrintTree(TestTree);
	cout << "\nThe Min is " << Retrieve(FindMin(TestTree)) << endl;
	cout << "The Max is " << Retrieve(FindMax(TestTree)) << endl;
	cout << "Now delete 10(with one child node)..." << endl;
	TestTree = Delete(10, TestTree);
	PrintTree(TestTree);
	cout << "\nNow delete 11(with none child node)..." << endl;
	TestTree = Delete(11, TestTree);
	PrintTree(TestTree);
	cout << "\nNow delete 1(with two child node)..." << endl;
	TestTree = Delete(1, TestTree);
	PrintTree(TestTree);
	cout << "\nMake empty..." << endl;
	TestTree = MakeEmpty(TestTree);
	int Success = TestTree == NULL;
	cout << "Succeed? " << Success << endl;
	cout << "Good bye!" << endl;
	getchar();
}