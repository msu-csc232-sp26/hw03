/**
 * @file    fibonacci_strategy.h
 * @brief   Fibonacci computation model specification
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    2026-02-22
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#ifndef HW03_SOLUTION_FIBONACCI_STRATEGY_H
#define HW03_SOLUTION_FIBONACCI_STRATEGY_H

using big_number = long long;

namespace csc232::hw03
{
    /**
     * @brief A computational model for computing the nth Fibonacci number.
     * @details We define the Fibonacci sequence as follows:
     *
     *          F(0) = 0
     *          F(1) = 1
     *          F(n) = F(n - 1) + F(n - 2) for n > 1
     *
     *          These definitions represent a naive approach to computing the nth Fibonacci number.
     */
    class fibonacci_strategy
    {
    public:
        /**
         * An upper limit index into the Fibonacci sequence to prevent long-running computations.
         */
        static constexpr auto UPPER_LIMIT{ 92 };

        /**
         * Default destructor.
         */
        virtual ~fibonacci_strategy( ) = default;

        /**
         * @brief Computes the nth Fibonacci number.
         * @param num an index into the Fibonacci sequence.
         * @return the nth Fibonacci number.
         * @pre num >= 0 && num < UPPER_LIMIT.
         * @throw std::invalid_argument exception if num < 0.
         * @throw std::overflow_error exception if num > UPPER_LIMIT.
         */
        [[nodiscard]] virtual auto compute( int num ) const -> big_number = 0; // num >= 0, returns F(num)
    };

} // hw03
// csc232

#endif // HW03_SOLUTION_FIBONACCI_STRATEGY_H
