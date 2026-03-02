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
            throw std::invalid_argument( "Negative input not allowed." );

        if ( num > 92 )
            throw std::overflow_error( "Result would overflow." );

        if ( num <= 1 )
            return num;

        big_number prev = 0;
        big_number curr = 1;

        for ( int i = 2; i <= num; ++i )
        {
            big_number next = prev + curr;
            prev = curr;
            curr = next;
        }

        return curr;
    }
} // hw03
// csc232
