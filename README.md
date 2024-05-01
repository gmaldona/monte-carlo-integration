# Parallelized Numerical Integral Computation

CS 547 High Performance Computing @ Binghamton University

release date 2024-04-29 ([piazza](/))

## Results

* Single runs, increasing sample size / thread count for each run
* Performance testing for done on Binghamton University OpenHPC servers


## Submission
* Deadline: 
   * 2024-05-06 11:59PM

Last working commit:
   * [insert last commit before turning in assignment]

## Execution
Included within the repository is a [`Makefile`](/Makefile).

```shell
make && ./build/integrate [lower_bound] [upper_bound] [sample_size] [threads]
```

## Source

* https://cs.binghamton.edu/~kchiu/cs447/assign/3/