#include <iostream>
using namespace std;

class vector{
    int len, *ptr;
    public:
        vector(){
            len = 0;
            ptr = NULL;
        }
        vector(int);
        friend istream &operator>>(istream &input, class vector &v);
        friend ostream &operator<<(ostream &output, class vector &v);
        friend void operator*(int, vector &);
        vector operator+(vector);
};

void operator*(int n, vector &v){
    for (int i = 0; i < v.len; i++)
        v.ptr[i] *= n;
    cout << v;
}

vector vector::operator+(vector v2){
    vector temp(len);
    for (int i = 0; i < len; i++)
        temp.ptr[i] = ptr[i] + v2.ptr[i];
    return temp;
}

istream &operator>>(istream &input, class vector &v){
    for (int i = 0; i < v.len; i++)
        input >> v.ptr[i];
}

ostream &operator<<(ostream &output, class vector &v){
    output << "( ";
    for (int i = 0; i < v.len; i++)
        output << v.ptr[i] << " ";
    output << ")" << endl;
}

vector::vector(int n){
    len = n;
    ptr = new int[len];
}

int main(int argc, char const *argv[]){
    int size, n;
    cout << "Enter the size of Vector: ";
    cin >> size;
    vector v1(size), v2(size);

    cout << "Enter the first vector: ";
    cin >> v1;

    cout << "Enter the second vector: ";
    cin >> v2;

    cout << "Enter the scalar to be multiplied: ";
    cin >> n;

    cout << "\nv1*" << n << "=";
    n*v1;

    cout << "\nv2*" << n << "=";
    n*v2;

    vector v3(2 * size);

    cout<<"\nv1 + v2 = ";
    v3 = v1 + v2;
    cout << v3;
    return 0;
}