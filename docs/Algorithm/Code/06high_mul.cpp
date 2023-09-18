#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &A, int B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i] * B;
        C.push_back(t % 10);
        t = t / 10;
    }
    if (t != 0)
        C.push_back(t);
    while (C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }

    return C;
}

int main()
{
    string a;
    vector<int> A;
    int B;
    cin >> a >> B;

    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    auto C = mul(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}