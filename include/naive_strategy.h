/**
 * @file    naive_strategy.h
 * @brief   Naive strategy specification.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#ifndef HW03_SOLUTION_NAIVE_FIBONACCI_STRATEGY_H
#define HW03_SOLUTION_NAIVE_FIBONACCI_STRATEGY_H

#include "fibonacci_strategy.h"

namespace csc232::hw03
{
    /**
     * A computational model for computing the nth Fibonacci number using a naive, recursive approach.
     */
    class naive_strategy : public fibonacci_strategy
    {
    public:
        /**
         * @copydoc fibonacci_strategy::compute
         * @note This strategy employs a naive, recursion implementation.
         */
        [[nodiscard]] auto compute( int num ) const -> big_number override;
    };

}

#endif // HW03_SOLUTION_NAIVE_FIBONACCI_STRATEGY_H
