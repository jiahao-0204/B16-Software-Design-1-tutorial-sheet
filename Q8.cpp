/**
 * * Inheritance: 
 * 
 * It is desired to write a class hierarchy for a set of graphics shapes, all of 
 * which have a position and orientation in 3D space, and which need to implement 
 * a method to draw themselves. The geometric objects are: Point, Line, Plane, Cube, 
 * Ellipsoid, Quadric, Cone, Cuboid.
 * 
 * 
 * ? (a) Draw a likely class hierarchy.
 * 
 * Shape
 * ├── Point
 * ├── Line
 * ├── Plane
 * ├── Cuboid
 * │   └── Cube
 * └── Quadric
 *     ├── Ellipsoid
 *     └── Cone

 * ? (b) Design the base class.
 * 
 * see below
 * 
 * 
 * ? (c) Explain why, by using a base class and hierarchy, the process of adding a 
 * ? new subclass, such as a Sphere, is greatly simplified.
 * 
 * by inheritance from the Shape class, the Sphere class doesn't have to define
 * position, orientation again
 */


class Vector3
{
    public:
        double x;
        double y;
        double z;

        // other necessary member data and functions such as operator overloadings etc.
};


class Shape
{
    private:
        Vector3 position;
        Vector3 orientation;
    
    public:
        virtual void draw() = 0;

};
