#include <time.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "src/TTTree.h"
using namespace std;
typedef unsigned long long INT_64;

static INT_64 RRand=15750;
const INT_64 mRand =(1<<63) -1;
const INT_64 aRand=6364136223846793005;
const INT_64 cRand=1442695040888963407;

vector<float> _insert;
vector<float> _delete;
vector<float> _search;

void sRand () {srand(time(0)); RRand=(INT_64)rand();}

INT_64 LineRand () {
    INT_64 y1,y2;
    y1= (aRand*RRand+cRand)%mRand;
    y2= (aRand*y1+cRand)%mRand;
    RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 &
    0xFFFFFFFF00000000LL)>>32;
    return RRand;
}

void test_rand(int n) {
    //создание дерева для 64 – разрядных ключей типа INT_64
    TTTree< INT_64,int > tree;
    //массив для ключей, которые присутствуют в дереве
    INT_64* m=new INT_64 [n];
    //установка первого случайного числа
    sRand();
    //заполнение дерева и массива элементами
    //со случайными ключами
    for(int i=0; i<n; i++) {
        m[i]=LineRand();
        tree.Insert(m[i],1);
    }
    //обнуление счётчиков трудоёмкости вставки,
    //удаления и поиска
    double I=0;
    double D=0;
    double S=0;
    //генерация потока операций, 10% - промахи операций
    for(int i=0;i<n/2;i++)
        if(i%10==0) { //10% промахов
            tree.Remove(LineRand ());
            D+=tree.CountNodes();
            tree.Insert(m[rand()%n],1);
            I+=tree.CountNodes();
            try {
                tree.Get(LineRand());
                S+=tree.CountNodes();
            }
            //обработка исключения при ошибке операции поиска
            catch(int){S+=tree.CountNodes();}
        }
    else { //90% успешных операций
        int ind=rand()%n;
        tree.Remove(m[ind]);
        D+=tree.CountNodes();
        INT_64 key=LineRand ();
        tree.Insert(key,1);
        I+=tree.CountNodes();
        m[ind]=key;
        try {
            tree.Get(m[rand()%n]);
            S+=tree.CountNodes();
        }
        //обработка исключения при ошибке операции поиска
        catch(int){S+=tree.CountNodes();}
    } //конец теста
    //вывод результатов:
    //экспериментальной оценки трудоёмкости вставки
    _insert.push_back(I/(n/2));
    //экспериментальной оценки трудоёмкости удаления
    _delete.push_back(D/(n/2));
    //экспериментальной оценки трудоёмкости поиска
    _search.push_back(S/(n/2));
    //освобождение памяти массива m[]
    delete[] m;
}


int main() {
    cout << "RANDOM TREE\n";
    test_rand(10);
    test_rand(100);
    test_rand(500);
    test_rand(1000);
    test_rand(2000);
    test_rand(3000);
    test_rand(4000);
    test_rand(5000);
    test_rand(10000);
    test_rand(15000);
    test_rand(20000);
    test_rand(25000);
    test_rand(30000);
    test_rand(35000);
    test_rand(40000);
    test_rand(45000);
    test_rand(50000);
    test_rand(55000);
    test_rand(75000);
    test_rand(100000);
    cout << "insert:\n";
    for (int i = 0; i < _insert.size(); i++)
        cout << _insert[i] << ",";
    cout << "delete:\n";
    for (int i = 0; i < _delete.size(); i++)
        cout << _delete[i] << ",";
    cout << "search:\n";
    for (int i = 0; i < _search.size(); i++)
        cout << _search[i] << ",";
    return 0;
}
