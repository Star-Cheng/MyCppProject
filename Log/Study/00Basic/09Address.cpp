#include <iostream>
using namespace std;
#include <string>
#define Max 1000
void showMenu()
{
    cout << "*******Menu*********" << endl;
    cout << "1. add a new contacts" << endl;
    cout << "2. show contacts" << endl;
    cout << "3. delete a contacts" << endl;
    cout << "4. search a contacts" << endl;
    cout << "5. modify a contacts" << endl;
    cout << "6. clear all contacts" << endl;
    cout << "0. exit" << endl;
    cout << "*********************" << endl;
}
struct person
{
    string name;
    int sex;
    int age;
    string phone;
    string address;
};
struct AddressBook
{
    person personArray[Max];
    int m_size = 0;
};
void addPerson(AddressBook *adp)
{
    if (adp->m_size == Max)
    {
        cout << "the address book is full" << endl;
    }
    else
    {
        person p;
        cout << "please input the name" << endl;
        cin >> p.name;
        cout << "please input the sex" << endl;
        cin >> p.sex;
        cout << "please input the age" << endl;
        cin >> p.age;
        cout << "please input the phone" << endl;
        cin >> p.phone;
        cout << "please input the address" << endl;
        cin >> p.address;
        adp->personArray[adp->m_size] = p;
        adp->m_size++;
        cout << "add a new contacts success" << endl;
    }
}
void showPerson(AddressBook *adp)
{
    if (adp->m_size == 0)
    {
        cout << "the address book is empty" << endl;
    }
    else
    {
        for (int i = 0; i < adp->m_size; i++)
        {
            cout << "\t" << adp->personArray[i].name << " "
                 << "\t" << adp->personArray[i].sex << " "
                 << "\t" << adp->personArray[i].age << " "
                 << "\t" << adp->personArray[i].phone << " "
                 << "\t" << adp->personArray[i].address << endl;
        }
    }
}
void deletePerson(AddressBook *adp)
{
    if (adp->m_size == 0)
    {
        cout << "the address book is empty" << endl;
    }
    else
    {
        cout << "please input the name you want to delete" << endl;
        string name;
        cin >> name;
        for (int i = 0; i < adp->m_size; i++)
        {
            if (adp->personArray[i].name == name)
            {
                for (int j = i; j < adp->m_size - 1; j++)
                {
                    adp->personArray[j] = adp->personArray[j + 1];
                }
                adp->m_size--;
                cout << "delete a contacts success" << endl;
                return;
            }
        }
    }
}
void searchPerson(AddressBook *adp)
{
    if (adp->m_size == 0)
    {
        cout << "the address book is empty" << endl;
    }
    else
    {
        cout << "please input the name you want to search" << endl;
        string name;
        cin >> name;
        cout << "\t" << "name" << "\t" << "sex" << "\t" << "age" << "\t" << "phone" << "\t" << "address" << endl;
        for (int i = 0; i < adp->m_size; i++)
        {
            if (adp->personArray[i].name == name)
            {

                cout << "\t" << adp->personArray[i].name << " "
                     << "\t" << adp->personArray[i].sex << " "
                     << "\t" << adp->personArray[i].age << ""
                     << "\t" << adp->personArray[i].phone << " "
                     << "\t" << adp->personArray[i].address << endl;
                //  return;
            }
        }
    }
    return;
}
void modifyPerson(AddressBook *adp)
{
    if (adp->m_size == 0)
    {
        cout << "the address book is empty" << endl;
    }
    else
    {
        cout << "please input the name you want to modify" << endl;
        string name;
        cin >> name;
        for (int i = 0; i < adp->m_size; i++)
        {
            if (adp->personArray[i].name == name)
            {
                cout << "please input the new name" << endl;
                cin >> adp->personArray[i].name;
                cout << "please input the new sex" << endl;
                cin >> adp->personArray[i].sex;
                cout << "please input the new age" << endl;
                cin >> adp->personArray[i].age;
                cout << "please input the new phone" << endl;
                cin >> adp->personArray[i].phone;
                cout << "please input the new address" << endl;
                cin >> adp->personArray[i].address;
                cout << "modify a contacts success" << endl;
                return;
            }
        }
    }
}
void clearPerson(AddressBook *adp)
{
    adp->m_size = 0;
    cout << "clear all contacts success" << endl;
}
int main()
{
    AddressBook adp;

    while (true)
    {
        showMenu();
        int select = 0;
        cin >> select;
        switch (select)
        {
        case 1:
            cout << "add a new contacts" << endl;
            addPerson(&adp);
        case 2:
            cout << "\t" << "name" << "\t" << "sex" << "\t" << "age" << "\t" << "phone" << "\t" << "address" << endl;
            showPerson(&adp);
            break;
        case 3:
            cout << "delete a contacts" << endl;
            deletePerson(&adp);
            break;
        case 4:
            cout << "search a contacts" << endl;
            searchPerson(&adp);
            break;
        case 5:
            cout << "modify a contacts" << endl;
            modifyPerson(&adp);
            break;
        case 6:
            cout << "clear all contacts" << endl;
            clearPerson(&adp);
            break;
        case 0:
            cout << "exit" << endl;
            return 0;
        }
    }
    return 0;
}