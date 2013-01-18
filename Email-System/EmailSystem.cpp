//Tacuma Solomon
// Data Structures
// Programming Assignment 1

/*This assignment involves modeling a very simple email system as C++ classes. 
All the email messages are addressed to you. 
Each email message has several data field: 
(1) a from-field (who it is from), (2) a date field, (3) a subject field, and
(4) a body field (the text of the message). 
Given as input a group of email messages (each having all the fields just indicated), 
listed from the oldest message to the most recent, your program should be able to respond
to queries of the following kinds:

§         Sort (arrange) and display the received messages from the most recent to the least recent

§         Delete the most recent message

§         Display all the (non-deleted) messages from a given sender, arranged the most recent to the least recent

§         Display a given message

The precise formatting of the input, the queries, and the answers of your program is detailed below.
*/


#include <iostream>
#include <fstream>
#include <string>
#include "StackType.h"
using namespace std;

void readmessages(StackType&, ifstream&); //Function prototype 
void readqueries(StackType&, ifstream&); // Function prototype
void Footer();


int main(int argc, char *argv[])
{
	//if (argc !=3 )
	//	cout << "File names are missing." << endl;
	//else {
		ifstream in,in2; 
		in.open("messagesfile.txt"); //argv[1]);
		in2.open("queriesfile.txt");//argv[2]);
		if ( !in.is_open() || !in2.is_open()) {
			cout<<"Could not open file\n";
		}
		else {
			StackType email;	// New stack of email messages
			readmessages(email, in);
			readqueries(email, in2);
		}
	//}
	Footer();
	system("pause");
	return 0;
}

//Prints Footer
void Footer()
{
	cout << endl << endl;
	cout << "() Code by Tacuma Solomon " << endl;
	cout << "() Not for Redistribution or Reuse." << endl << endl;
}

// Reads messages file and pushes email messages to the stack
void readmessages(StackType& email, ifstream& in)
{
	Message message; // Redo the constructor

	while (!(in.eof())) {

		char Body[1000];
		char FROM[6], sender[50];
		char DATE[6], date[15];
		char SUBJECT[9], subject[60]; // Body, sender,date, and subject initialized as character arrays

		in >> FROM;
		in.ignore(1);
		in.getline(sender,50);
		in >> DATE >> date;
		in >> SUBJECT;
		in.ignore(1);
		in.getline(subject,60);
		in.ignore(100,'\n');  // reads the data from messagesfile.txt

		in.get(Body,1000,'#');

		message.setSender(sender);
		message.setDate(date);
		message.setSubject(subject);
		message.setBody(Body); // Sets the information into a message object

		email.Push(message);   // Pushes the message object onto the emails stack

		in.ignore(100,'\n');
	}
}

// Reads and executes commmands from queriesfile.txt
void readqueries(StackType& email, ifstream& in){
	char command[30], address[50];
	int k;

	while (!(in.eof())) {
		in >> command;
		if (strcmp(command,"LIST-MESSAGES-BY-DATE") == 0)
				email.Report();
		if (strcmp(command,"LIST-MESSAGES-FROM") == 0){
			 in>>address;
			 email.ReportfromSender(address);
		}
		if (strcmp(command,"DELETE-MOST-RECENT-MESSAGE") == 0)
			email.Pop();
		if (strcmp(command,"DISPLAY") == 0 ){
			in >> k;
			email.Get(k);
		}
	}

}

/*
LIST-MESSAGES-BY-DATE:
yourcs103TAs##2nd phase of assignment 1##09-28-2005
yourethics##academic honesty##09-22-2005
ayoussef##next phase of assignment 1##09-21-2005
korman##cs103##09-16-2005
ayoussef##Do your homework##09-15-2005
##########

LIST-MESSAGES-FROM: ayoussef
ayoussef##next phase of assignment 1##09-21-2005
ayoussef##Do your homework##09-15-2005
##########

MESSAGE: 5
My advice to you is to start to do your programming assignment 1 today. -AY
##########

DELETE-MOST-RECENT-MESSAGE:
MESSAGE DELETED
##########

MESSAGE: 3
listen to your professor of cs103, and follow his advice.
You won't regret it.

Good luck!
Your Chairman
##########

MESSAGE: 6
NONE
##########

LIST-MESSAGES-FROM: dean
NONE
##########



() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . . */