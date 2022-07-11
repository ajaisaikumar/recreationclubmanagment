#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

fstream f1, f2, f3, f4;

class rec_club
{
private:
    int clubno;
    char mem_name[50], facilities[50];
    long long int phno;
    int memid;

public:
    void rec_club1(char arr[], long long int phn, int clbno, char facility[], int memno)
    {
        phno = phn;
        clubno = clbno;
        strcpy(mem_name, arr);
        strcpy(facilities, facility);
        memid = memno;
    }
    void showmem()
    {
        cout << mem_name << "          " << phno << "          " << facilities << "          " << memid << endl;
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
    char clubname[50], facilities[50];
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
        cout << "select the facilty" << endl
             << "1.gym" << endl
             << "2.golf" << endl
             << "3.tennis" << endl
             << "4.badmiton" << endl;
        cin >> ch2;
        switch (ch2)
        {
        case 1:
        {
            strcpy(facilities, "gym");
            break;
        }
        case 2:
        {
            strcpy(facilities, "golf");
            break;
        }
        case 3:
        {
            strcpy(facilities, "tennis");
            break;
        }
        case 4:
        {
            strcpy(facilities, "badmiton");
            break;
        }
        default:
            cout << "enter a valid option" << endl;
        }
    }
    void showmember()
    {
        cout << name << "          " << memid << "          " << clubname << "          " << facilities << endl;
    }
    long long int getphno()
    {
        return phno;
    }
    char *getname()
    {
        return name;
    }
    char *getfacility()
    {
        return facilities;
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
    c1.rec_club1(m1.getname(), m1.getphno(), m1.getclubno(), m1.getfacility(), m1.get_memid());
    f1.open("newdata.txt", ios::out | ios::app);
    if (m1.getclubno() == 1)
    {
        f2.open("graciusclub.txt", ios::out | ios::app);
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
}
void showall(int n)
{

    cout << "RECORDS" << endl;
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
}
void display_record(int memno)
{
    bool found = false;
    f1.open("newdata.txt", ios::in);
    while (f1.read((char *)&m1, sizeof(m1)))
    {
        if (m1.get_memid() == memno)
        {
            system("cls");
            m1.showmember();
            found = true;
        }
    }
    f1.close();
    if (found == false)
    {
        cout << "member phone number not found." << endl;
    }
}
int gettingclubno(int number)
{
    f1.open("newdata.txt", ios::in | ios::out);
    while (f1.read((char *)&m1, sizeof(m1)))
    {
        if (m1.get_memid() == number)
        {
            return m1.getclubno();
        }
    }
}
void deletes()
{
    int number;
    cout << "enter the member id:";
    cin >> number;
    f1.open("newdata.txt", ios::in | ios::out);
    f3.open("uchihaclub.txt", ios::in | ios::out);
    f4.open("xebecclub.txt", ios::in | ios::out);
    fstream fp, ft;
    fp.open("temp.txt", ios::out);
    ft.open("temp2.txt", ios::out);

    while (f1.read((char *)&m1, sizeof(m1)))
    {
        if (m1.get_memid() != number)
        {
            fp.write((char *)&m1, sizeof(m1));
        }
    }
    if (gettingclubno(number) == 1)
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
        remove("graciasclub.txt");
        rename("temp2.txt", "graciasclub.txt");
    }
    if (gettingclubno(number) == 2)
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
        remove("uchihaclub.txt");
        rename("temp2.txt", "uchihaclub.txt");
    }
    if (gettingclubno(number) == 3)
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
        remove("xebecclub.txt");
        rename("temp2.txt", "xebecclub.txt");
    }
    fp.close();
    f1.close();
    ft.close();
    remove("newdata.txt");
    rename("temp.txt", "newdata.txt");
}
void managementactivities(int a)
{
    int i;
    cout << "1.display all records" << endl
         << "2.search for particular record" << endl
         << "3.delete member" << endl
         << "4.go to main menu" << endl;
    cin >> i;
    switch (i)
    {
    case 1:
    {
        showall(a);
        break;
    }
    case 2:
    {
        int number;
        cout << "enter the member id:";
        cin >> number;
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
        system("cls");
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
    switch (i)
    {
    case 1:
    {
        int pwd;
        int pwd1 = 1001;
        cout << "GRACIAS CLUB" << endl;
        cout << "enter management id:";
        cin >> pwd;
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
        system("cls");
    }
    default:
    {
        cout << "invalid club option" << endl;
        club();
    }
    }
}
void users()
{
    int i;
    cout << "select option" << endl
         << "1.my club" << endl
         << "2.new registration" << endl
         << "3.exit" << endl;
    cin >> i;
    switch (i)
    {
    case 1:
    {
        int memid;
        cout << "enter your member id:";
        cin >> memid;
        display_record(memid);
        break;
    }
    case 2:
    {
        savemember();
        break;
    }
    case 3:
        system("cls");
        break;
    default:
        cout << "enter a valid option" << endl;
    }
}

int main()
{
    int i;

    do
    {
        cout << "select MODE" << endl
             << "1.member" << endl
             << "2.club management" << endl;
        cin >> i;
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