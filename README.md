
Simple Email System
===================

Courtesy of 
George Washington University's
Fall 2005 class on Data Structures in C++
http://www.seas.gwu.edu/~ayoussef/cs103/fall05/Assignment1.html


Data Structures/Concepts Used:
==============================
Stacks, Object Oriented Programming (OOP), File I/O


Output:
=======

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

	Press any key to continue . . . 

Input:
======
#####queriesfile.txt
	LIST-MESSAGES-BY-DATE
	LIST-MESSAGES-FROM ayoussef
	DISPLAY 5
	DELETE-MOST-RECENT-MESSAGE
	DISPLAY 3
	DISPLAY 6
	LIST-MESSAGES-FROM dean
#####messagesfile.txt
	FROM: ayoussef
	DATE: 09-15-2005  
	SUBJECT: Do your homework
	BODY:
	My advice to you is to start to do your programming assignment 1 today. -AY
	##########
	FROM: korman
	DATE: 09-16-2005  
	SUBJECT: cs103
	BODY:
	listen to your professor of cs103, and follow his advice.
	You won't regret it.
	
	Good luck!
	Your Chairman
	##########
	FROM: ayoussef
	DATE: 09-21-2005  
	SUBJECT: next phase of assignment 1
	BODY:
	I hope you are progressing well in your first programming assignment 
	in cs103. By now, you should have come up with an overall design of 
	your program, determined what classes to use to model each message and to
	model the whole set of messages. Also, you should by now be done
	implementing the file-reading part of your program.
	
	Good luck!
	Your instructor
	##########
	FROM: yourethics
	DATE: 09-22-2005  
	SUBJECT: academic honesty
	BODY:
	Hello there,
	We hope you are doing well in all your assignments.
	Remember to do your best while maintaining the highest moral conduct.
	You cannot cheat, you cannot download software from anywhere to
	do your programming assignments in cs103, and you cannot ask anyone else
	to write a program or piece of code for you to include in your cs 103
	programming assignments. If you have any question or need help, ask the
	instructor or the TAs; they are there to help you. They know how much to
	tell you without giving away the answers and denying you the opportunity
	to challenge yourself and learn.
	
	Good luck!
	Your ethics
	##########
	FROM: yourcs103TAs
	DATE: 09-28-2005  
	SUBJECT: 2nd phase of assignment 1
	BODY:
	By now, you should have completed the coding of the classes and the 
	main function, along with adequate documentation for you and your graders.
	You should now turn into testing your program against the sample data 
	that Professor Youssef provided to you on the course Web site, and do
	the necessary debugging and corrections. 
	
	Remember, your program must read two input files, called literally 
	messagesfile and queriesfile. These two files are assumed to be in the
	same folder (or directory) as your C++ program. Remember also that your
	program output goes to the standard output, using cout.
	
	Good luck!
	Your TAs
	##########
		
	
	
Statement of the Problem:  
=========================

This assignment involves modeling a very simple email system as C++ classes. All the email messages are addressed to you. Each email message has several data field: (1) a from-field (who it is from), (2) a date field, (3) a subject field, and (4) a body field (the text of the message). Given as input a group of email messages (each having all the fields just indicated), listed from the oldest message to the most recent, your program should be able to respond to queries of the following kinds:

+ Sort (arrange) and display the received messages from the most recent to the least recent

+ Delete the most recent message

+ Display all the (non-deleted) messages from a given sender, arranged the most recent to the least recent

+ Display a given message

The precise formatting of the input, the queries, and the answers of your program is detailed below.

The Input:  

Your program will take two input files from the command prompt, the first file containing information about the email messages, and the second file containing the queries that your program should answer. 

The first input file, called the messagesfile.txt, which contains the messages, will be such that each message has one "paragraph" of several lines, and each message is separated from the next with a line consisting of ##########, that is, 10 consecutive occurrences of #. The format of the paragraph of a message is: 

FROM:  a string of at most 50 characters representing the email address of the sender. It has no blanks.
DATE: a data, formatted as MM-DD-YYYY 
SUBJECT: a line of at most 60 characters
BODY: a string (one or more lines starting at the next line below). It can have of any number of characters, such that no line begins with ########## 

Note that for the date, MM is a 2-digit number representing the number of the month; for example, MM=01 for January, MM=03 for March, and MM=11 for November. DD is a 2-digit number representing the day of the month (between 01 and 31). YYYY is a 4-digit number representing the year.
 
Note that you are guaranteed that each message in messagesfile.txt is more recent (has later date) than all the messages before it in that file.
 
The second input file, called the queriefile.txt, will have a sequence of queries, one query per line, where each query is any of the following:
LIST-MESSAGES-BY-DATE
LIST-MESSAGES-FROM email-address-string
DELETE-MOST-RECENT-MESSAGE
DISPLAY k

Note that each of those queries could repeat multiple times in the queries file. 

Here is an explanation of each kind of query.

+ The first kind of query asks you to list all the undeleted messages, arranged from the most recent to the least recent message.

+ The 2nd kind of query asks you to list all the undeleted messages from the sender whose email address is the specified email-address-string.  The messages must be arranged from the most recent to the least recent message.

+ The 3rd kind of query asks you to delete the most recent message.

+ The 4th kind of query asks you to show (output) the body of the kth most recent message in the remaining list of undeleted messages.

The output:

Your program must take as input the two input files above, in that order. That is, we should be able to compile your program into an executable file (called Program1, say), then call it from the command-line like this: 

>> Program1 messagesfile.txt queriesfile.txt 

Your program must then write the output to the standard output (using cout). The output of the first two kinds of query should begin by repeating the same query on a new line, followed by a colon (:), followed on the next line by a sequence of lines, one line per message; each line will have the email address of the sender, then the subject of the message, and finally the date of the message (using the same date format as explained above). Put ## between each field and the next in each line. (see the sample input and output for illustration)

The output of the 3rd kind of query has two line, where the first is "DELETE-MOST-RECENT-MESSAGE:" and the second line is "DELETED MESSAGE" or "THERE ARE NO MESSAGES TO DELETE". 

The output of the 4th kind of query should begin on a new line with

MESSAGE k:

followed on the next line with the body of the kth message, in exactly the same as it was given in the messages input file, but without the ##########.

If there is no output for one of the first, second, and fourth kinds of query, you output the word NONE.

Finally, the output of each query must be followed by ########## on a new line, and then by a blank line, except for the last query’s output, which must be followed by ########## on a new line, but not followed by a blank line.
