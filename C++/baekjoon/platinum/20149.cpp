#include<iostream>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
void query(pair<double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d) {
	double p = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);
	if (p == 0) {
		if (b == c && a <= c) cout << b.x << " " << b.y << "\n";
		else if (a == d && c <= a) cout << a.x << " " << a.y << "\n";
	}
	else {
		double meet_x = ((a.x * b.y - a.y * b.x) * (c.x - d.x) - (a.x - b.x) * (c.x * d.y - c.y * d.x)) / p;
		double meet_y = ((a.x * b.y - a.y * b.x) * (c.y - d.y) - (a.y - b.y) * (c.x * d.y - c.y * d.x)) / p;
		cout << fixed;
		cout.precision(9);
		cout << meet_x << " " << meet_y;
	}
}

double ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
	double tmp = a.x * b.y + b.x * c.y + c.x * a.y;
	tmp -= b.x * a.y + c.x * b.y + a.x * c.y;
	if (tmp > 0) return 1;
	else if (tmp == 0) return 0;
	else if (tmp < 0) return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pair<double, double> a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

	if (ccw(a, b, c) * ccw(a, b, d) == 0 && ccw(c, d, a) * ccw(c, d, b) == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (a <= d && c <= b) {
			cout << 1 << "\n";
			query(a, b, c, d);
		}
		else cout << 0 << "\n";
	}
	else {
		if (ccw(a, b, c) * ccw(a, b, d) <= 0 && ccw(c, d, a) * ccw(c, d, b) <= 0) {
			cout << 1 << "\n";
			query(a, b, c, d);
		}
		else cout << 0 << "\n";
	}
}