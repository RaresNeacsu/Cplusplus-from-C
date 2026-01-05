#include <iostream>
#include <complex>
using namespace std;
template<class summable>
inline void sumarr(const summable *arr, int size, summable sum = 0) {
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << sum << endl;
}
template<class printab>
inline void afisare(const printab *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
template<class differ>
inline void diffarr(const differ *arr, int size, differ diff = 0) {
    for (int i = 0; i < size; i++) {
        diff -= arr[i];
    }
    cout << diff << endl;
}
int main() {
    int n;
    cin >> n;
    int *v= new int[n];
    double *v2=new double[n];
    complex<double> *v3=new complex<double>[n];
    for (int i = 0; i < n; i++) {
        v[i] = rand()%100;
        v2[i] = rand()%100+1.2893;
        v3[i] = complex<double>(rand()%100, rand()%100);
    }
    afisare(v, n);
    afisare(v2, n);
    afisare(v3, n);
    sumarr(v, n);
    sumarr(v2, n);
    sumarr(v3, n);
    diffarr(v, n);
    diffarr(v2, n);
    diffarr(v3, n);
    delete[] v;
    delete[] v2;
    delete[] v3;
    return 0;
}