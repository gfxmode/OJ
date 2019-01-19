#include <limits.h>
#include "OJ.h"
#include "gtest/gtest.h"

namespace
{
    TEST(Solution, 1)
    {
        Solution objOJ;
        EXPECT_EQ(1, objOJ.longestPalindrome(3));
    }
}
