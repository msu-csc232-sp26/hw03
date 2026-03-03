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
        {
            throw std::invalid_argument( "num must be non-negative" );
        }

        if ( num > UPPER_LIMIT )
        {
            
            throw std::overflow_error( "requested fibonacci index exceeds 64-bit range" );
        }

        if ( num <= 1 )
        {
            return num; // 
        }

        return compute( num - 1 ) + compute( num - 2 );
    }
} // hw03
// csc232
