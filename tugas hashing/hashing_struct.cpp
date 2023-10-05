#include <iostream>
#include <string>
using namespace std;

const int SIZE_ARR = 26;

// Hash Table
struct HashTable
{
    string username, password;
} dataAkun[SIZE_ARR];

// Hash Function
int hashFunction(string password)
{
    int hash = 0;

    for (char c : password)
    {
        hash += static_cast<int>(c);
    }

    return hash % SIZE_ARR;
}

//print
void printAll()
{
    for (int i = 0; i < SIZE_ARR; i++)
    {
        cout << i << " [ " << dataAkun[i].username << " - " << dataAkun[i].password << " ]" << endl;
    }
}

//buat register
void registerUser()
{
    string username, password;

    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    int index = hashFunction(password);

    if (dataAkun[index].username.empty() && dataAkun[index].password.empty())
    {
        dataAkun[index].username = username;
        dataAkun[index].password = password;
        cout << "Registrasi berhasil." << endl;
    }
    else
    {
        cout << "Anda telah membuat akun sebelumnya. COba lagi" << endl;
    }
}

// Login function
bool loginUser()
{
    string username, password;

    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    int index = hashFunction(password);

    if (dataAkun[index].username == username && dataAkun[index].password == password)
    {
        cout << "Login berhasil" << endl;
        return true;
    }
    else
    {
        cout << "Login gagal. Coba lagi ya." << endl;
        return false;
    }
}

void menu()
{
    while (true)
    {
        int input_user;

        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl
             << endl;

        cout << "Pilih: ";
        cin >> input_user;
        cout << endl;

        switch (input_user)
        {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser())
            {
                // Implement the logic for logged-in user here
                cout << "Menu Login" << endl;
            }
            break;
        case 3:
            printAll();
            return;
        default:
            cout << "Invalid!" << endl;
            break;
        }
    }
}

int main()
{
    menu();
    return 0;
}
