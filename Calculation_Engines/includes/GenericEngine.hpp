/*
 * GenericEngine.hpp
 *
 *  Created on: 19-Jan-2018
 *      Author: sudhanshu
 */

#ifndef GENERICENGINE_HPP_
#define GENERICENGINE_HPP_
#include <iostream>

namespace mathematics {

class GenericEngine : public calculation_Engine<int> {
public:
	static calculation_Engine* createINstance(){
		if(_instance == nullptr)
			_instance = new GenericEngine;

		return _instance;
	}
	virtual void performOperation(const std::vector<int>& data,int &result) {
		std::cout << "Supply your own function" <<  std::endl;
	}
	virtual void performOperation(std::ifstream &in ,int &result)
	{
		std::cout << "Write your own engine" << std::endl;
	}
	virtual void performSpecilizedOperation()
	{
		if(doCalculate != nullptr)
			doCalculate(*this);
	}
protected:
	GenericEngine() = default;
private:
	static GenericEngine* _instance ;
};

}




#endif /* GENERICENGINE_HPP_ */
