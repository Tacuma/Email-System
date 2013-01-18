// Tacuma Solomon

#include "Message.h"
const int MAX_ITEMS = 10;

class FullStack
// Exception class thrown by Push when stack is full.
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
{};


class StackType
{
public:
   StackType();
   // Class constructor.
   bool IsFull() const;
   // Function: Determines whether the stack is full.
   bool IsEmpty() const;
   // Function: Determines whether the stack is empty.
   void Push(Message item);
   // Function: Adds newItem to the top of the stack.
   void Pop();
   // Function: Removes top item from the stack.
   Message Top();
   // Function: Returns a copy of top item on the stack.
   void Report();
   // Prints out the headers of all emails in the stack
   void ReportfromSender(char* address);
   // Prints the email headers of a specific sender
   void Get(int k);
   //retrieves kth email from the top

private:
   int top;
   Message  items[MAX_ITEMS]; //stack array
};
