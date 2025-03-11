#include "MyRTCLibrary.h"

MyRTCLibrary::MyRTCLibrary() {
    // Constructeur
}

bool MyRTCLibrary::begin() {
    if (!rtc.begin()) {
        return false;
    }

    if (rtc.lostPower()) {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

    return true;
}

uint16_t MyRTCLibrary::nb_day_in_the_years(DateTime now) {
    const int tab_nb_days_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    uint16_t day_nb = now.day();

    for (int i = 0; i < now.month() - 1; i++) {
        day_nb += tab_nb_days_month[i];
    }

    if (now.year() % 4 == 0 && (now.year() % 100 != 0 || now.year() % 400 == 0) && now.month() > 2) {
        day_nb++;
    }

    return day_nb;
}

uint16_t MyRTCLibrary::getDayOfYear() {
    DateTime now = rtc.now();
    return nb_day_in_the_years(now);
}

void MyRTCLibrary::printDayOfYear() {
    uint16_t Day_Num = getDayOfYear();
    Serial.print("Numéros du jour dans l'année (uint16_t): ");
    Serial.println(Day_Num);
}