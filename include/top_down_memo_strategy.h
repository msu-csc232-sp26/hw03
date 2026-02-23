/**
 * @file    top_down_memo_strategy.h
 * @brief   Top-down (memoization) strategy specification.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#ifndef HW03_SOLUTION_TOP_DOWN_MEMO_STRATEGY_H
#define HW03_SOLUTION_TOP_DOWN_MEMO_STRATEGY_H

#include "fibonacci_strategy.h"
#include <vector>

namespace csc232::hw03
{

    /**
     * A computational model for computing the nth Fibonacci number using a top-down (memoization) approach.
     */
    class top_down_memo_strategy : public fibonacci_strategy
    {
    public:
        /**
         * @copydoc fibonacci_strategy::compute
         * @note This strategy employs a top-down dynamic programming solution that uses memoization.
         */
        [[nodiscard]] auto compute( int num ) const -> big_number override;

    private:
        /**
         * @breif Helper function supporting memoization.
         * @param num an index into the Fibonacci sequence.
         * @param memo a vector of previously computed Fibonacci numbers.
         * @return the nth Fibonacci number.
         */
        static auto helper( int num, std::vector<big_number> &memo ) -> big_number;
    };

} // hw03
// csc232

#endif // HW03_SOLUTION_TOP_DOWN_MEMO_STRATEGY_H
