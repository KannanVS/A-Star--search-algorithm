#ifndef _MAP_H
#define _MAP_H

#include "list.h"
#include "status.h"
typedef struct City {
	char cityName[20];
	int longitude;
	int latitude;
	List* neighbors;
	struct City* prevCity;
	double gn;
	double hn;
} City;

typedef struct Neighbor {
	City* neighborCity;
	int distance;
} Neighbor;

status parseMap(char* fileName,List* cityList);

void initalGn(List* cityList,City* currentCity);
double findHn(City* currentCity,City* goalCity);
void computeHn(List* cityList,City* currentCity,City* goalCity);
status findShortestPath(List* cityList,City* startCity,City* endCity);

#endif
