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

git_root=$(git worktree list | cut -d' ' -f1)
stamp=$(date +"%y%m%dT%T")

#SBATCH -A gmaldonado
#SBATCH --job-name=gmaldonado-integrate
#SBATCH --output="integrate-$stamp.out"
#SBATCH --time=00:05:00
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=32
#SBATCH --mem-per-cpu=500

if [ -e "$git_root"/build/integrate ]; then
  srun $(pwd)/build/1brc $@
fi