/**
 * @file    fibonacci_calculator.h
 * @brief   A Fibonacci calculator (Context in the strategy design pattern).
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#ifndef HW03_SOLUTION_FIBONACCI_CALCULATOR_H
#define HW03_SOLUTION_FIBONACCI_CALCULATOR_H
#include "fibonacci_strategy.h"

#include <memory>

namespace csc232::hw03
{

    /**
     * A device for calculating the nth number in the Fibonacci sequence.
     * @note This class is an instance of the "Context" described in the Strategy GoF software design pattern.
     */
    class fibonacci_calculator
    {
    public:
        /**
         * @brief Initializing constructor.
         *
         * @param strategy the computational strategy that dictates the operation of this calculator.
         */
        explicit fibonacci_calculator( std::unique_ptr<fibonacci_strategy> strategy );

        /**
         * @brief Computational model mutator method.
         *
         * @param strategy the computational model to be used by this Fibonacci calculator.
         */
        void set_strategy( std::unique_ptr<fibonacci_strategy> strategy );

        /**
         * @brief Calculates the nth number in the Fibonacci sequence, where the given number represents n.
         *
         * @param number an index into the Fibonacci sequence.
         * @return the nth Fibonacci number.
         *
         * @pre number >= 0
         * @pre number <= UPPER_LIMIT.
         * @post the nth number of the Fibonacci number is returned.
         *
         * @throws invalid_argument when number < 0
         * @throws overflow_error when number > UPPER_LIMIT.
         */
        [[nodiscard]] auto calculate( int number ) const -> big_number;

    private:
        std::unique_ptr<fibonacci_strategy> strategy_;
    };

} // hw03
// csc232

#endif // HW03_SOLUTION_FIBONACCI_CALCULATOR_H
