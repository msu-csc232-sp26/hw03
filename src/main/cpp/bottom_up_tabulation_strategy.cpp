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
        {
            throw std::invalid_argument( "num must be non-negative" );
        }

        if ( num > UPPER_LIMIT )
        {
            throw std::overflow_error( "requested fibonacci index exceeds 64-bit range" );
        }

        
        if ( num <= 1 )
        {
            return num;
        }

     
        std::vector<big_number> dp( static_cast<std::size_t>( num ) + 1 );
        dp.at( 0 ) = 0;
        dp.at( 1 ) = 1;

        for ( int i = 2; i <= num; ++i )
        {
            dp.at( i ) = dp.at( i - 1 ) + dp.at( i - 2 );
        }

        return dp.at( num );
    }
} // hw03
// csc232
