#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach : Linear Search
// T.C. -> O(N * M)
// S.C. -> O(1)
// bool search_Matrix(vector<vector<int>>& matrix, int target) {

//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j] == target) return true;
//             }
//         }
//         return false;
//     }

// Optimal Approach : Binary Search
// T.C. -> O(log(N * M))
// S.C. -> O(1)
bool search_Matrix(int matrix[3][4], int target)
{
    int n = 3;
    int m = 4;

    int s = 0;
    int e = (n * m) - 1;

    while (s <= e)
    {

        int mid = s + (e - s) / 2;
        if (matrix[mid / m][mid % m] == target)
            return true;
        if (matrix[mid / m][mid % m] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return false;
}

int main()
{

    int matrix[3][4] = {{1, 3, 5, 7},
                        {10, 11, 16, 20},
                        {23, 30, 34, 50}};

    cout << "2D Matrix is : " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }

    int target;
    cout << "Enter the Value to be Searched in the Matrix: " << endl;
    cin >> target;

    bool ans = search_Matrix(matrix, target);

    if (ans == true)
        cout << " " << target << " is present in the Matrix" << endl;
    else
        cout << " " << target << " is Not present in the Matrix" << endl;

    return 0;
}
