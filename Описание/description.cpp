#include <iostream>
#include <math.h>
#include <windows.h>
#include <string>
#define N 30;

using namespace std;

class Building
{
protected:
    float width, height;
public:
    void show_size()
    {
        cout << "Building size: " << width << "x" << height << endl;
    };
    void resize_building(float neww, float newh);
    Building(): width(10), height(10) { }
    Building(float a, float b): width(a), height(b) { }
};

void Building::resize_building(float neww, float newh)
{
    width = neww;
    height = newh;
}

class House:public Building
{
    private:
        int number_of_floors;
        string HouseName = "empty";
    public:
        int living_rooms;
        void show_number_floors()
        {
            cout << "Number of floors: " << number_of_floors << endl;
        }
        void Change_name(string name1);
        void Parameters_building(void);
        House(): number_of_floors(1), living_rooms(2) { }
        House(int num1, int num2): number_of_floors(num1), living_rooms(num2) { }
};

void House::Change_name(string name1)
{
    strcpy(HouseName, name1);
}

void House::Parameters_building(void)
{
    double area = width * height;
    float rooms_per_floor = living_rooms / number_of_floors;
    cout << "Building """ << HouseName << "" << endl;
    show_size();
    cout << "Area = " << area << " m2" << endl;
    show_number_floors();
    cout << "Living rooms: " << living_rooms << endl;
    cout << "Rooms per floor = " << rooms_per_floor << endl << endl;
}

int main()
{
    /*
    Building
        show_size - показать размер
        resize_building(ширина, высота) - поменять размер здания
    House : Building
        Change_name - поменять имя
        Parameters_building - показать параметры здания
        Show_number_floors - количество этажей
    */
    setlocale(LC_CTYPE, "rus");
    int i;

    House name1(10, 40);
    House name2(10, 160);
    name1.resize_building(100.3, 500.1);
    name2.Change_name("test name");

    name1.Parameters_building();
    name2.Parameters_building();
    system("pause");
    return 0;
}

