/**
 * @file    iterative_strategy.h
 * @brief   Iterative strategy specification.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#ifndef HW03_SOLUTION_ITERATIVE_O1_STRATEGY_H
#define HW03_SOLUTION_ITERATIVE_O1_STRATEGY_H

#include "fibonacci_strategy.h"

namespace csc232::hw03
{

    /**
     * A computational model for computing the nth Fibonacci number using an iterative approach.
     */
    class iterative_strategy : public fibonacci_strategy
    {
    public:
        /**
         * @copydoc fibonacci_strategy::compute
         * @note This strategy employs simple iteration.
         */
        [[nodiscard]] auto compute( int num ) const -> big_number override;
    };

} // hw03
// csc232

#endif // HW03_SOLUTION_ITERATIVE_O1_STRATEGY_H
