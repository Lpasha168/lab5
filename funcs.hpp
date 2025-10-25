#pragma once
namespace DateCalculator {
	extern short day1, mon1, year1, start1;
	extern short day2, mon2, year2, start2;
	extern bool visyear1, visyear2;
	void day_of_the_week();
	void leap();
	void correct();
	void daysdiff();
}