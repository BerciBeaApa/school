#include "Vector.hpp"
#include "Line.hpp"
#include "Color.hpp"
#include "Intersection.hpp"

#ifndef RT_LIGHT_INCLUDED
#define RT_LIGHT_INCLUDED

namespace rt {

  class Light {
  private:
    Color _ambient;
    Color _diffuse;
    Color _specular;
    double _intensity;

  public:
    Light(Color& ambient, Color& diffuse, Color& specular,
             double intensity) {
      _ambient = Color(ambient);
      _diffuse = Color(diffuse);
      _specular = Color(specular);

      _intensity = intensity;
    }

    Light(Light& mat) {
      _ambient = Color(mat.ambient());
      _diffuse = Color(mat.diffuse());
      _specular = Color(mat.specular());

      _intensity = mat.intensity();
    }

    inline Color& ambient() {
      return _ambient;
    }

    inline Color& diffuse() {
      return _diffuse;
    }

    inline Color& specular() {
      return _specular;
    }

    inline double intensity() {
        return _intensity;
    }
  };
}

#endif

