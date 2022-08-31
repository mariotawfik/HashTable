#include <iostream>
using namespace std;
#include "associative_array.h"

int main()
{
    associative_array A;
    A.userInteractionForInsert();
    A.userInteractionForInsert();
    cout << endl << A.is_empty() << endl << endl;
    A.userInteractionForDelete();
    A.printList();
    cout << A.size() << endl;
}
