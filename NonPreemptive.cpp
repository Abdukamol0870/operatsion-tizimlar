
#include <iostream>
using namespace std;

int main() {
    int at[5] = {0, 1, 4, 9, 2};
    int bt[5] = {14, 10, 2, 6, 9};
    int ct[5], tat[5], wt[5];
    int time = 0, sum = 0;

    for (int i = 0; i < 5; i++) {
        if (time < at[i])
            time = at[i];

        time += bt[i];
        ct[i] = time;
    }

    cout << "Process  CT  TAT  WT\n";

    for (int i = 0; i < 5; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        sum += wt[i];

        cout << "P" << i + 1 << "       "
             << ct[i] << "   "
             << tat[i] << "   "
             << wt[i] << endl;
    }

    cout << "Average WT = " << sum / 5.0;
    return 0;
}
