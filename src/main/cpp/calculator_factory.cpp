/**
 * @file    calculator_factory.h
 * @brief   Calculator factory implementation.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#include "calculator_factory.h"

namespace csc232::hw03
{
    auto calculator_factory::create( const compute_strategy strategy ) -> fibonacci_calculator
    {
        // Use a strategy factory for creating the computational model needed by this
        // Fibonacci calculator.
        return fibonacci_calculator( strategy_factory::create( strategy ) );
    }
} // hw03
// csc232