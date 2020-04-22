//
//  SVGcode.cpp
//  IditarodChallenge5
//
//  Created by Sarah Carter on 4/19/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#include "SVGcode.hpp"

std::string ChartPath(CityList& list, std::vector<int>& bestPath){
    std::string svgData;
    
    std::string svgPath = "<path d=\"";
    std::string svgPoints;
    std::string city;
    std::string point;
    CityNode cityData;
    double x = 0.0;
    double y = 0.0;
    
    for(size_t i = 0; i < bestPath.size()-1; i++){
        cityData = list.getCityNode(bestPath[i]);
        x = cityData.getNodeLat();
        y = cityData.getNodeLong();
        
        if(i == 0)
            city = "M " + std::to_string(x) + " " + std::to_string(y) + " ";
        else if(i == bestPath.size()-2)
            city = "L " + std::to_string(x) + " " + std::to_string(y) + " Z\"/>\n\n";
        else
            city = "L " + std::to_string(x) + " " + std::to_string(y) + " ";
        svgPath += city;
        
        point = "<circle cx=\"" + std::to_string(x) + "\" cy=\"" + std::to_string(y)
                + "\" r=\"1\" fill=\"red\"/>\n";
        svgPoints += point;
    }
    svgData = svgPath + svgPoints;
    return svgData;
}
