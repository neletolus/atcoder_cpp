#include <cmath>
#include <iostream>
using namespace std;

int main() {
    // 入力
    long long a, b, c;
    cin >> a >> b >> c;

    // c = 1 のときの場合分け
    if (c == 1) {
        cout << "No" << endl;
        return 0;
    }

    // 右辺の計算（c の b 乗）
    long long v = 1;
    for (long long i = 1; i <= b; i++) {
        if (a / c < v) {
            // この条件分岐は a < (v * c) を言い換えただけ
            // 条件の言い換えをした理由は、v, c が 10^18 程度になる可能性があるため
            // a < v * c にすると最悪の場合 v * c = 10^36 になりオーバーフローするから
            cout << "Yes" << endl;
            return 0;
        }
        v *= c;
    }

    // ループが打ち切られない場合
    cout << "No" << endl;
    return 0;
}