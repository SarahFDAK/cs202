//
//  SVGcode.hpp
//  IditarodChallenge5
//
//  Created by Sarah Carter on 4/19/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//

#ifndef SVGcode_hpp
#define SVGcode_hpp

#include <stdio.h>

#include "CityNode.hpp"

double convertPoint(double xmin, double xmax, double ymin, double ymax, double dimension);

std::string ChartPath(CityList& list, std::vector<int>& bestPath, double xmin, double xmax, double ymin, double ymax);

std::string buildSVG(const std::string& chartData, double xmax, double ymax);

void CreateFile

#endif /* SVGcode_hpp */
