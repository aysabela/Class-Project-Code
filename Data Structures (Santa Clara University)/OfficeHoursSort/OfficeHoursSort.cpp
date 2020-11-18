#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

struct Student {
public:
    Student();

    string name;
    string subject;
    bool beenInLine;
    double wait_time;
    double time_spent_prof;
    double arrival_time;
    int priority;

};

Student::Student() {
    
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char letter = letters[rand() % 26];
    name = "Student";
    name = name + letter;

    //name = "Student " + to_string(rand() % 100 + 1);
    string subjects[10] = { "Heaps","Queues","Stacks","B-Trees","MAPs","Priority Queues","Trees","Binary Trees","In-place Sort","Divide-and-Conquer Sort" };
    subject = subjects[rand() % 10];
    priority = rand() % 9 + 1;
    time_spent_prof = rand() % 19 + 1;
    double wait_time = 0.0;
    double time_spent_prof = 0.0;
    double arrival_time = 0.0;
    beenInLine = false;

}

void queuesClear(queue<Student>& studentsFinished, priority_queue<Student>& students) {
    while (!students.empty()) students.pop();
    while (!studentsFinished.empty()) studentsFinished.pop();
}

//void displayResult(double total_avg_wait, double avg_time_help, double time_after_officehrs_total) {
//
//    total_avg_wait = total_avg_wait / 100;
//    avg_time_help = avg_time_help / 100;
//    time_after_officehrs_total = time_after_officehrs_total / 100;
//
//    cout << "Average time student waits during office hours: " << total_avg_wait << " min" << endl;
//    cout << "Average time student spends with the professor during office hours: " << avg_time_help << " min" << endl;
//    cout << "Average time Professor spends beyond office hours: " << time_after_officehrs_total << " min" << endl;
//
//}

double timePastHour(double last) {
    double time_after_officehrs;

    (last < 60.0) ? time_after_officehrs = 0 : time_after_officehrs = (last - 60.0);

    return time_after_officehrs;
}

bool operator<(const Student& student1, const Student& student2) {

    return (student1.priority < student2.priority) ? true : false;

}

bool studentArrived() {

    return (rand() % 10 + 1 <= 1) ? true : false;

}

void officeHrsSort(string fileName, string SNameOrQTopic, string sortDirection) {

    ifstream infile;
    ofstream outfile;
    string temp1 = "";
    infile.open(fileName);
    outfile.open("HW07_Output4.txt");

    multimap<string, string> fileInput;
    pair<multimap<string, string>::iterator, multimap<string, string>::iterator> tempMap;

    while (!infile.eof()) {
        getline(infile, temp1);
        fileInput.insert(pair<string, string>(temp1.substr(0, temp1.find(':')), temp1.substr(temp1.find(':') + 1)));
    }

    if (SNameOrQTopic == "studentName" && sortDirection == "A") {
        for (multimap<string, string>::const_iterator it = fileInput.begin(); it != fileInput.end(); it++) {

            string temp2 = it->first;
            outfile << it->first << " ";
            tempMap = fileInput.equal_range(it->first);
            outfile << it->second << endl;

        }
    }
    else if (SNameOrQTopic == "studentName" && sortDirection == "D") {
        multimap<string, string>::reverse_iterator it1;
        for (it1 = fileInput.rbegin(); it1 != fileInput.rend(); ++it1) {

            string temp2 = it1->first;
            outfile << it1->first << " ";
            tempMap = fileInput.equal_range(it1->first);
            outfile << it1->second << endl;


        }
    }
    else if (SNameOrQTopic == "questionTopic" && sortDirection == "A") {

        multimap<string, string> reverse;

        for (multimap<string, string>::const_iterator it = fileInput.begin(); it != fileInput.end(); it++) {
            reverse.insert(make_pair(it->second, it->first));

        }

        for (multimap<string, string>::const_iterator it = reverse.begin(); it != reverse.end(); it++) {
            outfile << it->second << " " << it->first << endl;

        }
    }
    else if (SNameOrQTopic == "questionTopic" && sortDirection == "D") {
        
        multimap<string, string> reverse;
        for (multimap<string, string>::const_iterator it = fileInput.begin(); it != fileInput.end(); it++) {
            reverse.insert(make_pair(it->second, it->first));

        }

        multimap<string, string>::reverse_iterator it1;
        for (it1 = reverse.rbegin(); it1 != reverse.rend(); it1++) {
            outfile << it1->first << " " << it1->second << endl;

        }
    }
  

    infile.close();
    outfile.close();

}



int main() {

   // ofstream outfile;
    srand(time(NULL));
    multimap <string, string> studentSubject;
    priority_queue<Student> students;
    queue<Student> studentsFinished;
    string fileName, SNameOrQTopic, sortDirection;

    double avg_time_help = 0, time_after_officehrs_total = 0;
    int num_students = 0;
    int total_avg_wait = 0;


    for (int i = 0; i < 100; i++) {

        //outfile.open("output.txt");
        queuesClear(studentsFinished, students);

        for (int j = 0; j < 60; j++) {

            if (studentArrived()) {
                Student nextStudent1;
                nextStudent1.arrival_time = j;
                students.push(nextStudent1);
                studentSubject.insert(pair<string, string>(nextStudent1.name, nextStudent1.subject));
            }

        }

        Student nextStudent1 = students.top();
        int j = nextStudent1.arrival_time;
        num_students = 0;

        double total_help_time = 60.0;
        double time_after_officehrs = 0, total_wait_time = 0;


        while (!students.empty()) {
            nextStudent1 = students.top();
            students.pop();

            if (j - nextStudent1.arrival_time < 0) {
                j = nextStudent1.arrival_time;
                nextStudent1.wait_time = 0;

            }
            else {
                nextStudent1.wait_time = j - nextStudent1.arrival_time;

            }

            j += nextStudent1.time_spent_prof;
            studentsFinished.push(nextStudent1);


            total_help_time += nextStudent1.time_spent_prof;
            total_wait_time += nextStudent1.wait_time;
            num_students++;


        }

        /*pair<multimap<string, string>::iterator, multimap<string, string>::iterator> studentSubjectEntry;

        for (multimap<string, string>::const_iterator it = studentSubject.begin(); it != studentSubject.end(); it = studentSubjectEntry.second)
        {

            string temp2 = it->first;
            outfile << "Amount of times that " << it->first << " attended office hours: " << studentSubject.count(it->first) << endl;
            outfile << it->first << ": " << endl;

            studentSubjectEntry = studentSubject.equal_range(it->first);

            for (auto k = studentSubjectEntry.first; k != studentSubjectEntry.second; ++k)
            {
                outfile << k->second << endl;
            }

        }
        outfile.close();*/

        /* double avg_wait_time = total_wait_time / num_students;
         avg_time_help += total_help_time / num_students;
         total_avg_wait += avg_wait_time;*/

        Student nextStudent2 = studentsFinished.back();
        int last = (nextStudent2.wait_time + nextStudent2.time_spent_prof + nextStudent2.arrival_time);
        time_after_officehrs_total += timePastHour(last);

    }

    cout << "Please enter the name of the fileInput fileName: ";
    cin >> fileName;
    cout << "Sort by studentName or questionTopic: ";
    cin >> SNameOrQTopic;
    cout << "Sort by ascending or descending order (please enter A or D): ";
    cin >> sortDirection; 


    officeHrsSort(fileName, SNameOrQTopic, sortDirection);
    cout << endl << "File output passed. Check files for output.";

    //displayResult(total_avg_wait, avg_time_help, time_after_officehrs_total);

    return 0;
}