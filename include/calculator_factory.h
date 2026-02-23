/**
 * @file    calculator_factory.h
 * @brief   Calculator factory specification.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#ifndef HW03_SOLUTION_CALCULATOR_FACTORY_H
#define HW03_SOLUTION_CALCULATOR_FACTORY_H

#include "fibonacci_calculator.h"
#include "strategy_factory.h"

namespace csc232::hw03
{
    /**
     * A factory for creating a fibonacci calculator that employs a given compute strategy.
     */
    class calculator_factory
    {
    public:
        /**
         * @brief Creates a fibonacci calculator that uses a particular computational model for computing the nth Fibonacci number.
         * @param strategy the computational model used to compute the nth Fibonacci number.
         * @return a fibonacci calculator that employs a particular computational model.
         */
        static auto create( compute_strategy strategy ) -> fibonacci_calculator;
    };

} // hw03
// csc232

#endif // HW03_SOLUTION_CALCULATOR_FACTORY_H
