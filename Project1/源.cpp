#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;
template <typename T1, int size>
class Array {
public:
    enum { sz = size };
    T1 i[sz];
    Array() { memset(i, 0, sz * sizeof(*i)); }
    T1& operator[](int x) {
        if (x > 0 && x < sz)
            return i[x];
        else
            exit(0);
    }
    template <typename T1, int size> friend ostream&
        operator<<(ostream& os, const Array& ia);
    template <typename T1, int size> friend istream&
        operator>>(istream& is, Array& ia);
};
template <typename T1,int size>
ostream& operator<<(ostream& os, const Array<T1,size>& ia) {
    for (int j = 0; j < ia.sz; j++) {
        os << ia.i[j];
        if (j != ia.sz - 1)
            os << ", ";
    }
    os << endl;
    return os;
}
template<typename T1,int size>
istream& operator>>(istream& is, Array<T1,size>& ia) {
    for (int j = 0; j < ia.sz; j++)
        is >> ia.i[j];
    return is;
}
void main() {
    stringstream input("47 34 56 92 103");
    Array<int, 5>   a;
    input >> a;
    a[4] = -1;           // Use overloaded operator[]
    cout << a;
}
