/**
 * @file    fast_doubling_strategy.h
 * @brief   Fast doubling strategy specification.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn
 */

#ifndef HW03_SOLUTION_FAST_DOUBLING_STRATEGY_H
#define HW03_SOLUTION_FAST_DOUBLING_STRATEGY_H

#include "fibonacci_strategy.h"

#include <utility>

namespace csc232::hw03
{
    /**
     * A computational model for computing the nth Fibonacci number using the fast doubling,
     * divide and conquer approach.
     */
    class fast_doubling_strategy : public fibonacci_strategy
    {
    public:
        /**
         * @copydoc fibonacci_strategy::compute
         * @note This strategy employs a fast doubling, divide and conquer approach.
         */
        [[nodiscard]] auto compute( int num ) const -> big_number override;

    private:
        static auto fib_pair( big_number number ) -> std::pair<big_number, big_number>;
    };

} // hw03
// csc232

#endif // HW03_SOLUTION_FAST_DOUBLING_STRATEGY_H
