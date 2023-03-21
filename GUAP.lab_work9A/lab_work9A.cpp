#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;
typedef int telem; //���������� ���� �������� �������
typedef telem* tmas; //���������� ���� "��������� �� telem"
void fillArray(tmas arr, int n);//������������ ���������� �������
void showArray(tmas arr, int n);
int firstPositive(tmas arr, telem& pol, int n);
void areElem(telem& mult, int i, int j, int n);
void absoluteValueMult(tmas arr, telem& mult, int n, int i_pol);//����� ��������� � ������� �������� � ���������� ����������� ������������

int main() {
    int n, i, pr;
    setlocale(LC_ALL, "Russian");
    cout << "\n���������� ������������ ���������� �������� ��������� " << endl;
    cout << "������� � ������� ��������, ������� ����� ������ ��������� " << endl;
    cout << "������� � ������������� ��������� � ��������� � ������� n." << endl;
    cout << "������� ���������� ��������� �������: ";
    cin >> n;
    
    tmas arr = new telem[2 * n]; /*�������� ����������-��������� �� telem, ��������� ������������ ������ ��� ������ ����� ������ ������� ��������� � arr*/
    int i_pol; //����� ������� �������� � ������������� ��������� ���������
    telem pol; //�������� ������� �������������� �������� 
    telem mult = 1; //�������� ����������� ������������
    fillArray(arr, 2 * n);
    showArray(arr, 2 * n);
    i_pol = firstPositive(arr, pol, 2 * n); //����� ������ ������� �������� � ������������� ���������
    
    cout << "\n������ ������� ������� � ������������� ���������: " << pol << ", ��� �������: " << i_pol << endl;
    cout << "������� ������� �� ���������: " << arr[n] << ", ��� ������� n = " << n;
    
    areElem(mult, n, i_pol, n);
    absoluteValueMult(arr, mult, n, i_pol);
    pr = mult;

    cout << "\n������������ ���������� �������� ��������� ������� " << endl;
    cout << "� ������� ��������, ������� ����� ������ ��������� " << endl;
    cout << "������� � ������������� ��������� � ��������� � ������� n: " << sr_pr << endl;
    delete[] arr; //������������ ������������ ������
    cout << " ���������-1, �����-2: ";
    cin >> i;
    if (i == 1) main();
    return 0;
}

int firstPositive(tmas arr, telem& pol, int n) {
    int i;
    int i_pol;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) > 0) {
            pol = *(arr + i);
            i_pol = i;
            return i_pol;
        }
    }
    cout << "\n� ������ ������� ��� ������������� ���������. ���������� ��������� ����������. " << endl;
    cout << "���������-1, �����-2: ";
    cin >> i;
    if (i == 1) main();
    exit(1);
    return i;
} 

void absoluteValueMult(tmas arr, telem& mult, int n, int i_pol) {
    int start{}, stop{};
    if (i_pol < n) { //���� ������ ������������� ����� ����� ������ ����� � ��������� n
        stop = n;
        if (i_pol % 2 == 0) {  //�������� �� ��������
            start = i_pol + 2; //������ - ������ �� ���������� �������
        }
        else {
            start = i_pol + 1;
        }
    }
    else if (i_pol > n) { //���� ����� � ��������� n ����� ������ ������� ��������������
        stop = i_pol;
        if (n % 2 == 0) {
            start = n + 2;
        }
        else {
            start = n + 1;
        }
    }
    cout << "\n�������� � ������� ��������: ";
    for (int i = start; i < stop; i += 2) {
        cout << *(arr + i) << " ";
        mult *= *(arr + i);
    }
    if (mult < 0) {
        mult = -mult;
    }
    cout << endl;
} 

void fillArray(tmas arr, int n) {
    cout << "\n������� ����� ������� �������� ������� �� ";
    cout << n << " ����� � ������� <Enter>" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
}  

void showArray(tmas arr, int n) {
    cout << "������ ����� ���: " << endl;
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
} 

void areElem(telem& mult, int i, int j, int n) {
    int k;
    if (i == n && (j == n - 1 || j == n + 1)) {
        cout << "\n� ������ ������� �� ���������� ��������� ��������� �������� � ������� ��������. ������������ ���������� �������� ��������� ������� �����: " << mult * 0 << endl;
        mult *= 0;
        cout << "���������-1, �����-2: ";
        cin >> k;
        if (k == 1) main();
        exit(1);
    }
    else if (i == j) {
        cout << "\n� ������ ������� ��� �������� ��������� �� ������ � ��������. ���������� ��������� ����������. " << endl;
        cout << "���������-1, �����-2: ";
        cin >> k;
        if (k == 1) main();
        exit(1);
    }
}
