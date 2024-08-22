// typewise-alert.tests.cpp
#include <gtest/gtest.h>
#include "typewise-alert.h"
#include "PassiveCoolingStrategy.h"
#include "HiActiveCoolingStrategy.h"
#include "MedActiveCoolingStrategy.h"

TEST(TypeWiseAlertTestSuite, InfersBreachAccordingToLimits) {
    BatteryCharacter batteryChar;
    PassiveCoolingStrategy passiveStrategy;
    HiActiveCoolingStrategy hiActiveStrategy;
    MedActiveCoolingStrategy medActiveStrategy;

    batteryChar.coolingStrategy = &passiveStrategy;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, -1), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 36), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 20), NORMAL);

    batteryChar.coolingStrategy = &hiActiveStrategy;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 46), TOO_HIGH);

    batteryChar.coolingStrategy = &medActiveStrategy;
    EXPECT_EQ(classifyTemperatureBreach(batteryChar, 41), TOO_HIGH);
}
