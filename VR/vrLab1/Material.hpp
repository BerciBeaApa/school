#include "Vector.hpp"
#include "Line.hpp"
#include "Color.hpp"
#include "Intersection.hpp"

#ifndef RT_MATERIAL_INCLUDED
#define RT_MATERIAL_INCLUDED

namespace rt {

  class Material {
  private:
    Color _ambient;
    Color _diffuse;
    Color _specular;
    double _shininess;
    double _opacity;
    double _reflectivity;

  public:
      Material() {
      }

    Material(Color& ambient, Color& diffuse, Color& specular,
             double shininess, double opacity, double reflectivity) {
      _ambient = Color(ambient);
      _diffuse = Color(diffuse);
      _specular = Color(specular);

      _shininess = shininess;
      _opacity = opacity;
      _reflectivity = reflectivity;
    }

    Material(const Material& mat) {
      _ambient = Color(mat.ambient());
      _diffuse = Color(mat.diffuse());
      _specular = Color(mat.specular());

      _shininess = mat.shininess();
      _opacity = mat.opacity();
      _reflectivity = mat.reflectivity();
    }

    inline const Color& ambient() const {
      return _ambient;
    }

    inline const Color& diffuse() const {
      return _diffuse;
    }

    inline const Color& specular() const {
      return _specular;
    }

    inline double shininess() const {
      return _shininess;
    }

    inline double opacity() const {
      return _opacity;
    }

    inline double reflectivity() const {
      return _reflectivity;
    }
  };
}

#endif
