//
//  spoj07718.cpp
//
//
//  Created by 赵洋 on 15/10/17.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#define capacity 1000

using namespace std;

int gcd(int m, int n)     	// function definition
{                         	// block begin
    int  r;                	// declaration of remainder
    
    while (n != 0) {       	// not equal
        r = m % n;          	// modulus operator
        m = n;              	// assignment
        n = r;
    }                      	// end while loop
    return m;              	// exit gcd with value m
}


void next_prime(vector<int>& primes){
    int size = primes.size();
    int num = primes[size - 1] + 2;
    while(true){
        bool flag = true;
        int temp = num*num;
        for(int i = 0; i < size && temp > primes[i]; ++i){
            if(num % primes[i] == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            primes.push_back(num);
            return;
        } else {
            num += 2;
        }
    }
}

int main(){
    // build a prime vector
    vector<int> primes;
    primes.reserve(capacity);
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    
    int T;
    scanf("%d", &T);
    while(T--){
        int a, b, min;
        scanf("%d%d", &a, &b);
        min = sqrt(gcd(a, b));
        int product = 1, count = 0, i = 0;
        while(true){
            if(a % primes[i] == 0 && b % primes[i] == 0){
                ++count;
                a /= primes[i];
                b /= primes[i];
                if(a == 1 || b == 1){
                    product = product * (count + 1);
                    break;
                }
            } else {
                product = product * (count + 1);
                ++i;
                if(i >= primes.size()){
                    next_prime(primes);
                    if(primes.back() > min)
                        break;
                }
                count = 0;
            }
        }
        
        printf("%d\n", product);
    }
}