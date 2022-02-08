/** 
 * * Classes: 
 * 
 * You are to design a program for a mass-spring simulation. The program will 
 * make use of three classes: Mass, Spring and World. The Mass class, naturally, will 
 * have some intrinsic properties such as mass, position and velocity. Each mass will 
 * need to be able to update itself based on the force(s) applied to it. The Spring
 * class will also have properties and will supply a force based on how far apart
 * its ends are (as given by the mass positions). The physical system will comprise 
 * two masses joined by a spring, encoded in the World class. Design the class interfaces 
 * required for this program and explain (in words) how the classes will interact.
 */

#include <vector>

class Mass 
{
    private:
        double m;
        double x;
        double y;
        double vx;
        double vy;
        double f;
        double r;

    public:
        Mass(double _m, double _x, double _y, double _vx, double _vy, double _r) : x(_x), y(_y), vx(_vx), vy(_vy), r(_r) {};

        void setForce(double force);
        void addForce(double force);
        
        double getX();
        double getY();
        double getVX();
        double getVY();
        double getR;

        void step();
};


class Spring
{
    private:
        double l0;
        double k;
        double d;

        Mass * mass1;
        Mass * mass2;

    public:
        Spring(double _l0, double _k, double _d) : l0(_l0), k(_k), d(_d) {};

        double getForce();

};


class World
{
    private:
        std::vector<Spring> spring_list;
        std::vector<Mass *> mass_list;

        double gravity;

    public:
        
        void step();
        void display();

        void addSpring(std::vector<Spring> more_spring);
        void loadExample();
        void setGravity(double _gravity); // ! member function can not have initialization list!
};


/** 
 * masses are the main component of this simulation. it stores the position, velocity and forces required for update. 
 * 
 * spring will stored pointer to the masses, to obtain position of its ends to calculate forces. springs merely provide
 * a force that acts upon the masses 
 * 
 * world stores a vector of springs and a vector of pointers of masses. so that it can uses its springs to obtain forces.
 * it also stores the pointer of masses because a mass can be connected to multiple springs and by storing their pointers we 
 * can identify duplicates. 
 * 
 * 
 * should separate functionality of spring and mass, one should not store the other. 
 * world should have data structure to store connection between mass and spring
 * 
 */
