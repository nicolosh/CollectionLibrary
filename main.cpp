#include <iostream>
#include <collection/coda.h>
#include <collection/lista.h>
#include <collection/set.h>
#include <collection/stack.h>

using namespace std;
using namespace collection;

int main() {
    const int LEN = 9;

    int z[] = {1,2,3,4};
    int b[] = {1,2,3};
    int c[] = {11,2,3,1};
    int d[] = {12,1};
    int* a[1] = {z};
    lista<int> firstList(a,1,"first");

    firstList.addElement(10,3);

    cout << "First list" << endl;
    for(int i = 0; i < 4; ++i)
    {
        cout << z[i] << " ";
    }
    return 0;
}
