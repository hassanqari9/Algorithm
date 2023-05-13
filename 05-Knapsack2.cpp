#include <iostream>
using namespace std;
int main()
{
    int j;
    int i;
    int w;
    int p[5] = {0, 1, 2, 5, 6};
    int wt[5] = {0, 2, 3, 4, 5};
    int m = 8, n = 4;
    int k[100][100];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (wt[i] <= w)
                k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]);
            else
                k[i][w] = k[i - 1][w];
        }
    }

    cout << "Dynamic Matrix \n";

    cout << "\n";
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 9; j++)
            cout << k[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    cout << "Max Profit = " << k[n][w - 1];
    cout<<"\n";
    
    i = 4, j = 8;
    while (i > 0 && j >= 0)
    {
        if (k[i][j] == k[i - 1][j])
        {
            cout << wt[i] << " = 0" << endl;
            i--;
        }
        else
        {
            cout << wt[i] << " = 1" << endl;
            j = j - wt[i];
            i--;
        }
    }
}