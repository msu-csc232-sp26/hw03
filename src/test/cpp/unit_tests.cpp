/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2025
 *
 * @file    unit_tests.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Assignment unit testing for evaluation.
 * @version 1.0.0
 * @date    12/13/25
 *
 * @copyright Copyright (c) 2025 James R. Daehn
 */

// unit_tests.cpp
#include "base_test_fixture.h"
#include "bottom_up_tabulation_strategy.h"
#include "csc232.h"
#include "fast_doubling_strategy.h"
#include "fibonacci_strategy.h"
#include "iterative_strategy.h"
#include "naive_strategy.h"
#include "top_down_memo_strategy.h"
#include "gtest/gtest.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>

// Helper to run basic correctness checks for any strategy
void basic_checks( csc232::hw03::fibonacci_strategy &strategy, const bool allow_large = true ) // NOLINT
{
    EXPECT_EQ( strategy.compute( 0 ), 0 );
    EXPECT_EQ( strategy.compute( 1 ), 1 );
    EXPECT_EQ( strategy.compute( 2 ), 1 );
    EXPECT_EQ( strategy.compute( 5 ), 5 );
    EXPECT_EQ( strategy.compute( 10 ), 55 );
    EXPECT_EQ( strategy.compute( 20 ), 6765 );
    if ( allow_large )
    {
        // Still reasonably fast for all but naïve recursion
        EXPECT_EQ( strategy.compute( 50 ), 12586269025LL );
    }
}

// -----------------------------------------------------------------------------
// Task 1 Fixture and Tests
// -----------------------------------------------------------------------------
#if TEST_TASK1
class Task1TestFixture : public csc232::CSC232BaseTestFixture
{
protected:
    void SetUp( ) override
    {
        // Initialize any shared state/resources for Task 1 tests.
    }

    void TearDown( ) override
    {
        // Cleanup for Task 1.
    }
};

TEST_F( Task1TestFixture, ItHandlesSmallInputs )
{
    csc232::hw03::naive_strategy strategy;
    basic_checks( strategy, false ); // avoid F(50) for naïve
}

TEST_F( Task1TestFixture, ItThrowsOnNegative ) // NOLINT
{
    EXPECT_THROW(
        {
            const csc232::hw03::naive_strategy strategy;
            if ( strategy.compute( -1 ) )
            {
                std::cerr << "An invalid argument exception should have been thrown\n";
            }
        },
        std::invalid_argument );
}

TEST_F( Task1TestFixture, ItThrowsOnOverflow ) // NOLINT
{
    EXPECT_THROW(
        {
            const csc232::hw03::naive_strategy strategy;
            if ( strategy.compute( 93 ) )
            {
                std::cerr << "An overflow exception should have been thrown\n";
            }
        },
        std::overflow_error );
}

#else
TEST( Task1Primer, ItIsNotReady )
{
    std::cerr << "Task 1 is not ready for evaluation; please toggle the TEST_TASK1 macro to TRUE\n";
    SUCCEED( );
}
#endif // TEST_TASK_1

// -----------------------------------------------------------------------------
// Task 2 Fixture and Tests
// -----------------------------------------------------------------------------
#if TEST_TASK2
class Task2TestFixture : public csc232::CSC232BaseTestFixture
{
protected:
    void SetUp( ) override { }
    void TearDown( ) override { }
};

TEST_F( Task2TestFixture, ItHandlesSmallInputs )
{
    csc232::hw03::top_down_memo_strategy strategy;
    basic_checks( strategy, true );
}

TEST_F( Task2TestFixture, ItThrowsOnNegative ) // NOLINT
{

    EXPECT_THROW(
        {
            const csc232::hw03::top_down_memo_strategy strategy;
            if ( strategy.compute( -1 ) )
            {
                std::cerr << "An invalid argument exception should have been thrown\n";
            }
        },
        std::invalid_argument );
}

TEST_F( Task2TestFixture, ItThrowsOnOverflow ) // NOLINT
{
    EXPECT_THROW(
        {
            const csc232::hw03::top_down_memo_strategy strategy;
            if ( strategy.compute( 93 ) )
            {
                std::cerr << "An overflow exception should have been thrown\n";
            }
        },
        std::overflow_error );
}
#else
TEST( Task2Primer, ItIsNotReady )
{
    std::cerr << "Task 2 is not ready for evaluation; please toggle the TEST_TASK2 macro to TRUE\n";
    SUCCEED( );
}
#endif // TEST_TASK_2

// -----------------------------------------------------------------------------
// Task 3 Fixture and Tests
// -----------------------------------------------------------------------------
#if TEST_TASK3
class Task3TestFixture : public csc232::CSC232BaseTestFixture
{
protected:
    void SetUp( ) override { }
    void TearDown( ) override { }
};

TEST_F( Task3TestFixture, ItHandlesSmallInputs )
{
    csc232::hw03::bottom_up_tabulation_strategy strategy;
    basic_checks( strategy, true );
}

TEST_F( Task3TestFixture, ItThrowsOnNegative ) // NOLINT
{
    EXPECT_THROW(
        {
            const csc232::hw03::bottom_up_tabulation_strategy strategy;
            if ( strategy.compute( -1 ) )
            {
                std::cerr << "An invalid argument exception should have been thrown\n";
            }
        },
        std::invalid_argument );
}

TEST_F( Task3TestFixture, ItThrowsOnOverflow ) // NOLINT
{
    EXPECT_THROW(
        {
            const csc232::hw03::bottom_up_tabulation_strategy strategy;
            if ( strategy.compute( 93 ) )
            {
                std::cerr << "An overflow exception should have been thrown\n";
            }
        },
        std::overflow_error );
}
#else
TEST( Task3Primer, ItIsNotReady )
{
    std::cerr << "Task 3 is not ready for evaluation; please toggle the TEST_TASK3 macro to TRUE\n";
    SUCCEED( );
}
#endif // TEST_TASK_3

// -----------------------------------------------------------------------------
// Task 4 Fixture and Tests
// -----------------------------------------------------------------------------
#if TEST_TASK4
class Task4TestFixture : public csc232::CSC232BaseTestFixture
{
protected:
    void SetUp( ) override { }
    void TearDown( ) override { }
};

TEST_F( Task4TestFixture, ItHandlesSmallInputs )
{
    csc232::hw03::iterative_strategy strategy;
    basic_checks( strategy, true );
}

TEST_F( Task4TestFixture, ItThrowsOnNegative ) // NOLINT
{
    EXPECT_THROW(
        {
            const csc232::hw03::iterative_strategy strategy;
            if ( strategy.compute( -1 ) )
            {
                std::cerr << "An invalid argument exception should have been thrown\n";
            }
        },
        std::invalid_argument );
}

TEST_F( Task4TestFixture, ItThrowsOnOverflow ) // NOLINT
{
    EXPECT_THROW(
        {
            const csc232::hw03::iterative_strategy strategy;
            if ( strategy.compute( 93 ) )
            {
                std::cerr << "An overflow exception should have been thrown\n";
            }
        },
        std::overflow_error );
}
#else
TEST( Task4Primer, ItIsNotReady )
{
    std::cerr << "Task 4 is not ready for evaluation; please toggle the TEST_TASK4 macro to TRUE\n";
    SUCCEED( );
}
#endif // TEST_TASK_4

// -----------------------------------------------------------------------------
// Task 5 Fixture and Tests
// -----------------------------------------------------------------------------
#if TEST_TASK5
class Task5TestFixture : public csc232::CSC232BaseTestFixture
{
protected:
    void SetUp( ) override { }
    void TearDown( ) override { }
};

TEST_F( Task5TestFixture, ItHandlesSmallInputs )
{
    csc232::hw03::fast_doubling_strategy strategy;
    basic_checks( strategy, true );
}

TEST_F( Task5TestFixture, ItThrowsOnNegative ) // NOLINT
{
    EXPECT_THROW(
        {
            const csc232::hw03::fast_doubling_strategy strategy;
            if ( strategy.compute( -1 ) )
            {
                std::cerr << "An invalid argument exception should have been thrown\n";
            }
        },
        std::invalid_argument );
}

TEST_F( Task5TestFixture, ItThrowsOnOverflow ) // NOLINT
{
    EXPECT_THROW(
        {
            const csc232::hw03::fast_doubling_strategy strategy;
            if ( strategy.compute( 93 ) )
            {
                std::cerr << "An overflow exception should have been thrown\n";
            }
        },
        std::overflow_error );
}

#else
TEST( Task5Primer, ItIsNotReady )
{
    std::cerr << "Task 5 is not ready for evaluation; please toggle the TEST_TASK5 macro to TRUE\n";
    SUCCEED( );
}
#endif // TEST_TASK_5

// -----------------------------------------------------------------------------
// Helper: Print task-by-task summary and compute score
// -----------------------------------------------------------------------------
struct SuiteSummary
{
    std::string name;
    int passed = 0;
    int failed = 0;
    int disabled = 0;
    int total = 0;
    double percent = 0.0; // passing percentage among executed tests (pass+fail)
};

static void PrintPerTaskSummaryAndScore( )
{
    using testing::TestSuite;
    using testing::UnitTest;

    const UnitTest *unitTest = UnitTest::GetInstance( );

    // Aggregate per suite (fixture) results
    std::vector<SuiteSummary> summaries;
    int overall_passed = 0;
    int overall_failed = 0;

    for ( int i = 0; i < unitTest->total_test_suite_count( ); ++i )
    {
        const TestSuite *suite = unitTest->GetTestSuite( i );
        // Only include suites that correspond to our tasks.
        // (Optional) You can filter by name prefix "Task" if needed.
        SuiteSummary suiteSummary;
        suiteSummary.name = suite->name( );
        suiteSummary.passed = suite->successful_test_count( );
        suiteSummary.failed = suite->failed_test_count( );
        suiteSummary.disabled = suite->disabled_test_count( );
        suiteSummary.total = suite->total_test_count( );
        const int executed = suiteSummary.passed + suiteSummary.failed;
        suiteSummary.percent = ( executed > 0 ) ? ( 100.0 * suiteSummary.passed / executed ) : 0.0;

        summaries.push_back( suiteSummary );
        overall_passed += suiteSummary.passed;
        overall_failed += suiteSummary.failed;
    }

    const int overall_executed = overall_passed + overall_failed;
    const double overall_percent =
        ( overall_executed > 0 ) ? ( 100.0 * static_cast<double>( overall_passed ) / overall_executed ) : 0.0;

    // Pretty print
    std::cout << "\n========== Assignment Task Results ==========\n";
    for ( const auto &suiteSummary : summaries )
    {
        // Recommend naming fixtures exactly "Task1", "Task2", "Task3"
        if ( suiteSummary.name == "Task1TestFixture" || suiteSummary.name == "Task2TestFixture" ||
             suiteSummary.name == "Task3TestFixture" || suiteSummary.name == "Task4TestFixture" ||
             suiteSummary.name == "Task5TestFixture" )
        {
            std::cout << "Task: " << suiteSummary.name << "\n"
                      << "  Passing: " << suiteSummary.passed << "\n"
                      << "  Failing: " << suiteSummary.failed << "\n"
                      << "  Disabled: " << suiteSummary.disabled << "\n"
                      << "  Total (compiled): " << suiteSummary.total << "\n"
                      << "  Score (% passing among executed): " << std::fixed << std::setprecision( 1 )
                      << suiteSummary.percent << "%\n\n";
        }
    }

    std::cout << "-------------- Overall Summary --------------\n"
              << "Passing: " << overall_passed << "\n"
              << "Failing: " << overall_failed << "\n"
              << "Executed: " << overall_executed << "\n"
              << "Overall Score: " << std::fixed << std::setprecision( 1 ) << overall_percent << "%\n"
              << "=============================================\n\n";
}

// -----------------------------------------------------------------------------
// Custom main (do NOT link gtest_main)
// -----------------------------------------------------------------------------
auto main( int argc, char **argv ) -> int
{
    ::testing::InitGoogleTest( &argc, argv );
    const int gtest_return = RUN_ALL_TESTS( );

    // After tests run, compute/print summaries & score
    PrintPerTaskSummaryAndScore( );

    // Return gtest's status (0 means all tests passed)
    return gtest_return;
}
