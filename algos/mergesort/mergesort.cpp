#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int merged[m - l + 1] = {};

    int i = l, j = m+1, k = 0;
    while (i <= m and j <= r)
    {
        if (a[i] <= a[j])
        {
            merged[k] = a[i];
            i++;
        }
        else
        {
            merged[k] = a[j];
            j++;
        }
        k++;
    }

    for (k = 0; k < m - l + 1; k++)
    {
        a[k+l] = merged[k];
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);;

        // Merge
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
        {
            L[i] = a[l+i];
        }

        for (int i = 0; i < n2; i++)
        {
            R[i] = a[m + i + 1];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 and j < n2)
        {
            if (L[i] <= R[j])
            {
                a[k] = L[i];
                i++;
            }
            else
            {
                a[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            a[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            a[k] = R[j];
            j++;
            k++;
        }
    }
}

int main()
{
    int n; cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    mergeSort(a, 0, n-1);

    for (int i = 0; i < n; i++) cout<<a[i]<<" \n"[i == n-1];
}
