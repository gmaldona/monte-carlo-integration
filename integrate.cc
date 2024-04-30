/*
 * Parallized Numerical Integral Computation for Binghamton University CS 547.
 * see: https://cs.binghamton.edu/~kchiu/cs447/assign/3/
 *
 * author: Gregory Maldonado
 * email : gmaldonado@cs.binghamton.edu
 * date  : 2024-01-25
 * web   : https://cs.binghamton.edu/~gmaldonado/
 *
 * Graduate student @ Thomas J. Watson College of Engineering and Applied
 * Sciences, Binghamton University.
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <thread>
#include "integrate.hh"

const double integrate(const double       lower_bound, 
                       const double       upper_bound,
                       const unsigned int samples,
                       const unsigned int threads) {
   return (threads > 1) ? 
      mt_integrate(lower_bound, upper_bound, samples, threads) :
      st_integrate(lower_bound, upper_bound, samples);
}

const double mt_integrate(const double       lower_bound,
                          const double       upper_bound,
                          const unsigned int samples,
                          const unsigned int threads) {
   return 0.0;
}

const double st_integrate(const double       lower_bound,
                          const double       upper_bound,
                          const unsigned int samples) {
   return 0.0;
}

int main(int args, char** argv) {
   
   if (args != 5) {
      std::cout << "Expected arguments:" << std::endl;
      std::cout <<
      "lower_bound(Double) upper_bound(Double) samples(uint) threads(uint)" <<
      std::endl;
      return 1;
   }

   const double lower_bound   = std::stod(argv[1]);
   const double upper_bound   = std::stod(argv[2]);
   const unsigned int samples = std::stoi(argv[3]);
   const unsigned int threads = (strcmp(argv[4], "MAX") == 0) ?
      std::thread::hardware_concurrency() : std::stoi(argv[4]);

   std::cout << integrate(lower_bound,
                          upper_bound,
                          samples,
                          threads);
}