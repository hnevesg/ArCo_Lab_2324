### Code parallelization issues
Without making any change, the atomic directive did not work as expected when applied in two consecutive lines. Moreover, the reduction directive did not work either since it must be used for a single variable, not controlling the summation of both, sum and xi.
