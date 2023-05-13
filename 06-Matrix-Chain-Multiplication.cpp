#include <iostream>
#include <climits>

using namespace std;

int MCM(int dimensions[], int n)
{
    int dp[n][n];

    // Initialize the dp matrix
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    // Fill the dp matrix in a bottom-up manner
    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;
            dp[i][j] = 32767;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1]; // Return the minimum number of multiplications
}

int main()
{
    int dimensions[] = {5, 4, 6, 2, 7};
    int n = 5;

    int result = MCM(dimensions, n);

    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}