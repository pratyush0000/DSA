#include <bits/stdc++.h>
using namespace std;

long minDeliveryTime(int charge1, int delivery1, int charge2, int delivery2) {
    auto simulate = [](int charge1, int delivery1, int charge2, int delivery2, bool drone1_priority) {
        int deliveries_done1 = 0;
        int deliveries_done2 = 0;
        int hour = 0;
        
        while (deliveries_done1 < delivery1 || deliveries_done2 < delivery2) {
            hour++;
            
            bool drone1_can_deliver = (hour % charge1 != 0) && (deliveries_done1 < delivery1);
            bool drone2_can_deliver = (hour % charge2 != 0) && (deliveries_done2 < delivery2);
            
            if (drone1_can_deliver && drone2_can_deliver) {
                if (drone1_priority) {
                    deliveries_done1++;
                } else {
                    deliveries_done2++;
                }
            } else if (drone1_can_deliver) {
                deliveries_done1++;
            } else if (drone2_can_deliver) {
                deliveries_done2++;
            }
        }
        return hour;
    };
    
    int result1 = simulate(charge1, delivery1, charge2, delivery2, true);
    int result2 = simulate(charge1, delivery1, charge2, delivery2, false);
    
    return min(result1, result2);
}

int main() {
    int charge1 = 2, delivery1 = 1, charge2 = 2, delivery2 = 3;
    cout << minDeliveryTime(charge1, delivery1, charge2, delivery2) << endl;
    
    charge1 = 3; delivery1 = 2; charge2 = 4; delivery2 = 1;
    cout << minDeliveryTime(charge1, delivery1, charge2, delivery2) << endl;
    
    return 0;
}