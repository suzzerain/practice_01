#include <iostream>
using namespace std;
int main() {
    // 1 razdel pracc PAB0Tbl

    cout << "int:" << sizeof(int) << "\n" << "short int:" << sizeof(short int) << "\n" << "long int:"
         << sizeof(long int) << "\n" << "float:" << sizeof(float) << "\n" << "double:" << sizeof(double) << "\n"
         << "long double:" << sizeof(long double) << "\n" << "char:" << sizeof(char) << "\n" << "bool:" << sizeof(bool)
         << "\n";
    //2 razdel

    int binaryInt;
    cout << "Enter data of type int:\n";
    while (!(cin >> binaryInt)) {
        cout << "error, expecting a num value\n";
        cin.clear();
        fflush(stdin);
    }
    int b = sizeof(binaryInt) * 8 - 1;
    int maskInt = 1 << b;
    for (int i = 0; i <= b; i++) {
        if (i == 1 || i % 8 == 0) {
            putchar(' ');
        }

        putchar(binaryInt & maskInt ? '1' : '0');
        binaryInt = binaryInt << 1;
    }
    int d = 0;
    do {

        int Type;
        cout << "\n Select type:\nfloat - 1 \ndouble - 2 \n";
        while (!(cin >> Type)) {
            cout << "error, expecting  '1' or '2' value\n";
            cin.clear();
            fflush(stdin);
        }

        if (Type == 1) {
            //3 razdel
            cout << "\n";
            cout << "Enter data of type float: \n";
            union {
                float binaryFloat;
                int value;
            };
            unsigned order = sizeof(float) * 8, mask = 1 << order - 1;
            while (!(cin >> binaryFloat)) {
                cout << "error, expecting num value\n";
                cin.clear();
                fflush(stdin);
            }
            for (int i = 1; i <= order; ++i) {
                if (i == 2 || i == 10) {
                    putchar(' ');
                }
                putchar(value & mask ? '1' : '0');
                value <<= 1;
            }
            cout << endl;
        }


        if (Type == 2) {
            //4 razdel
            cout << "\n";
            cout << "Enter data of type double: \n";
            union {
                double binaryDouble;
                int arr[2];
            };
            while (!(cin >> binaryDouble)) {
                cout << "error, expecting num value\n";
                cin.clear();
                fflush(stdin);
            }

            int orderg = sizeof(double) * 8;
            int gmaskk = 1 << (orderg - 1);
            for (int j = 1; j >= 0; j--) {
                for (int i = 1; i <= orderg / 2; i++)
                {
                    putchar(arr[j] & gmaskk ? '1' : '0');
                    arr[j] <<= 1;
                    if ((i == 1 || i == 12) && j == 1) {
                        putchar(' ');
                    }
                }
            }

        }

        cout <<  "\nDo you want to exit, or you want to continue? \n1 - continue 2 - exit\n";
        cin >> d;
    } while (d!=2);

}

