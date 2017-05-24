#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ofstream cout ("planar_equation.txt");
	srand(0);
	int a, b, c;
	for (int i = 0; i < 100; i++) {
		a = rand() % 20;
		b = rand() % 20;
		c = rand() % 20;
		cout << a << " " << b << " " << c;
		if (i < 50) cout << " " << (5 * a) + (3 * b) - (4 * c);
		cout << "\n";
	}
	return 0;
}