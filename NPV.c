// Maria Kaninia, Dec 2013
// Tutorial for course in finance
// ........1: Calculation of Net Present Value
// beware: non-optimised code
// goal: explain the principles - not teach programming

// to compile:
// gcc -Wall NPV.c -o NPV

#include <stdio.h>
#include <math.h>

float calc_npv(float *cf, float r, int n);

int main() {
	float r = 0.2; // interest rate
	
	// array of cash-flows, years 1 to 4
	float cf[4] = {2.0, 1.9, 2.1, 2.0};
	
	// length of array
	int n = sizeof(cf)/sizeof(cf[0]);
	
	float npv; // net present value of cash-flows
	npv = calc_npv(cf, r, n);
	
	printf("NPV of array [");
	int i;
	for (i = 0; i < n; i++) {
		printf("%.1f ", cf[i]);
	}
	printf("] with discount factor %.1f is [%.1f]", r, npv);
	
	return 0;
}

float calc_npv(float *cf, float r, int n) {
	int j;
	float npv = 0;
	for (j = 0; j < n; j++) {
		npv += cf[j]/pow(1+r,j);
	}
	return npv;	
}