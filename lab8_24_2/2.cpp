#include <iostream>
#include <vector>

using namespace std;

// Objective function (a.x^2 + b.x + c)
double f(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

void hillClimb(double a, double b, double c, double start, double step) {
    double current = start;
    vector<double> history;
    history.push_back(current);

    while (true) {
        double left_neighbor = current - step;
        double right_neighbor = current + step;

        double next_point = (f(a, b, c, left_neighbor) > f(a, b, c, right_neighbor)) ? left_neighbor : right_neighbor;

        if (f(a, b, c, next_point) <= f(a, b, c, current)) {
            break;
        }
        
        current = next_point;
        history.push_back(current);
    }

    cout << "Final Path: [";
    for (size_t i = 0; i < history.size(); ++i) {
        cout << history[i] << (i == history.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
}

int main() {
    double a, b, c, start, step;
    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;
    cout << "Enter starting point: ";
    cin >> start;
    cout << "Enter step size: ";
    cin >> step;

    hillClimb(a, b, c, start, step);
    cout << "23052247\nKush Singh\nCSE-22\n";
    return 0;
}

/*
    Output :
    Enter coefficient a: -1
    Enter coefficient b: 4
    Enter coefficient c: 0
    Enter starting point: 0
    Enter step size: 1
    Final Path: [0, 1, 2]
    23052247
    Kush Singh
    CSE-22
 */