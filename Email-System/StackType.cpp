// Tacuma Solomon
// File: StackType.cpp

#include "StackType.h"
#include <iostream>

StackType::StackType()
{
  top = -1;
}

bool StackType::IsEmpty() const
{
  return (top == -1);
}

bool StackType::IsFull() const
{
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(Message newItem)
{
  if( IsFull() )
    throw FullStack();
  top++;
  items[top] = newItem;
}

void StackType::Pop()
{
  if( IsEmpty() )
    cout << "THERE ARE NO MESSAGES TO DELETE" << endl;
  top--;
  cout << "DELETE-MOST-RECENT-MESSAGE:" << endl;
  cout << "MESSAGE DELETED" << endl << "##########" << endl << endl;
}

Message StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    

void StackType::Report()
{
	int count=0;
	cout << "LIST-MESSAGES-BY-DATE:" << endl;
	int temp = top;
	for(temp;temp>=0;temp--){
		items[temp].printHeader();
		count++;
	}
	if (count==0)
		cout << "NONE" << endl;
	cout << "##########" << endl << endl;
}

void StackType::ReportfromSender(char* address)
{
	int count = 0;
	int temp = top;
	cout << "LIST-MESSAGES-FROM: " << address << endl;
	for(temp;temp>=0;temp--){
		if (strcmp(address,items[temp].getSender()) == 0){
			items[temp].printHeader();
			count++;
		}
	}
	if (count==0)
		cout <<"NONE"<<endl;
	cout << "##########" << endl << endl;
}

void StackType::Get(int k)
{
	cout << "MESSAGE: " << k << endl;
	int temp = top;
	if (k>(top+1))
		cout << "NONE" << endl;
	else
		items[temp-(k-1)].printBody();
	cout << "##########" << endl << endl;

}


