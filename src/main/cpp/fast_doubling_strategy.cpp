/**
 * @file    fast_doubling_strategy.cpp
 * @brief   Fast doubling strategy implementation.
 *
 * @authors James R. Daehn <jdaehn@missouristate.edu>
 *          Prajjwol B. Rana <prajjwol4062@missouristate.edu>
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
    auto fast_doubling_strategy::fib_pair( const big_number number ) -> std::pair<big_number, big_number>
    {
        if ( number == 0 )
            return { 0, 1 };
        auto [ a, b ] = fib_pair( number / 2 );
        big_number c = a * ( 2 * b - a );
        big_number d = a * a + b * b;
        if ( number % 2 == 0 )
            return { c, d };
        else
            return { d, c + d };
    }

    auto fast_doubling_strategy::compute( const int num ) const -> big_number
    {
        if ( num < 0 )
            throw std::invalid_argument{ "n must be non-negative" };
        if ( num > 92 )
            throw std::overflow_error{ "overflow for n>92" };
        return fib_pair( num ).first;
    }

} // hw03
// csc232
