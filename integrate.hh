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

#include <random>
#include <cmath>
#include <cstdint>
#include <cstddef>
#include <functional>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <future>
#include <chrono>
#include <thread>

//==================================================================== 80 ====>>

/**
 * Function that will be integrated in this Monte Carlo Simulation.
 */
inline double fnx(const double x) {
   return std::sin(x) / x;
}

/**
 * Entry point function for the integration calculator. Depending on number of
 * threads passed into the function, either st_integrate (Single Threaded) or
 * mt_integrate (Multi Thread) is called. While mt_integrate could handle both
 * implementations, a separate sequential approach is desired by this design.
 *
 * The function that will be integrate:
 *
 *                       f(x) = sin(x) / x
 *
 * @param lower_bound Definite integral lower bound value
 * @param upper_bound Definite integral upper bound value
 * @param samples     Number of samples to in the Monte Carlo computation method
 * @param threads     Number of threads to spawn to compute the simulation
 * @return An approximated integral value for the given function
 */
double integrate(double       lower_bound,
                 double       upper_bound,
                 unsigned int samples,
                 unsigned int threads);

/**
 * Single Threaded integration computation. Uses the Monte Carlo integration
 * method to approximate the integral value of the given function.
 *
 * See #integrate for the function that will be integrated.
 *
 * @param lower_bound Lower bound value of the definite integral
 * @param upper_bound Upper bound value of the definite integral
 * @param samples     Number of samples to in the Monte Carlo computation method
 * @return An approximated integral value for the given function
 */
double st_integrate(double       lower_bound,
                    double       upper_bound,
                    unsigned int samples);

/**
 * Multi Threaded integration computation. Uses the Monte Carlo integration
 * method to approximate the integral value of the given function.
 *
 * See #integrate for the function that will be integrated.
 *
 * @param lower_bound Lower bound value of the definite integral
 * @param upper_bound Upper bound value of the definite integral
 * @param samples     Number of samples to in the Monte Carlo computation method
 * @param threads     Number of threads to spawn to compute the simulation
 * @return An approximated integral value for the given function
*/
double mt_integrate(double       lower_bound,
                    double       upper_bound,
                    unsigned int samples,
                    unsigned int threads);

//==================================================================== 80 ====>>