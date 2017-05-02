// Maria Kaninia, Dec 2013
// Tutorial for course in finance
// ........2: Bonds: 
// beware: non-optimised code
// goal: explain the principles - not teach programming

/*
What is the value of a bond that pays annual coupon C,
has a face value F, and expires T years from now?
Typically, the annually payable coupon C is calculated as a percentage of F.
Assume the interest rate required for calculating the Net Present Value (NPV) is r
*/

// to compile:
// gcc -Wall BOND.c -o BOND

#include <stdio.h>
#include <math.h>

// function declaration
float calc_npv(float *cf, float r, int n);

int main() {
	float r = 0.09; // interest rate
	float c = 0.10; // coupon payment (as a fraction of face value)
	int T = 3; // years until maturity
	float F = 100; // face value of bond	
		
	// array of cash-flows receivable, years 1 to T
	float cf[T];
	
	int j;
	for (j = 0; j < T; j++) {
		// every year, the bond-holder receives a payment corresponding to the coupon
		cf[j] = c*F;
	}
	// in the last period, the face value is paid out to the bond-holder
	// in addition to the last coupon payment
	cf[T-1] += F;
		
	// length of array
	int n = sizeof(cf)/sizeof(cf[0]);
	
	float npv; // net present value of cash-flows
	npv = calc_npv(cf, r, n);
	
	printf("NPV of array [");
	int i;
	for (i = 0; i < n; i++) {
		printf("%.1f ", cf[i]);
	}
	printf("] with discount factor %.2f is [%.1f]", r, npv);
	
	// if the price of the bond in the secondary market is less than the calculated npv,
	// then the bond is underpriced (however, expectation regarding the future evolution of interest rates play a role as well)
	
	return 0;
}

// function definition
float calc_npv(float *cf, float r, int n) {
	int j;
	float npv = 0;
	for (j = 0; j < n; j++) {
		float term = cf[j]/pow(1+r,1+j);		
		npv += term;
	}
	return npv;	
}