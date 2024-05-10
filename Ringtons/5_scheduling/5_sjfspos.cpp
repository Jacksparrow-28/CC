#include<iostream>
using namespace std;

int main() {
    // shortest job first
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], ct[n], ta[n], wt[n], f[n], k[n];
    int i, st = 0, tot = 0;
    float avgwt = 0, avgta = 0;

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter arrival time for process " << (i + 1) << ": ";
        cin >> at[i];
        cout << "Enter burst time for process " << (i + 1) << ": ";
        cin >> bt[i];
        k[i] = bt[i];
        f[i] = 0;
    }

    while (true) {
        int min = 99, c = n;
        if (tot == n)
            break;

        for (i = 0; i < n; i++) {
            if ((at[i] <= st) && (f[i] == 0) && (bt[i] < min)) {
                min = bt[i];
                c = i;
            }
 }

        if (c == n)
            st++;
        else {
            bt[c]--;
            st++;
            if (bt[c] == 0) {
                ct[c] = st;
                f[c] = 1;
                tot++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        ta[i] = ct[i] - at[i];
        wt[i] = ta[i] - k[i];
        avgwt += wt[i];
        avgta += ta[i];
    }

    cout << "pid  arrival  burst  complete turn waiting\n";
    for (i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << k[i] << "\t" << ct[i] << "\t" << ta[i] << "\t" << wt[i] << "\n";
    }

    cout << "\naverage tat is " << (float)(avgta / n) << "\n";
    cout << "average wt is " << (float)(avgwt / n) << "\n";

    return 0;
}




















































// 0 7 
// 2 4 
// 4 1
// 5 4








