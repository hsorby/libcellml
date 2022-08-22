#include "gtest/gtest.h"

#include <libcellml>

TEST(Version, versionMatch)
{
    unsigned int version = libcellml::version();
    EXPECT_EQ(0x0003100U, version);

    std::string versionString = libcellml::versionString();
    EXPECT_EQ("0.3.100", versionString);
}
