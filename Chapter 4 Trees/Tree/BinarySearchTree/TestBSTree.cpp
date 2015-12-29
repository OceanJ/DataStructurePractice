#include "BinarySearchTree.h"


int main()
{
	SearchTree TestTree = NULL;
	TestTree = Insert(6, TestTree);
	TestTree = Insert(2, TestTree);
	TestTree = Insert(8, TestTree);
	TestTree = Insert(1, TestTree);
	TestTree = Insert(4, TestTree);
	TestTree = Insert(3, TestTree);
	cout << "PreOrder traversal:";
	PreOrder(TestTree);
	cout << "\nInOrder traversal:";
	InOrder(TestTree);
	cout << "\nPostOrder traversal:";
	PostOrder(TestTree);
	cout << "\nThe Min is " << Retrieve(FindMin(TestTree)) << endl;
	cout << "The Max is " << Retrieve(FindMax(TestTree)) << endl;
	cout << "\nThe Height is:" << CalHeight(TestTree);
	cout << "Now delete 4(with one child node)" << endl;
	TestTree = Delete(4, TestTree);
	PreOrder(TestTree);
	cout << "\nNow delete 3(with none child node)" << endl;
	TestTree = Delete(3, TestTree);
	PreOrder(TestTree);
	cout << "\nNow insert 5,3,4 " << endl;
	TestTree = Insert(5, TestTree);
	TestTree = Insert(3, TestTree);
	TestTree = Insert(4, TestTree);
	PreOrder(TestTree);
	cout << "\nNow delete 5(with two child node)" << endl;
	TestTree = Delete(5, TestTree);
	PreOrder(TestTree);
	cout << "\nThe Height is:" << CalHeight(TestTree);
	cout << "\nMake empty!" << endl;
	TestTree = MakeEmpty(TestTree);
	int Success = TestTree == NULL;
	cout << "Succeed? " << Success<<endl;
	cout << "Good bye!" << endl;
	getchar();
}