/*
 * Divider.hpp
 *
 *  Created on: 19-Jan-2018
 *      Author: sudhanshu
 */

#ifndef DIVIDER_HPP_
#define DIVIDER_HPP_


#include <algorithm>
#include <iterator>
#include <iostream>
#include "AbstractCalculationEngine.hpp"

namespace mathematics {

class Divider : public calculation_Engine<int> {
public:
	static calculation_Engine* createINstance(){
		if(_instance == nullptr)
			_instance = new Divider;

		return _instance;
	}
	virtual void performOperation(const std::vector<int>& container,int &result)
	{
		for(const auto &data : container)
		{
			if(!data)
				std::cout << "Divide by zero" << std::endl;
			if(!result)
			{
				result = data;
				continue;
			}

			result = result/data;
		}

	}
	virtual void performOperation(std::ifstream &in ,int &result)
	{

		std::vector<int> container;
		std::copy(std::istream_iterator<int>(in),std::istream_iterator<int>(),
				  std::back_inserter(container));
		for(const auto &data : container)
		{
			if(!data)
				std::cout << "Divide by zero" << std::endl;

			if(!result)
			{
				result = data;
				continue;
			}

			result = result/data;
		}
	}
	virtual void performSpecilizedOperation() {
		return;
	}
	virtual void setCalculateFunction(calculate_Function &func) {
		doCalculate = nullptr;
	}

protected:
	Divider() = default;

private:
	static Divider* _instance ;


};
}
#endif /* DIVIDER_HPP_ */
