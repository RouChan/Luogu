#include <iostream>
using namespace std;

const int MAX = 25;
bool    machine[MAX][10005];         // 机器是否工作
int     timing[MAX];                // 某工件当前步骤最早开始时间
int     step[MAX];                  // 某工件下一工序编号
int     maxTime[MAX];               // 某机器最大操作时间
int     operation[MAX * MAX];       // 安排顺序
struct Proc {
    int     num;                    // 机器号
    int     cost;                   // 时间
} x[MAX][MAX];                      // 某一工件某一步骤的操作信息

int main () {
    int m, n;
    cin >> m >> n;          // 机器数（工序数）、工件数

    for(int i = 0; i < m * n; ++i) {
        cin >> operation[i];
    }

    for(int i = 1;  i <= n; ++i) {           // 零件编号
        for(int j = 1; j <= m; ++j) {        // 工序编号
            int a;
            cin >> a;
            x[i][j].num = a;
        }
    }

    for(int i = 1;  i <= n; ++i) {           // 零件编号
        for(int j = 1; j <= m; ++j) {        // 工序编号
            int a;
            cin >> a;
            x[i][j].cost = a;
        }
    }

    for(int flag = 0; flag < m * n; ++flag) {
        int componentNum    = operation[flag];     // 当前操作的工件序号
        int procedureNum    = step[componentNum] + 1;  // 当前操作的工件步骤
        int machineNum      = x[componentNum][procedureNum].num;    // 当前调用的机器编号
        int preCost         = x[componentNum][procedureNum].cost;   // 当前步骤的时间

        int earliestTime    = timing[componentNum];// 当前步骤最早开始时间

        int beginT;                                // 开始时间
        for(beginT = earliestTime; ; ++beginT) {
            int i = 0;
            for(; i < preCost; ++i) {
                if(machine[machineNum][beginT + i] == true) {
                    break;
                }
            }
            if(i >= preCost) break;
        }

        for(int i = 0; i < preCost; ++i) {          // 表示机器这段时间开始工作
            machine[machineNum][beginT + i] = true;
        }

        // 变化(下一工序等)
        if(maxTime[machineNum] < beginT + preCost) {
            maxTime[machineNum] = beginT + preCost;
        }
        timing[componentNum] = beginT + preCost;
        step[componentNum]++;
    }

    int ans = maxTime[1];
    for(int i = 1; i <= m; ++i) {
        if(maxTime[i] > ans) ans = maxTime[i];
    }

    cout << ans << endl;

    return 0;
}