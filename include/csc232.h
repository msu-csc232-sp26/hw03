/**
 * @file    csc232.h
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 *
 * @author  James R. Daehn <jdaehn@missouristate.edu>
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 2026
 *            James R. Daehn. All rights reserved.
 */

#ifndef MSU_CSC232_H
#define MSU_CSC232_H

#define FALSE 0
#define TRUE 1

#define EXECUTE_PREAMBLE TRUE

#define TEST_TASK1 FALSE // TODO:  Task 1 - Step 1: Toggle TEST_TASK1 TO TRUE
#define TEST_TASK2 FALSE // TODO:  Task 2 - Step 1: Toggle TEST_TASK2 TO TRUE
#define TEST_TASK3 FALSE // TODO:  Task 3 - Step 1: Toggle TEST_TASK3 TO TRUE
#define TEST_TASK4 FALSE // TODO:  Task 4 - Step 1: Toggle TEST_TASK4 TO TRUE
#define TEST_TASK5 FALSE // TODO:  Task 5 - Step 1: Toggle TEST_TASK5 TO TRUE

#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <format>
#include <functional>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

/** Common iostream objects */
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/** Common iomanip objects */
using std::left;
using std::right;
using std::setprecision;
using std::setw;

/**
 * @brief Common namespace for CSC232 identifiers.
 */
namespace csc232
{
    // Add any user-defined functions prescribed in your assignment below

    // DO NOT Modify anything below this line

    namespace util
    {
        /**
         * @brief A utility class for timing the execution of functions.
         * @tparam Clock the type of clock to use with this timer
         * @tparam DefaultDuration the default duration to use with this timer
         */
        template <typename Clock = std::chrono::steady_clock, typename DefaultDuration = std::chrono::milliseconds>
        class timer
        {
        public:
            /// Standardize syntax internally
            using clock = Clock;
            using duration = DefaultDuration;

            /**
             * @brief Compute the duration (only) of a function's execution.
             * @tparam Duration duration class to model function execution duration
             * @tparam F the return type of the given function
             * @tparam Args the types of the function arguments
             * @param t_function the function whose value and duration are computed
             * @param args the arguments to pass to the given function
             * @return the time it took to execute the given function.
             */
            template <typename Duration = DefaultDuration, typename F, typename... Args>
                requires std::invocable<F, Args...>
            static auto time_only( F &&t_function, Args &&...args ) -> Duration
            {
                const auto start = clock::now( );
                std::invoke( std::forward<F>( t_function ), std::forward<Args>( args )... );
                const auto stop = clock::now( );
                return std::chrono::duration_cast<Duration>( stop - start );
            }

            /**
             * @brief Calculate the duration and return value of a value-returning function.
             * @tparam Duration duration class to model function execution duration
             * @tparam F a function type
             * @tparam Args the types of the function arguments
             * @param t_function the function whose execution is timed
             * @param args the arguments to pass to the timed function
             * @return a pair capturing the return value of the function and the time it took to execute.
             */
            template <typename Duration = DefaultDuration, typename F, typename... Args>
                requires std::invocable<F, Args...> && ( !std::is_void_v<std::invoke_result_t<F, Args...>> )
            static auto time_and_result( F &&t_function, Args &&...args )
            {
                using result_t = std::invoke_result_t<F, Args...>;
                const auto start = clock::now( );
                result_t result = std::invoke( std::forward<F>( t_function ), std::forward<Args>( args )... );
                const auto stop = clock::now( );
                Duration timed_duration = std::chrono::duration_cast<Duration>( stop - start );
                return std::pair<result_t, Duration>{ std::move( result ), timed_duration };
            }

            /**
             * @brief Calculate the duration of a void function.
             * @tparam Duration duration class to model function execution duration
             * @tparam F a function type
             * @tparam Args the parameter types for the given timed function
             * @param t_function the function whose execution is timed
             * @param args the arguments to pass to the timed function
             * @return the time it took to execute the given function
             */
            template <class Duration = DefaultDuration, class F, class... Args>
                requires std::invocable<F, Args...> && ( std::is_void_v<std::invoke_result_t<F, Args...>> )
            static auto time_and_result( F &&t_function, Args &&...args ) -> Duration
            {
                // This overload matches void-returning functions; it behaves like time_only
                const auto start = clock::now( );
                std::invoke( std::forward<F>( t_function ), std::forward<Args>( args )... );
                const auto stop = clock::now( );
                return std::chrono::duration_cast<Duration>( stop - start );
            }
        };
    }

    static constexpr auto VALUE_MASK{ 0xF };
    static constexpr auto DECIMAL_UPPER_BOUND{ 10 };

    inline auto hex_lower( unsigned value ) -> char
    {
        value &= VALUE_MASK;
        return static_cast<char>( value < DECIMAL_UPPER_BOUND ? ( '0' + value )
                                                              : ( 'a' + ( value - DECIMAL_UPPER_BOUND ) ) );
    }

    static constexpr auto NUM_BYTES = 16;
    static constexpr auto DISTRIBUTION_UPPER_BOUND{ 255 };
    static constexpr auto V4_INDEX{ 6 };
    static constexpr auto V4_HEX_MASK1{ 0x0F };
    static constexpr auto V4_HEX_MASK2{ 0x40 };
    static constexpr auto VARIANT_INDEX{ 8 };
    static constexpr auto VARIANT_HEX_MASK1{ 0x3F };
    static constexpr auto VARIANT_HEX_MASK2{ 0x80 };
    static constexpr auto BYTE_RESERVATION{ 36 };
    static constexpr auto FIRST_DASH_INDEX{ 4 };
    static constexpr auto SECOND_DASH_INDEX{ 6 };
    static constexpr auto THIRD_DASH_INDEX{ 8 };
    static constexpr auto FOURTH_DASH_INDEX{ 10 };

    /**
     * @brief Generate a quasi-random UUID.
     * @return A string representation of a quasi-random UUID.
     */
    inline auto generate_uuid( ) -> std::string
    {
        std::array<std::uint8_t, NUM_BYTES> bytes{ };

        static std::random_device random_device;
        static std::mt19937 rng( random_device( ) );
        std::uniform_int_distribution<unsigned> dist( 0, DISTRIBUTION_UPPER_BOUND );

        for ( auto &b : bytes )
        {
            b = static_cast<std::uint8_t>( dist( rng ) );
        }

        // Set version (4) and variant (RFC 4122)
        bytes.at( V4_INDEX ) =
            static_cast<std::uint8_t>( ( bytes.at( V4_INDEX ) & V4_HEX_MASK1 ) | V4_HEX_MASK2 ); // version 4
        bytes.at( VARIANT_INDEX ) = static_cast<std::uint8_t>( ( bytes.at( VARIANT_INDEX ) & VARIANT_HEX_MASK1 ) |
                                                               VARIANT_HEX_MASK2 );              // variant 10xxxxxx

        std::string uuid;
        uuid.reserve( BYTE_RESERVATION );

        for ( int index = 0; index < NUM_BYTES; ++index )
        {
            if ( index == FIRST_DASH_INDEX || index == SECOND_DASH_INDEX || index == THIRD_DASH_INDEX ||
                 index == FOURTH_DASH_INDEX )
            {
                uuid += '-';
            }

            uuid += hex_lower( bytes.at( index ) >> 4 );
            uuid += hex_lower( bytes.at( index ) );
        }

        return uuid;
    }
} // namespace csc232

#endif // MSU_CSC232_H
