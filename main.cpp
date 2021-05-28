#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "tests.hpp"
#include "functions.hpp"
#include "MySet.hpp"

using namespace std;

int main() {
    string str;
    int s1 = 0;
    while (s1 != 3) {
        cout << endl << "Select an action:" << endl << "1 - create set" << endl << "2 - run tests" << endl << "3 - exit" << endl;
        cin >> s1;
        switch (s1) {
            case 1: {
                cout << "Write an items:" << endl;
                getline(cin, str);
                getline(cin, str);
                MySet<int> st = setFromString(str);
                int s2 = -1, item;
                while (s2 != 0) {
                    cout << endl << "Your set:" << endl;
                    st.print(cout);
                    cout << endl << endl << "Select the action with set:" << endl
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
                            if (st.search(item)) cout << "TRUE";
                            else cout << "FALSE";
                            cout << endl;
                            break;
                        }
                        case 3: {
                            cout << "item: ";
                            cin >> item;
                            st.remove(item);
                            break;
                        }
                        case 4: {
                            cout << "Write an items:" << endl;
                            getline(cin, str);
                            getline(cin, str);
                            MySet<int> new_st = setFromString(str);
                            cout << endl << "New set:" << endl;
                            new_st.print(cout);
                            cout << endl;
                            st = st.intersection(new_st);
                            break;
                        }
                        case 5: {
                            cout << "Write an items:" << endl;
                            getline(cin, str);
                            getline(cin, str);
                            MySet<int> new_st = setFromString(str);
                            cout << endl << "New set:" << endl;
                            new_st.print(cout);
                            cout << endl;
                            st = st.unification(new_st);
                            break;
                        }
                        case 6: {
                            cout << "Write an items:" << endl;
                            getline(cin, str);
                            getline(cin, str);
                            MySet<int> new_st = setFromString(str);
                            cout << endl << "New set:" << endl;
                            new_st.print(cout);
                            cout << endl;
                            st = st.subtraction(new_st);
                            break;
                        }
                        case 7: {
                            cout << "Write an items:" << endl;
                            getline(cin, str);
                            getline(cin, str);
                            MySet<int> new_st = setFromString(str);
                            cout << endl << "New set:" << endl;
                            new_st.print(cout);
                            cout << endl << endl;
                            if (st.include(new_st)) cout << "TRUE";
                            else cout << "FALSE";
                            cout << endl;
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
