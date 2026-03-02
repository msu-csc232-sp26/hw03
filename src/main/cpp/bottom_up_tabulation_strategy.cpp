/**
 * @file    bottom_up_tabulation_strategy.cpp
 * @brief   Bottom-up tabulation strategy implementation.
 *
 * @authors James R. Daehn <jdaehn@missouristate.edu>
 *          // TODO: Add your name using the above format
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#include "bottom_up_tabulation_strategy.h"

#include <stdexcept>
#include <vector>

namespace csc232::hw03
{
    auto bottom_up_tabulation_strategy::compute( const int num ) const -> big_number
    {
        if ( num < 0 )
            throw std::invalid_argument{ "n must be non-negative" };
        if ( num > 92 )
            throw std::overflow_error{ "overflow for n>92" };
        if ( num <= 1 )
            return num;
        std::vector<big_number> dp( num + 1 );
        dp.at( 0 ) = 0;
        dp.at( 1 ) = 1;

        for ( int i = 2; i <= num; ++i )
            dp.at( i ) = dp.at( i - 1 ) + dp.at( i - 2 );

        return dp.at( num );
    }
} // hw03
// csc232
