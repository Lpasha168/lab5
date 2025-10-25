#include <iostream>
#include "funcs.hpp"
namespace DateCalculator { 
short base = 2024;
short yd1, vesk1, dow1, smewenie1, wd1, yd2, vesk2, dow2, smewenie2, wd2, sumdays1, sumdays2, start1, start2;
short mo1, year1, day1;
short mo2, year2, day2;
short daynedeli1, daynedeli2, max1, max2, dydf, yrdf, vyr;
bool visyear1, visyear2;
bool cor = true;
void correct() {
	std::cout << "First date (Ex: 5 2 2012): " << std::endl;
	std::cin >> day1 >> mo1 >> year1;
	std::cout << "Second date (Ex: 3 11 2012): " << std::endl;;
	std::cin >> day2 >> mo2 >> year2;
	if ((mo1 < 1) || (mo1 > 12) || (mo1 < 1) || (mo1 > 12)) {
		std::cout << "Incorrect month input" << std::endl;
		cor = false;
	}
	if ((year1 < 0) || (year2 < 0)) {
		std::cout << "Incorrect year input" << std::endl;
		cor = false;
	}
	switch (mo1) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		max1 = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		max1 = 30;
		break;
	case 2:
		max1 = 28;
		break;
	}
	switch (mo2) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		max2 = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		max2 = 30;
		break;
	case 2:
		max2 = 28;
		break;
	}
	bool visyear1 = (year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0);
	bool visyear2 = (year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0);
	if ((visyear1 == true) && (mo1 == 2)) {
		max1 = 29;
	}
	if ((visyear2 == true) && (mo2 == 2)) {
		max2 = 29;
	}
	if ((day1 > max1) || (day1 < 1) || (day2 < 1) || (day2 > max2)) {
		std::cout << "Incorrect day input" << std::endl;
		cor = false;
	}
}
void leap() {
	if (cor == true) {
		bool visyear1 = (year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0);
		bool visyear2 = (year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0);
		if (visyear1 != true) {
			std::cout << year1 << " Isn't leap" << std::endl;
		}
		else {
			std::cout << year1 << " Is leap" << std::endl;
		}
		if (visyear2 != true) {
			std::cout << year2 << " Isn't leap" << std::endl;
		}
		else {
			std::cout << year2 << " Is leap" << std::endl;
		}
	}
	
}
void day_of_the_week() {
	if (cor == true) {
		yd1 = abs(year1 - base);
		vesk1 = yd1 / 4;
		if (base > year1) {
			smewenie1 = (yd1 - vesk1) + (vesk1 * 2);
			wd1 = smewenie1 % 7;
			dow1 = (7 - wd1) ;
		}
		else if (base < year1) {
			smewenie1 = (yd1 - vesk1) + (vesk1 * 2);
			wd1 = smewenie1 % 7;
			dow1 = (1 + wd1);
		}
		if (base == year1) {
			dow1 = 1;
		}
		if (dow1 > 7) {
			dow1 = dow1 - 7;
		}
		switch (mo1) {
		case 1:
			sumdays1 = 0;
			break;
		case 2:
			sumdays1 = 31;
			break;
		case 3:
			sumdays1 = 59;
			break;
		case 4:
			sumdays1 = 90;
			break;
		case 5:
			sumdays1 = 120;
			break;
		case 6:
			sumdays1 = 151;
			break;
		case 7:
			sumdays1 = 181;
			break;
		case 8:
			sumdays1 = 212;
			break;
		case 9:
			sumdays1 = 243;
			break;
		case 10:
			sumdays1 = 273;
			break;
		case 11:
			sumdays1 = 304;
			break;
		case 12:
			sumdays1 = 334;
			break;
		}
		bool visyear1 = (year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0);
		bool visyear2 = (year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0);
		if (visyear1 && mo1 > 2) {
			start1 = (sumdays1 + day1) + 1;
			daynedeli1 = (dow1 + (sumdays1 + day1)) % 7;
			if (daynedeli1 == 0) daynedeli1 = 7;
		}
		else {
			start1 = (sumdays1 + day1);
			daynedeli1 = (dow1 + (sumdays1 + day1)) % 7;
			if (daynedeli1 == 0) daynedeli1 = 7;
		}
		yd2 = abs(year2 - base);
		vesk2 = yd2 / 4;
		if (base > year2) {
			smewenie2 = (yd2 - vesk2) + (vesk2 * 2);
			wd2 = smewenie2 % 7;
			dow2 = (7 - wd2) + 1;
		}
		else if (base < year2) {
			smewenie2 = (yd2 - vesk2) + (vesk2 * 2);
			wd2 = smewenie2 % 7;
			dow2 = (1 + wd2) + 1;
		}
		if (base == year2) {
			dow2 = 1;
		}
		if (dow2 > 7) {
			dow2 = dow2 - 7;
		}
		switch (mo2) {
		case 1:
			sumdays2 = 0;
			break;
		case 2:
			sumdays2 = 31;
			break;
		case 3:
			sumdays2 = 59;
			break;
		case 4:
			sumdays2 = 90;
			break;
		case 5:
			sumdays2 = 120;
			break;
		case 6:
			sumdays2 = 151;
			break;
		case 7:
			sumdays2 = 181;
			break;
		case 8:
			sumdays2 = 212;
			break;
		case 9:
			sumdays2 = 243;
			break;
		case 10:
			sumdays2 = 273;
			break;
		case 11:
			sumdays2 = 304;
			break;
		case 12:
			sumdays2 = 334;
			break;
		}
		if (visyear2 && mo2 > 2) {
			start2 = (sumdays2 + day2) + 1;
			daynedeli2 = (dow2 + (sumdays2 + day2)) % 7;
			if (daynedeli2 == 0) daynedeli2 = 7;
		}
		else {
			start2 = (sumdays2 + day2);
			daynedeli2 = (dow2 + (sumdays2 + day2)-1) % 7;
			if (daynedeli2 == 0) daynedeli2 = 7;
		}
		switch (daynedeli1) {
		case 1:
			std::cout << "First date" << " - Monday" << std::endl;
			break;
		case 2:
			std::cout << "First date" << " - Tuesday" << std::endl;
			break;
		case 3:
			std::cout << "First date" << " - Wednesday" << std::endl;
			break;
		case 4:
			std::cout << "First date" << " - Thursday" << std::endl;
			break;
		case 5:
			std::cout << "First date" << " - Friday" << std::endl;
			break;
		case 6:
			std::cout << "First date" << " - Saturday" << std::endl;
			break;
		case 7:
			std::cout << "First date" << " - Sunday" << std::endl;
			break;
		}
		switch (daynedeli2) {
		case 1:
			std::cout << "Second date" << " - Monday" << std::endl;
			break;
		case 2:
			std::cout << "Second date" << " - Tuesday" << std::endl;
			break;
		case 3:
			std::cout << "Second date" << " - Wednesday" << std::endl;
			break;
		case 4:
			std::cout << "Second date" << " - Thursday" << std::endl;
			break;
		case 5:
			std::cout << "Second date" << " - Friday" << std::endl;
			break;
		case 6:
			std::cout << "Second date" << " - Saturday" << std::endl;
			break;
		case 7:
			std::cout << "Second date" << " - Sunday" << std::endl;
			break;

		}
	}
	
}
void daysdiff() {
	int fulldiff;
	if (year1 != year2) {
		if (year1 > year2) {
			short leapc = 0;
			for (short minyear = (year2 + 1); minyear < year1; ++minyear) {
				if ((minyear % 4 == 0 && minyear % 100 != 0) || (minyear % 400 == 0)) {
					leapc++;
				}
			}
			yrdf = abs(year1 - year2) - 1;
			fulldiff = (365 - start2) + start1 + yrdf * 365 + leapc;
		}
		else {
			short leapc = 0;
			for (short minyear = (year1 + 1); minyear < year2; ++minyear) {
				if ((minyear % 4 == 0 && minyear % 100 != 0) || (minyear % 400 == 0)) {
					leapc++;
				}
			}
			yrdf = abs(year1 - year2) - 1;
			fulldiff = (365 - start1) + start2 + yrdf * 365 + leapc;
		}
	}
	else {
		fulldiff = abs(start1 - start2);
	}
	if (cor == true) {
	std::cout << "Date difference - " << fulldiff << std::endl;
	}	
}
}



