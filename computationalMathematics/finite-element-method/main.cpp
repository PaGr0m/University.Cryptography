#include <QCoreApplication>
#include <QVector>
#include <QtMath>
#include <QDebug>

#include <iomanip>
#include <iostream>

using namespace std;

void showTable(QVector<double> u,
               QVector<double> f)
{
    cout << "+--------+-----------+" << endl;
    cout << "| Point  |   Value   |" << endl;
    cout << "+--------+-----------+" << endl;
    for (int i = 0; i < u.size(); i++)
        cout << "| u[" << setw(3) << i << "] | " << setw(10) << u.at(i) << "|" << endl;
    cout << "+--------+-----------+" << endl;
    cout << endl << endl;

    cout << "+-------+-------+" << endl;
    cout << "|     Check     |" << endl;
    cout << "+-------+-------+" << endl;
    cout << "| Func  | Value |" << endl;
    cout << "+-------+-------+" << endl;
    for (int i = 0; i < f.size(); i++)
        cout << "| f[" << setw(2) << i << "] |   " << f.at(i) << "   |" << endl;
    cout << "+-------+-------+" << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    const double a = 1;
    const double b = 1;
    const double h = 0.01;

    const int N = 1.0/h;

    QVector<double> u(N+1);
    QVector<double> f(N);

    u[0] = a;
    u[1] = u[0] + h*b;

    for (int i = 1; i < N; i++)
    {
        double x = i*h;

        u[i+1] = 2 * qPow(h, 2);
        u[i+1] += (u[i] * (4 - 2 * qPow(h, 2) * qCos(x)));
        u[i+1] += (u[i-1] * (h * qSin(x) - 2));

        u[i+1] /= (2 + h * qSin(x));
    }

//    for (int i = 0; i < N+1; i++)
//        qDebug() << i << ") " << u[i];

    f[0] = 1;
    for (int i = 1; i < N; i++)
    {
        double x = i*h;

        f[i] = (qCos(x) * u[i]);
        f[i] += (qSin(x) * ((u[i+1]-u[i-1])/(2*h)));
        f[i] += (u[i+1] - 2*u[i] + u[i-1])/qPow(h, 2);
    }

//    for (int i = 0; i < N; i++)
//        qDebug() << i << ") " << f[i];

    showTable(u, f);

    return app.exec();
}
