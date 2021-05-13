
#include "geometry.h"
#include "../include/catch2/catch2.hpp"

using namespace std;


TEST_CASE ("Constructor, if called with 0 arguments, should initialize a point (0,0)", "[Point][default constructor]"){        
        Point p;
        REQUIRE(p.get_x() == 0);
        REQUIRE(p.get_y() == 0);
}


TEST_CASE ("Constructor, if called with two arguments x and y, creates a point located at (x, y)", "[Point][constructor]"){        
        Point p (1,2);
        REQUIRE(p.get_x() == 1);
        REQUIRE(p.get_y() == 2);
}   

TEST_CASE ("set_x should set x coordinate", "[Point]"){        
        Point p (1,1);
        p.set_x(3);
        REQUIRE(p.get_x() == 3);
}   

TEST_CASE ("set_y should set y coordinate", "[Point]"){        
        Point p (1,1);
        p.set_y(3);
        REQUIRE(p.get_y() == 3);
}

TEST_CASE ("Default constructor, it should create an array with size 0", "[PointArray][default constructor]"){        
        PointArray arr;
        REQUIRE(arr.get_size() == 0);
}

TEST_CASE ("Constructor, it should initialize a PointArray with the specified size", "[PointArray][constructor]"){        
        
        Point p1 (1,1);
        Point p2 (1,1);

        Point points [2] = {p1,p2};
        
        PointArray arr (points, 2);

        REQUIRE(arr.get_size() == 2);
}

TEST_CASE ("Constructor, it should initialize a PointArray copying the values from an array", "[PointArray][constructor]"){        
        Point p1 (1,1);
        Point p2 (1,1);

        Point points [2] = {p1,p2};
        
        PointArray array (points, 2);

        REQUIRE(array.get(0)->get_x() == 1);
        REQUIRE(array.get(0)->get_y() == 1);
        REQUIRE(array.get(1)->get_x() == 1);
        REQUIRE(array.get(1)->get_y() == 1);
}

TEST_CASE ("Negative size should throw std::invalid_argument", "[PointArray][constructor]"){        
        Point p1 (1,1);
        Point p2 (1,1);

        Point points [2] = {p1,p2};

        REQUIRE_THROWS_AS( PointArray(points,-2), invalid_argument);  
        
}

TEST_CASE ("Constructor that creates a copy of a given PointArray", "[PointArray][copy constructor]"){        
        const Point p1 (11 , 3);
        PointArray pa;
        pa.push_back(p1);
        
        PointArray pa2(pa);

        REQUIRE(pa.get_size() == pa2.get_size());
        REQUIRE(pa.get(0)->get_x() == pa2.get(0)->get_x());
        REQUIRE(pa.get(0)->get_y() == pa2.get(0)->get_y());
}

/*
TEST_CASE("Destructor that deletes the internal array of the PointArray","[PointArray][destructor]"){
        const Point p1 (11 , 3);
        PointArray pa;
        pa.push_back(p1);

        ~PointArray();
}
*/

TEST_CASE("push_back add a Point to the end of the array","[PointArray]"){
        PointArray pa;
        pa.push_back(Point(1,1));
        pa.push_back(Point(2,2));

        REQUIRE(pa.get(1)->get_x() == 2);
        REQUIRE(pa.get(1)->get_y() == 2);       
}

TEST_CASE("function insert, if pos is negative, throw std::invalid_argument exception","[PointArray]"){
        PointArray pa;
        pa.push_back(Point(1,1));

        REQUIRE_THROWS_AS(pa.insert(-1,Point(2,2)),invalid_argument);       
}

TEST_CASE("function insert, if pos is greater than current size, throw std::invalid_argument exception","[PointArray]"){
        PointArray pa;
        pa.push_back(Point(1,1));

        REQUIRE_THROWS_AS(pa.insert(2,Point(2,2)),invalid_argument);       
}

TEST_CASE("function insert add a Point at some arbitrary position","[PointArray]"){
        PointArray pa;
        pa.push_back(Point(1,1));
        pa.insert(0,Point(2,2));

        REQUIRE(pa.get(0)->get_x() == 2);
        REQUIRE(pa.get(0)->get_y() == 2);       
}

TEST_CASE("function remove, if pos is negative, throw std::invalid_argument exception","[PointArray]"){
        PointArray pa;
        pa.push_back(Point(1,1));
        pa.push_back(Point(2,2));

        REQUIRE_THROWS_AS(pa.remove(-2),invalid_argument);  
}

TEST_CASE("function remove, if pos doesn’t correspond to an existing cell, throw std::invalid_argument exception","[PointArray]"){
        PointArray pa;
        pa.push_back(Point(1,1));
        pa.push_back(Point(2,2));

        REQUIRE_THROWS_AS(pa.remove(2),invalid_argument);  
}

TEST_CASE("function remove, remove a Point at some arbitrary position","[PointArray]"){
        PointArray pa;
        pa.push_back(Point(1,1));
        pa.push_back(Point(2,2));
        pa.remove(0);

        REQUIRE(pa.get(0)->get_x() == 2);
        REQUIRE(pa.get(0)->get_y() == 2);       
}

TEST_CASE("function get_size, get the size of the array","[PointArray]"){
        PointArray pa;
        pa.push_back(Point(1,1));

        REQUIRE(pa.get_size() == 1);
}

/*
TEST_CASE("function clear, remove everything from the array and sets its size to 0","[PointArray]"){
        PointArray pa;
        pa.push_back(Point(1,1));

        pa.clear();

        REQUIRE(pa.get_size() == 0);
        REQUIRE(pa.get(0) == NULL);
}
*/

TEST_CASE("function get, get a pointer to the element at some arbitrary position in the array","[PointArray]"){
        PointArray pa;
        pa.push_back(Point(1,1));

        Point* p1 = pa.get(0);

        REQUIRE(p1->get_x() == 1);
        REQUIRE(p1->get_y() == 1);  
}