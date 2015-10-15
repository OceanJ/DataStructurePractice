#include "Stack_List.h"
void PrintStack(Stack S)
{
	PtrToNode Ptr=S;
	cout << "Stack¡¡: ";
	while (Ptr = Ptr->Next)
	{
		cout << Ptr->Element<<" << ";
	}
	cout << endl;
}
int main()
{
	cout << "Creating Stack..." << endl;
	Stack S= CreateStack();
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