#include <iostream>
using namespace std;

int main()
{
    int* idrec = (int*)calloc(10, sizeof(int));
    char **sportrec= (char**)calloc(10, 9 * sizeof(char));
    for (int i = 0; i < 10; i++)
    {
        cout << idrec[i] << sportrec[i];
    }
}
