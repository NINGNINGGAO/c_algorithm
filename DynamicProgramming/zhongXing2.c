/*
 * @Author: AGOGIN
 * @Date: 2019-09-14 20:10:40
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-14 21:25:07
 */
/*
题目描述:
维克多博士创造了一个裂变反应堆，可取用处于液体状态的放射性物质。
反应堆的容量是V加仑。他有N瓶的放射性液体，每个都有一定的质量和一定的体积。
当液体倒入反应堆时，也产生一些单位的能量。现在，维克多想要将能量输出最大化。
但是，有一个限制条件。他研究了原子元素的物理知识和历史，
认识到反应堆内放射性液体的总量不能超过特定的临界质量M，否则反应就会失控，并引发剧烈的爆炸。
写一个算法，帮助他从反应堆获得最大的能量，而不会让他丢掉性命。

输入：
该函数/方法的输入包括六个参数------
reactorCap，一个整数，表示反应堆的容量(V);
numberOfRadLiquid,一个整数，表示现有小瓶的数量(N);
criticalMass，一个整数，表示反应堆的最大临界质量(M);
volumes，一个整数列表，按顺序表示N份放射性液体的体积;
masses，一个整数列表，按顺序表示N份放射性液体的质量;
energies,一个整数列表，按顺序表示N份放射性液体产生的能量。

输出：
返回一个整数，表示可给定的约束条件下从反应堆中产生的最大能量。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int solution(int reactorCap, int numberOfRadLiquid, int critcaMass, int* volumes, int* masses, int* energies) {
    int arr[numberOfRadLiquid + 1][reactorCap + 1][critcaMass + 1];

    for (int i = 1; i < numberOfRadLiquid + 1; i++) {
        for (int j = 1; j < reactorCap + 1; j++) {
            for (int k = 1; k < critcaMass + 1; k++) {
                if (masses[i - 1] <= k && volumes[i - 1] <= j) {
                    arr[i][j][k] = Max(arr[i - 1][j][k], arr[i - 1][j - volumes[i - 1]][k - masses[i - 1]] + energies[i - 1]);
                } else {
                    arr[i][j][k] = arr[i - 1][j][k];
                }
            }
        }
    }
    return arr[numberOfRadLiquid][reactorCap][critcaMass];
}



int main() {
    /*int reactorCap = 100;
    int numberOfRadLiquid = 5;
    int critcaMass = 15;
    int volumes[5] = {50,40,30,20,10};
    int masses[5] = {1,2,3,9,5};
    int energies[5] = {300,480,270,200,180};*/
    int reactorCap, numberOfRadLiquid, critcaMass;
    scanf("%d\n", &reactorCap);
    scanf("%d\n", &numberOfRadLiquid);
    scanf("%d\n", critcaMass);
    int volumes[numberOfRadLiquid], masses[numberOfRadLiquid], energies[numberOfRadLiquid];
    for (int i = 0; i < numberOfRadLiquid; i++) {
        scanf("%d %d %d", &(volumes[i]), &(masses[i], &(energies[i])));
    }
    int ret = solution(reactorCap, numberOfRadLiquid, critcaMass, volumes, masses, energies);
    printf("%d\n", ret);
    return 0;
}