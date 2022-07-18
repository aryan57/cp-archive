#include <iostream>
using namespace std;
class Shapes
{
public:
	// Abstract Base Class
	virtual void draw() = 0; // Pure Virtual Function
};
class Polygon : public Shapes
{
	// Concrete Class
	void draw() { cout << "Polygon: Draw by Triangulation" << endl; }
};
class ClosedConics : public Shapes
{
	// Abstract Base Class
	// draw() inherited - Pure Virtual
	virtual void draw(){
		
	}

};
class Triangle : public Polygon
{
public:
	// Concrete Class
	void draw() { cout << "Triangle: Draw by Lines" << endl; }
};
class Quadrilateral : public Polygon
{
public:
	// Concrete Class
	void draw() { cout << "Quadrilateral: Draw by Lines" << endl; }
};
class Circle : public ClosedConics
{
public:
	// Concrete Class
	void draw() { cout << "Circle: Draw by Breshenham Algorithm" << endl; }
};
class Ellipse : public ClosedConics
{
public:
	// Concrete Class
	void draw() { cout << "Ellipse: Draw by ..." << endl; }
};
int main()
{
	Shapes *arr[] = {new Triangle, new Quadrilateral, new Circle, new Ellipse};
	for (int i = 0; i < sizeof(arr) / sizeof(Shapes *); ++i)
		arr[i]->draw();
	// ...
	return 0;
}