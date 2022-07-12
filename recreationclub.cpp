#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

fstream f1, f2, f3, f4;
const auto SCREEN_WIDTH = 150;

class rec_club
{
private:
    int clubno;
    char mem_name[50], facilities1[50] = "-", facilities2[50] = "-", facilities3[50] = "-", facilities4[50] = "-";
    long long int phno;
    int memid;

public:
    void rec_club1(char arr[], long long int phn, int clbno, char facility1[], char facility2[], char facility3[], char facility4[], int memno)
    {
        phno = phn;
        clubno = clbno;
        strcpy(mem_name, arr);
        strcpy(facilities1, facility1);
        strcpy(facilities2, facility2);
        strcpy(facilities3, facility3);
        strcpy(facilities4, facility4);
        memid = memno;
    }
    void showmem()
    {

        cout << setw(20) << mem_name << setw(20) << phno << setw(20) << facilities1 << setw(20) << facilities2 << setw(20)
             << facilities3 << setw(20) << facilities4 << setw(20) << memid << endl;
    }
    long long int getphn_no()
    {
        return phno;
    }
    int get_memid()
    {
        return memid;
    }
};

class member
{
private:
    char name[50];
    long long int phno;
    int age, memid;
    char clubname[50], facilities1[50] = "-", facilities2[50] = "-", facilities3[50] = "-", facilities4[50] = "-";
    int clubno;

public:
    void createmember()
    {
        int ch, ch2;
        cout << "enter your fullname:";
        getchar();
        cin.getline(name, 50);
        cout << endl
             << "enter your phno:";
        cin >> phno;
        cout << endl
             << "enter your member id:";
        cin >> memid;
        cout << endl
             << "enter your age:";
        cin >> age;
        cout << endl
             << "1.gracias club" << endl
             << "2.uchiha club" << endl
             << "3.xebec club\n";
        cout << "enter the choice\n ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
        {
            strcpy(clubname, "gracias club");
            clubno = 1;
            break;
        }
        case 2:
        {
            strcpy(clubname, "uchiha club");
            clubno = 2;
            break;
        }
        case 3:
        {
            strcpy(clubname, "xebec club");
            clubno = 3;
            break;
        }
        default:
            cout << "enter a valid option" << endl;
        }
        do
        {

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

                strcpy(facilities1, "gym");

                break;
            }
            case 2:
            {

                strcpy(facilities2, "golf");

                break;
            }
            case 3:
            {
                strcpy(facilities3, "tennis");

                break;
            }
            case 4:
            {

                strcpy(facilities4, "badmiton");

                break;
            }
            default:
                cout << "enter a valid option" << endl;
            }
        } while (ch2 > 0 && ch2 < 5);
    }
    void showmember()
    {
        cout << setw(20) << name << setw(20) << memid << setw(20)
             << clubname << setw(20) << facilities1 << setw(20)
             << facilities2 << setw(20) << facilities3 << setw(20)
             << facilities4 << endl;
    }
    long long int getphno()
    {
        return phno;
    }
    char *getname()
    {
        return name;
    }
    char *getfacility1()
    {
        return facilities1;
    }
    char *getfacility2()
    {
        return facilities2;
    }
    char *getfacility3()
    {
        return facilities3;
    }
    char *getfacility4()
    {
        return facilities4;
    }
    int getclubno()
    {
        return clubno;
    }
    int get_memid()
    {
        return memid;
    }
};
member m1;
rec_club c1;
void savemember()
{
    m1.createmember();
    c1.rec_club1(m1.getname(), m1.getphno(), m1.getclubno(), m1.getfacility1(), m1.getfacility2(), m1.getfacility3(), m1.getfacility4(), m1.get_memid());
    f1.open("newdata.txt", ios::out | ios::app);
    if (m1.getclubno() == 1)
    {
        f2.open("graciasclub.txt", ios::out | ios::app);
        f1.write((char *)&m1, sizeof(m1));
        f2.write((char *)&c1, sizeof(c1));
        f2.close();
    }
    if (m1.getclubno() == 2)
    {
        f3.open("uchihaclub.txt", ios::out | ios::app);
        f1.write((char *)&m1, sizeof(m1));
        f3.write((char *)&c1, sizeof(c1));
        f3.close();
    }
    if (m1.getclubno() == 3)
    {
        f4.open("xebecclub.txt", ios::out | ios::app);
        f1.write((char *)&m1, sizeof(m1));
        f4.write((char *)&c1, sizeof(c1));
        f4.close();
    }
    f1.close();
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
}
void showall(int n)
{

    cout << "RECORDS:" << endl;
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
    cout << endl;
    if (n == 1)
    {
        f2.open("graciasclub.txt", ios::in);
        while (f2.read((char *)&c1, sizeof(c1)))
        {
            c1.showmem();
        }
        f2.close();
    }
    if (n == 2)
    {
        f3.open("uchihaclub.txt", ios::in);
        while (f3.read((char *)&c1, sizeof(c1)))
        {
            c1.showmem();
        }
        f3.close();
    }
    if (n == 3)
    {
        f4.open("xebecclub.txt", ios::in);
        while (f4.read((char *)&c1, sizeof(c1)))
        {
            c1.showmem();
        }
        f4.close();
    }
    cout << endl
         << endl;
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
    cout << endl
         << endl;
}
void display_record(long long int phnno)
{
    bool found = false;
    
    f1.open("newdata.txt", ios::in);
    while (f1.read((char *)&m1, sizeof(m1)))
    {
        if (m1.getphno() == phnno)
        {
            
            m1.showmember();
            found = true;
        }
    }
    f1.close();
    if (found == false)
    {
        cout << "member phone number not found." << endl;
    }
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
}
int gettingclubno(long long int number)
{
    f1.open("newdata.txt", ios::in | ios::out);
    int a;
    while (f1.read((char *)&m1, sizeof(m1)))
    {
        if (m1.getphno() == number)
        {
            
            a=m1.getclubno();
        }
    }
    f1.close();
    return a;

    
}
void deletes()
{
    long long int number;
    cout << "enter the phone number:";
    cin >> number;
    cout << endl;
    int clubnumber;
    clubnumber = gettingclubno(number);
    fstream ff, ft;
    f1.open("newdata.txt", ios::in | ios::out);
    ff.open("temp1.txt", ios::out);
    ft.open("temp2.txt", ios::out);

    while (f1.read((char *)&m1, sizeof(m1)))
        {
            if (m1.getphno() != number)
            {
                ff.write((char *)&m1, sizeof(m1));
            }
        }
  
    if (clubnumber == 1)
    {
        f2.open("graciasclub.txt", ios::in | ios::out);
        while (f2.read((char *)&c1, sizeof(c1)))
        {
            if (c1.getphn_no() != number)
            {
                ft.write((char *)&c1, sizeof(c1));
            }
        }
        f2.close();
        ft.close();
        remove("graciasclub.txt");
        rename("temp2.txt", "graciasclub.txt");
    }
    if (clubnumber == 2)
    {
        f3.open("uchihaclub.txt", ios::in | ios::out);
        while (f3.read((char *)&c1, sizeof(c1)))
        {
            if (c1.getphn_no() != number)
            {
                ft.write((char *)&c1, sizeof(c1));
            }
        }
        f3.close();
        ft.close();
        remove("uchihaclub.txt");
        rename("temp2.txt", "uchihaclub.txt");
    }
    if (clubnumber == 3)
    {
        f4.open("xebecclub.txt", ios::in | ios::out);
        while (f4.read((char *)&c1, sizeof(c1)))
        {
            if (c1.getphn_no() != number)
            {
                ft.write((char *)&c1, sizeof(c1));
            }
        }
        f4.close();
        ft.close();
        remove("xebecclub.txt");
        rename("temp2.txt", "xebecclub.txt");
    }
    ff.close();
    f1.close();
    remove("newdata.txt");
    rename("temp1.txt", "newdata.txt");
    cout << "deleted" << endl;
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
}
void managementactivities(int a)
{
    int i;
    cout << "1.display all records" << endl
         << "2.search for particular record" << endl
         << "3.delete member" << endl
         << "4.go to main menu" << endl;
    cin >> i;
    cout << endl;
    switch (i)
    {
    case 1:
    {
        showall(a);
        break;
    }
    case 2:
    {
        long long int number;
        cout << "enter the phone number:";
        cin >> number;
        cout << endl;
        display_record(number);
        break;
    }
    case 3:
    {
        deletes();
        break;
    }
    case 4:
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
void club()
{
    int i;
    cout << "select your club" << endl
         << "1.gracias club" << endl
         << "2.uchiha club" << endl
         << "3.xebec club" << endl
         << "4.exit" << endl;
    cin >> i;
    cout << endl;
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
    switch (i)
    {
    case 1:
    {
        int pwd;
        int pwd1 = 1001;
        cout << "GRACIAS CLUB" << endl;
        cout << "enter management id:";
        cin >> pwd;
        cout << endl;
        if (pwd == pwd1)
        {
            managementactivities(1);
        }
        else
        {
            cout << "invalid management id" << endl;
        }
        break;
    }
    case 2:
    {
        int pwd;
        int pwd1 = 1002;
        cout << "UCHIHA CLUB" << endl;
        cout << "enter management id:";
        cin >> pwd;
        cout << endl;
        if (pwd == pwd1)
        {
            managementactivities(2);
        }
        else
        {
            cout << "invalid management id" << endl;
        }
        break;
    }
    case 3:
    {
        int pwd;
        int pwd1 = 1003;
        cout << "XEBEC CLUB" << endl;
        cout << "enter management id:";
        cin >> pwd;
        cout << endl;
        if (pwd == pwd1)
        {
            managementactivities(3);
        }
        else
        {
            cout << "invalid management id" << endl;
        }
        break;
    }
    case 4:
    {
        exit(0);
    }
    default:
    {
        cout << "invalid club option" << endl;
        club();
    }
    }
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
}
void users()
{
    int i;
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
    cout << "select option" << endl
         << "1.my club" << endl
         << "2.new registration" << endl
         << "3.exit" << endl;
    cin >> i;
    cout << endl;
    cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
         << endl;
    switch (i)
    {
    case 1:
    {
        long long int phno;
        cout << "enter your phone number:";
        cin >> phno;
        cout << endl;
        cout << setfill('*') << setw(SCREEN_WIDTH + 1) << " " << setfill(' ')
             << endl;
        display_record(phno);
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
            club();
        }
    } while (i < 3 && i > 0);
}
