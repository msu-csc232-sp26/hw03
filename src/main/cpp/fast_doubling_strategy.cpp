/**
 * @file    fast_doubling_strategy.cpp
 * @brief   Fast doubling strategy implementation.
 *
 * @authors James R. Daehn <jdaehn@missouristate.edu>
 *          // TODO: Add your name using the above format
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn
 */

#include "fast_doubling_strategy.h"

#include <stdexcept>

namespace csc232::hw03
{
    // TODO: Task 5 - Implement me (both member functions need an updated implementation)
    auto fast_doubling_strategy::fib_pair( const big_number number ) -> std::pair<big_number, big_number>
    {
        return std::pair{ number, number };
    }


    auto fast_doubling_strategy::compute( const int num ) const -> big_number
    {
        return fib_pair( num ).first;
    }

} // hw03
// csc232