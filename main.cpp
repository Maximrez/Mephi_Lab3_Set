#include <iostream>
#include <algorithm>
#include <vector>
#include "Heap.hpp"
#include "tests.hpp"
#include "functions.hpp"
#include "MySet.hpp"

int main() {
    auto set = setFromString("1 2 3 4 5 -672");
    set.print(cout);

    auto set1 = MySet<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, -1});
    auto set2 = MySet<int>({1, 2, 3, -1});
    cout << endl << set1.include(set2);

//    cout << endl << endl << "NLR:" << endl;
//    heap->NLR();
//    cout << endl << endl << "NRL:" << endl;
//    heap->NRL();
//    cout << endl << endl << "LRN:" << endl;
//    heap->LRN();
//    cout << endl << endl << "LNR:" << endl;
//    heap->LNR();
//    cout << endl << endl << "RLN:" << endl;
//    heap->RLN();
//    cout << endl << endl << "RNL:" << endl;
//    heap->RNL();
//    cout << endl;
//
//    vector<int> vec = heap->getValues();
//    for (int i : vec){
//        cout << i << " ";
//    }

//    int n1 = 11;
//    int list1[n1];
//    for (int i = 0; i < n1; i++) {
//        list1[i] = (i + 16) % n1;
//    }
//    auto *heap1 = new Heap<int>(list1, n1);
//    cout << endl;
//    heap1->print(cout);
//    auto *intesection = heap->intersection(*heap1);
//    cout << endl;
//    intesection->print(cout);
//    auto *unity = heap->unification(*heap1);
//    cout << endl;
//    unity->print(cout);

//    const string file_name = "logs.txt";
//    ofstream fout(file_name, ios_base::trunc);
//    fout.close();
//    write_results(test_create_int(10000), file_name, "TEST CREATE INT (N=10000)");
//    write_results(test_create_double(10000), file_name, "TEST CREATE DOUBLE (N=10000)");
//    write_results(test_insert_int(10000), file_name, "TEST INSERT INT (N=10000)");
//    write_results(test_insert_double(10000), file_name, "TEST INSERT DOUBLE (N=10000)");
    return 0;
}
