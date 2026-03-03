/**
 * @file    top_down_memo_strategy.cpp
 * @brief   Top-down (memoization) strategy implementation.
 *
 * @authors James R. Daehn <jdaehn@missouristate.edu>
 *          // TODO: Add your name using the above format
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#include "top_down_memo_strategy.h"
#include <stdexcept>

namespace csc232::hw03
{

    auto top_down_memo_strategy::helper( const int num, std::vector<big_number> &memo ) -> big_number
    {
        if ( num <= 1 )
        {
            return num;
        }

        if ( memo.at( num ) != -1 )
        {
            return memo.at( num );
        }

        memo.at( num ) = helper( num - 1, memo ) + helper( num - 2, memo );
        return memo.at( num );
    }

    auto top_down_memo_strategy::compute( const int num ) const -> big_number
    {
        if ( num < 0 )
        {
            throw std::invalid_argument( "num must be non-negative" );
        }

        if ( num > UPPER_LIMIT )
        {
            throw std::overflow_error( "requested fibonacci index exceeds 64-bit range" );
        }

        std::vector<big_number> memo( static_cast<std::size_t>( num ) + 1, -1 );
        return helper( num, memo );
    }
} // hw03
// csc232
