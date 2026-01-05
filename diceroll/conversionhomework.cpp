#include <iostream>
using namespace std;
const int N = 40;
//sum function
inline void sum(int *p, int n, int v[]) {
  *p = 0;
  for (int i = 0; i < n; i++)
    *p += v[i];
}
//main function
int main() {
  int accum = 0;
  int *vec = new int[N];
  for (int i = 0; i < N; i++)
    vec[i] = i;
  sum(&accum, N, vec);
  cout << "Sum is: " << accum << endl;
  delete[] vec;
  return 0;
}