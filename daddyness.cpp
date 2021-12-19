/*This script checks the pseudo-daddyness of numbers.(compiled in c++14)
A number N is daddy if the following conditions are met:

1) The sum of its digits S and the alternating sum of its digits A are both primes (requiring A to be positive)
2) Some concatenation of the primes that factor (S+A) is equal to N.

Pseudo-daddies only obey rule 2.

Example: 52 is a daddy number:
S = 5+2 = 7
A = 5-2 = 3
S+A = 7+3 = 10 = 2*5
conc(S+A) = [25 , 52]

The conjecture is that 52 is the only daddy number. This program tests up to 10 millions, and no other example was found.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define UPTO 10'000'000
#define MAXN 130 // this is for prime factorisation of S+A, which can't go further than 9*2*7 (S+S for n=9'999'999)

typedef unsigned long num;
typedef std::vector<num> vec;

// C++ class to find prime factorization of a 
// number n in O(Log n) time with precomputation 
// allowed. 
class Primefac
{
public:
    Primefac();
    // A O(log n) function returning primefactorization 
    // by dividing by smallest prime factor at every step 
    vec operator()(num x);

private:
    // Calculating SPF (Smallest Prime Factor) for every 
    // number till MAXN. 
    // Time Complexity : O(nloglogn) 
    void sieve();

    vec spf;// stores smallest prime factor for every number 
};

// Sum and alternating sum of the digits of n
// Time complexity: O( (log n)^2 )
long digitsum(num n, bool alternate=false);

// All the concatenations of a list of numbers
// Time complexity: O(N^2) (N will typically be O(log n), for the number of prime factors of n)
vec conc(vec lon);

//main

int main()
{
    Primefac primefac{};
    for(num n{2} ; n < UPTO ; n++)
    {
        if(!(n%1'000'000)) std::clog << "Tested up to n = " << n/1'000'000 << " millions" << std::endl;
        long S{digitsum(n)};
        long A{digitsum(n,true)};

        vec ans{conc(primefac(S+A))};
        for(num m : ans)
            if(m == n)
                std::cout << n << std::endl;
    }

    return EXIT_SUCCESS;
}

//other functions

Primefac::Primefac() {sieve();}

vec Primefac::operator()(num x)
{ 
    vec ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x];
    } 
    return ret; 
}

void Primefac::sieve() 
{ 
    spf.push_back(0); spf.push_back(1); 
    for (num i{2}; i<MAXN; i++) 
 
        // marking smallest prime factor for every 
        // number to be itself. 
        spf.push_back(i); 
  
    // separately marking spf for every even 
    // number as 2 
    for (num i{4}; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (num i{3}; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (num j{i*i}; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

long digitsum(num n, bool alternate)
{
    vec S{};//every digit
    long s{0};//the sum
    num d{0};//the number of digits

    //calculating highest digit position
    if(n == 0) d = 0;
    else d = 1+std::floor(std::log10(n));

    while(d > 0)//isolating digits
    {
        d--;
        S.push_back(std::floor(n/std::pow(10,d)));
        n -= S.back()*std::pow(10,d);
    }

    for(num i{0} ; i < S.size() ; i++)
    {
        if(alternate) s += (1 - 2*(i&1))*S.at(i);
        else s += S.at(i);
    }
    return s;
}

vec conc(vec lon)
{
    vec r{};
    std::sort(lon.begin(),lon.end());
    do{
        r.push_back(0);
        for(num n : lon)
        {
            num d{0};
            if(r.back() == 0) d = 0;
            else d = 1+std::floor(std::log10(r.back()));

            r.back() += std::pow(10,d)*n;//we concatenate from right to left.
        }
    } while(std::next_permutation(lon.begin(),lon.end()));

    return r;
}

