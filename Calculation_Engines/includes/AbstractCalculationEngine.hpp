/*
 * AbstractCalculationEngine.hpp
 *
 *  Created on: 18-Jan-2018
 *      Author: sudhanshu
 */

#ifndef ABSTRACTCALCULATIONENGINE_HPP_
#define ABSTRACTCALCULATIONENGINE_HPP_

#include <functional>
#include <vector>
#include <fstream>

namespace mathematics {

class Icalculation_Engine {
public:
	virtual ~Icalculation_Engine()= default;
	virtual void performSpecilizedOperation() = 0;
};

template<typename T>
class calculation_Engine:public Icalculation_Engine {
public:
	typedef std::function<void(const Icalculation_Engine&)> calculate_Function;
	calculation_Engine() = default;
	const std::vector<T>& getValueList();
	virtual void setCalculateFunction(calculate_Function &func);
	virtual void performOperation(const std::vector<T>& data, T &result) = 0;
	virtual void performOperation(std::ifstream &in, T &result) = 0;
	calculate_Function doCalculate;
};

template<typename T>
void calculation_Engine<T>::setCalculateFunction(calculate_Function &func)
{
	doCalculate = func;
}

}
#endif /* ABSTRACTCALCULATIONENGINE_HPP_ */
