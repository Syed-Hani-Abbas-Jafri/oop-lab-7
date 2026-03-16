#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int    id;
    string addr;
    string phone;
    string email;

public:
    Person(string n, int i, string a, string p, string e)
    {
        name  = n;
        id    = i;
        addr  = a;
        phone = p;
        email = e;
    }

    virtual void displayInfo()
    {
        cout << "Name  : " << name  << endl;
        cout << "ID    : " << id    << endl;
        cout << "Addr  : " << addr  << endl;
        cout << "Phone : " << phone << endl;
        cout << "Email : " << email << endl;
    }

    void updateInfo(string a, string p, string e)
    {
        addr  = a;
        phone = p;
        email = e;
    }

    string getName() { return name; }
};


class Student : public Person {
private:
    string courses[10];
    int    courseCount;
    double gpa;
    int    enrollYear;

public:
    Student(string n, int i, string a, string p, string e,
            string c[], int count, double g, int yr)
        : Person(n, i, a, p, e)
    {
        courseCount = count;
        for (int j = 0; j < count; j++)
            courses[j] = c[j];
        gpa        = g;
        enrollYear = yr;
    }

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Enroll Year : " << enrollYear << endl;
        cout << "GPA         : " << gpa        << endl;
        cout << "Courses     : ";
        for (int j = 0; j < courseCount; j++)
            cout << courses[j] << " ";
        cout << endl;
    }
};


class Professor : public Person {
private:
    string dept;
    string courses[10];
    int    courseCount;
    double salary;

public:
    Professor(string n, int i, string a, string p, string e,
              string d, string c[], int count, double sal)
        : Person(n, i, a, p, e)
    {
        dept        = d;
        courseCount = count;
        for (int j = 0; j < count; j++)
            courses[j] = c[j];
        salary = sal;
    }

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Dept    : " << dept   << endl;
        cout << "Salary  : " << salary << endl;
        cout << "Courses : ";
        for (int j = 0; j < courseCount; j++)
            cout << courses[j] << " ";
        cout << endl;
    }
};


class Staff : public Person {
private:
    string dept;
    string position;
    double salary;

public:
    Staff(string n, int i, string a, string p, string e,
          string d, string pos, double sal)
        : Person(n, i, a, p, e)
    {
        dept     = d;
        position = pos;
        salary   = sal;
    }

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Dept     : " << dept     << endl;
        cout << "Position : " << position << endl;
        cout << "Salary   : " << salary   << endl;
    }
};


class Course {
private:
    string courseId;
    string courseName;
    int    credits;
    string instructor;
    string schedule;
    string students[50];
    int    studentCount;

public:
    Course(string id, string name, int cr, string instr, string sched)
    {
        courseId     = id;
        courseName   = name;
        credits      = cr;
        instructor   = instr;
        schedule     = sched;
        studentCount = 0;
    }

    void registerStudent(Student &s)
    {
        students[studentCount++] = s.getName();
        cout << s.getName() << " registered in " << courseName << endl;
    }

    void calculateGrades()
    {
        cout << "Grades calculated for : " << courseName << endl;
    }

    void displayCourse()
    {
        cout << "Course ID   : " << courseId   << endl;
        cout << "Course Name : " << courseName << endl;
        cout << "Credits     : " << credits    << endl;
        cout << "Instructor  : " << instructor << endl;
        cout << "Schedule    : " << schedule   << endl;
        cout << "Students    : ";
        for (int j = 0; j < studentCount; j++)
            cout << students[j] << " ";
        cout << endl;
    }
};


int main()
{
    string sCourses[] = {"OOP", "DSA"};
    Student s1("Hassan", 101, "Karachi", "123456", "hassan@email.com",
               sCourses, 2, 3.8, 2023);

    string pCourses[] = {"OOP"};
    Professor p1("Dr. Ali", 201, "Lahore", "987654", "ali@email.com",
                 "Computer Science", pCourses, 1, 120000);

    Staff st1("Ahmed", 301, "Islamabad", "555555", "ahmed@email.com",
              "Administration", "Manager", 60000);

    Course c1("CS101", "Object Oriented Programming", 3, "Dr. Ali", "Mon-Wed");

    cout << "\n/-/-/-/-/-/- student info /-/-/-/-/-/-" << endl;
    s1.displayInfo();

    cout << "\n/-/-/-/-/-/- professor info /-/-/-/-/-/-" << endl;
    p1.displayInfo();

    cout << "\n/-/-/-/-/-/- staff info /-/-/-/-/-/-" << endl;
    st1.displayInfo();

    cout << "\n/-/-/-/-/-/- course registration /-/-/-/-/-/-" << endl;
    c1.registerStudent(s1);
    c1.calculateGrades();
    c1.displayCourse();

    return 0;
}
