#include <bits/stdc++.h>
using namespace std;

long minDeliveryTime(int charge1, int delivery1, int charge2, int delivery2) {
    long d1 = delivery1, d2 = delivery2;
    long time = 1;

    while (d1 > 0 || d2 > 0) {
        int d1_can_deliver = (d1 > 0 && (time % charge1 != 0));
        int d2_can_deliver = (d2 > 0 && (time % charge2 != 0));

        if (d1_can_deliver && d2_can_deliver) {
            if (d1 >= d2) {
                d1--;
            } else {
                d2--;
            }
        } else if (d1_can_deliver) {
            d1--;
        } else if (d2_can_deliver) {
            d2--;
        }
        time++;
    }

    return time - 1;
}


int main() {
    int charge1, delivery1, charge2, delivery2;
    if (!(cin >> charge1 >> delivery1 >> charge2 >> delivery2)) return 0;
    cout << minDeliveryTime(charge1, delivery1, charge2, delivery2) << endl;
    return 0;
}
