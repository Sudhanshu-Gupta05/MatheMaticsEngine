/*
 * Singleton.hpp
 *
 *  Created on: 19-Jan-2018
 *      Author: sudhanshu
 */

#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

/*standard header files */
#include <unordered_map>
#include <string>
#include <functional>

/*user defined header files */
#include "AbstractCalculationEngine.hpp"
#include "Divider.hpp"
#include "Multiplier.hpp"
#include "GenericEngine.hpp"


namespace mathematics {

typedef std::pair<std::string,std::string> allowableOperation;

struct newhash {
	std::size_t operator()(const allowableOperation &key) const
	{
		std::hash<std::string> hasher;
		return hasher(key.first);

	}
};

struct myEqual {

	bool operator()(const allowableOperation &a,const allowableOperation &b) const {
		return a.first==b.first;
	}
};

class CalcEngineCreation {
public:
	void RegisterEngines();
	static bool enginesEnabled;
	virtual Icalculation_Engine* GetEngines(const std::string &EngineName,const std::string &input_type);

	virtual ~CalcEngineCreation() = default;

private:
	virtual void registerNewEngines();
	std::unordered_map<allowableOperation,Icalculation_Engine*,newhash,myEqual> available_engines;
};

}

#endif /* SINGLETON_HPP_ */
