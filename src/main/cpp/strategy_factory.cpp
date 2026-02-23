/**
 * @file    strategy_factory.cpp
 * @brief   Strategy factory implementation.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#include "strategy_factory.h"

#include "bottom_up_tabulation_strategy.h"
#include "iterative_strategy.h"
#include "naive_strategy.h"
#include "top_down_memo_strategy.h"

namespace csc232::hw03
{
    auto strategy_factory::create( const compute_strategy strategy ) -> std::unique_ptr<fibonacci_strategy>
    {
        switch ( strategy )
        {
        case compute_strategy::BOTTOM_UP:
            return std::make_unique<bottom_up_tabulation_strategy>( );
        case compute_strategy::ITERATIVE:
            return std::make_unique<iterative_strategy>( );
        case compute_strategy::NAIVE:
            return std::make_unique<naive_strategy>( );
        case compute_strategy::TOP_DOWN:
            return std::make_unique<top_down_memo_strategy>( );
        default:
            throw std::invalid_argument( "Unknown strategy" );
        }
    }
}