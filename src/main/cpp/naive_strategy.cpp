/**
 * @file    naive_strategy.cpp
 * @brief   Naive strategy implementation.
 *
 * @authors James R. Daehn <jdaehn@missouristate.edu>
 *          // TODO: Add your name using the above format
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#include "naive_strategy.h"
#include <stdexcept>

namespace csc232::hw03
{
    auto naive_strategy::compute( const int num ) const -> big_number
    {
        if ( num < 0 )
            throw std::invalid_argument{ "n must be non-negative" };
        if ( num > 92 )
            throw std::overflow_error{ " exceeds 64-bit signed range" };
        if ( num <= 1 )
            return static_cast<big_number>( num );
        return compute( num - 1 ) + compute( num - 2 );
    }
} // hw03
// csc232
