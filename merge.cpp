
#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int C[100];

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

    for (i = low, k = 0; i <= high; i++, k++)
    {
        A[i] = C[k];
    }
}

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);

        merge(A, low, mid, high);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int A[100];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    mergeSort(A, 0, n - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}

