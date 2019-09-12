#include <iostream>
using namespace std;
class fraction {
public:
	int den;//·Ö×Ó
	int num;//·ÖÄ¸
	fraction(int d, int n) {
		den = d;
		num = n;
	}
	friend ostream& operator <<(ostream&, fraction);
};
ostream &operator <<(ostream& os, fraction fr) {
	cout << fr.den << '/' << fr.num;
	return os;
}
int main() {
	int den, num;
	cin >> den >> num;
	fraction fr(den, num);
	cout << fr << endl;
	return 0;
}