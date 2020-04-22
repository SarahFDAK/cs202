//
//  SVGcode.cpp
//  IditarodChallenge5
//
//  Created by Sarah Carter on 4/19/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "SVGcode.hpp"

std::string ChartPath(CityList& list, std::vector<int>& bestPath){
    std::string svgPath;
    std::string city;
    CityNode cityData;
    double x;
    double y;
    
    for(size_t i = 0; i < bestPath.size(); i++){
        cityData = list.getCityNode(bestPath[i]);
        x = cityData.getNodeLat();
        y = cityData.getNodeLong();
        
        if(i == 0)
            city = "M " + std::to_string(x) + " " + std::to_string(y) + " ";
        else if(i == bestPath.size()-1)
            city = "L " + std::to_string(x) + " " + std::to_string(y) + " Z";
        else
            city = "L " + std::to_string(x) + " " + std::to_string(y) + " ";
        svgPath += city;
    }
    return svgPath;
}
