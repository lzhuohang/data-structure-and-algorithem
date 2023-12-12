#pragma warning(disable:4996)
#include<stdio.h>
#include <vector>
using namespace std;

void decomposition1(vector<double>& diag1, vector<double>& diag2, vector<double>& diag3) {
    int n = diag2.size();
    double i3;
    for (int i = 1; i < n; i++) {
        i3 = diag3[i - 1];
        diag3[i - 1] = diag3[i - 1] / diag2[i - 1];
        diag2[i] = diag2[i] - i3 * diag1[i - 1] / diag2[i - 1];
    }
}
void decomposition2(vector<double>& diag1, vector<double>& diag2, vector<double>& diag3, vector<double>& diag4, vector<double>& diag5) {
    int n = diag3.size();
    diag3[1] = diag3[1] - diag4[0] * diag2[0] / diag3[0];
    double pd = diag4[0];
    diag4[0] = diag4[0] / diag3[0];
    double pc;
    for (int i = 2; i < n; i++) {
        pc = diag3[i] - diag5[i - 2] * diag1[i - 2] / diag3[i - 2];
        diag2[i - 1] = diag2[i - 1] - pd * diag1[i - 2] / diag3[i - 2];
        pd = diag4[i - 1] - diag5[i - 2] * diag2[i - 2] / diag3[i - 2];
        diag3[i] = pc - pd * diag2[i - 1] / diag3[i - 1];
        diag4[i - 1] = pd / diag3[i - 1];
        diag5[i - 2] = diag5[i - 2] / diag3[i - 2];
    }
}


void solve1(vector<double>& diag1, vector<double>& diag2, vector<double>& diag3, const vector<double>& Z, int& n) {
    vector<double> Y(n, 0.0);
    vector<double> X(n, 0.0);
    Y[0] = Z[0];
    for (int i = 1; i < n; i++) {
        Y[i] = Z[i] - diag3[i - 1] * Y[i - 1];
    }
    X[n - 1] = Y[n - 1] / diag2[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        X[i] = (Y[i] - diag1[i] * X[i + 1]) / diag2[i];
    }
    for (int j = 0; j < n; ++j) {
        printf("%.4lf ", X[j]);
    }

}

void solve2(vector<double>& diag1, vector<double>& diag2, vector<double>& diag3, vector<double>& diag4, vector<double>& diag5, vector<float>& Z, int& n)
{
    vector<double> Y(n, 0.0);
    vector<double> X(n, 0.0);
    Y[0] = Z[0];
    Y[1] = Z[1] - diag4[0] * Y[0];
    for (int i = 2; i < n; i++) {
        Y[i] = Z[i] - diag4[i - 1] * Y[i - 1] - diag5[i - 2] * Y[i - 2];
    }
    X[n - 1] = Y[n - 1] / diag3[n - 1];
    X[n - 2] = (Y[n - 2] - diag2[n - 2] * X[n - 1]) / diag3[n - 2];
    for (int i = n - 3; i >= 0; i--) {
        X[i] = (Y[i] - diag2[i] * X[i + 1] - diag1[i] * X[i + 2]) / diag3[i];
    }
    for (int j = 0; j < n; ++j) {
        printf("%.4lf ", X[j]);
    }
}
int main() {
    int p, n, m;
    scanf("%d %d %d", &p, &n, &m);
    if (p == 3)
    {
        vector<double> diag2(n - 1, 0.0);
        vector<double> diag3(n, 0.0);
        vector<double> diag4(n - 1, 0.0);
        for (int i = 0; i < n - 1; i++) {
            scanf("%lf", &diag2[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%lf", &diag3[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            scanf("%lf", &diag4[i]);
        }
        decomposition1(diag2, diag3, diag4);
        vector<double> all(n, 0.0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
            {
                scanf("%lf", &all[j]);
            }
            solve1(diag2, diag3, diag4, all, n);
            printf("\n");
        }
        return 0;
    }

     if (p == 5) {
        vector<double> diag1(n - 2, 0.0);
        vector<double> diag2(n - 1, 0.0);
        vector<double> diag3(n, 0.0);
        vector<double> diag4(n - 1, 0.0);
        vector<double> diag5(n - 2, 0.0);
        for (int i = 0; i < n - 2; i++) {
            scanf("%lf", &diag1[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            scanf("%lf", &diag2[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lf", &diag3[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            scanf("%lf", &diag4[i]);
        }
        for (int i = 0; i < n - 2; i++) {
            scanf("%lf", &diag5[i]);
        }
        decomposition2(diag1, diag2, diag3, diag4, diag5);
        for (int i = 0; i < m; i++) {
            vector<float> all(n, 0.0);
            for (int j = 0; j < n; j++)
            {
                scanf("%f", &all[j]);
            }
            solve2(diag1, diag2, diag3, diag4, diag5, all, n);
            all.clear();
            printf("\n");
        }
        return 0;
    }
}
