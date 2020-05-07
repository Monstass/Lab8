/* Анекдот:

- Вы не боитесь умереть от коронавируса?
- У меня кредит, откачают. */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Класс "человек"
class Person
{
private:
    // Имя
    string st_name;   
    // Фамилия
    string nd_name;
    // Возраст
    int age;

public:
    // Конструктор по умолчанию
    Person()
    {
        age = 0;
    }                                          
    // Конструктор, перегрузка
    Person(string stName, string ndName, int Age)
    {
        st_name = stName;
        nd_name = ndName;
        age = Age;
    }

    // Прототипы
    void show_info_basic();
    void input_basic_info();
};

// Вывод информации о человеке
void Person::show_info_basic()                                   
{
    cout << "Firstname: " << st_name << endl;
    cout << "Second name: " << nd_name << endl;
    cout << "Age: " << age << endl;
}
//  Ввод информации о человеке
void Person::input_basic_info()
{
    cout << "Enter 1st name: ";
    cin >> st_name;
    cout << "Enter 2nd name: ";
    cin >> nd_name;
    while (1)
    {
        cout << "Enter age: ";
        cin >> age;
        if (age > 0)
        {
            break;
        }
    }
}
// Дочерний класс "рабочий"
class Employer:public Person
{
private:
    // Профессия
    string profession;
    // Оплата за час работы
    float payment;
    // Количество отработанных часов за месяц
    float hours;
    // Итоговая зарплата
    float salary;

public:
    // Конструктор по умолчанию
    Employer()
    {
        profession = "";
        payment = 0;
        hours = 0;
        salary = 0;
    }
    // Конструктор, перегрузка
    Employer(string prfsn, float pmnt, float hrs)
    {
        profession = prfsn;
        payment = pmnt;
        hours = hrs;
        salary = pmnt * hrs;
    }
    // Прототипы
    void salary_count();
    void show_emplo_info();
    void input_emplo_info();
};

// Метод нахождения зарплаты
void Employer::salary_count()
{
    salary = hours * payment;
}
// Метод вывода информации о работнике
void Employer::show_emplo_info()
{
    // Вызов метода из родительского класса
    show_info_basic();
    cout << "Profession: " << profession << endl;
    cout << "Hours for month: " << hours << endl;
    cout << "Salary: " << salary << endl << endl;
}

void Employer::input_emplo_info()
{
    // Вызов метода из родительского класса
    input_basic_info();
    cout << "Enter profession: ";
    cin >> profession;
    cout << "Enter hours for month: ";
    cin >> hours;
    cout << "Enter payment for hour: ";
    cin >> payment;

    salary_count();
}
// Дочерний класс "начальник"
class Master:public Employer
{
private:
    // Количество найденных нарушений
    int warnings_detected;

public:
    // Конструктор по умолчанию
    Master()
    {
        warnings_detected = 0;
    }
    // Конструктор, перегрузка
    Master(int warnings)
    {
        warnings_detected = warnings;
    }
    // Прототипы
    void show_master_info();
    void input_master_info();
};
// Метод вывода информации о начальнике
void Master::show_master_info()
{
    // Вызов метода из родительского класса
    show_emplo_info();
    cout << "Warnings detcted: " << warnings_detected << endl;
}
// Метод ввода информации о начальнике
void Master::input_master_info()
{
    // Вызов метода из родительского класса
    input_emplo_info();
    cout << "Enter number of warnings: ";
    cin >> warnings_detected;
}
// Класс "прибыль"
class Profit
{
private:
    /* stonks - прибыль 
     not_stonks - убытки 
     stonks_sum - чистая прибыль */
    float stonks, not_stonks, stonks_sum;

public:
    // Конструктор по умолчанию
    Profit()
    {
        stonks = 0;
        not_stonks = 0;
        stonks_sum = 0;
    }
    // Конструктор, перегрузка
    Profit (float stnks, float ntstnks)
    {
        stonks = stnks;
        not_stonks = ntstnks;
        stonks_sum = stonks - not_stonks;
    }
    // Прототипы
    void show_profit();
    void input_profit();
};
// Метод ввода информации
void Profit::input_profit()
{
    cout << "Input profit: ";
    cin >> stonks;
    cout << "Input costs: ";
    cin >> not_stonks;
    stonks_sum = stonks - not_stonks;
}
// Метод вывода информации
void Profit::show_profit()
{
    cout << "Profit: " << stonks_sum << endl << endl;
}

int main()
{
    // Экземпляр класса "человек"
    Person E1;
    // Экземпляр класса "рабочий"
    Employer E2;

    E1.input_basic_info();
    E2.input_emplo_info();
    // Экземпляр класса "начальник"
    Master M1;
    M1.input_master_info();
    // Экземпляр класса "прибыль"
    Profit May;
    May.input_profit();
  
    system("cls");
    
    cout << "--Information: customer---" << endl;
    E1.show_info_basic();
    cout << endl;
    cout << "---Information: employer---" << endl;
    E2.show_emplo_info();
    cout << endl;
    cout << "---Information: manager---" << endl;
    M1.show_master_info();
    cout << endl;
    cout << "---Infromation: profit---" << endl;
    May.show_profit();

    return 0;
}