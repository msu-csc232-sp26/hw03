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
            throw std::invalid_argument( "Negative input not allowed." );

        if ( num > 92 )
            throw std::overflow_error( "Result would overflow." );

        if ( num <= 1 )
            return num;

        std::vector<big_number> table( num + 1 );
        table[ 0 ] = 0;
        table[ 1 ] = 1;

        for ( int i = 2; i <= num; ++i )
            table[ i ] = table[ i - 1 ] + table[ i - 2 ];

        return table[ num ];
    }
}

// csc232
