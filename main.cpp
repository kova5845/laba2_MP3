// Лабораторная работа 2 по дисциплине МРЗвИС
// Выполнена студентом группы 721701
// БГУИР Коваленко Алексеем Васильевичем
// Реализация модели решения задачи на ОКМД архитектуре

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double a_to_b(double a, double b);
double a_and_b(double a, double b);
double f(double a, double b, double e);
double d(double a, double b);
double ** createArray(int n, int m);
void random(double **a, int n, int m);
void view(double **a, int n, int m);


int main() {
    srand(time(nullptr));
    int p_size = 0, m_size = 0, q_size = 0;
    double **a, **b, *e, **g, **c;

    cout << "Input p, m, q";
    cout << endl;
    cin >> p_size >> m_size >> q_size;
    a = createArray(p_size, m_size);
    b = createArray(m_size, q_size);
    g = createArray(p_size, q_size);
    c = createArray(p_size, q_size);
    e = new double [m_size];
    random(a, p_size, m_size);
    random(b, m_size, q_size);
    random(g, p_size, q_size);
    for (int i = 0; i < m_size; i++) {
        e[i] = (double)rand()/(double) RAND_MAX*2 - 1;
    }

    for (int i = 0; i < p_size; i++) {
        for (int j = 0; j < q_size; j++) {
            double f1 = 1, d1 = 1;
            for(int k = 0; k  < m_size; k++){
                f1 *= f(a[i][k], b[k][j], e[k]);
                d1 *= 1 - d(a[i][k], b[k][j]);
            }
            d1 = 1 - d1;
            c[i][j] = f1*(3*g[i][j] - 2)*g[i][j] + (d1 + (4*a_and_b(f1, d1) - 3*d1)*g[i][j])*(1 - g[i][j]);
        }
    }
    cout << endl;
    view(a, p_size, m_size);
    view(b, m_size, q_size);
    view(g, p_size, q_size);
    for (int i = 0; i < m_size; i++) {
        cout << e[i] << " ";
    }
    cout << endl;
    cout << endl;
    view(c, p_size, q_size);
    for (int i = 0; i < p_size; i++) {
        delete[] a[i];
        delete[] g[i];
        delete[] c[i];
    }
    for (int i = 0; i < m_size; i++) {
        delete[] b[i];
    }
    delete[] e;
    return 0;
}

void view(double **a, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void random(double **a, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = (double)rand()/(double) RAND_MAX*2 - 1;
        }
    }
}

double ** createArray(int n, int m){
    double **a = new double*[n];
    for(int i = 0; i < n; i++){
        a[i] = new double[m];
    }
    return a;
}

double a_to_b(double a, double b){
    return (a + b - 1 > 1) ? 1 : a + b - 1;
}

double a_and_b(double a, double b){
    return (a + b - 1 > 0) ? a + b - 1  : 0;
}

double f(double a, double b, double e){
    return a_to_b(a, b)*(2*e - 1)*e + a_to_b(a, b)*(1 + 4*e*a_to_b(a, b))*(1 - e);
}

double d(double a, double b){
    return a_and_b(a, b);
}