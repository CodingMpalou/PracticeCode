#include <cstdio>
#include <algorithm>

int n, key[1005], area_key[4][4], emf[4];

int greedy_swap(int areaA, int areaB){
    int ret = std::min(areaA, areaB);
    area_key[areaA][areaB] -= ret;
    area_key[areaB][areaA] -= ret;
    return ret;
}

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key[i]);
        emf[key[i]]++;
    }

    for (int i = 0; i < n; i++) {
        int area;
        if (i < emf[1]) area = 1;
        else if (i < emf[1]+emf[2]) area=2;
        else area=3;
        area_key[area][key[i]]++;
    }

    int ans = greedy_swap(1, 2);
    ans += greedy_swap(1, 3);
    ans += greedy_swap(2, 3);
    ans += 2 * (!!!+!!!);
  /*  2 | 3 | 1 |
      3 | 1 | 2 |*/
    printf("%d", ans);
}