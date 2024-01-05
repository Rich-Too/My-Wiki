#include <iostream>
#include <vector>
using namespace std;

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    if (B.size() > A.size())
        return sub(B, A);
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (i < B.size())
            t += B[i];
        t += A[i];
        C.push_back(t % 10);
        t = t / 10;
    }
    if (t)
        C.push_back(t);
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    auto C = sub(A, B);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
}