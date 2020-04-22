//
//  SVGcode.cpp
//  IditarodChallenge5
//
//  Created by Sarah Carter on 4/19/20.
//  Copyright © 2020 Sarah Carter. All rights reserved.
//
#include <fstream>

#include "SVGcode.hpp"

double convertPoint(const double v, double vmax, double vmin, double dimension){
    double vConvert = 0.0;
    vConvert = dimension * (v - vmin) / (vmax - vmin) + 10;
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
        x = convertPoint(cityData.getNodeLat(), xmax, xmin,1000.0);
        y = convertPoint(cityData.getNodeLong(), ymax, ymin,700.0);
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

std::string buildSVG(const std::string& chartData, double xmax, double ymax){
    std::string svgContents = "<svg version=\"1.1\"\nbaseProfile=\"full\"\nwidth=\""
                + std::to_string(xmax) + "\" height=\"" + std::to_string(ymax) + "\"\nxmlns=\"http://www.w3.org/2000/svg\">\n\n";
    svgContents += chartData;
    svgContents += "\n</svg>";
    return svgContents;
}

bool CreateFile(const std::string& svgData, const std::string& title){
    std::string outputFile = title + ".svg";
    std::cout << outputFile << std::endl;
    std::ofstream fout(outputFile);
    if(!fout)
        return false;
    fout << svgData;
    return true;
}

