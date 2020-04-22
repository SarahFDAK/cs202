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

double convertPoint(const double v, double vmax, double vmin, double dimension1, double dimension2);

std::string ChartPath(CityList& list, std::vector<int>& bestPath, double xmin, double xmax, double ymin, double ymax);

std::string buildSVG(const std::string& chartData, double xmax, double ymax);

bool CreateFile(const std::string& svgData, const std::string& title);

#endif /* SVGcode_hpp */
