
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> C;                      
void Merge(vector<int>& A, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            C[k] = A[i];
            i++;
        }
        else
        {
            C[k] = A[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        C[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        C[k] = A[j];
        j++;
        k++;
    }

    for (int p = low; p <= high; p++)
    {
        A[p] = C[p];
    }
}

void MergeSort(vector<int>& A, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);

        Merge(A, low, mid, high);
    }
}

int main()
{
    int n, m;

    
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    
    cin >> m;

    vector<int> B(m);

    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }

    
    C.resize(max(n, m));


    MergeSort(A, 0, n - 1);
    MergeSort(B, 0, m - 1);

    int i = 0;
    int j = 0;


    while (i < n && j < m)
    {
        if (A[i] < B[j])
        {
            i++;
        }
        else if (A[i] > B[j])
        {
            j++;
        }
        else
        {
            cout << A[i] << " ";

            i++;
            j++;
        }
    }

    return 0;
}
