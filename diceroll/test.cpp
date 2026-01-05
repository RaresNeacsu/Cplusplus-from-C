//Convert this program to C++
//Change to C++ io
//Change to one line comments
//Change defines of constants to const
//Change array to vector<>
//Inline any short function

#include<iostream>
#include<vector>
using namespace std;

const int N = 40;

inline void sum(int &p, const vector<int> &v)
{
	p = 0;
	for (int i = 0; i<v.size(); i++)
	{
		p += v[i];
	}
}
int main()
{
	vector<int> v;
	for(int i=0; i<N; i++)
	{
		v.push_back(i);
	}
	int accum;
	sum(accum, v);
	cout<<"Sum is "<<accum<<endl;
	return 0;
}