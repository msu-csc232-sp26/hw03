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
    auto fast_doubling_strategy::fib_pair( const big_number number ) -> std::pair<big_number, big_number>
    {
        if ( number == 0 )
        {
            return { 0, 1 };
        }

        const auto half = fib_pair( number / 2 );
        const big_number a = half.first;            
        const big_number b = half.second;           

        const big_number c = a * ( ( b * 2 ) - a ); 
        const big_number d = ( a * a ) + ( b * b ); 

        if ( ( number % 2 ) == 0 )
        {
            return { c, d };
        }

        return { d, c + d };
    }

    auto fast_doubling_strategy::compute( const int num ) const -> big_number
    {
        if ( num < 0 )
        {
            throw std::invalid_argument( "num must be non-negative" );
        }

        if ( num > UPPER_LIMIT )
        {
            throw std::overflow_error( "requested fibonacci index exceeds 64-bit range" );
        }

        return fib_pair( static_cast<big_number>( num ) ).first;
    }

} // hw03
// csc232
