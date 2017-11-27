#include "SafePrime.h"
#pragma warning(disable: 4800)


//define function modular exponentiation to be used in factoring
ll f(ll a, ll b, ll c) //this function = a^b (mod c) or a^b is congruent to f(a,b,c) (mod c)
{
	if (b == 0) return 1;
	if (b % 2 == 1) return (a*f(a, b - 1, c)) % c;
	ll d = f(a, b / 2, c);
	return (d*d) % c;
}

ll fermat(ll p, ll a)
{//  Computes a^(p-1) mod p.
	a = 2;
	ll t = f(a, p - 1, p);
	if (t == 1) {
		return 1; //is a prime
	}
	else {
		return 0; //is not a prime
	}
}

/*bool isSafePrime(ll x, ll a) {
	ll y;
	a = 2;

	if (fermat(x, a) == 1) {
		y = (2 * x) + 1;
		if ((fermat(x, a) == 1) && (fermat(y, a) == 1)) { //check if both are prime
			cout << y << '\n';
		}
	}
	else {
		return false;
		}
}*/

int main() {
	ll num, y, a = 2;
	
	cout << "Enter num-";
	cin >> num;

	for (ll x = num; x < (num*num); x+=12) {
		if (fermat(x, a) == 1) {
			y = (2 * x) + 1;
			if ((fermat(y, a) == 1)) { //check if both are prime
				cout << y << '\n';
			}
		}
	}
	system("pause");
}
