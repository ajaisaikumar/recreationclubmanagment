#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;

fstream f2, f3;
const auto SCREEN_WIDTH = 150;
int total_mem=40,rest_fac=10;

class member
{
private:
    string name;
    string age;
    string phno;
    string total;
    string memid;
    string date_time;
    string facilities1 = "f1", facilities2 = "f2", facilities3 = "f3", facilities4 = "f4";

public:
    void createmember()
    {
        int ch, ch2;
        cout << "enter your fullname:";
        cin >> name;
        cout << endl
             << "enter your phno:";
        cin >> phno;
        while(phno.size()!=10)
        {
            cout<<endl<<"enter correct phone number:";
            cin>>phno;
        }

        cout << endl
             << "enter your age:";
        cin >> age;
        srand(time(0));
        int f;
        f = rand();
        memid = to_string(f);
        cout <<endl<< "your member id is:" << memid << endl;
        time_t now = time(0);

       date_time = ctime(&now);

   cout << "The current date and time is: " << date_time << endl;
        total = memid + "," + name + "," + age + "," + phno + "," + facilities1 + "," + facilities2 + "," + facilities3 + "," + facilities4 + "," + date_time;
    }
    string get_totstr()
    {
        return total;
    }
    void showmember()
    {
        cout << setw(20) << name << setw(20) << endl;
    }
    string getphno()
    {
        return phno;
    }
    string getname()
    {
        return name;
    }
    string get_memid()
    {
        return memid;
    }
};
member m1;

int count()
{
    int cnt = 0;

    f2.open("newdata.csv", ios::in);
    string str1;
    istringstream stream;
    while (getline(f2, str1))
    {

        cnt++;
    }

    f2.close();
    return cnt;
}

void savemember()
{
    cout<<"slots left:"<<total_mem-count()<<endl;
    if(count()<41)
    {
        m1.createmember();

    string str, str1, str2;
    f2.open("newdata.csv", ios::out | ios::app | ios::in);
    f2 << m1.get_totstr();
    f2.close();}
    else
    {
        cout<<"all slots are booked"<<endl;
    }
    
    
}

void showall()
{

    cout << "RECORDS:" << endl;
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
    cout << endl;

    f2.open("newdata.csv", ios::in | ios::out);
    string str1;
    istringstream stream;
    while (getline(f2, str1))
    {
        stream.str(str1);

        string str2{};

        while (getline(stream, str2, ','))
        {
            cout << str2 << "\t";
            if (str2 == "f4" || str2 == "badmiton" || str2 == "\n")
            {

                break;
            }
        }
        cout << endl;
    }
    f2.close();

    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
}
int count_facility(string str)
{
    fstream ft;
    int cnt = 0;
    string temp;
    ft.open("newdata.csv", ios::out | ios::in);
    while (getline(ft, temp, ','))
    {
        if (temp == str)
        {
            cnt++;
        }
    }
    ft.close();
    return cnt;
}
void booking_facility()
{
    string number;
    string facilities;
    cout << "enter your member id:";
    cin >> number;
    int ch2;
    int x;
    string replaces;

    cout << "select the facilty" << endl
         << "1.gym" << endl
         << "2.golf" << endl
         << "3.tennis" << endl
         << "4.badmiton" << endl
         << "enter any other number to exit" << endl;
    cin >> ch2;
    cout << endl;
    

    switch (ch2)
    {
    case 1:
    {

        facilities = "gym";
        replaces = "f1";
        x = 4;

        break;
    }
    case 2:
    {

        facilities = "golf";
        replaces = "f2";
        x = 6;

        break;
    }
    case 3:
    {
        facilities = "tennis";
        replaces = "f3";
        x = 8;

        break;
    }
    case 4:
    {

        facilities = "badmiton";
        replaces = "f4";
        x = 10;

        break;
    }
    default:
        cout << "enter a valid option" << endl;
    }

    if(count_facility(facilities)<=10)
    {fstream ft, f2;

    string temp;

    ft.open("temp2.csv", ios::app | ios::in | ios::out);
    f2.open("newdata.csv", ios::in | ios::out);

    while (getline(f2, temp))
    {
        if (temp.substr(0, temp.find_first_of(",")) == number)
        {

            if (temp.find(replaces) != string::npos)
            {
                temp.replace(temp.find(replaces), replaces.length(), facilities);
                
            }
        }

        ft << temp << endl;
    }

    ft.close();
    f2.close();
    remove("newdata.csv");
    rename("temp2.csv", "newdata.csv");
    }
    else
    {
        cout<<"slots for "<<facilities<<" are all booked"<<endl;
    }

    
}
void search_particulars()
{
    string number;
    cout << "enter your member id:";
    cin >> number;
    f2.open("newdata.csv", ios::in);
    string str1;
    istringstream stream;
    while (getline(f2, str1))
    {
        stream.str(str1);

        string str2{};
        if (str1.substr(0, str1.find_first_of(",")) == number)
        {

            while (getline(stream, str2, ','))
            {
                cout << str2 << "\t";
            }
            cout << endl;
        }
    }
    f2.close();

    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
}




int check_number(string str)
{
    f2.open("newdata.csv", ios::in | ios::out);
    string temp;
    int found = 0;
    istringstream stream;
    while (getline(f2, temp))
    {
        if (temp.substr(0, temp.find_first_of(",")) == str)
        {
            found = 1;
            break;
        }
    }
    return found;
    f2.close();
}
void deletes()
{
    string number;
    cout << "enter the member id:";
    cin >> number;
    cout << endl;

    fstream ft;
    int found_number = 0;
    ft.open("temp2.csv", ios::app | ios::in | ios::out);
    f2.open("newdata.csv", ios::in | ios::out);
    string temp;
    istringstream stream;
    while (getline(f2, temp))
    {
        if (temp.substr(0, temp.find_first_of(",")) == number)
        {
            found_number = 1;
        }
        else
        {
            temp = temp + "\n";
            ft << temp;
        }
    }

    f2.close();
    ft.close();
    remove("newdata.csv");
    rename("temp2.csv", "newdata.csv");

    if (found_number == 0)
    {
        cout << "enter correct number" << endl;
    }
    else
    {
       

        

        cout << "deleted" << endl;
    }
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
}

void managementactivities()
{
    int i;
    cout << "1.display all records" << endl
         << "2.search for particular record" << endl
         << "3.delete member" << endl
         << "4.number of slots free" << endl
         << "5.go back to main menu" << endl;
    cin >> i;
    cout << endl;
    switch (i)
    {
    case 1:
    {
        showall();
        break;
    }
    case 2:
    {

        cout << endl;
        search_particulars();
        break;
    }
    case 3:
    {
        deletes();
        break;
    }
    case 4:
    {
        int x = count();
        int x1= count_facility("gym");
        int x2 = count_facility("golf");
        int x3 = count_facility("badmiton");
        int x4 = count_facility("tennis");
        cout<<"total:"<<count()<<endl;
        cout<<"gym:"<<count_facility("gym")<<endl;
        cout<<"golf:"<<count_facility("golf")<<endl;
        cout<<"badmiton:"<<count_facility("badmiton")<<endl;
        cout<<"tennis:"<<count_facility("tennis")<<endl;

        break;
    }
    case 5:
    {
        exit(0);
        break;
    }
    default:
    {
        cout << "invalid option" << endl;
    }
    }
}

void users()
{
    int i;
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
    cout << "select option" << endl
         << "1.book facility" << endl
         << "2.new registration" << endl
         << "3.display my booking details" << endl
         << "4.exit" << endl;
    cin >> i;
    cout << endl;
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
    switch (i)
    {
    case 1:
    {
  
            booking_facility();
       
    
        break;
    }
    case 2:
    {
        cout << "RULES:" << endl
             << "A MEMBER CAN REGISTER IN ANY ONE CLUB ONLY BUT CAN REGISTER IN MULTIPLE FACILITIES" << endl
             << "THANK YOU" << endl;
        cout << endl;
        savemember();
        break;
    }
    case 3:
    {
        search_particulars();

        break;
    }
    case 4:
    {
        exit(0);
        break;
    }
    default:
        cout << "enter a valid option" << endl;
    }
}

int main()
{
    int i;
     f2.open("newdata.csv", ios::out | ios::app | ios::in);
    f2.close();
   

    do
    {
        cout << "SELECT MODE" << endl
             << "1.Member" << endl
             << "2.Club management" << endl;
        cin >> i;
        cout << endl;
        cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
             << endl;
        if (i == 1)
        {
            users();
        }
        if (i == 2)
        {
            managementactivities();
        }
    } while (i < 3 && i > 0);
}
