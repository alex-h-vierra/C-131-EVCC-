#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Courses
{
    int credits = 0;
    string professor;
    string nameOfClass;
    string classID;
    string TeacherID;

};
struct ContactInfo
{
    string number;
    string email;
    string EmergencyNumber;
};
struct StudentsInfo
{
    string sid;
    double balance = 0.0;
    string firstName;
    string lastName;
    char middle_Initial;
    ContactInfo contact;
    vector<Courses> classInfo;
};

StudentsInfo* getStudentInfo();
Courses *getTeacherClassInfo();


int main()
{

    bool ok = false;
    StudentsInfo *ptr_arr[1];
    Courses *ptr1_arr[1];

    string Std_or_Teacher;
    cout << setw(38) << setfill('_') << " " << endl;
    cout << "| Type Teacher if you are a Teacher |" << endl;
    cout << setfill(' ') << setw(20) << "or" << endl;
    cout << "| Type Student if you are a Student |" << endl;
    cout << setw(38) << setfill('_') << " " << endl;
    cin >> Std_or_Teacher;
    do
    {
        if (Std_or_Teacher == "Teacher")
        {
            ptr1_arr[0] = getTeacherClassInfo();
        }
        else if (Std_or_Teacher == "Student")
        {
            ptr_arr[0] = getStudentInfo();
        }
        else
        {
            ok = true;
            cout << "Please Type Student or Teacher to continue" << endl;
            cin >> Std_or_Teacher;
        }
    }
    while (ok);

    cout <<
}

StudentsInfo* getStudentInfo()
{
    StudentsInfo *s = new StudentsInfo();
    bool ok = false;
    do
    {
        cout << "Please Enter Your SID: " << endl;
        cin >> s->sid;
        if(s->sid.size() < 9 || s->sid.size() > 9)
        {
            ok = false;
        }
        else
        {
            ok = true;
        }
    }
    while (!ok);

    cout << "Please enter your fist name: " << endl;
    cin >> s->firstName;
    cout << "Please enter your last name: " << endl;
    cin >> s->lastName;
    cout << "Please enter your middle initial: " << endl;
    cin >> s->middle_Initial;
    cout << "Please enter your home Phone Number: " << endl;
    cin >> s->contact.number;
    cout << "Please enter your Emergency Number: " << endl;
    cin >> s->contact.EmergencyNumber;
    cout << "Pleas enter your Email Address: " << endl;
    cin >> s->contact.email;
    return s;
}
Courses *getTeacherClassInfo()
{
    Courses*c =new Courses();
    bool ok = false;
    do
    {
        cout << "Please Enter Your Teachers ID " << endl;
        cin >> c->TeacherID;
        if(c->TeacherID.size() < 9 || c->TeacherID.size() > 9)
        {
            ok = false;
        }
        else
        {
            ok = true;
        }
    }
    while (!ok);

    cout << "what is your Professor name" << endl;
    cin >> c->professor;
    cout << "what is the amount of credit that your class is" << endl;
    cin >> c->credits;
    cout << "What is the name of the class" << endl;
    cin >> c->nameOfClass;
    cout << "What is your Class ID" << endl;
    cin >> c->classID;

}
