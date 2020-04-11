#include <algorithm>
#include <climits>
#include <stdio.h>
#include <math.h>
 
using namespace std;
 
int T, N, M, c1, c2, c3, ans, c, temp, i_temp, j_temp, ij_temp, cow[500000], horse[500000], arr[3];
 
int main() {
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d %d", &N, &M, &c1, &c2);
        for (int i = 0; i < N; i++) scanf("%d", cow + i);
        for (int i = 0; i < M; i++) scanf("%d", horse + i);
        sort(cow, cow + N); sort(horse, horse + M);
        ans = INT_MAX, c = 0;
        int i = 0, j = 0;
        while (i < N && j < M) {

            temp = abs(cow[i] - horse[j]);
            if (temp < ans)  
                ans = temp; c = 1; 
            else if (temp == ans)  
                c++; 

            if (i == N - 1)  
                i_temp = INT_MAX; 
            else 
                i_temp = abs(cow[i + 1] - horse[j]); 

            if (j == M - 1)  
                j_temp = INT_MAX; 
            else 
                j_temp = abs(cow[i] - horse[j + 1]);

            if (i == N - 1 || j == M - 1)  
                ij_temp = INT_MAX;
            else 
                ij_temp = abs(cow[i + 1] - horse[j + 1]);


            arr[0] = i_temp; 
            arr[1] = j_temp; 
            arr[2] = ij_temp;
            sort(arr, arr + 3);
            if (arr[0] == i_temp)  
                i++; 
            else if (arr[0] == j_temp) 
                j++;
            else if (arr[0] == ij_temp) {
                i++; 
                j++; 
            }
        }
        c3 = (c1 > c2) ? (c1 - c2) : (c2 - c1);
        ans = ans + c3;
        printf("#%d %d %d\n", t, ans, c);
    }
    return 0;
}