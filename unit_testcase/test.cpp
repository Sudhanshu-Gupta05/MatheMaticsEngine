/*
 * test.cpp
 *
 *  Created on: 28-Jan-2018
 *      Author: sudhanshu
 */


#include "calc.hpp"
#include "gtest/gtest.h"

/*******Test Data Setup ***************/
extern int no_of_params;
extern char **parameters;
extern int file_list ;//deault 0 for integers

class MathTest:public ::testing::Test {
public:
	virtual void SetUp(){
		engine.RegisterEngines();
		ptr = engine.GetEngines(parameters[1],"integer");
		result = 0;
	}
	virtual void TearDown() {
		engine.enginesEnabled = false;
		result = 0;
	}
	mathematics::CalcEngineCreation engine;
	Icalculation_Engine *ptr;
	int result ;
};

// test data setup done

// Test starts

/*
 * This test whether command line arguments are correctly supplied
 */
TEST(Mathematics,start){
	bool validparams = validCommandLine(no_of_params,parameters);
	ASSERT_EQ(validparams,true) << "valid args not supplied";
}

/*
 * This test whether all different engines are setup properly
 * when command line arguments are supplied
 */
TEST_F(MathTest,enginesetup){
	ASSERT_EQ(engine.enginesEnabled,true) << "Calculation start engine failed";
	auto getCalculationEngine = engine.GetEngines(parameters[1],"integer");
	ASSERT_NE(getCalculationEngine,nullptr)<< "Engine registration failed";
}

/*
 * This test case is fixed output testing
 */
TEST_F(MathTest,operations_Divide){
	int argc_manual = 4;
	char* argv_manual[4] = {"Mathematics","Divider","20","10"};
	auto getCalculationEngine = engine.GetEngines(std::string(argv_manual[1]),"integer");
	listofIntegers(argc_manual, argv_manual,getCalculationEngine,result);
	EXPECT_EQ(result,2) << "Caculation failed";
}

/*
 * List of integers not supported by Multiplier
 */
TEST_F(MathTest,operations_Multiply){
	int argc_manual = 4;
	char* argv_manual[4] = {"Mathematics","Multiplier","20","10"};

	//Check the data with standard output
	std::stringstream buffer;
	std::streambuf *sbuf = std::cout.rdbuf();
	std::cout.rdbuf(buffer.rdbuf());
	std::string output;

	auto getCalculationEngine = engine.GetEngines(std::string(argv_manual[1]),"integer");
	listofIntegers(argc_manual, argv_manual,getCalculationEngine,result);
	std::getline(buffer,output);

	EXPECT_STREQ(output.c_str(),"List of Integers are not supported with Multiplier");

	std::cout.rdbuf(sbuf);
	EXPECT_EQ(result,0) << "Caculation failed";
}

/*
 * Divider on files
 */

TEST_F(MathTest,operations_DivideFiles){
	int argc_manual = 3;
	char* argv_manual[3] = {"Mathematics","Divider","sudhanshu.txt"};
	auto getCalculationEngine = engine.GetEngines(std::string(argv_manual[1]),"integer");
	listofFiles(argc_manual, argv_manual,getCalculationEngine,result);
	EXPECT_EQ(result,2) << "Caculation failed";
}

/*
 * Mutiplier on files
 */
TEST_F(MathTest,operations_MultiplyFiles){
	int argc_manual = 3;
	char* argv_manual[3] = {"Mathematics","Multiplier","sudhanshu.txt"};
	auto getCalculationEngine = engine.GetEngines(std::string(argv_manual[1]),"integer");
	listofFiles(argc_manual, argv_manual,getCalculationEngine,result);
	EXPECT_EQ(result,200) << "Caculation failed";
}

/*
 * Generic functions : Needs to get specialized function from user
 * Support is added only for list of integers..can be extended further
 */
TEST_F(MathTest,operations_Generic){
	int argc_manual = 4;
	char* argv_manual[4] = {"Mathematics","Generic","20","10"};

	//Check the data with standard output
	std::stringstream buffer;
	std::streambuf *sbuf = std::cout.rdbuf();
	std::cout.rdbuf(buffer.rdbuf());
	std::string output;

	auto getCalculationEngine = engine.GetEngines(std::string(argv_manual[1]),"integer");
	listofIntegers(argc_manual, argv_manual,getCalculationEngine,result);
	std::getline(buffer,output);

	EXPECT_STREQ(output.c_str(),"Users need to specialize the functions");

	std::cout.rdbuf(sbuf);
	EXPECT_EQ(result,0) << "Caculation failed";
}
