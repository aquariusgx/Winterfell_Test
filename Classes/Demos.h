//
//  Demos.h
//  NutRock_Demo
//
//  Created by guxin on 11/19/13.
//
//

#ifndef NutRock_Demo_Demos_h
#define NutRock_Demo_Demos_h

enum
{
    DEMO_LIST = 0,
    DEMO_DIALOG,
    // last one
	TESTS_COUNT,
};

const std::string g_aTestNames[TESTS_COUNT] = {
    "列表",
    "Dialog",
   
};

static std::string m_data[20] ;

#endif
