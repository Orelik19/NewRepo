#include <iostream>
#include <cstring>  
using namespace std;

void razmery_tipov() {
    cout << "bool        = " << sizeof(bool) << " bait" << endl;
    cout << "char        = " << sizeof(char) << " bait" << endl;
    cout << "short int   = " << sizeof(short int) << " bait" << endl;
    cout << "int         = " << sizeof(int) << " bait" << endl;
    cout << "long int    = " << sizeof(long int) << " bait" << endl;
    cout << "float       = " << sizeof(float) << " bait" << endl;
    cout << "double      = " << sizeof(double) << " bait" << endl;
    cout << "long double = " << sizeof(long double) << " bait" << endl;
}

void pechat_short(short chislo) {
    unsigned short a = chislo;
    int kolvo_bitov = sizeof(a) * 8;
    cout << "short " << chislo << " = ";
    for (int i = kolvo_bitov - 1; i >= 0; i--) {
        cout << ((a >> i) & 1);
        if (i == kolvo_bitov - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void pechat_int(int chislo) {
    unsigned int a = chislo;
    int kolvo_bitov = sizeof(a) * 8;
    cout << "int " << chislo << " = ";
    for (int i = kolvo_bitov - 1; i >= 0; i--) {
        cout << ((a >> i) & 1);
        if (i == kolvo_bitov - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void pechat_long(long chislo) {
    unsigned long a = chislo;
    int kolvo_bitov = sizeof(a) * 8;
    cout << "long " << chislo << " = ";
    for (int i = kolvo_bitov - 1; i >= 0; i--) {
        cout << ((a >> i) & 1);
        if (i == kolvo_bitov - 1) {
            cout << " ";
        }
    }
    cout << endl;
}


short pomenyat_bit_short(short chislo, int nomer, int znachenie) {
    unsigned short a = chislo;
    unsigned short maska = 1 << nomer;
    if (znachenie == 1) {
        a = a | maska;
    }
    else {
        a = a & ~maska;
    }
    return a;
}

int pomenyat_bit_int(int chislo, int nomer, int znachenie) {
    unsigned int a = chislo;
    unsigned int maska = 1u << nomer;
    if (znachenie == 1) {
        a = a | maska;
    }
    else {
        a = a & ~maska;
    }
    return a;
}

long pomenyat_bit_long(long chislo, int nomer, int znachenie) {
    unsigned long a = chislo;
    unsigned long maska = 1ul << nomer;
    if (znachenie == 1) {
        a = a | maska;
    }
    else {
        a = a & ~maska;
    }
    return a;
}


float pomenyat_bit_float(float chislo, int nomer, int znachenie) {
    unsigned int a;
    memcpy(&a, &chislo, sizeof(chislo));
    unsigned int maska = 1u << nomer;
    if (znachenie == 1) {
        a = a | maska;
    }
    else {
        a = a & ~maska;
    }
    float otvet;
    memcpy(&otvet, &a, sizeof(otvet));
    return otvet;
}

double pomenyat_bit_double(double chislo, int nomer, int znachenie) {
    unsigned long long a;
    memcpy(&a, &chislo, sizeof(chislo));
    unsigned long long maska = 1ull << nomer;
    if (znachenie == 1) {
        a = a | maska;
    }
    else {
        a = a & ~maska;
    }
    double otvet;
    memcpy(&otvet, &a, sizeof(otvet));
    return otvet;
}

short sdelat_nechetnym_short(short chislo) {
    return chislo | 1;
}

int sdelat_nechetnym_int(int chislo) {
    return chislo | 1;
}

long sdelat_nechetnym_long(long chislo) {
    return chislo | 1;
}

int main() {
    cout << "===== 1. razmery tipov =====" << endl;
    razmery_tipov();
    cout << endl;

    cout << "===== 2. dvoichnoe predstavlenie =====" << endl;
    pechat_short(5);
    pechat_short(-5);
    pechat_int(100);
    pechat_int(-100);
    pechat_long(7);
    pechat_long(-7);
    cout << endl;

    cout << "===== 3. menyaem bity =====" << endl;
    cout << "short 5, bit 1 -> 1:" << endl;
    pechat_short(5);
    pechat_short(pomenyat_bit_short(5, 1, 1));

    cout << "int -100, bit 31 -> 0 (ubiraem znak):" << endl;
    pechat_int(-100);
    pechat_int(pomenyat_bit_int(-100, 31, 0));

    cout << "long 7, bit 0 -> 0:" << endl;
    pechat_long(7);
    pechat_long(pomenyat_bit_long(7, 0, 0));

    float f = 1.5;
    cout << "float " << f << ", bit 31 (znak) -> 1: " << pomenyat_bit_float(f, 31, 1) << endl;

    float nol = 0.0;
    cout << "float 0, bit 0 -> 1 (denormalizovannoe): " << pomenyat_bit_float(nol, 0, 1) << endl;

    double d = 2.5;
    cout << "double " << d << ", bit 63 (znak) -> 1: " << pomenyat_bit_double(d, 63, 1) << endl;
    double d_nol = 0.0;
    cout << "double 0, bit 0 -> 1 (denormalizovannoe): " << pomenyat_bit_double(d_nol, 0, 1) << endl;
    cout << endl;

    int vvod, nomer, znach;
    cout << "vvedite celoe chislo: ";
    cin >> vvod;
    cout << "vvedite nomer bita (0-31): ";
    cin >> nomer;
    cout << "vvedite znachenie (0 ili 1): ";
    cin >> znach;
    if (nomer < 0 || nomer > 31 || (znach != 0 && znach != 1)) {
        cout << "nepravilnyi vvod" << endl;
    }
    else {
        cout << "bilo:  ";
        pechat_int(vvod);
        cout << "stalo: ";
        pechat_int(pomenyat_bit_int(vvod, nomer, znach));
    }
    cout << endl;

    cout << "===== 5. sdelat nechetnym =====" << endl;
    pechat_short(10);
    pechat_short(sdelat_nechetnym_short(10));
    pechat_int(-4);
    pechat_int(sdelat_nechetnym_int(-4));
    pechat_long(7);
    pechat_long(sdelat_nechetnym_long(7));

    return 0;
}
