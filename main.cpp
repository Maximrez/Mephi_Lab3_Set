#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include "Heap.hpp"
#include "tests.hpp"
#include "functions.hpp"
#include "MySet.hpp"

int main() {
    string str;
    int s1 = 0;
    while (s1 != 3) {
        cout << endl << "Select an action:" << endl << "1 - create set" << endl << "2 - run tests" << endl << "3 - exit" << endl;
        cin >> s1;
        switch (s1) {
            case 1: {
                cout << "Write an items: ";
                cin >> str;
                MySet<int> st = setFromString(str);
                int s2 = -1, index, item;
                while (s2 != 0) {
                    cout << endl << "Your set:" << endl;
                    st.print();
                    cout << endl << "Select the action with set:" << endl
                         << "1 - insert element" << endl
                         << "2 - search element" << endl
                         << "3 - remove element" << endl
                         << "4 - intersect set" << endl
                         << "5 - unite set" << endl
                         << "6 - subtract set" << endl
                         << "7 - search subset" << endl
                         << "0 - exit" << endl;
                    cin >> s2;
                    switch (s2) {
                        case 1: {
                            cout << "item: ";
                            cin >> item;
                            st.insert(item);
                            break;
                        }
                        case 2: {
                            cout << "item: ";
                            cin >> item;
                            cout << endl;
                            if (st.search(item)) cout << "TRUE";
                            else cout << "FALSE";
                            break;
                        }
                        case 3: {
                            cout << "item: ";
                            cin >> item;
                            st.remove(item);
                            break;
                        }
                        case 4: {
                            cout << "index: ";
                            cin >> index;
                            while ((index < 0) or (index > polynomial.GetSize())) {
                                cout << "Index out of range!" << endl << "index: ";
                                cin >> index;
                            }
                            cout << "new value: ";
                            cin >> item;
                            polynomial.InsertAt(item, index);
                            break;
                        }
                        case 5: {
                            Polynomial<int> new_polynomial = create_polynomial_int();
                            cout << endl << "New polynomial:" << endl;
                            new_polynomial.Print();
                            polynomial = polynomial.AddPolynomial(new_polynomial);
                            break;
                        }
                        case 6: {
                            int scalar;
                            cout << "scalar: ";
                            cin >> scalar;
                            polynomial = polynomial.MulScalar(scalar);
                            break;
                        }
                        case 7: {
                            Polynomial<int> new_polynomial = create_polynomial_int();
                            cout << endl << "New polynomial:" << endl;
                            new_polynomial.Print();
                            polynomial = polynomial.MulPolynomial(new_polynomial);
                            break;
                        }
                        case 8: {
                            Polynomial<int> new_polynomial = create_polynomial_int();
                            cout << endl << "New polynomial:" << endl;
                            new_polynomial.Print();
                            polynomial = polynomial.Composition(new_polynomial);
                            break;
                        }
                        case 9: {
                            int value;
                            cout << "value: ";
                            cin >> value;
                            cout << "result: " << polynomial.CalculatingValue(value) << endl;
                            break;
                        }
                        case 0: {
                            break;
                        }
                        default: {
                            printf("Enter a number from the list!\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 2: {
                const string file_name = "logs.txt";
                ofstream fout(file_name, ios_base::trunc);
                fout.close();

                write_results(test_create_int(10000), file_name, "TEST CREATE INT (N=10000)");
                write_results(test_create_double(10000), file_name, "TEST CREATE DOUBLE (N=10000)");

                write_results(test_insert_int(10000), file_name, "TEST INSERT INT (N=10000)");
                write_results(test_insert_double(10000), file_name, "TEST INSERT DOUBLE (N=10000)");

                cout << "Tests successfully saved to " << file_name << endl;
                break;
            }
            case 3 : {
                break;
            }
            default: {
                cout << "Enter a number from the list!" << endl;
                break;
            }
        }
    }
    return 0;
}
