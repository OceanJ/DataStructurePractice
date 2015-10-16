#include "Stack_Array.h"
void PrintStack(Stack S)
{
	cout << "Top>>";
	for (int i = S->TopOfStack ; i >= 0 ;i--)
	{
		cout << S->Array[i]<<" >> ";
	}
	cout << "End ";
	cout << endl;
}
int main()
{
	cout << "Creating Stack..." << endl;
	Stack S= CreateStack(11);
	for (int i = 0; i < 10; i++)
	{
		cout << "Push " << i<<"..."<<endl;
		Push(i, S);
		PrintStack(S);
	}
	for (int i = 9; i>=5; i--)
	{
		cout << "Pop " << i << "..." << endl;
		Pop(S);
		PrintStack(S);
	}
	cout << "Now the top of the stack is :" << Top(S)<<endl;
	cout << "Making Empty....." << endl;
	MakeEmpty(S);
	cout << "Is Empty? " <<(bool) IsEmpty(S)<<endl;
	cout << "Disposing the stack..." << endl;
	DisposeStack(S);
	cout << "Succeed!" << endl;
	cout << "That is awesome ! Good Bye !";
	getchar();
}