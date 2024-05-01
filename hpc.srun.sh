#!/bin/bash

# Parallelized Numerical Integral Computation for Binghamton University CS 547.
# see: https://cs.binghamton.edu/~kchiu/cs447/assign/3/
#
# author: Gregory Maldonado
# email : gmaldonado@cs.binghamton.edu
# date  : 2024-04-30
# web   : https://cs.binghamton.edu/~gmaldonado/
#
# Graduate student @ Thomas J. Watson College of Engineering and Applied
# Sciences, Binghamton University.

# hpc.srun.sh -
# utility script for running this computation in SLURM workload (srun).

stamp=$(date +"%y%m%dT%T")

#SBATCH -A gmaldonado
#SBATCH --job-name=gmaldonado-integrate
#SBATCH --output="integrate-$stamp.out"
#SBATCH --time=00:05:00
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=16
#SBATCH --mem-per-cpu=500

if [ -e $(pwd)/build/integrate ]; then
  srun $(pwd)/build/integrate $@
fi