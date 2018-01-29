/*
 * calc.hpp
 *
 *  Created on: 21-Jan-2018
 *      Author: sudhanshu
 */

#ifndef CALC_HPP_
#define CALC_HPP_

#include <string>
#include <regex>
#include <vector>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include "Singleton.hpp"

using namespace mathematics;

bool validCommandLine(int argc,char **argv);
void standardDeviation(const Icalculation_Engine &getCalculationEngine);
void listofIntegers(int argc, char **argv,Icalculation_Engine *getCalculationEngine,int &result);
void listofFiles(int argc, char **argv,Icalculation_Engine *getCalculationEngine,int &result);
int runApp(int argc,char *argv[]);

#endif /* CALC_HPP_ */
