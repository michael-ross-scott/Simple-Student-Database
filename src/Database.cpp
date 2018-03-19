//
// Created by SCTMIC012 on 2018-02-26.
//

#include <iostream>
#include "Database.h"
using namespace SCTMIC012;
using namespace std;

// Adds student to database
void Database::addStudent(string student_number, string name, string surname, string class_record)
{
    StudentRecord new_student;

    new_student.name = name;
    new_student.surname = surname;
    new_student.student_number = student_number;
    new_student.class_record = class_record;

    if(!isExistingStudent(new_student))
    {
        students.push_back(new_student);
    }
}

// Prints Database
void Database::readDatabase(){
    for (auto student : students)
    {
        cout << student.student_number + " " +
                student.name + " " +
                student.surname + " " +
                student.class_record
             << endl;
    }
}

// Prints student information
string Database::displayStudent(string student_number)
{
    for (auto student : students)
    {
        if(student.student_number == student_number)
        {
            return  student.student_number + ": " +
                    student.name + " " +
                    student.surname + " " +
                    student.class_record;
        }
    }

    return "There are no students in the database with that record.";
}

// Determines if student already exists, if they do overwrite them
bool Database::isExistingStudent(StudentRecord new_student){
    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].student_number == new_student.student_number)
        {
            students[i] = new_student;
            return true;
        }
    }
    return false;
}

// Determines final student grade from class record
string Database::gradeStudent(string student_number)
{
    for (auto student : students)
    {
        if (student.student_number == student_number)
        {
            string gradeAverage = calculateGradeAverage(student.class_record);
            return student.student_number + " GPA: " + gradeAverage;
        }
    }

    return "The student record does not exist.";
}

// Breaks up class_record into individual values and averages them
string Database::calculateGradeAverage(string class_record)
{
    stringstream indiv_records(class_record);
    int records = 0;
    int numRecords = 0;

    while(indiv_records.good())
    {
        int record;
        indiv_records >> record;

        numRecords++;
        records += record;
    }
    double avRecord = records/numRecords;
    return to_string(avRecord);
}

// Saves existing textfile as a database (with structure: student_number name surname class_record)
string Database::saveTextfileToDatabase(string filename){
    ifstream file(filename);
    string line;
    if(file.is_open())
    {
        while(getline(file,line))
        {
            StudentRecord new_student;
            stringstream indiv_records(line);
            
            indiv_records >> new_student.student_number;
            indiv_records >> new_student.name;
            indiv_records >> new_student.surname;
            getline(indiv_records,new_student.class_record);

            if(!isExistingStudent(new_student))
            {
                students.push_back(new_student);
            }
        }
        file.close();
        file.clear();
        return "Database has been successfully saved";
    }
    else
    {
        file.close();
        file.clear();
        return "Cannot detect file, please try again.";
    }
}

// Saves an existing database to textfile
string Database::saveDatabaseToTextfile(string filename)
{
    ofstream file(filename);
    if(file.is_open())
    {
       for (auto &student : students)
       {
            string line;

            string student_number = student.student_number;
            string name = student.name;
            string surname = student.surname;
            string class_record = student.class_record;

            line+= student_number + " " ;
            line+= name + " ";
            line+= surname + " ";
            line+= class_record + "\n";

            file << line;
        }
        file.close();
        file.clear();
    }
    else
    {
        return "Database could not be saved to textfile, try naming the textfile differently.";
    }

    return "textfile write successful";
}
