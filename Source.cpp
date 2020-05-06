#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Person
{
private:
    string st_name;                                        
    string nd_name;
    int age;

public:
    /* Constructor def */
    Person()
    {
        age = 0;
    };                                           
    /* Constructor, overload */
    Person(string stName, string ndName, int Age)          
    {
        st_name = stName;
        nd_name = ndName;
        age = Age;
    }
    void set_basic_info(string , string , int );
    void show_info_basic();
};
/* Show info*/
void Person::show_info_basic()                                   
{
    cout << "Firstname: " << st_name << endl;
    cout << "Second name: " << nd_name << endl;
    cout << "Age: " << age << endl;
}
/* Setter */
void Person::set_basic_info(string stName, string ndName, int Age)      
{
    st_name = stName;
    nd_name = ndName;
    age = Age;
}

class Employer:public Person
{
private:
    string profession;
    /* per hour */
    float payment;
    /* Hours for month */
    float hours;
    /* for month */
    float salary;

public:
    /* Constructor def */
    Employer()
    {
        payment = 0;
        hours = 0;
        salary = 0;
    }
    /* Setter */
    void set_emplo_info(string prof, float hrs, float slr)
    {
        profession = prof;
        hours = hrs;
        payment = slr;
        salary_count();
    }

    void salary_count();
    void show_emplo_info();
};

void Employer::salary_count()
{
    salary = hours * payment;
}

void Employer::show_emplo_info()
{
    show_info_basic();
    cout << "Profession: " << profession << endl;
    cout << "Hours for month: " << hours << endl;
    cout << "Salary: " << salary << endl << endl;
}

class Master:public Employer
{
private:
    int warnings_detected;

public:
    /* Constructor def */
    Master()
    {
        warnings_detected = 0;
    }
    /* Setter */
    void set_warnings(int wrngs)
    {
        warnings_detected = wrngs;
    }

    void show_master_info();
};

void Master::show_master_info()
{
    show_emplo_info();
    cout << "Warnings detcted: " << warnings_detected << endl;
}

void input_info(Employer);

int main()
{
    Employer Alexey;
    Alexey.set_basic_info("Olesya", "Tyan", 52);
    input_info(Alexey);
    Alexey.show_emplo_info();

   /* Employer Alexey;
    Alexey.set_basic_info("Alexey", "Petrov", 43);
    Alexey.set_emplo_info("Confectioner", 20, 500);
    Alexey.show_emplo_info();

    Employer Dimas;
    Dimas.set_basic_info("Dima", "Boganoff", 20);
    Dimas.set_emplo_info("Courier", 15, 200);
    Dimas.show_emplo_info();

    Master Julia;
    Julia.set_basic_info("Julia", "Petrova", 40);
    Julia.set_emplo_info("Manager", 22, 499);*/
    return 0;
}

/* Function for input */
void input_info(Employer Name)
{
    string name_1, name_2, prof;
    int age;
    float payment, hours;
    
    cout << "Enter 1st name of worker: ";
    cin >> name_1;
    cout << "Enter 2nd name of woker: ";
    cin >> name_2;
    while (1)
    {
        cout << "Enter age of worker: ";
        cin >> age;
        if (age > 0)
        {
            break;
        }
    }
    cout << "Enter profession: ";
    cin >> prof;
    cout << "Enter hours for month: ";
    cin >> hours;
    cout << "Enter payment for hour: ";
    cin >> payment;
    /* Calling methods */
    Name.set_basic_info("Dima", name_2, age);
    Name.set_emplo_info(prof, hours, payment);
}