#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
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

    name = "Student " + to_string(rand() % 100 + 1);
    string subjects[10] = {"Heaps","Queues","Stacks","B-Trees","MAPs","Priority Queues","Trees","Binary Trees","In-place Sort","Divide-and-Conquer Sort"};
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

int main() {

    ofstream outfile;
    srand(time(NULL));
    multimap <string, string> studentSubject;
    priority_queue<Student> students;
    queue<Student> studentsFinished;

    double avg_time_help = 0, time_after_officehrs_total = 0;
    int num_students = 0;
    int total_avg_wait = 0;


    for (int i = 0; i < 100; i++) {

        outfile.open("output.txt");
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

        pair<multimap<string, string>::iterator, multimap<string, string>::iterator> studentSubjectEntry;

        for (multimap<string, string>::const_iterator it = studentSubject.begin(); it != studentSubject.end(); it = studentSubjectEntry.second)
        {

            string st = it->first;
            outfile << "Amount of times that " << it->first << " attended office hours: " << studentSubject.count(it->first) << endl;
            outfile << it->first << ": " << endl;

            studentSubjectEntry = studentSubject.equal_range(it->first);

            for (auto k = studentSubjectEntry.first; k != studentSubjectEntry.second; ++k)
            {
                outfile << k->second << endl;
            }

        }
        outfile.close();

       /* double avg_wait_time = total_wait_time / num_students;
        avg_time_help += total_help_time / num_students;
        total_avg_wait += avg_wait_time;*/

        Student nextStudent2 = studentsFinished.back();
        int last = (nextStudent2.wait_time + nextStudent2.time_spent_prof + nextStudent2.arrival_time);
        time_after_officehrs_total += timePastHour(last);


    }

    //displayResult(total_avg_wait, avg_time_help, time_after_officehrs_total);

    return 0;
}
