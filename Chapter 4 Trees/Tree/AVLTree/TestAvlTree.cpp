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
	cout << "This is the test for Avl Tree." << endl;
	cout << "Notice:The print method is preorder traversal " << endl;
	cout << "First,insert some datas..." << endl;
	TestTree = Insert(9, TestTree);
	TestTree = Insert(5, TestTree);
	TestTree = Insert(10, TestTree);
	TestTree = Insert(0, TestTree);
	TestTree = Insert(6, TestTree);
	TestTree = Insert(11, TestTree);
	TestTree = Insert(-1, TestTree);
	TestTree = Insert(1, TestTree);
	TestTree = Insert(2, TestTree);
	PrintTree(TestTree);
	cout << "\nThe Min is " << Retrieve(FindMin(TestTree)) << endl;
	cout << "The Max is " << Retrieve(FindMax(TestTree)) << endl;
	cout << "Count Nodes: " << CountNodes(TestTree) << " Leaves: " 
		<< CountLeaves(TestTree) << " Full: " << CountFull(TestTree) << endl;
	cout << "Now delete 10(with one child node)..." << endl;
	TestTree = Delete(10, TestTree);
	PrintTree(TestTree);
	cout << "\nNow delete 11(with none child node)..." << endl;
	TestTree = Delete(11, TestTree);
	PrintTree(TestTree);
	cout << "\nNow delete 1(with two child node)..." << endl;
	TestTree = Delete(1, TestTree);
	PrintTree(TestTree);
	cout << "\nNow Print element between 5 and 10 in order " << endl;
	PrintKeyBetween(5, 10, TestTree);
	cout << "\nMake empty..." << endl;
	TestTree = MakeEmpty(TestTree);
	int Success = TestTree == NULL;
	cout << "Succeed? " << Success << endl;
	cout << "Now Generate the mininum tree with Height equal to 5" << endl;
	AvlTree MinH10 = MinAvlTree(5);
	PrintTree(MinH10);
	cout << "\nNow Generate the perfect tree with Height equal to 5" << endl;
	AvlTree PrefectH10 = PerfectAvlTree(5);
	PrintTree(PrefectH10);
	cout << "\nMake empty..." << endl;
	MinH10 = MakeEmpty(MinH10);
	PrefectH10 = MakeEmpty(PrefectH10);
	cout << "Good bye!" << endl;
	getchar();
}