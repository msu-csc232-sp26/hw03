/**
 * @file    strategy_factory.h
 * @brief   Strategy factory specification.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#ifndef HW03_SOLUTION_STRATEGY_FACTORY_H
#define HW03_SOLUTION_STRATEGY_FACTORY_H
#include "fibonacci_strategy.h"

#include <memory>
#include <string>

namespace csc232::hw03
{
    /**
     * Enumerate the computational strategies used by the fibonacci calculators.
     */
    enum class compute_strategy
    {
        BOTTOM_UP, // dynamic programming approach using tabulation
        ITERATIVE, // constant-time, iterative solution
        NAIVE,     // naive, recursive approach
        TOP_DOWN   // dynamic programming approach using memoization
    };

    /**
     * A factory for generating computational strategies for computing the nth Fibonacci number.
     */
    class strategy_factory
    {
    public:
        /**
         * @brief Creates a strategy for computing the nth Fibonacci number.
         * @param strategy the computational model to create.
         * @return a strategy for finding the nth Fibonacci number.
         */
        static auto create( compute_strategy strategy ) -> std::unique_ptr<fibonacci_strategy>;
    };

}

#endif // HW03_SOLUTION_STRATEGY_FACTORY_H
