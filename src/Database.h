//
// Created by SCTMIC012 on 2018-02-26.
//

#ifndef ASSIGNMENT_1_DATABASE_H
#define ASSIGNMENT_1_DATABASE_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

namespace SCTMIC012
{
    class Database
    {

    private:
        //Database entries
        struct StudentRecord
        {
            string name;
            string surname;
            string student_number;
            string class_record;
        };

        vector <StudentRecord> students;

        //Helper method used to get average of grade results
        string calculateGradeAverage(string class_record);
        //Determines if student is present in the DB, replaces their data if they are
        bool isExistingStudent(StudentRecord new_student);

    public:
        string saveDatabaseToTextfile(string filename);
        string saveTextfileToDatabase(string filename);
        void readDatabase();

        void addStudent(string name, string surname, string student_number, string class_record);
        string displayStudent(string student_number);
        string gradeStudent(string student_number);
        ;
    };
}

#endif //ASSIGNMENT_1_DATABASE_H
