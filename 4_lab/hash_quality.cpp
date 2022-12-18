#include <stdlib.h>
#include <time.h> 
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string newStr(int num) {
    string str;
    for (int i = 0; i < num; i++)
        str += 'A' + rand() % 26;
    return str;
}



int HornerFunction(string str, int m) {
    unsigned k = 0;
    for (unsigned i = 0; i < str.size(); ++i) {
        k += pow(32, str.size() - 1 - i) * (str.at(i) - 'A' + 1);
    }

    double g_r = 0.6180339887;

    double X = g_r * k;
    X = X - (unsigned) X;
    return (unsigned) (X * m);

}

int main() {
    int m = 100;
    int P = 20 * m;
    int tries_num = 100;
    double hi_sum = 0;
    srand(time(NULL));
    for (int j = 0; j < tries_num; j++) {
        vector<int> keys;
        for (int i = 0; i < m; i++) {
            keys.push_back(0);
        }
        for (int i = 0; i < P; i++) {
            (keys[HornerFunction(newStr(10), m)])++;
        }
        double hi = 0;
        for (int i = 0; i < m; i++) {
            hi += pow((keys[i]- (double)P/(double)m), 2);
        }
        hi *= (double)m/(double)P;
        hi_sum += hi;
        cout << "hi = " << hi << "\n";
    }
    cout << "hi_avg = " << hi_sum/tries_num << "\n";
    cout << "m+-sqrt(m) = " << m << "+-" << sqrt(m) << "\n";
    return 0;
}