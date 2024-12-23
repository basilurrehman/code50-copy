#include <iostream>
using namespace std;

int main()
{
    // Allocate space for 10 pointers (each pointing to a string)
    const char **sportrec = (const char**)calloc(10, sizeof(char*));

    // String literals
    const char* f = "football";
    const char* c = "cricket";
    const char* h = "hockey";

    // Assign each string to sportrec array
    sportrec[0] = f;  // First entry points to "football"
    sportrec[1] = c;  // Second entry points to "cricket"
    sportrec[2] = h;  // Third entry points to "hockey"

    // Print the sportrec array content (including garbage or 0 for uninitialized)
    for (int i = 0; i < 10; i++) {
        cout << "sportrec[" << i << "] = " << sportrec[i] << endl;
    }

    // Free the memory allocated by calloc (for sportrec itself, not the strings)
    free(sportrec);

    return 0;
}
