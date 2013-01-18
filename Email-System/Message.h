//Tacuma Solomon
//Message header file
#include<string>
using namespace std;

class Message
{
public:
	Message();
	char* getSender();
	// Retrieves message sender
	void printHeader();
	// Prints email header
	void printBody();
	// Prints body of email
	void setSender(char* send);
	// sets the send
	void setDate(char* date1);
	// sets the date data member
	void setSubject(char* sub);
	// sets the subject data member
	void setBody(char* body);
	// sets the body data member

private:
	char sender[50]; // message sender
	char date[15];   // message date
	char subject[60]; // message subject
	char* bodyptr;  // message body
};