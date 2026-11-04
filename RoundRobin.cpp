
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int at[5] = {0, 1, 4, 9, 2};
    int bt[5] = {14, 10, 2, 6, 9};
    int rem[5] = {14, 10, 2, 6, 9};
    int ct[5], tat[5], wt[5];
    bool added[5] = {false};

    queue<int> q;
    int tq = 3, time = 0, done = 0;
    int sum = 0;

    while (done < 5) {
        for (int i = 0; i < 5; i++) {
            if (!added[i] && at[i] <= time) {
                q.push(i);
                added[i] = true;
            }
        }

        if (q.empty()) {
            time++;
            continue;
        }

        int i = q.front();
        q.pop();

        int run = rem[i];
        if (run > tq)
            run = tq;

        cout << "P" << i + 1 << " ("
             << time << "-" << time + run << ") ";

        time += run;
        rem[i] -= run;

        for (int j = 0; j < 5; j++) {
            if (!added[j] && at[j] <= time) {
                q.push(j);
                added[j] = true;
            }
        }

        if (rem[i] > 0) {
            q.push(i);
        } else {
            ct[i] = time;
            done++;
        }
    }

    cout << "\n\nProcess  CT  TAT  WT\n";

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
