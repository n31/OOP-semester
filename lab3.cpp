#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

class Matrix {
private:
    int n;
    int** arr;
public:
    void init() {
        arr = new int* [n];
        for (int i = 0; i < n; i++)
            arr[i] = new int[n];
    }

    void fill(int x) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = x;
    }

    void set(int i, int j, int x) {
        arr[i][j] = x;
    }

    char get(int i, int j) {
        return arr[i][j];
    }

    Matrix() : n(1) { init(); fill(75); }
    Matrix(int size) : n(size) { init(); fill(75); }
    Matrix(Matrix& obj) : n(obj.n) {
        init();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = obj.arr[i][j];
    }
    ~Matrix() {
        for (int i = 0; i < n; i++)
            delete[] arr[i];
        delete[] arr;
    }
    Matrix& operator = (const Matrix& obj) {
        n = obj.n;
        init();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = obj.arr[i][j];
        return *this;
    }

    Matrix& operator + (const Matrix& obj) {
        for (int i = 0; i < min(n, obj.n); i++)
            for (int j = 0; j < min(n, obj.n); j++)
                arr[i][j] += obj.arr[i][j];
        return *this;
    }

    Matrix& operator - (const Matrix& obj) {
        for (int i = 0; i < min(n, obj.n); i++)
            for (int j = 0; j < min(n, obj.n); j++)
                arr[i][j] -= obj.arr[i][j];
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Matrix& obj);

};

ostream& operator<<(ostream& os, const Matrix& obj)
{
    for (int i = 0; i < obj.n; i++) {
        for (int j = 0; j < obj.n; j++)
            os << char(obj.arr[i][j]) << ' ';
        os << endl;
    }
    os << endl;
    return os;
}

int main()
{
    srand(time(0));

    cout << "8)\n";
    Matrix a(4), b(2);
    b.fill(1);
    cout << a << b;
    Matrix c = a + b;
    cout << c;
    Matrix e = a - b - b;
    cout << e;

    cout << "9)\n";
    Matrix* f = new Matrix(5);
    Matrix* g = new Matrix(*f);
    g->fill(1);
    cout << *f << *g;
    delete f, g;

    cout << "10)\n";
    Matrix** h = new Matrix*[5];
    for (int i = 0; i < 5; i++) {
        h[i] = new Matrix(rand() % 5 + 1);
        h[i]->fill(rand() % 127 + 65);
        cout << *h[i];
    }
    for (int i = 0; i < 5; i++)
        delete h[i];
    delete h;
        


    system("pause");
    return 0;
}
