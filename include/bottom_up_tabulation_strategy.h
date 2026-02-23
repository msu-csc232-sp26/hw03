/**
 * @file    bottom_up_tabulation_strategy.h
 * @brief   Bottom-up tabulation strategy specification
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#ifndef HW03_SOLUTION_BOTTOM_UP_TABULATION_STRATEGY_H
#define HW03_SOLUTION_BOTTOM_UP_TABULATION_STRATEGY_H

#include "fibonacci_strategy.h"

namespace csc232::hw03
{
    /**
     * A computational model for computing the nth Fibonacci number using a bottom-up (tabulation) approach.
     */
    class bottom_up_tabulation_strategy : public fibonacci_strategy
    {
    public:
        /**
         * @copydoc fibonacci_strategy::compute
         * @note This strategy employs a bottom-up dynamic programming solution that uses tabulation.
         */
        [[nodiscard]] auto compute( int num ) const -> big_number override;
    };

} // hw03
// csc232

#endif // HW03_SOLUTION_BOTTOM_UP_TABULATION_STRATEGY_H
