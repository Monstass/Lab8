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
    }                                          
    /* Constructor, overload */
    Person(string stName, string ndName, int Age)
    {
        st_name = stName;
        nd_name = ndName;
        age = Age;
    }

    void show_info_basic();
    void input_basic_info();
};

/* Show info*/
void Person::show_info_basic()                                   
{
    cout << "Firstname: " << st_name << endl;
    cout << "Second name: " << nd_name << endl;
    cout << "Age: " << age << endl;
}
/*  Input info */
void Person::input_basic_info()
{
    cout << "Enter 1st name of worker: ";
    cin >> st_name;
    cout << "Enter 2nd name of woker: ";
    cin >> nd_name;
    while (1)
    {
        cout << "Enter age of worker: ";
        cin >> age;
        if (age > 0)
        {
            break;
        }
    }
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
        profession = "";
        payment = 0;
        hours = 0;
        salary = 0;
    }
    /* Constructor overload */
    Employer(string prfsn, float pmnt, float hrs)
    {
        profession = prfsn;
        payment = pmnt;
        hours = hrs;
        salary = pmnt * hrs;
    }

    void salary_count();
    void show_emplo_info();
    void input_emplo_info();
};

/* Method for finding salary */
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

void Employer::input_emplo_info()
{
    input_basic_info();
    cout << "Enter profession: ";
    cin >> profession;
    cout << "Enter hours for month: ";
    cin >> hours;
    cout << "Enter payment for hour: ";
    cin >> payment;

    salary_count();
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
    /* Constructor overload */
    Master(int warnings)
    {
        warnings_detected = warnings;
    }

    void show_master_info();
    void input_master_info();
};

void Master::show_master_info()
{
    show_emplo_info();
    cout << "Warnings detcted: " << warnings_detected << endl;
}

void Master::input_master_info()
{
    input_emplo_info();
    cout << "Enter number of warnings: ";
    cin >> warnings_detected;
}

class Profit
{
private:
    float stonks, not_stonks, stonks_sum;

public:
    /* Constructor def */
    Profit()
    {
        stonks = 0;
        not_stonks = 0;
        stonks_sum = 0;
    }
    /* Constructor overload */
    Profit (float stnks, float ntstnks)
    {
        stonks = stnks;
        not_stonks = ntstnks;
        stonks_sum = stonks - not_stonks;
    }

    void show_profit();
    void input_profit();
};

void Profit::input_profit()
{
    cout << "Input profit: ";
    cin >> stonks;
    cout << "Input costs: ";
    cin >> not_stonks;
    stonks_sum = stonks - not_stonks;
}

void Profit::show_profit()
{
    cout << "Profit: " << stonks_sum << endl << endl;
}

int main()
{
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
    Employer E1;
    Employer E2;

    E1.input_emplo_info();
    E2.input_emplo_info();

    Master M1;
    M1.input_master_info();
    
    Profit May;
    May.input_profit();
 
    system("cls");

    E1.show_emplo_info();
    cout << endl;
    E2.show_emplo_info();
    cout << endl;
    M1.show_master_info();
    cout << endl;
    May.show_profit();

    return 0;
}