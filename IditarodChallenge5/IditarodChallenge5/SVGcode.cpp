//
//  SVGcode.cpp
//  IditarodChallenge5
//
//  Created by Sarah Carter on 4/19/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//
#include <fstream>
#include <utility>

#include "SVGcode.hpp"

double convertPoint(const double v, double vmax, double vmin, double dimension1, double dimension2){
    double vConvert = 0.0;
    vConvert = dimension1 - dimension2 * (v - vmin) / (vmax - vmin);
    return vConvert;
}

std::string ChartPath(CityList& list, std::vector<int>& bestPath, double xmin, double xmax, double ymin, double ymax){
    std::string svgData;
//    for(size_t i = 0; i < bestPath.size(); i++)
//        std::cout << bestPath[i] << std::endl;
    std::string svgPath = "<path d=\"";
    std::string svgPoints;
    std::string city;
    std::string point;
    CityNode cityData;
    double x = 0.0;
    double y = 0.0;
    
    for(size_t i = 0; i < bestPath.size()-1; i++){
        cityData = list.getCityNode(bestPath[i]-1);
//        std::cout << cityData.getNodeNum() << ", " << cityData.getNodeLat() << ", " << cityData.getNodeLong() << std::endl;
        y = convertPoint(cityData.getNodeLat(), ymax, ymin, 2080.0,1080.0);
        x = convertPoint(cityData.getNodeLong(), xmax, xmin,1980.0,1920.0);
//        std::cout << x << ", " << y << std::endl;
        
        if(i == 0)
            city = "M " + std::to_string(x) + " " + std::to_string(y) + " ";
        else if(i == bestPath.size()-2)
            city = "L " + std::to_string(x) + " " + std::to_string(y) + " Z\" fill=\"transparent\" stroke=\"blue\"/>\n\n";
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

std::string buildSVG(const std::string& chartData, double width, double height){
    std::string svgContents = "<svg width=\"" + std::to_string(width) + "\" height=\"" + std::to_string(height)+ "\" xmlns=\"http://www.w3.org/2000/svg\">\n\n";
    svgContents += chartData;
    svgContents += "\n</svg>";
    return svgContents;
}

bool CreateFile(const std::string& svgData, const std::string& title){
    std::string outputFile = title + ".svg";
    std::ofstream fout(outputFile);
    if(!fout)
        return false;
    fout << svgData;
    return true;
}

