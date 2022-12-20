#include "src/HashTable.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

double teorCL(int n, int m) { return 1 + ((double)n / (double)m) / 2; }

double sucTeorOA(int n, int m) {
  double a = (double)n / (double)m;
  return (1 + 1 / (1 - a)) / 2;
}

double unsucTeorOA(int n, int m) {
  double a = (double)n / (double)m;
  return (1 + 1 / pow((1 - a), 2)) / 2;
}

string newStr(int num) {
  string str;
  for (int i = 0; i < num; i++)
    str += 'A' + rand() % 26;
  return str;
}

int main() {
  int n, m = 10000;
  srand(time(NULL));
  int step = m / 20;
  vector<string> keys;
  vector<double> alphas;
  vector<double> insert_c;
  vector<double> search_c;
  vector<double> remove_c;
  vector<double> teor;
  for (int i = 0; i < 1.5 * m / step; i++) {
    insert_c.push_back(0);
    search_c.push_back(0);
    remove_c.push_back(0);
  }
  cout << "step = " << step << "\n";
  for (int j = 0; j < 10; j++) {
    HashTable<int> cltable(m, true);
    for (int k = 0; cltable.GetSize() <= 1.5 * (double)m; k++) {
      n = cltable.GetSize();
      if (alphas.size() <= 1.5 * m / step)
        alphas.push_back((double)n / (double)m);
      string key = newStr(10);
      cltable.Insert(key, 1);
      insert_c[k] += cltable.CountNodes();
      cltable.Get(key);
      search_c[k] += cltable.CountNodes();
      cltable.Remove(key);
      remove_c[k] += cltable.CountNodes();
      if (teor.size() <= 1.5 * m / step)
        teor.push_back(teorCL(n, m));
      for (int i = 0; i < step; i++) {
        string str = newStr(10);
        keys.push_back(str);
        cltable.Insert(str, 0);
      }
    }
  }
  cout << "cltable, m = " << m << "\n";
  cout << "alphas: ";
  for (int i = 0; i < alphas.size(); i++)
    cout << alphas[i] << ", ";
  cout << "\ninsert: ";
  for (int i = 0; i < insert_c.size(); i++)
    cout << insert_c[i] / 10 << ", ";
  cout << "\nsearch: ";
  for (int i = 0; i < search_c.size(); i++)
    cout << search_c[i] / 10 << ", ";
  cout << "\nremove: ";
  for (int i = 0; i < remove_c.size(); i++)
    cout << remove_c[i] / 10 << ", ";
  cout << "\nteor: ";
  for (int i = 0; i < teor.size(); i++)
    cout << teor[i] << ", ";
  alphas.clear();
  insert_c.clear();
  search_c.clear();
  remove_c.clear();
  for (int i = 0; i < m / step; i++) {
    insert_c.push_back(0);
    search_c.push_back(0);
    remove_c.push_back(0);
  }
  teor.clear();
  for (int j = 0; j < 10; j++) {
    HashTable<int> oatable(m, false);
    for (int k = 0; oatable.GetSize() < m; k++) {
      n = oatable.GetSize();
      if (alphas.size() <= m / step)
        alphas.push_back((double)n / (double)m);
      string key = newStr(10);
      oatable.Insert(key, 1);
      insert_c[k] += oatable.CountNodes();
      oatable.Get(key);
      search_c[k] += oatable.CountNodes();
      oatable.Remove(key);
      remove_c[k] += oatable.CountNodes();
      if (teor.size() <= m / step)
        teor.push_back(sucTeorOA(n, m));
      for (int i = 0; i < step; i++) {
        string str = newStr(10);
        keys.push_back(str);
        oatable.Insert(str, 0);
      }
    }
  }
  cout << "\noatable, m = " << m << "\n";
  cout << "alphas: ";
  for (int i = 0; i < alphas.size(); i++)
    cout << alphas[i] << ", ";
  cout << "\ninsert: ";
  for (int i = 0; i < insert_c.size(); i++)
    cout << insert_c[i] / 10 << ", ";
  cout << "\nsearch: ";
  for (int i = 0; i < search_c.size(); i++)
    cout << search_c[i] / 10 << ", ";
  cout << "\nremove: ";
  for (int i = 0; i < remove_c.size(); i++)
    cout << remove_c[i] / 10 << ", ";
  cout << "\nteor: ";
  for (int i = 0; i < teor.size(); i++)
    cout << teor[i] << ", ";
  return 0;
}