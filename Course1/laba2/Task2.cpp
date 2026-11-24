#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector<int> repeat(const vector<int>& v, int n) {
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        result.insert(result.end(), v.begin(), v.end());
    }
    return result;
}


bool sameLastTwoDigits(int x) {
    int absx = abs(x);
    int last = absx % 10;
    int prelast = (absx / 10) % 10;
    return last == prelast;
}

int main() {
    int m;
    cout << "Введите количество элементов исходного вектора: ";
    cin >> m;
    vector<int> v(m);
    cout << "Введите " << m << " целых чисел: ";
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
    }

    int n;
    cout << "Введите число повторений n: ";
    cin >> n;

    vector<int> seq = repeat(v, n);

   
    long long sum = 0;
    int count = 0;
    for (int x : seq) {
        if (sameLastTwoDigits(x)) {
            sum += x;
            ++count;
        }
    }
    double avg = 0.0;
    if (count > 0) {
        avg = static_cast<double>(sum) / count;
    }
    double avg_sq = avg * avg;

    int pair_count = 0;
    long long max_sum_sq = -1;
    for (size_t i = 0; i + 1 < seq.size(); ++i) {
        int a = seq[i];
        int b = seq[i + 1];

        
        int last_a = abs(a) % 10;
        int prelast_a = (abs(a) / 10) % 10;
        int last_b = abs(b) % 10;
        int prelast_b = (abs(b) / 10) % 10;
        bool cond1 = (last_a == prelast_b) || (last_b == prelast_a);

       
        bool div_a = (a % 11 == 0);
        bool div_b = (b % 11 == 0);
        bool cond2 = (div_a != div_b);

       
        long long sum_sq = 1LL * a * a + 1LL * b * b;
        bool cond3 = (sum_sq >= avg_sq);

        if (cond1 && cond2 && cond3) {
            ++pair_count;
            if (sum_sq > max_sum_sq) {
                max_sum_sq = sum_sq;
            }
        }
    }

    if (max_sum_sq == -1) max_sum_sq = 0;
    cout << "Количество найденных пар: " << pair_count << endl;
    cout << "Максимальная сумма квадратов: " << max_sum_sq << endl;

    return 0;
}