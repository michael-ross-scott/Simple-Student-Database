# Simple-Student-Database

Simple database that stores student information in a vector. 

Student data can be queried and received via the command line.

The database interface has the following features:
  1.  add student
  2.  read database
  3.  save database
  4.  display given student data
  5.  grade student

# Files

Database.h	:

	-> Header file for the Database. 
	-> Declares the studentRecord structure and its corresponding vector students <StudentRecord>
	   (used to store data in 'DB')
	-> Declares methods to be used in Database.cpp

Database.cpp	:

	-> Implements methods that populate the vector <students>

main.cpp	:

	-> Facilitates user interaction
	-> Uses the Database class and its methods to fulfill user requests

makefile rules	:

	-> make:
		
		* Builds all classes for execution

	-> make clean	:

		* Removes object and executable files
		
Execution rules	:

	-> ./main to run
	
NOTE						:

	-> example.txt is a textfile already made that can be saved as a database
	-> When creating other files to be saved as databases each value needs to be seperated
		 by a space
