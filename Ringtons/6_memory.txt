#include <iostream>
using namespace std;

class MemoryAllocationAlgo {
    int* job;
    int* block;
    int* Allocation;
    

public:
    int js, bs;
    void ReadData(int n, int m) {
        job = new int[n];
        block = new int[m];

        for (int i = 0; i < n; i++) {
            cout << "Enter Size of Job " << i << ": ";
            cin >> job[i];
        }

        for (int i = 0; i < m; i++) {
            cout << "Enter Size of FREE Block " << i << ": ";
            cin >> block[i];
        }
    }

    void FirstFit() {
        Allocation = new int[js];
        for (int i = 0; i < js; i++) {
            Allocation[i] = -1;
        }

        int flag; 
        for (int i = 0; i < js; i++) {
            flag = 0;
            for (int j = 0; j < bs; j++) {
                if (block[j] >= job[i])
                {
                    for (int k = 0; k < js; k++) {
                        if (Allocation[k] == j) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        Allocation[i] = j;
                        break;
                    }
                }
            }
        }

        Display();
    }

    void BestFit() {
        Allocation = new int[js];
        for (int i = 0; i < js; i++) {
            Allocation[i] = -1;
        }

        int flag;
        for (int i = 0; i < js; i++) {
            int BestInd = -1;
            for (int j = 0; j < bs; j++) {
                flag = 0;
                if (block[j] >= job[i]) {
                    for (int k = 0; k < js; k++) {
                        if (Allocation[k] == j) {
                            flag = 1;
                            break;
                        }
                    }
                    if (BestInd == -1 && flag == 0) {
                        BestInd = j;
                    } else if (flag == 0 && block[BestInd] > block[j]) {
                        BestInd = j;
                    }
                }
            }
            if (BestInd != -1) {
                Allocation[i] = BestInd;
            }
        }

        Display();
    }

    void WorstFit() {
        Allocation = new int[js];
        for (int i = 0; i < js; i++) {
            Allocation[i] = -1;
        }

        int flag;
        for (int i = 0; i < js; i++) {
            int WorstInd = -1;
            for (int j = 0; j < bs; j++) {
                flag = 0;
                if (block[j] >= job[i]) {
                    for (int k = 0; k < js; k++) {
                        if (Allocation[k] == j) {
                            flag = 1;
                            break;
                        }
                    }
                    if (WorstInd == -1 && flag == 0) {
                        WorstInd = j;
                    } else if (flag == 0 && block[WorstInd] < block[j]) {
                        WorstInd = j;
                    }
                }
            }
            if (WorstInd != -1) {
                Allocation[i] = WorstInd;
            }
        }

        Display();
    }

    void Display() {
        cout << "Job No.\tJobSize\tBlock No\tFragment" << endl;
        for (int i = 0; i < js; i++) {
            cout << " " << i << "\t" << job[i] << "\t";
            if (Allocation[i] != -1) {
                cout << "\t" << Allocation[i] << "\t" << (block[Allocation[i]] - job[i]);
            } else {
                cout << " Not allocated";
            }
            cout << endl;
        }
    }
};

int main() {
    MemoryAllocationAlgo MA;
    while (true) {
        cout << "Menu:\n\n1. Read Data-Job No. & Size, Block No. & Size\n2. First Fit\n3. Best Fit\n4. Worst Fit\n5. Exit" << endl;
        cout << "Enter Your Choice: ";
        int ch;
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter total no. of jobs to allocate: ";
                cin >> MA.js;
                cout << "\nEnter total no. of Free blocks: ";
                cin >> MA.bs;
                MA.ReadData(MA.js, MA.bs);
                break;
            case 2:
                MA.FirstFit();
                break;
            case 3:
                MA.BestFit();
                break;
            case 4:
                MA.WorstFit();
                break;
            case 5:
                exit(0);
                break;
        }
    }
    return 0;
}




































// 250 320 450 520 80
// 100 300 500 700 400 