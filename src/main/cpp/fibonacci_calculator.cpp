/**
 * @file    fibonacci_calculator.cpp
 * @brief   Fibonacci calculator implementation.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#include "fibonacci_calculator.h"

namespace csc232::hw03
{
    fibonacci_calculator::fibonacci_calculator( std::unique_ptr<fibonacci_strategy> strategy )
        : strategy_{ std::move( strategy ) }
    {
        if ( strategy_ == nullptr )
        {
            throw std::invalid_argument( "strategy is not set" );
        }
    }

    void fibonacci_calculator::set_strategy( std::unique_ptr<fibonacci_strategy> strategy )
    {
        strategy_ = std::move( strategy );
    }

    auto fibonacci_calculator::calculate( int number ) const -> big_number
    {
        if ( strategy_ == nullptr )
        {
            throw std::logic_error( "strategy is not set" );
        }
        return strategy_->compute( number );
    }
} // hw03
// csc232