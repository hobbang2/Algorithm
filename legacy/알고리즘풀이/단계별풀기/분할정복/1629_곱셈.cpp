#include <cstdio>


long long calPow(long long given, long long numOfMult,long long mod) {
	if (numOfMult == 1) {
		return (given % mod);
	}
	long long tmp = calPow(given, numOfMult / 2, mod);
	if (numOfMult % 2 == 0) {
		return ((tmp%mod) * (tmp%mod)) % mod;
	}
	else {
		return ((((tmp%mod) * (tmp%mod)) % mod)*given) % mod;
	}
}


int main() {
	long long A = 0, B = 0, C = 0;
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld\n",calPow(A % C, B, C));
	return 0;
}