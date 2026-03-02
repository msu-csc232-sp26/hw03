/**
 * @file    iterative_strategy.cpp
 * @brief   Iterative strategy implementation.
 *
 * @authors James R. Daehn <jdaehn@missouristate.edu>
 *          // TODO: Add your name using the above format
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn
 */

#include "iterative_strategy.h"

#include <stdexcept>

namespace csc232::hw03
{
    auto iterative_strategy::compute( const int num ) const -> big_number
    {

        if ( num < 0 )
            throw std::invalid_argument{ "n must be non-negative" };
        if ( num > 92 )
            throw std::overflow_error{ "overflow for n>92" };
        if ( num <= 1 )
            return num;

        big_number prev2 = 0;
        big_number prev1 = 1;
        for ( int i = 2; i <= num; i++ )
        {
            big_number cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

} // hw03
// csc232
