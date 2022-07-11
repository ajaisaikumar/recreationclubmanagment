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
    long int phno;

public:
    void rec_club1(char arr[], long int phn, int clbno, char facility[])
    {
        phno = phn;
        clubno = clbno;
        strcpy(mem_name, arr);
        strcpy(facilities, facility);
    }
    void showmem()
    {
        cout << mem_name << "          " << phno << "          " << facilities << endl;
    }
    long int getphn_no()
    {
        return phno;
    }
};

class member
{
private:
    char name[50];
    long int phno;
    int age;
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
        cout << "select the facilty"
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
        cout << name << "          " << phno << "          " << clubname << "          " << facilities << endl;
    }
    long int getphno()
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
};
member m1;
rec_club c1;
void savemember()
{
    m1.createmember();
    c1.rec_club1(m1.getname(), m1.getphno(), m1.getclubno(), m1.getfacility());
    f1.open("newdata.dat", ios::out | ios::app);
    if (m1.getclubno() == 1)
    {
        f2.open("graciusclub.dat", ios::out | ios::app);
        f1.write((char *)&m1, sizeof(m1));
        f2.write((char *)&c1, sizeof(c1));
        f2.close();
    }
    if (m1.getclubno() == 2)
    {
        f3.open("uchihaclub.dat", ios::out | ios::app);
        f1.write((char *)&m1, sizeof(m1));
        f3.write((char *)&c1, sizeof(c1));
        f3.close();
    }
    if (m1.getclubno() == 3)
    {
        f4.open("xebecclub.dat", ios::out | ios::app);
        f1.write((char *)&m1, sizeof(m1));
        f4.write((char *)&c1, sizeof(c1));
        f4.close();
    }
    f1.close();
}
void showall(int n)
{
    system("cls");
    cout << "RECORDS" << endl;
    if (n == 1)
    {
        f2.open("graciasclub.dat", ios::in);
        while (f2.read((char *)&c1, sizeof(c1)))
        {
            c1.showmem();
            getchar();
        }
        f2.close();
    }
    if (n == 2)
    {
        f3.open("uchihaclub.dat", ios::in);
        while (f3.read((char *)&c1, sizeof(c1)))
        {
            c1.showmem();
            getchar();
        }
        f3.close();
    }
    if (n == 3)
    {
        f4.open("xebecclub.dat", ios::in);
        while (f4.read((char *)&c1, sizeof(c1)))
        {
            c1.showmem();
            getchar();
        }
        f4.close();
    }
}
void display_record(long int phnno)
{
    bool found = false;
    f1.open("newdata.dat", ios::in);
    while (f1.read((char *)&m1, sizeof(m1)))
    {
        if (m1.getphno() == phnno)
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
int gettingclubno(long int number)
{
    f1.open("newdata.dat", ios::in | ios::out);
    while (f1.read((char *)&m1, sizeof(m1)))
    {
        if (m1.getphno() == number)
        {
            return m1.getclubno();
        }
    }
}
void deletes()
{
    long int number;
    cout << "enter the phone number:";
    cin >> number;
    f1.open("newdata.dat", ios::in | ios::out);
    f3.open("uchihaclub.dat", ios::in | ios::out);
    f4.open("xebecclub.dat", ios::in | ios::out);
    fstream fp, ft;
    fp.open("temp.dat", ios::out);
    ft.open("temp2.dat", ios::out);

    while (f1.read((char *)&m1, sizeof(m1)))
    {
        if (m1.getphno() != number)
        {
            fp.write((char *)&m1, sizeof(m1));
        }
    }
    if (gettingclubno(number) == 1)
    {
        f2.open("graciasclub.dat", ios::in | ios::out);
        while (f2.read((char *)&c1, sizeof(c1)))
        {
            if (c1.getphn_no() != number)
            {
                ft.write((char *)&c1, sizeof(c1));
            }
        }
        f2.close();
        remove("graciasclub.dat");
        rename("temp2.dat", "graciasclub.dat");
    }
    if (gettingclubno(number) == 2)
    {
        f3.open("uchihaclub.dat", ios::in | ios::out);
        while (f3.read((char *)&c1, sizeof(c1)))
        {
            if (c1.getphn_no() != number)
            {
                ft.write((char *)&c1, sizeof(c1));
            }
        }
        f3.close();
        remove("xebecclub.dat");
        rename("temp2.dat", "uchihaclub.dat");
    }
    if (gettingclubno(number) == 3)
    {
        f4.open("uchihaclub.dat", ios::in | ios::out);
        while (f4.read((char *)&c1, sizeof(c1)))
        {
            if (c1.getphn_no() != number)
            {
                ft.write((char *)&c1, sizeof(c1));
            }
        }
        f4.close();
        remove("xebecclub.dat");
        rename("temp2.dat", "xebecclub.dat");
    }
    fp.close();
    f1.close();
    ft.close();
    remove("newdata.dat");
    rename("temp.dat", "newdata.dat");
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
        long int number;
        cout << "enter the phone number:";
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
        long int phno;
        cout << "enter your phone number:";
        cin >> phno;
        display_record(phno);
        break;
    }
    case 2:
    {
        savemember();
    }
    case 3:
        system("cls");
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