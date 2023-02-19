#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <functional>
#include <limits>
#include <cmath>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int jN, t, f;
    cin >> jN >> t >> f;
    vector<pair<long,long>> judges(jN);
    for (int i = 0; i < jN; i++)
        cin >> judges[i].first >> judges[i].second;

    vector<pair<long,long>> tar(t);
    for (int i = 0; i < t; i++)
        cin >> tar[i].first >> tar[i].second;

    vector<pair<long,long>> feather(f);
    for (int i = 0; i < f; i++)
        cin >> feather[i].first >> feather[i].second;

    vector<bool> tar_t(t, false);
    vector<bool> fea_t(f, false);
    vector<bool> jud_t(f, false);



    double total_dist = 0.0;

    for(int i = 0; i < jN; i++) {
        int idx, jdx;
        long dist = numeric_limits<long>::max();

        for (int j = 0; j < jN; j++) {
            if (jud_t[i]) continue;
            for(int k = 0; k < t; k++) {
                if( tar_t[k] ) continue;
                long dist_x = judges[j].first - tar[k].first;
                long dist_y = judges[j].second - tar[k].second;
                long d = (dist_x * dist_x) + (dist_y * dist_y);
                if(d < dist) {
                    dist = d;
                    idx = k;
                    jdx = j;
                }
            }
        }
        tar_t[idx] = true;
        jud_t[jdx] = true;
        total_dist += sqrt(dist);
    }

    for(int i=0; i<jN; i++)
        jud_t[i] = false;

    for(int i = 0; i < jN; i++) {
        int idx, jdx;
        long dist = numeric_limits<long>::max();

        for (int j = 0; j< jN; j++) {
            if (jud_t[i]) continue;
            for(int k = 0; k < f; k++) {
                if( fea_t[k] ) continue;
                long dist_x = judges[j].first - feather[k].first;
                long dist_y = judges[j].second - feather[k].second;
                long d = (dist_x * dist_x) + (dist_y * dist_y);
                if(d < dist) {
                    dist = d;
                    idx = k;
                    jdx = j;
                }
            }
        }

        fea_t[idx] = true;
        jud_t[jdx] = true;
        total_dist += sqrt(dist);
    }
    // double x;
    // cout << std::fixed << setprecision(min(modf(total_dist, &x) + 1, 7.0)) << total_dist << "\n";
    cout << std::fixed << setprecision(6) << total_dist << "\n";

}
