#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*
int countOcc(string p, char x)
{
   int count = std::count(p.begin(), p.end(), x);

    return count;
}
*/

typedef struct{
    int e;
    double* d;
}vector;

void vector_init(vector&, int);
double read_and_sum(int);

int main()
{   
    cout<< "Sum of vector: " << read_and_sum(6) <<endl;
    
    return 0;
}



// Construct a vector
void vector_init(vector& v, int s)
{
    v.d = new double[s]; // allocate an array of double s
    v.e = s;    
}

double read_and_sum(int s)
{
    vector v;
    vector_init(v,s);
    
    for(int i = 0; i != s; ++i)
        cin>>v.d[i];
    
    double sum = 0;
    for(int i=0; i!=s; ++i)
        sum += v.d[i];

    return sum;

}