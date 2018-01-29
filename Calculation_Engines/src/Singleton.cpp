/*
 * Singleton.cpp
 *
 *  Created on: 19-Jan-2018
 *      Author: sudhanshu
 */

#include "Singleton.hpp"


namespace mathematics {

Divider* Divider::_instance = nullptr;
Multiplier* Multiplier::_instance = nullptr;
GenericEngine* GenericEngine::_instance = nullptr;
bool CalcEngineCreation::enginesEnabled = false;


void CalcEngineCreation::RegisterEngines() {
	//	std::call_once (enginesEnabled,[&]{ this->registerNewEngines(); });

	if(!enginesEnabled)
	{
		this->registerNewEngines();
		enginesEnabled = true;
	}
}

void CalcEngineCreation::registerNewEngines() {
	//Register Multiplier
	allowableOperation multiplier_Data(allowableOperation(std::string("Multiplier"),std::string("integer")));
	auto multiplierInstance = Multiplier::createINstance();
	available_engines.insert(std::pair<allowableOperation,Icalculation_Engine*>(multiplier_Data,multiplierInstance));

	//Register Divider
	allowableOperation divider_Data(allowableOperation(std::string("Divider"),std::string("integer")));
	auto dividerInstance = Divider::createINstance();
	available_engines.insert(std::pair<allowableOperation,Icalculation_Engine*>(divider_Data,dividerInstance));

	//Register Generic Engine
	allowableOperation generic_Data(allowableOperation(std::string("Generic"),std::string("integer")));
	auto genericInstance = GenericEngine::createINstance();
	available_engines.insert(std::pair<allowableOperation,Icalculation_Engine*>(generic_Data,genericInstance));

}

Icalculation_Engine* CalcEngineCreation::GetEngines(const std::string &EngineName,const std::string &input_type)
{

	allowableOperation input_Data(allowableOperation(EngineName,input_type));
	auto itr = available_engines.find(input_Data);
	if(itr != available_engines.end())
	{
		if(itr->first.second == input_Data.second)
		{
			return itr->second;
		}
	}

	return nullptr;
}

}//end namespace mathematics



