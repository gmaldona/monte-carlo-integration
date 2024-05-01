/*
 * Parallelized Numerical Integral Computation for Binghamton University CS 547.
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

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <numeric>
#include <thread>
#include <functional>
#include "integrate.hh"

//==================================================================== 80 ====>>

const double integrate(const double       lower_bound, 
                       const double       upper_bound,
                       const unsigned int samples,
                       const unsigned int threads) {

   // https://stackoverflow.com/questions/2704521
   std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
   std::default_random_engine re;

   return (threads > 1) ? 
      mt_integrate(lower_bound, upper_bound, samples, threads, unif, re) :
      st_integrate(lower_bound, upper_bound, samples, unif, re);
}

const double st_integrate(const double       /*lower_bound*/,
                          const double       /*upper_bound*/,
                          const unsigned int samples,
                          std::uniform_real_distribution<double>& unif,
                          std::default_random_engine& re) {

   double approximation = 0.0;
   for (unsigned int sample = 0; sample < samples; ++sample) {
      approximation += fnx(unif(re));
   }

   return approximation / samples;
}

const double mt_integrate(const double       lower_bound,
                          const double       upper_bound,
                          const unsigned int samples,
                          const unsigned int threads,
                          std::uniform_real_distribution<double>& unif,
                          std::default_random_engine& re) {

   std::vector<double*> ret_values(threads);
   std::vector<std::thread> thread_vec;

   const unsigned int divided_samples = std::floor(samples / threads);

   // TODO: ahh implementation.
   auto computation = [&](const unsigned int samples,
                                                      double* ret) {
      double approximation = 0.0;
      for (unsigned int sample = 0; sample < samples; ++sample) {
         approximation += fnx(unif(re));
      }
      *ret = approximation;
   };

   for (unsigned int thread = 1; thread <= threads; ++thread) {
      ret_values[thread] = new double();

      if (thread == threads && samples % threads != 0) {
         thread_vec.emplace_back(computation,
                         divided_samples + samples % thread,
                         ret_values[thread]);
      } else {
         thread_vec.emplace_back(computation,
                         divided_samples,
                         ret_values[thread]);
      }
   }

   for (auto& thread : thread_vec) {
      thread.join();
   }

   double approximation = 0.0;
   for (auto& ret_value : ret_values) {
      approximation += *ret_value;
      delete ret_value;
   }

   return approximation / samples;
}

int main(int args, char** argv) {
   
   if (args != 5) {
      std::cout << "Expected arguments:" << std::endl;
      std::cout <<
      "lower_bound(Double) upper_bound(Double) samples(uint) threads(uint)" <<
      std::endl;
      return 1;
   }

   // https://stackoverflow.com/questions/13445688
   srand((unsigned) time(NULL));

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

//==================================================================== 80 ====>>