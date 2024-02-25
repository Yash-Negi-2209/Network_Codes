#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

int cross_product(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) {
        return 0;
    } else if (val < 0) {
        return -1;
    } else {
        return 1;
    }
}

bool is_inside_polygon(vector<Point>& polygon, Point p) {
    int n = polygon.size();
    int sign = cross_product(polygon[0], polygon[1], p);
    for (int i = 1; i < n; i++) {
        int curr_sign = cross_product(polygon[i], polygon[(i+1)%n], p);
        if (curr_sign != sign) {
            return false;
        }
    }
    return true;
}

vector<Point> convex_hull(vector<Point>& points) {
    int n = points.size();
    if (n <= 1) {
        return points;
    }
    sort(points.begin(), points.end(), [](Point a, Point b) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    });
    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && cross_product(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    int t = hull.size() + 1;
    for (int i = n-2; i >= 0; i--) {
        while (hull.size() >= t && cross_product(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    hull.pop_back();
    return hull;
}

int main() {
    vector<Point> polygon = {{0, 0}, {0, 4}, {4, 4}, {4, 0}};
    Point p = {2, 2};
    if (is_inside_polygon(polygon, p)) {
        cout << "Point is inside polygon" << endl;
    } else {
        cout << "Point is outside polygon" << endl;
    }
    vector<Point> points = {{0, 0}, {0, 4}, {4, 4}, {4, 0}, {2, 2}};
    vector<Point> hull = convex_hull(points);
    cout << "Convex hull points: ";
    for (auto h : hull) {
        cout << "(" << h.x << "," << h.y << ") ";
    }
    cout << endl;
    return 0;
}