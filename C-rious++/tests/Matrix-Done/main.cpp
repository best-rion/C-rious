#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int r=3 , c=2;
    vector<vector<int>> mat 
                    {
                        {1,2},
                        {4,5},
                        {6,7}
                    };
                    
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat [i].size(); j++)
        {
            cout << mat [i][j] << " ";
        }    
        cout << endl;
    }

    return 0;
}