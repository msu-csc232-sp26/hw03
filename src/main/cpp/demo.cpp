/**
 * @file    demo.cpp
 * @brief   Entry-point for demo target.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#include "csc232.h"

#if TEST_TASK1
// Placeholder for task 1 demo code
#endif

#if TEST_TASK2
// Placeholder for task 2 demo code
#endif

#if TEST_TASK3
// Placeholder for task 3 demo code
#endif
static auto constexpr BIG_VALUE{ 1'000'000 };
static auto constexpr MIDDLE_VALUE{ 700'00 };
static auto constexpr SMALL_VALUE{ 500'000 };

// Example functions
void some_function( )
{
    volatile int sum = 0;
    for ( int i = 0; i < BIG_VALUE; ++i )
    {
        sum += i;
    }
}

auto compute_value( const int parameter_value ) -> int
{
    for ( int i = 0; i < SMALL_VALUE; ++i )
    { /* do work */
    }
    return parameter_value * 2;
}

struct Widget
{
    void some_method( )
    {
        for ( int i = 0; i < MIDDLE_VALUE; ++i )
        { /* do work */
            ++data_;
        }
    }

private:
    int data_{ };
};

auto main( ) -> int
{
    std::cout << "Demo target" << std::endl;
    std::cout << "A random UUID: " << csc232::generate_uuid( ) << std::endl;

    using csc232::util::timer;

    // 1) Time a void function in milliseconds (default is ms)
    const auto ms1 = timer<>::time_only<>( some_function );
    std::cout << "some_function took " << ms1.count( ) << " ms\n";

    // 2) Time a member function call (wrap in a lambda)
    Widget some_widget;
    const auto ms2 = timer<>::time_only<>( [ & ] // NOLINT
                                           { some_widget.some_method( ); } );
    std::cout << "Widget::some_method took " << ms2.count( ) << " ms (milliseconds)\n";

    // 3) Time with a different unit per call (microseconds here)
    const auto us1 = timer<>::time_only<std::chrono::microseconds>( some_function );
    std::cout << "some_function took " << us1.count( ) << " us (microseconds) \n";

    // 4) Get both result and time
    constexpr auto argument{ 21 };
    auto [ value, dur_ns ] = timer<>::time_and_result<std::chrono::nanoseconds>( compute_value, argument );
    std::cout << "compute_value returned " << value << " in " << dur_ns.count( ) << " ns\n";

    return EXIT_SUCCESS;
}
