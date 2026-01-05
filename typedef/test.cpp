#include <iostream>
using namespace std;
typedef enum days {monday, tuesday, wednesday, thursday, friday, saturday, sunday} days;
inline days operator++ (days &d)
{
    return d = static_cast<days>((static_cast<int>(d) + 1+7)%7);
}
inline days operator-- (days &d)
{
    return d = static_cast<days>((static_cast<int>(d) - 1+7)%7);
}
ostream& operator<< (ostream &os, days d)
{
    switch (d)
    {
    case monday:
        os << "Monday";
        break;
    case tuesday:
        os << "Tuesday";
        break;
    case wednesday:
        os << "Wednesday";
        break;
    case thursday:
        os << "Thursday";
        break;
    case friday:
        os << "Friday";
        break;
    case saturday:
        os << "Saturday";
        break;
    case sunday:
        os << "Sunday";
        break;
    default:
        break;
    }
    return os;
}
int main() 
{
    days d = monday;
    for (int i = 0; i < 6; i++)
    {
        cout << d << endl;
        ++d;
    }
    for (int i = 0; i < 7; i++)
    {
        cout << d << endl;
        --d;
    }
    return 0;
}