#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>

using namespace std;


												//***************************************************************
												//                   �����, ������������ � �������
												//****************************************************************


class account
{
	int idDogovora;
	char name[20];
	double deposit;
	char type;
	int birthY;
	char town[25];
	char telNubmer[11];
	char placeWork[30];
	double income;
	public:
		void create_account();					//������� ��� ��������� ������ �� ������������
		void show_account() const;				//������� ��� ����������� ������ �� ������
		void modify();							//������� ��� ���������� ����� ������
		void dep(int);							//������� ��� �������� ����� � ���������� � ����� �������
		void draw(int);							//������� ��� �������� ����� � ��������� �� ����� �������
		void report() const;					//������� ��� ����������� ������ � ��������� �������
		double retdeposit() const;					//������� ��� �������� ����� �������
		char rettype() const;					//������� ��� �������� ���� �����
		int retidDogovora() const;				//������� ��� �������� id ��������
		int retbirthY() const;					//������� ��� �������� ���� ��������
		double retincome() const;				//������� ��� �������� �������� ��������� 
};												

void account::create_account()
{
	cout << " ������� id ��������������� �������� (6 ����, ������ ��������� � ������� ��������) : ";
	cin >> idDogovora;
	cout << " ������� ��� ������� : ";
	cin.ignore();
	cin.getline(name, 25);
	cout << " ������� ��� �������: ";
	cin >> birthY;
	cout << " ������� ����� ����������: ";
	cin.ignore();
	cin.getline(town, 25);
	cout << " ������� ���������� ����� �������� (� ������� 89**): ";
	cin.ignore();
	cin.getline(telNubmer, 11);
	cout << " ������� ����� ������ (������������ �����������): ";
	cin.ignore();
	cin.getline(placeWork, 30);
	cout << " ������� ������� ����������� ����� ������� (���. ���.): ";
	cin >> income;
	cout << " ������� ��� ������� ������ (������ (W)/���������� (A)): "; //������� ��� ������� ������ (C/S) 
	cin >> type;
	type = toupper(type);
	cout << " ������� �����, �������� �� �/� (���. ���.): ";
	cin >> deposit;
	cout << "\n ������� ������ �������.\n" << endl;
}

void account::show_account() const
{
	cout << "\n Id ��������������� ��������: " << idDogovora;
	cout << "\n ��� �������: " << name;
	cout << "\n ��� ��������: " << birthY;
	cout << "\n ����� ����������: " << town;
	cout << "\n ���������� ����� ��������: " << telNubmer;
	cout << "\n ����� ������: " << placeWork;
	cout << "\n ������� ����������� �����: " << income;
	cout << "\n ��� ������� ������ (������ (W)/���������� (A)): " << type;
	cout << "\n ������ ������� ������: " << deposit;
}

void account::modify()
{
	cout << "\n������� id ��������������� �������� (6 ����, ������ ��������� � ������� ��������) :";
	cin >> idDogovora;
	cout << "\n\n������� ���������� ��� ������� : ";
	cin.ignore();
	cin.getline(name, 25);
	cout << "\n������� ���������� ��� ������� : ";
	cin >> birthY;
	cout << "\n������� ���������� ����� ���������� : ";
	cin.ignore();
	cin.getline(town, 25);
	cout << "\n������� ���������� ���������� ����� �������� (� ������� 89**) : ";
	cin.ignore();
	cin.getline(telNubmer, 11);
	cout << "\n\n������� ���������� ����� ������ (������������ �����������): ";
	cin.ignore();
	cin.getline(placeWork, 30);
	cout << "\n������� ������� ����������� ����� ������� (���. ���.) : ";
	cin >> income;
	cout << "\n������� ��� ������� ������ (������ (W)/���������� (A)) : "; //������� ��� ������� ������ (C/S) 
	cin >> type;
	type = toupper(type);
	cout << "\n������� �����, �������� �� �/� (���. ���.) : ";
	cin >> deposit;
}

void account::dep(int x)
{
	deposit += x;
}

void account::draw(int x)
{
	deposit -= x;
}

void account::report() const
{
	cout << "| " << idDogovora << setw(4)
		<< " | " << name << setw(4) 
		<< " | " << birthY << setw(4) 
		<< " | " << town << setw(4) 
		<< " | " << telNubmer << setw(4) 
		<< " | " << placeWork << setw(4) 
		<< " | " << type << setw(4) 
		<< " | " << income << setw(4) << endl;
}

int account::retidDogovora() const
{
	return idDogovora;
}

double account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}

int account::retbirthY() const
{
	return birthY;
}

double account::retincome() const
{
	return income;
}



												//***************************************************************
												//			���������� �������
												//****************************************************************
void create_database(string name_file, string tip);
void operations_rko();							//������� �������� ���
void settings_bd(string name_file, string tip);								//������� ��������� ��
void zag1();

void write_account();							//������� ��� ������ ������ � �������� ����
void display_sp(int);							//������� ��� ����������� ���������� ������� ������, ��������������� �������������
void modify_account(int);						//������� ��� ��������� ������ �����
void delete_account(int);						//������� ��� �������� ������ �����
void display_all(string name_file, string tip);								//������� ��� ����������� ���� ���������� �����
void deposit_withdraw(int, int);				//������� ��� ��������/������ ����� ��� ������� �����
void intro();									//������� �������� ������

char otv;


int main()
{
	setlocale(LC_ALL, "Russian");
	char ch;
	intro();
	do
	{
		system("cls");
		cout << "\n\n\n\t ������� ����";
		cout << "\n\n\t 01. ������� ���� ������ ���";
		cout << "\n\n\t 02. ������� ������ ��������";
		cout << "\n\n\t 03. ���������� �� �������� ������������ ������ ��������";
		cout << "\n\n\t 04. ���������� �� �������������� ���������";
		cout << "\n\n\t 05. ��������� ���������� ��������";
		cout << "\n\n\t 06. ������������� ���� ������ ���������";
		cout << "\n\n\t 07. �����";
		cout << "\n\n\t ������� ����� �������� (1-7) ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			//create_database(name_file, tip);
			break;
		case '2':
			write_account();
			break;
		case '3':
			
			break;
		case '4':
			
			break;
		case '5':
			operations_rko();
			break;
		case '6':
			//settings_bd(name_file, tip);
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


												//*******************************************************************************************
												//    		������� ��� ��������� ���� ������
												//*******************************************************************************************
void settings_bd(string name_file, string tip) {
	char ch;
	int num;
	do {
		system("cls");
		cout << "\n\n\n\t �������������� ���� ������ ���������";
		cout << "\n\n\t 01. ������� ������ ���� ��������";
		cout << "\n\n\t 02. �������� ������� ������ ������";
		cout << "\n\n\t 03. �������� ������� ������ �������";//����� ������� ������
		cout << "\n\n\t 05. ������� ������� ������ �������";
		cout << "\n\n\t 05. ��������� � ����" << endl;
		cout << "\n\t ������� ����� �������� (1-5): ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			display_all(name_file, tip);
			break;
		case '2':
			write_account();
			break;
		case '3':
			cout << "\n\n\t������� id �������� : "; cin >> num;
			modify_account(num);
			break;
		case '4':
			cout << "\n\n\t������� id �������� : "; cin >> num;
			delete_account(num);
			break;
		case '5':
			//main();
			break;
		}
		cin.ignore();
		cin.get();
	} while (ch != '5');
	return;
}

												//***************************************************************
												//			������� ��� ������ ������ � �������� ����
												//****************************************************************

void create_database(string name_file, string tip)
{		
	account ac;
	ofstream outFile;
	cout << " ������ ���� ������: ";
	cin >> name_file;
	tip = name_file + tip;


	outFile.open(tip, ios::binary | ios::app);

	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));

	outFile.close();
	
}


												//***************************************************************
												//			������� ��� ������ ������ � �������� ����
												//****************************************************************

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
	outFile.close();
}

												//*******************************************************************************************
												//    		������� ��������� ���������� ��������
												//*******************************************************************************************

void operations_rko()
{
	char ch;
	int num;
	do {
		system("cls");
		cout << "\n\n\n\t ��������� ���������� �������� ";
		cout << "\n\n\t 01. ��������� ������� �ר�";
		cout << "\n\n\t 02. ����� � �������� �ר��";
		cout << "\n\n\t 03. ������� ������ �� �����";
		cout << "\n\n\t 04. ��������� � ������� ����" << endl;
		cout << "\n\n\t ������� ����� �������� (1-4): ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			cout << "\n\n\t ������� id �������� : "; cin >> num;
			deposit_withdraw(num, 1);
			break;
		case '2':
			cout << "\n\n\t ������� id �������� : "; cin >> num;
			deposit_withdraw(num, 2);
			break;
		case '3':
			cout << "\n\n\t ������� id �������� : "; cin >> num;
			display_sp(num);
			break;
		case '4':
			main();
			break;
		}
		cin.ignore();
		cin.get();
	} while (ch != '4');
	return;
}



												//*******************************************************************************************
												//    		������� ��� ����������� ���������� ������� ������, ��������������� �������������
												//*******************************************************************************************

void display_sp(int n)
{
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << " ������ �������� ����� ��� ������! Press any Key...";
		return;
	}
	cout << "\n\t �������� � ������� ���������\n";

	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		if (ac.retidDogovora() == n)
		{
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\t ������ id �������� - �� ����������.";
}


												//***************************************************************
												//    		������� ��� ��������� ������ �����
												//****************************************************************

void modify_account(int n)
{
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << " ������ �������� ����� ��� ������! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retidDogovora() == n)
		{
			ac.show_account();
			cout << "\n\n ������� ���������� ������ ��`���� ������" << endl;
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t ������� ������ ���������.";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n ������� ������ �� �������. ";
}

												//***************************************************************
												//    		������� ��� �������� ������ �����
												//****************************************************************


void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << " ������ �������� ����� ��� ������! Press any Key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
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



	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\n\n\t ������� ������ �������.";
}

												//***************************************************************
												//    		������� ��� ����������� ���� ���������� �����
												//****************************************************************

void display_all(string name_file, string tip)
{
	account ac;
	ifstream inFile;
	inFile.open(tip, ios::binary);
	if (!inFile)
	{
		cout << " ������ �������� ����� ��� ������! Press any Key...";
		return;
	}
	cout << "\n\n\t\t ���� ������ ��������� \n\n";
	zag1();

	
	cout << "\n====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

void zag1() {
	int i;
	for (i = 1; i <= 80; i++) {
		cout << "--";
	}
	cout << endl;
	cout << "| ID �������� |" << " ��� ������� |" << " ��� �������� |" << " ����� |" << " ���������� ������� |" << " ����� ������ |" << " ����|" << " ��. ����� |" << endl;
	for (i = 1; i <= 80; i++) {
		cout << "--";
	}
	return;
}




												//***************************************************************
												//    		������� ��� ��������/������ ����� ��� ������� �����
												//****************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "������ �������� ����� ��� ������! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
		if (ac.retidDogovora() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << "\n\n\t ���������� �������� �ר�� ";
				cout << "\n\n ������� �����, ���������� ��������: ";
				cin >> amt;
				ac.dep(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\t ������ � �������� �ר�� ";
				cout << "\n\n ������� �����, ���������� ������: ";
				cin >> amt;
				int bal = ac.retdeposit() - amt;
				if ((bal < 500 && ac.rettype() == 'A') || (bal < 1000 && ac.rettype() == 'W'))
					cout << " ����������� �������� �������!";
				else
					ac.draw(amt);
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t �������� �������� ���������! ";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n ��� ����������� ������ ���������! ";
}


												//***************************************************************
												//    		������� �������� ������
												//****************************************************************


void intro()
{
	cout << "\n\n\n\t            DATABASE";
	cout << "\n\n\t          ���� � ����";
	cout << "\n\n\t    ������� ���������� ���";
	cout << "\n\n\n\n��������: ������� ��. ������ Z1411";
	cout << "\n\n�������� �.�.";
	cin.get();
}

												//***************************************************************
												//    			����� �������
												//***************************************************************