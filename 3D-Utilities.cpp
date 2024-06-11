#include <bits/stdc++.h>
using namespace std;

// Data Structure
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

// Constructors
Vector ContructVectorFromPoints(Point A, Point B)
{
    Vector res;
    res.x = B.x - A.x;
    res.y = B.y - A.y;
    res.z = B.z - A.z;
    return res;
}

Line ConstructLineFromPoints(Point A, Point B)
{
    Line res;
    res.StartPoint = A;
    res.DirectionVector = ContructVectorFromPoints(A, B);
    return res;
}

// 3D math utils
double Matrix(double A, double B, double C, double D)
{
    return (double)(A * D - B * C);
}

double DotProd(Vector A, Vector B)
{
    return (double)(A.x * B.x + A.y * B.y + A.z * B.z);
}

Vector CrossProd(Vector A, Vector B)
{
    Vector res;
    res.x = Matrix(A.y, A.z, B.y, B.z);
    res.y = Matrix(A.z, A.x, B.z, B.x);
    res.z = Matrix(A.x, A.y, B.x, B.y);
    return res;
}

double LengthOfVector(Vector A)
{
    return sqrt((pow(A.x, 2) + pow(A.y, 2) + pow(A.z, 2)));
}

// Modules
double DistanceOfLines(Line A, Line B)
{
    Vector CrossProdOfLines = CrossProd(A.DirectionVector, B.DirectionVector);
    return abs(DotProd(CrossProdOfLines, ContructVectorFromPoints(A.StartPoint, B.StartPoint))) / LengthOfVector(CrossProdOfLines);
}

double AngleBetweenLines(Line A, Line B)
{
    double cosTheta = abs(DotProd(A.DirectionVector, B.DirectionVector)) / (LengthOfVector(A.DirectionVector) * LengthOfVector(B.DirectionVector));
    return acos(cosTheta);
}

double DistanceBetweenPointAndLine(Point A, Line L)
{
    double crossProductLength = LengthOfVector(CrossProd(ContructVectorFromPoints(L.StartPoint, A), L.DirectionVector));
    double directionVectorLength = LengthOfVector(L.DirectionVector);
    return crossProductLength / directionVectorLength;
}

// Standard IO
Point PointInput(string msg)
{
    cout << msg << " > \n";
    Point res;
    cin >> res.x >> res.y >> res.z;
    return res;
}

void PointOutput(Point A)
{
    cout << setprecision(16) << "(" << A.x << ", " << A.y << ", " << A.z << ")";
}

void VectorOutput(Vector A)
{
    cout << setprecision(16) << "(" << A.x << ", " << A.y << ", " << A.z << ")";
}

// Main thread
int main()
{

    return 0;
}