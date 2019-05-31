#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int a_to_b(int a, int b);
int b_to_a(int a, int b);
int a_and_b(int a, int b);
int f(int a, int b, int e);
int d(int a, int b);

int main() {
    srand(time(nullptr));
    int p_size = 0, m_size = 0, q_size = 0;
    int **a, **b, *e, **g, **c;

    cout << "Input p, m, q";
    cout << endl;
    cin >> p_size >> m_size >> q_size;
    a = new int *[p_size];
    b = new int *[m_size];
    e = new int [m_size];
    g = new int *[p_size];
    c = new int *[p_size];
    for (int i = 0; i < p_size; i++) {
        a[i] = new int[m_size];
        g[i] = new int[q_size];
        c[i] = new int[q_size];
    }
    for (int i = 0; i < m_size; i++) {
        b[i] = new int[q_size];
    }
    for (int i = 0; i < p_size; i++) {
       for (int j = 0; j < m_size; j++) {
           a[i][j] = rand() % 3 - 1;
       }
    }
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < q_size; j++) {
            b[i][j] = rand() % 3 - 1;
        }
    }
    for (int i = 0; i < m_size; i++) {
        e[i] = rand() % 3 - 1;
    }
    for (int i = 0; i < p_size; i++) {
        for (int j = 0; j < q_size; j++) {
            g[i][j] = rand() % 3 - 1;
        }
    }
    for (int i = 0; i < p_size; i++) {
        for (int j = 0; j < q_size; j++) {
            c[i][j] = rand() % 3 - 1;
        }
    }

    for (int i = 0; i < p_size; i++) {
        for (int j = 0; j < q_size; j++) {
            int f1 = 1, d1 = 1;
            for(int k = 0; k  < m_size; k++){
                f1 *= f(a[i][k], b[k][j], e[k]);
                d1 *= 1 - d(a[i][k], b[k][j]);
            }
            d1 = 1 - d1;
            c[i][j] = f1*(3*g[i][j] - 2)*g[i][j] + (d1 + (4*a_and_b(f1, d1) - 3*d1)*g[i][j])*(1 - g[i][j]);
        }
    }
    cout << endl;
    for (int i = 0; i < p_size; i++) {
        for (int j = 0; j < m_size; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < q_size; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < m_size; i++) {
            cout << e[i] << " ";
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < p_size; i++) {
        for (int j = 0; j < q_size; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < p_size; i++) {
        for (int j = 0; j < q_size; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int a_to_b(int a, int b){
    return 1-a ? b : (1-a > b);
}

int b_to_a(int a, int b){
    return a ? 1-b : (a > 1-b);
}

int a_and_b(int a, int b){
    return a ? b : (a < b);
}

int f(int a, int b, int e){
    return a_to_b(a, b)*(2*e - 1)*e + b_to_a(a, b)*(1 + 4*e*a_to_b(a, b))*(1 - e);
}

int d(int a, int b){
    return a_and_b(a, b);
}