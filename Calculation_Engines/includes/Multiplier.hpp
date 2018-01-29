/*
 * Multiplier.hpp
 *
 *  Created on: 18-Jan-2018
 *      Author: sudhanshu
 */

#ifndef MULTIPLIER_HPP_
#define MULTIPLIER_HPP_

#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream>
#include "AbstractCalculationEngine.hpp"

namespace mathematics {

class Multiplier : public calculation_Engine<int> {
public:
	static calculation_Engine* createINstance(){
		if(_instance == nullptr)
			_instance = new Multiplier;

		return _instance;
	}
	virtual void performOperation(const std::vector<int>& data,int &result) {
		std::cout << "List of Integers are not supported with Multiplier" << std::endl;
	}
	virtual void performOperation(std::ifstream &in ,int &result)
	{
		std::vector<int> container;
		std::copy(std::istream_iterator<int>(in),std::istream_iterator<int>(),
				  std::back_inserter(container));
		for(const auto &data : container)
		{
			if(!result)
			{
				result = data;
				continue;
			}

			result = result * data;
		}
	}
	virtual void setCalculateFunction(calculate_Function &func) {
		doCalculate = nullptr;
	}
	virtual void performSpecilizedOperation() {
		return;
	}
protected:
	Multiplier() = default;
private:
	static Multiplier* _instance ;

};
}


#endif /* MULTIPLIER_HPP_ */
