#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#include <stdexcept>

// Data Structures
struct Point
{
    double x;
    double y;
    double z;
};

struct Vector
{
    double x;
    double y;
    double z;
};

struct Line
{
    Point StartPoint;
    Vector DirectionVector;
};

struct Plane
{
    Point StartPoint;
    Vector NormalVector;
};

// Function Declarations

#endif // GEOMETRY_H
