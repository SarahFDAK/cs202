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

//Modify coordinates to be smaller numbers, while still the same relative positions
double convertPoint(const double v, double vmax, double vmin, double dimension1, double dimension2){
    double vConvert = 0.0;
    vConvert = dimension1 - dimension2 * (v - vmin) / (vmax - vmin);
    return vConvert;
}

//Get an individual string of path points
std::string ChartPath(CityList& list, CityPath& bestPath, double xmin, double xmax, double ymin, double ymax){
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
    
    for(size_t i = 0; i < bestPath.getPathSize()-1; i++){
        cityData = list.getCityNode(bestPath.getPathEntry(i)-1);

        y = convertPoint(cityData.getNodeLat(), ymax, ymin, 2080.0,1080.0);
        x = convertPoint(cityData.getNodeLong(), xmax, xmin,1980.0,1920.0);

        //Create paths between points
        if(i == 0)
            city = "M " + std::to_string(x) + " " + std::to_string(y) + " ";
        else if(i == bestPath.getPathSize()-2)
            city = "L " + std::to_string(x) + " " + std::to_string(y) + " Z\" fill=\"transparent\" stroke=\"blue\"/>\n\n";
        else
            city = "L " + std::to_string(x) + " " + std::to_string(y) + " ";
        //Add all path information to string
        svgPath += city;
        
        //Create points
//        point = "<circle cx=\"" + std::to_string(x) + "\" cy=\"" + std::to_string(y)
//                + "\" r=\"2\" fill=\"red\"/>\n";
//        //Add point information to string
//        svgPoints += point;
    }
    //Concatenate path and points strings and return string
//    svgData = svgPath + svgPoints;
    return svgPath;
}

//Get an individual string of chart points
std::string ChartPoints(CityList& list, CityPath& bestPath, double xmin, double xmax, double ymin, double ymax){
//    for(size_t i = 0; i < bestPath.size(); i++)
//        std::cout << bestPath[i] << std::endl;
    std::string svgPoints;
//    std::string city;
    std::string point;
    CityNode cityData;
    double x = 0.0;
    double y = 0.0;
    
    for(size_t i = 0; i < bestPath.getPathSize()-1; i++){
        cityData = list.getCityNode(bestPath.getPathEntry(i)-1);

        y = convertPoint(cityData.getNodeLat(), ymax, ymin, 2080.0,1080.0);
        x = convertPoint(cityData.getNodeLong(), xmax, xmin,1980.0,1920.0);

        //Create paths between points
//        if(i == 0)
//            city = "M " + std::to_string(x) + " " + std::to_string(y) + " ";
//        else if(i == bestPath.getPathSize()-2)
//            city = "L " + std::to_string(x) + " " + std::to_string(y) + " Z\" fill=\"transparent\" stroke=\"blue\"/>\n\n";
//        else
//            city = "L " + std::to_string(x) + " " + std::to_string(y) + " ";
//        //Add all path information to string
//        svgPath += city;
        
        //Create points
        point = "<circle cx=\"" + std::to_string(x) + "\" cy=\"" + std::to_string(y)
                + "\" r=\"2\" fill=\"red\"/>\n";
        //Add point information to string
        svgPoints += point;
    }
    //Concatenate path and points strings and return string
    return svgPoints;
}

//Build entire SVG data string with image dimensions
std::string buildSVG(const std::string& chartPath, const std::string& chartPoints, double width, double height){
    std::string svgContents = "<svg width=\"" + std::to_string(width) + "\" height=\"" + std::to_string(height)+ "\" xmlns=\"http://www.w3.org/2000/svg\">\n\n";
    svgContents += chartPath;
    svgContents += chartPoints;
    svgContents += "\n</svg>";
    return svgContents;
}

//Build SVG file
bool CreateFile(const std::string& svgData, const std::string& title){
    std::string outputFile = title + ".svg";
    std::ofstream fout(outputFile);
    if(!fout)
        return false;
    fout << svgData;
    return true;
}

//Print SVG files as the algorithm progresses
void inProgress(CityList& list, CityPath& bestPath, CityPath& tempPath){
    bestPath.deleteUsed(bestPath.getPathEntry(bestPath.getPathSize()));
    int listLength = list.getCityVectorCount();
    int partSize = listLength/16;
    int count = 0;
    std::string points = ChartPoints(list, bestPath, list.getMinLong(), list.getMaxLong(), list.getMinLat(), list.getMaxLat());
    while(listLength > partSize){
        count++;
        for(int i = listLength; i > (listLength - partSize); i--){
            tempPath.fillPath(bestPath.getPathEntry(i));
            bestPath.deleteUsed(tempPath.getPathEntry(0));
        }
        std::string tName = "Greedy" + std::to_string(count);
        CreateFile(buildSVG(ChartPath(list, tempPath, list.getMinLong(), list.getMaxLong(), list.getMinLat(), list.getMaxLat()), points, 2500, 2250), tName);
        listLength -= partSize;
    }
    CreateFile(buildSVG(ChartPath(list, tempPath, list.getMinLong(), list.getMaxLong(), list.getMinLat(), list.getMaxLat()), points, 2500, 2250), "GreedyLast");
}


