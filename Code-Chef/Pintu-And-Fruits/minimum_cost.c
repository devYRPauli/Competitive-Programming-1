/*
 * Problem Statement: https://www.codechef.com/MARCH20B/problems/CHPINTU
 * Author: striker
 *
 * Copyright 2020 striker
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

typedef struct Point2D {
    int x, y;
} point_2d;

#define MOD (1000000000 + 7) // Prime Number
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define SCANF_READ_ERROR(return_val) fprintf(stderr, "Line number: %u: scanf() read error!\nExpected-Return-Value: %d\n", __LINE__, return_val); exit(0)
#define INITIALISE_INT_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define INITIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '0', (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

// The below function macros refers to the GCC functions for doing computation directly on the bit-level of a number.
#define COMPUTE_SET_BITS(number) __builtin_popcountll(number) // Returns the number of set-bits in number (unsigned long long).
#define COMPUTE_PARITY(number) __builtin_parityll(number) // Returns the parity of the number (unsigned long long) i.e. True if 1's are odd else False.
#define COUNT_LEAD_ZEROES(number) __builtin_clzll(number) // Returns the count of lead zeroes before first set-bit from MSB in number (unsigned long long).
#define COUNT_TRAIL_ZEROES(number) __builtin_ctzll(number) // Return the count of trailing zeroes in number(unsigned long long).

#define TOTAL_FRUIT_TYPE 50
#define TOTAL_PRICE_NONEXISTENCE_BASKET -1

static void take_input_array(int[], const int);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("test-cases/test-case-1.in", "r", stdin);
        freopen("test-cases/test-case-1.out", "w", stdout);
    #endif
    int test;
    if(1 == scanf("%d", &test)) {
        if(test < 1) {
            CONSTRAINTS_OUT_OF_BOUND_ERROR(test, test value cannot be 0 or -ve);
            exit(0);
        }
        while(test--) {
            int n, m;
            if(2 == scanf("%d%d", &n, &m)) {
                int basket_config[n], basket_price[n];
                take_input_array(basket_config, n);
                take_input_array(basket_price, n);
                int basket_type_tot_price[TOTAL_FRUIT_TYPE];
                memset(basket_type_tot_price, TOTAL_PRICE_NONEXISTENCE_BASKET, TOTAL_FRUIT_TYPE * sizeof(int));
                for(register int i = 0; i < n; ++i) {
                    if(TOTAL_PRICE_NONEXISTENCE_BASKET == basket_type_tot_price[basket_config[i] - 1]) {
                        basket_type_tot_price[basket_config[i] - 1] = 0;
                    }
                    basket_type_tot_price[basket_config[i] - 1] += basket_price[i];
                }
                int min_price = INT_MAX;
                for(register int i = 0; i < TOTAL_FRUIT_TYPE; ++i) {
                    if(TOTAL_PRICE_NONEXISTENCE_BASKET != basket_type_tot_price[i] && basket_type_tot_price[i] < min_price) {
                        min_price = basket_type_tot_price[i];
                        continue;
                    }
                }
                printf("%d\n", min_price);
            } else {
                SCANF_READ_ERROR(2);
            }
        }
    } else {
        SCANF_READ_ERROR(1);
    }
    return EXIT_SUCCESS;
}

static void take_input_array(int sequence[], const int n) {
    for(register int i = 0; i < n; ++i) {
        scanf("%d", sequence + i);
    }
}
