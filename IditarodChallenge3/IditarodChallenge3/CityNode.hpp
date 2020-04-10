//
//  CityNode.hpp
//  IditarodChallenge3
//
//  Created by Sarah Carter on 4/9/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef CityNode_hpp
#define CityNode_hpp

#include <stdio.h>

class CityNode {
public:
    CityNode ();
    
    ~CityNode ();
private:
    int nodeNum_;
    double nodeLat_;
    double nodeLong_;
    double graphX_;
    double graphY_;
};

class CityList {
    
};

#endif /* CityNode_hpp */
