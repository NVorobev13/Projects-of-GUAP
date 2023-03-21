#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<cstdlib>

#define FNAME_B "Hands_in_Hand.dat"  //��� ����� � �������� �����
#define FNAME_T "searchTown.dat"  //��� ����� � ������������ ���������� �� �������
#define FNAME_D "Delete.dat"   //��� ����� � ������������ ����� ��������

using namespace std;

const char PR_R[] = "rb";            //������� �������� ��������� ����� �� ������
const char PR_S[] = "r+b";           //������� �������� ����� �� ������ � ������

class trip {
public:
    int idDogovora;
    int birthY;
    char name[20];
    char town[20];
    char telNubmer[12];
    char placeWork[30];
    char type;
    double deposit;
    double income;
};

class account
{
    int idDogovora;
    int birthY;
    char name[20];
    char town[20];
    char telNubmer[12];
    char placeWork[30];
    char type;
    double deposit;
    double income;
public:
    void create_account();
    void show_account() const;
    void dep(double);
    void draw(double);
    void visual_table() const;
    void visual_sort_income(const char* fname) const;
    void visual_sort_town(const char* fname) const;
    void zag_vt() const;
    void zag_vsi() const;
    void zag_vst() const;
    int retidDogovora() const;
    double retdeposit() const;
    double retincome() const;
    char rettype() const;
    char rettown() const;
};

void account::create_account()
{
    int i;
    cout << endl << "\t";
    for (i = 1; i < 100; i++) {
        cout << "-";
    }
    cout << "\n\t|| ������� id ��������������� �������� (6 ����, ������ ��������� � ������� ��������) : ";
    cin >> idDogovora;
    cout << "\t|| ������� ��� �������: ";
    cin.ignore();
    cin.getline(name, 25);
    cout << "\t|| ������� ��� ��������: ";
    cin >> birthY;
    cout << "\t|| ������� ����� ����������: ";
    cin.ignore();
    cin.getline(town, 20);
    cout << "\t|| ������� ���������� ����� �������� (� ������� 89**): ";
    cin >> telNubmer;
    cout << "\t|| ������� ����� ������ (������ �������� ����������� '_'): ";
    cin >> placeWork;
    cout << "\t|| ������� ������� ����������� ����� ������� (���. ���.): ";
    cin >> income;
    cout << "\t|| ������� ��� ������� ������ (B (Bring_out) / I (Insert)): ";
    cin >> type;
    type = toupper(type);
    cout << "\t|| ������� �����, �������� �� �/� (���. ���.): ";
    cin >> deposit;
    cout << "\t";
    for (i = 1; i < 100; i++) {
        cout << "-";
    }
}

void account::show_account() const
{
    int i;
    cout << endl << "\t";
    for (i = 1; i < 55; i++) {
        cout << "-";
    }
    cout << "\n\t| ID ��������������� ��������: " << idDogovora;
    cout << "\n\t| ��� �������: " << name;
    cout << "\n\t| ��� ��������: " << birthY;
    cout << "\n\t| ����� ����������: " << town;
    cout << "\n\t| ���������� ����� ��������: " << telNubmer;
    cout << "\n\t| ����� ������: " << placeWork;
    cout << "\n\t| ������� ����������� �����: " << income;
    cout << "\n\t| ��� ������� ������ (Bring_out (B)/Insert (I)): " << type;
    cout << "\n\t| ������ ������� ������: " << deposit;
    cout << endl << "\t";
    for (i = 1; i < 55; i++) {
        cout << "-";
    }
}

void account::dep(double x)
{
    deposit += x;
}

void account::draw(double x)
{
    deposit -= x;
}

void account::visual_table() const
{
    cout << endl << "\t|";
    cout.width(13); cout << idDogovora << "|";
    cout.width(14); cout << name << "|";
    cout.width(14); cout << birthY << "|";
    cout.width(14); cout << town << "|";
    cout.width(20); cout << telNubmer << "|";
    cout.width(18); cout << placeWork << "|";
    cout.width(11); cout << income << "|";
    cout.width(8); cout << deposit << "|";
    cout.width(11); cout << type << "|";
}

void account::visual_sort_income(const char* fname) const {
    int i;
    account ship{};
    FILE* baza;
    baza = fopen(fname, PR_R);
    cout << "\n\n\n\t ���� ������ �����-���������� ����������� '���� � ����'\n\n";
    zag_vsi();
    while (fread(&ship, sizeof(ship), 1, baza) > 0) {
        cout << endl << "\t|";
        cout.width(11); cout << ship.income << "|";
        cout.width(13); cout << ship.idDogovora << "|";
        cout.width(14); cout << ship.name << "|";
        cout.width(14); cout << ship.birthY << "|";
        cout.width(14); cout << ship.town << "|";
        cout.width(20); cout << ship.telNubmer << "|";
        cout.width(18); cout << ship.placeWork << "|";
        cout.width(8); cout << ship.deposit << "|";
        cout.width(11); cout << ship.type << "|";
    }
    cout << endl << "\t";
    for (i = 1; i <= 133; i++) {
        cout << "-";
    }
    cout << "\n\n\t ���������� �� �������� ������������ ������ �������� ���������.";
    cout << "\n\n\t ��� �����������, ����������, ������� <Enter>" << endl;
    fclose(baza);
    return;
}

void account::visual_sort_town(const char* fname) const {
    int i;
    account ship;
    FILE* baza;
    baza = fopen(fname, PR_R); //��������� ���� �� ������
    cout << "\n\n\t ���� ������ �����-���������� ����������� '���� � ����'\n";
    zag_vst();
    while (fread(&ship, sizeof(ship), 1, baza) > 0) {
        cout << endl << "\t|";
        cout.width(14); cout << ship.town << "|";
        cout.width(13); cout << ship.idDogovora << "|";
        cout.width(14); cout << ship.name << "|";
        cout.width(14); cout << ship.birthY << "|";
        cout.width(20); cout << ship.telNubmer << "|";
        cout.width(18); cout << ship.placeWork << "|";
        cout.width(11); cout << ship.income << "|";
        cout.width(8); cout << ship.deposit << "|";
        cout.width(11); cout << ship.type << "|";
    }
    cout << endl << "\t";
    for (i = 1; i <= 133; i++) {
        cout << "-";
    }
    fclose(baza);
    return;
}

void account::zag_vt() const
{
    int i;
    cout << endl << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    cout << endl;

    cout << "\t| ID �������� |" << " ��� ������� |" << " ��� �������� |" << "    �����     |" << " ���������� ������� |" << "   ����� ������   |" << " ��. ����� |" << " ������ |" << " ��� ����� |" << endl;
    cout << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    return;
}

void account::zag_vsi() const
{
    int i;
    cout << endl << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    cout << endl;
    cout << "\t| ��. ����� |" << " ID �������� |" << " ��� ������� |" << " ��� �������� |" << "    �����     |" << " ���������� ������� |" << "   ����� ������   |" << " ������ |" << " ��� ����� |" << endl;
    cout << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    return;
}

void account::zag_vst() const
{
    int i;
    cout << endl << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    cout << endl;
    cout << "\t|    �����     |" << " ID �������� |" << " ��� ������� |" << " ��� �������� |" << " ���������� ������� |" << "   ����� ������   |" << " ��. ����� |" << " ������ |" << " ��� ����� |" << endl;
    cout << "\t";
    for (i = 1; i <= 133; i++)
        cout << "-";
    return;
}

int account::retidDogovora() const
{
    return idDogovora;
}

double account::retdeposit() const
{
    return deposit;
}

double account::retincome() const
{
    return income;
}

char account::rettype() const
{
    return type;
}

char account::rettown() const
{
    return town[19];
}

//���������� �������
void display_sp(const char* fname, int);                                      //������� ��� ����������� ���������� ������� ������, ��������������� �������������
void modify_account(const char* fname, int);                                     //������� ��� ��������� ������ �����
void delete_account(const char* fname_b, const char* fname_d, int);                                //������� ��� �������� ������ �����
void display_all(const char* fname);                                       //������� ��� ����������� ���� ���������� �����
void settings_bd(const char* fname1, const char* fname2);                   //������� ��������� ��   
void intro();                                             //������� �������� ������
int proverka_file(const char* fname);                                                       //������� �������� ������� ����������� �����
void write_account(const char* fname);                                       //������� ��� ������ ������ � �������� ����
void sort_income(const char* fname);                                                                  //������� ���������� �������� �� �������� ������������ ������
void sort_town(const char* fname1, const char* fname2);                                               //������� ���������� �������� �� ��������������
void operations_rko(const char* fname);                                       //������� �������� ���
void deposit_withdraw(const char* fname, int, int);                                       //������� ��� ��������/������ ����� ��� ������� �����

int main()
{
    account ac{};
    char ch, otv;
    char fname_b[25] = FNAME_B;
    char fname_t[25] = FNAME_T;
    char fname_d[20] = FNAME_D;
    setlocale(LC_ALL, "Russian");
    intro();
    do
    {
        system("cls");
        cout << "\n\n\n\t ������� ����";
        cout << "\n\n\t 01. ������� ���� ������ ���";         //+++
        cout << "\n\n\t 02. ������� ������ ��������";         //+++
        cout << "\n\n\t 03. ���������� �� �������� ������������ ������ ��������";  //+++
        cout << "\n\n\t 04. ���������� �� �������������� ��������";      //---
        cout << "\n\n\t 05. ��������� ���������� ��������";        //+++
        cout << "\n\n\t 06. ������������� ���� ������ ���������";      //+++
        cout << "\n\n\t 07. �����";              //+++
        cout << "\n\n\t ������� ����� �������� (1-7) ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            
            if (proverka_file(fname_b)) {
                cout << "\n\t ������� ���� � ����� ������? [Y/N] ";
                while ((otv = getc(stdin)) == '\n');
                if (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�') {
                    cout << "\n\t ����� �������� ���� ������ ��� �� �����. (���������� ����� ������� ���������� .dat): ";
                    cin >> fname_b;
                }
                else {
                    cout << "\n\t ���� ������ � ����� ������ - �� �������." << endl;
                    cout << "\n\t ��� �������� � ������� ����, ����������, ������� <Enter>.";
                    break;
                }
            }
            else if (!(proverka_file(fname_b))) {
                cout << "\n\t ������ �������� ����� ��� ������." << endl;
                break;
            }

            cout << "\n\t ������� ���� " << fname_b << endl;
            cout << "\n\t �������� ������� ������� � ���� ���� ������.";
            getchar();
            write_account(fname_b);
            if (proverka_file(fname_b)) {
                cout << "\n\t ���� ������ ��� ������ � ������. ����������, ������� <Enter>" << endl;
            }
            else {
                cout << "\n\t ���� ������ - �� �������." << endl;
            }
            break;
        case '2':
            write_account(fname_b);
            break;
        case '3':
            sort_income(fname_b);
            ac.visual_sort_income(fname_b);
            break;
        case '4':
            sort_town(fname_b, fname_t);
            ac.visual_sort_town(fname_t);
            cout << "\n\n\t ���������� �� �������������� ���������.";
            cout << "\n\n\t ��� �����������, ����������, ������� <Enter>" << endl;
            break;

        case '5':
            operations_rko(fname_b);
            break;
        case '6':
            settings_bd(fname_b, fname_d);
            break;
        case '7':
            cout << "\n\n\t���������� ��� �� ������������� ������ ��. \n\n\t\t\t�� ����� ������!";
            break;
        default:cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (ch != '7');
    return 0;
}

void intro()
{
    int i;
    cout << endl << "\t";
    for (i = 1; i < 92; i++) {
        cout << "-";
    }
    cout << "\n\n\t|| \t\t\t\t\t   DATABASE \t\t\t\t\t ||";
    cout << "\n\n\t|| \t\t\t\t\t ���� � ���� \t\t\t\t\t ||";
    cout << "\n\n\t|| \t\t\t\t   ������� ���������� ���  \t\t\t\t ||";
    cout << "\n\n\t|| \t\t\t\t\t\t\t\t\t\t\t ||";
    cout << "\n\n\t|| ��������: ������� ������� ������ Z1411  \t\t\t\t\t\t ||";
    cout << "\n\n\t|| ������-�������������� ���������������� ������������ ���������������� ���������������� ||";
    cout << "\n\n\t|| \t\t\t\t\t\t\t\t\t   �������� �.�. ||";
    cout << endl << "\t";
    for (i = 1; i < 92; i++) {
        cout << "-";
    }
    cout << "\n\n\t *��� ������������� ������������ ����� - ������� <Enter>.";
    cin.get();
}

//������� ��� ������ ������ � �������� ����
void write_account(const char* fname_b)
{
    char otv;
    account ac{};
    ofstream outFile;
    outFile.open(fname_b, ios::binary | ios::app);
    cout << "\n\t �������� ������ ������� � ���� ���: " << fname_b;
    do {
        ac.create_account();
        outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
        cout << "\n\t �ר���� ������ �������.\n";
        cout << "\n\n\t ������� ���? [Y/N]: ";
        while ((otv = getc(stdin)) == '\n');
    } while (otv == 'Y' || otv == 'y' || otv == '�' || otv == '�');
    cout << "\n\n\t ��� �����������, ����������, ������� <Enter>" << endl;
    outFile.close();
}

//������� ��� ���������� �� ����������� �������� ������������ ������ 
void sort_income(const char* fname)
{
    int i;
    int fl;
    account ppp, ship;
    FILE* baza;
    baza = fopen(fname, PR_S); //��������� ���� �� ������ � ������
    do {
        rewind(baza);
        fl = 0;
        for (i = 0; fread(&ship, sizeof(ship), 1, baza) > 0; i += sizeof(ship), fseek(baza, i, SEEK_SET)) {
            if (fread(&ppp, sizeof(ship), 1, baza) > 0) {
                if (ship.retincome() > ppp.retincome()) {
                    fseek(baza, i, SEEK_SET); //������� i �� ������ �����
                    fwrite(&ppp, sizeof(ship), 1, baza);
                    fwrite(&ship, sizeof(ship), 1, baza);
                    fl = 1;
                }
            }
        }
    } while (fl);
    fclose(baza);
    return;
}

//������� ��� ���������� �� ��������������
void sort_town(const char* fname1, const char* fname2) {
    char searchTown[20];
    trip ship{};
    ifstream inFile;
    ofstream outFile;
    inFile.open(fname1, ios::binary);
    if (!inFile)
    {
        cout << "\n\t ������ �������� ����� ��� ������ � ������! Press any Key...";
        return;
    }
    outFile.open(fname2, ios::binary);
    cout << "\n\t ������� �������� ������: : ";
    cin >> searchTown;
    while (inFile.read(reinterpret_cast<char*> (&ship), sizeof(trip))) {
        if (strncmp(ship.town, searchTown, 20) == 0) {
            outFile.write(reinterpret_cast<char*> (&ship), sizeof(trip));
        }
    }
    inFile.close();
    outFile.close();
    return;
}

//������� ��� ������������� ���������-�������� ��������
void operations_rko(const char* fname_b)
{
    int num;
    char ch;
    do {
        system("cls");
        cout << "\n\n\n\t ��������� ���������� �������� ";
        cout << "\n\n\t 01. ��������� ������� �ר�.";
        cout << "\n\n\t 02. ����� � �������� �ר��.";
        cout << "\n\n\t 03. ������� ������ �� �����.";
        cout << "\n\n\t 04. ��������� � ������� ����.";
        cout << "\n\n\n\t ������� ����� �������� (1-4): ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            cout << "\n\t ������� ID ������ ��������: ";
            cin >> num;
            deposit_withdraw(fname_b, num, 1);
            break;
        case '2':
            cout << "\n\t ������� ID ������ ��������: ";
            cin >> num;
            deposit_withdraw(fname_b, num, 2);
            break;
        case '3':
            cout << "\n\t ������� ID ������ ��������: ";
            cin >> num;
            display_sp(fname_b, num);
            break;
        case '4':
            cout << "\n\n\t ��� �����������, ����������, ������� <Enter> 3 ����." << endl;
            break;
        }
        cin.ignore();
        cin.get();
    } while (ch != '4');
    return;
}

//������� ���������� / �������� �������� ������� � �������� �����
void deposit_withdraw(const char* fname, int num, int option)
{
    double amt;
    bool found = false;
    account ac{};
    fstream File;
    File.open(fname, ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\n\t ������ �������� ����� ��� ������ � ������! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (&ac), sizeof(account));
        if (ac.retidDogovora() == num)
        {
            ac.show_account();
            if (option == 1)
            {
                cout << "\n\n\t\t ���������� �������� �ר�� �������� ";
                cout << "\n\n\t ������� �����, �� ������� ������ ���������� ����������: ";
                cin >> amt;
                ac.dep(amt);
                cout << "\n\t\t �ר���� ������ �������� ���������.";
            }
            if (option == 2)
            {
                cout << "\n\n\t\t ����� ������� � �������� �ר�� �������� ";
                cout << "\n\n\t ������� �����, �� ������� ������ ���������� ����� �������: ";
                cin >> amt;
                double bal = ac.retdeposit() - amt;
                if ((bal < 5 && ac.rettype() == 'B') || (bal < 25 && ac.rettype() == 'I')) {
                    cout << "\n\t *��� ������ �������� ������������ �������� �������.\n\t **����������, ��������� � ������������ ������� � ���������� ��� ���!";
                }
                else {
                    ac.draw(amt);
                    cout << "\n\t\t �ר���� ������ �������� ���������.";
                }
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*> (&ac), sizeof(account));

            cout << "\n\n\t ��� ����������� - ������� <Enter>.";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\t ������ ������ �����. �������� ���� ���������! ";
}

//������� ��� ����������� ���������� ������� ������, ��������������� �������������
void display_sp(const char* fname_b, int n)
{
    account ac{};
    bool flag = false;
    ifstream inFile;
    inFile.open(fname_b, ios::binary);
    if (!inFile)
    {
        cout << "\n\t ������ �������� ����� ��� ������! Press any Key...";
        return;
    }
    cout << "\n\t �������� � ������� ���������\n";

    while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
    {
        if (ac.retidDogovora() == n)
        {
            ac.show_account();
            flag = true;
            cout << "\n\t ��� ����������� - ������� <Enter>.";
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\t ������ id �������� - �� ����������.";
}

//������� ��� ��������� ���� ������
void settings_bd(const char* fname1, const char* fname2)
{
    char ch;
    int num;

    do {
        system("cls");
        cout << "\n\n\n\t �������������� ���� ������ ���������";
        cout << "\n\n\t 01. ������� ������ ���� ���������.";
        cout << "\n\n\t 02. �������� �ר���� ������ ��������.";
        cout << "\n\n\t 03. �������� �ר���� ������ ��������.";
        cout << "\n\n\t 04. ������� �ר���� ������ ��������.";
        cout << "\n\n\t 05. ��������� � ����." << endl;
        cout << "\n\t ������� ����� �������� (1-5): ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            display_all(fname1);
            break;
        case '2':
            cout << "\n\t ��������� ������ � ���� " << fname1 << endl;
            write_account(fname1);
            cout << "\n\n\t **���� ���� ������ ������� ��������.";
            break;
        case '3':
            cout << "\n\t ������� id �������� : "; cin >> num;
            modify_account(fname1, num);
            break;
        case '4':
            cout << "\n\t ������� id �������� : "; cin >> num;
            delete_account(fname1, fname2, num);
            break;
        case '5':
            cout << "\n\t ��� ����������� - ������� <Enter> 3 ����." << endl;
            break;
        }
        cin.ignore();
        cin.get();
    } while (ch != '5');
    return;
}

//������� ��� ����������� ���� ���������� �����
void display_all(const char* fname)
{
    int i;
    account ac{};
    ifstream inFile;
    inFile.open(fname, ios::binary);
    if (!inFile)
    {
        cout << " ������ �������� ����� ��� ������! Press any Key...";
        return;
    }
    cout << "\n\n\t\t ���� ������ ���������: " << fname << "\n";
    ac.zag_vt();
    while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
    {
        ac.visual_table();
    }
    cout << endl << "\t";
    for (i = 1; i <= 133; i++) {
        cout << "-";
    }
    cout << "\n\n\t *��� ����������� - ������� <Enter>." << endl;
    inFile.close();
}

//������� ��� ��������� ������ �����
void modify_account(const char* fname, int n)
{
    bool found = false;
    account ac;
    fstream File;
    File.open(fname, ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\n\t ������ �������� ����� ��� ������! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char*> (&ac), sizeof(account));
        if (ac.retidDogovora() == n)
        {
            ac.show_account();
            cout << "\n\n\t ������� ���������� ������ ������� ������" << endl;
            ac.create_account();
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*> (&ac), sizeof(account));
            cout << "\n\n\t ������� ������ - ���������.";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\t ������� ������ �� �������. ";
}

//������� �������� ����������� ����� 
void delete_account(const char* fname1, const char* fname2, int n)
{
    account ac{};
    ifstream inFile;
    ofstream outFile;
    inFile.open(fname1, ios::binary);
    if (!inFile)
    {
        cout << "\n\t ������ �������� ����� ��� ������ � ������! Press any Key...";
        return;
    }
    outFile.open(fname2, ios::binary);
    inFile.seekg(0, ios::beg);

    while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
    {
        if (ac.retidDogovora() != n)
        {
            outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove(fname1);
    rename(fname2, fname1);
    cout << "\n\t �ר���� ������ �� �������� " << n << " - �������. \n";
    display_all(fname1);
}

//������� �������� ������� ����������� �����
int proverka_file(const char* fname) {
    fstream File;
    File.open(fname, ios::binary | ios::in | ios::out);
    if (!File) {
        return 0;
    }
    return 1;
}