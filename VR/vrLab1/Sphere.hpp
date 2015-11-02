#include "Vector.hpp"
#include "Line.hpp"
#include "Intersection.hpp"
#include "Geometry.hpp"
#include "Color.hpp"

#ifndef RT_SPHERE_INCLUDED
#define RT_SPHERE_INCLUDED

namespace rt {

  class Sphere : public Geometry {
  private:
    Vector _center;
    double _radius;

  public:
    Sphere(const Vector& center, double radius, const Material& material)
    : Geometry(material) {
      _center = Vector(center);
      _cen = Vector(center);
      _radius = radius;
    }

    Sphere(double x, double y, double z, double radius,
           double r, double g, double b)
    : Geometry (Material(*(new Color(r*0.2,g*0.2,b*0.2)), *(new Color(r*0.4,g*0.4,b*0.4)), *(new Color(r*0.6,g*0.6,b*0.6)), 100, 0.5, 0.5)){
      _center = Vector(x, y, z);
      _cen = Vector(x, y, z);
      _radius = radius;
    }

    virtual Intersection getIntersection(const Line& line,
                                         double minDist,
                                         double maxDist);

    inline double& radius() {
      return _radius;
    }

    inline Vector& center() {
      return _center;
    }
  };
}

#endif
