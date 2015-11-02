#include "Material.hpp"
#include "Vector.hpp"
#include "Line.hpp"
#include "Intersection.hpp"

#ifndef RT_GEOMETRY_INCLUDED
#define RT_GEOMETRY_INCLUDED

namespace rt {

  class Geometry {
  private:
    Material _material;
    public: Vector _cen;

  public:
    Geometry(const Material& material) {
      _material = Material(material);
    }

    Geometry(const Geometry& geometry) {
      _material = Material(geometry.material());
    }

    virtual Intersection getIntersection(const Line& line,
                                         double minDist,
                                         double maxDist) {
      Intersection in(false, *this, line, 0);
      return in;
    };

    inline const Material material() const {
      return _material;
    }


  };
}

#endif
