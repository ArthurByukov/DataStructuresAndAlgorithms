#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> v(n);
    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if (n > 0) {
        
        vector<int>::iterator min_it = min_element(v.begin(), v.end());
        vector<int>::iterator max_it = max_element(v.begin(), v.end());
        
        swap(*min_it, *max_it);
    }

    cout << "Изменённый вектор: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}