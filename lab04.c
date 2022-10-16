// EE2310 Lab04. Pythagorean Triples
// 111061106, ¦ó¦t«í
// Date: Oct. 15, 2022
#include <stdio.h>

// Dickson's method is used in this algorithm. Explanation is
// after the main function

int main(void)
{
    int r = 2, s_0, s, t, k; // parameters used in Dickson's
    // method, assisting variant s_0, variant k to find the
    // multiple of primitive triples
    int N, n, tmp, tp, round = 0, cnt = 0;  // variants that
    // help co-prime-checking, set boundaries, switch methods,
    // and count the sets

    do {                    // plug in different numbers for r
        round = 0;          // initialize round to 0
        s_0 = 1; s = s_0 * s_0; // initialize s using s_0
        t = r * r / 2 / s;  // find the t for that s

        do {                // plug in different sets of s, t
            tp = N = t; n = s;  // set up variants used in co-
            // prime checking and used as the boundary

            while (n > 1){  // check if s, t are co-prime
                            // using Euclidean algorithm
                N -= n * (N / n);
                tmp = N; N = n; n = tmp;
            }

            if (n){         // if n == 1, s and t are co-prime
                for (k = 1; k * (r + s + t) <= 20000; k++){
                            // find the multiples of the triple
                            // under 20000

                    if (t < s){ // eliminate cases of a > b
                        printf("Pythagorean Triple #%d", ++cnt);
                        printf(" is (%d, %d, %d)\n", (r + t) *
                               k, (r + s) * k, (r + s + t) * k);
                    }
                    else {      // print normal cases
                        printf("Pythagorean Triple #%d", ++cnt);
                        printf(" is (%d, %d, %d)\n", (r + t) *
                               k, (r + s) * k, (r + s + t) * k);
                    }
                }
            }


            if (round) {        // find the next set of s, t if
                                // the number of rounds
                                // completed is odd
                s_0 += 1; s = s_0 * s_0;
                                // s is a square number
                while ((r * r / 2) % s && s_0 < r){
                                // if s is not a factor of r *
                                // r / 2, find the next s
                    s_0 += 1; s = s_0 * s_0;
                }
                t = r * r / 2 / s;
                round = 0;
            }
            else {              // the number of rounds
                                // completed is even
                s *= 2;         // the extra "2" is on s now
                t = r * r / 2 / s;
                round = 1;
            }
        } while (s != tp);      // leave when all sets of legit
                                // s, t are tried
        r += 2;                 // r is the next even number
    } while (r < 20000 / 2);

    printf("Total number of Pythagorean triples found is %d\n",
           cnt);                // print the total number of
                                // triples found

    return 0;
}

// Dickson's method: r is an even number, r * r = 2 * s * t
// a = r + s, b = r + t, c = r + s + t
// If s and t are co-prime, the triple found is primitive
// To make them co-prime, one of s, t must be a square number,
// and the other would be a square number * 2 (the extra "2")
// It's not necessary to find all even r < 20000,
// and when r is large enough, 20000 / 2 is a legit boundary
