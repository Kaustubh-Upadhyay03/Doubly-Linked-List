#include <iostream>
#include <string>
#include "test.h"
#include "doubly-linked-list.h"
#include "doubly-linked-list.cpp"

using namespace std;

string get_status_str(bool status)
{
    return status ? "TEST PASSED" : "TEST FAILED";
}

int main() {
    DoublyLinkedListTest linked_test;
    string linked_test_descriptions[10] = {
            "Test1: New empty list is valid",
            "Test2: insert_front() and insert_back() on zero-element list",
            "Test3: select() and search() work properly",
            "Test4: remove_front() and remove_back() on one-element list",
            "Test5: replace() works properly",
            "Test6: insert_front() keeps moving elements forward",
            "Test7: inserting at different positions in the list",
            "Test8: try to remove too many elements, then add a few elements",
            "Test9: lots of inserts and deletes, all of them valid",
            "Test10: lots of inserts and deletes, some of them invalid"
    };

    bool linked_test_results[10];
    linked_test_results[0] = linked_test.test1();
    linked_test_results[1] = linked_test.test2();
    linked_test_results[2] = linked_test.test3();
    linked_test_results[3] = linked_test.test4();
    linked_test_results[4] = linked_test.test5();
    linked_test_results[5] = linked_test.test6();
    linked_test_results[6] = linked_test.test7();
    linked_test_results[7] = linked_test.test8();
    linked_test_results[8] = linked_test.test9();
    linked_test_results[9] = linked_test.test10();

    cout << "DOUBLY LINKED LIST TESTING RESULTS \n";
    cout << "********************************** \n";
    for (int i = 0; i < 10; ++i) {
        cout << linked_test_descriptions[i] << endl << get_status_str(linked_test_results[i]) << endl;
    }
    cout << endl;
}