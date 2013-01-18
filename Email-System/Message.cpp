// Tacuma Solomon
// Message.cpp

#include "Message.h"
#include <iostream>


Message::Message()
{
}

void Message::setSender(char* send)
{
	strcpy_s(sender,send);
}

void Message::setDate(char* date1)
{
	strcpy_s(date,date1);
}

void Message::setSubject(char* sub)
{
	strcpy_s(subject,sub);
}

void Message::setBody(char* body)
{
	bodyptr=new char[strlen(body)];
	strcpy(bodyptr,body);
}

char* Message::getSender()
{
	return sender;
}

void Message::printBody()
{
	std::cout << bodyptr;
}

void Message::printHeader()
{
	std::cout << sender << "##" << subject << "##" << date << std::endl;
}