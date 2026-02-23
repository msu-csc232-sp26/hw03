/**
 * @file    main.cpp
 * @brief   Entry-point for main target.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn
 */

#include "bottom_up_tabulation_strategy.h"
#include "calculator_factory.h"
#include "csc232.h"
#include "fibonacci_calculator.h"
#include "fibonacci_strategy.h"
#include "iterative_strategy.h"
#include "strategy_factory.h"
#include "top_down_memo_strategy.h"

#include <cstdlib>
#include <iostream>

auto main( ) -> int
{
    using namespace csc232::hw03;
    std::cout << "Enter n and a corresponding compute strategy: ";

    // The following make I/O faster
    std::ios::sync_with_stdio( false );
    std::cin.tie( nullptr );

    int number = 0;
    std::string strategy;
    if ( !( std::cin >> number >> strategy ) )
    {
        std::cerr << "Usage: <n> <memo|tab|iter|naive>\n";
        return 1;
    }

    auto technique = compute_strategy::BOTTOM_UP;

    if ( strategy == "memo" )
    {
        technique = compute_strategy::TOP_DOWN;
    }
    else if ( strategy == "tab" )
    {
        technique = compute_strategy::BOTTOM_UP;
    }
    else if ( strategy == "iter" )
    {
        technique = compute_strategy::ITERATIVE;
    }
    else if ( strategy == "naive" )
    {
        technique = compute_strategy::NAIVE;
    }
    else
    {
        std::cerr << "Unknown strategy: " << strategy << " (use memo|tab|iter|naive)\n";
        return EXIT_FAILURE;
    }

    const fibonacci_calculator calculator = calculator_factory::create( technique );

    try
    {
        std::cout << "fib( " << number << " ) = " << calculator.calculate( number ) << '\n';
    }
    catch ( const std::exception &compute_exception )
    {
        std::cerr << "Error: " << compute_exception.what( ) << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
