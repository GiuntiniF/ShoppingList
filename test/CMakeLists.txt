cmake_minimum_required(VERSION 3.5)

#Aggiunta di googleTest via FetchContent come indicato sulla documentazione
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

#definizione target come indicato sulla documentazione
enable_testing()

set(TEST_SOURCE_FILES runAllTests.cpp MeatAndChickenItemTest.cpp VegetableAndFruitItemTest.cpp NullItemTest.cpp ItemListTestFixture.cpp ItemManagerTest.cpp UserTextFixture.cpp)
add_executable(runShoppingListTests ${TEST_SOURCE_FILES})
target_link_libraries(runShoppingListTests GTest::gtest_main ShoppingListCore)

include(GoogleTest)
gtest_discover_tests(runShoppingListTests)