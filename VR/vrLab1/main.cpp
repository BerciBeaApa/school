#include <cmath>
#include <iostream>
#include <string>

#include "Vector.hpp"
#include "Line.hpp"
#include "Geometry.hpp"
#include "Sphere.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "Intersection.hpp"
#include "Material.hpp"
#include "Light.hpp"

#include "Scene.hpp"

using namespace std;
using namespace rt;

double imageToViewPlane(int n, int imgSize, double viewPlaneSize) {
  double u = (double)n*viewPlaneSize/(double)imgSize;
  u -= viewPlaneSize/2;
  return u;
}

const Intersection findFirstIntersection(const Line& ray,
                                         double minDist, double maxDist) {
  Intersection intersection;

  for(int i=0; i<geometryCount; i++) {
    Intersection in = scene[i]->getIntersection(ray, minDist, maxDist);
    if(in.valid()) {
      if(!intersection.valid()) {
        intersection = in;
      }
      else if(in.t() < intersection.t()) {
        intersection = in;
      }
    }
  }

  return intersection;
}

int main() {
  Vector viewPoint(0, 0, 0);
  Vector viewDirection(0, 0, 1);
  Vector viewUp(0, -1, 0);

  double frontPlaneDist = 2;
  double backPlaneDist = 1000;

  double viewPlaneDist = 100;
  double viewPlaneWidth = 200;
  double viewPlaneHeight = 100;

  int imageWidth = 1000;
  int imageHeight = 500;

  Vector viewParallel = viewUp^viewDirection;

  viewDirection.normalize();
  viewUp.normalize();
  viewParallel.normalize();

  Image image(imageWidth, imageHeight);

  // ADD CODE HERE
  Color *c = new Color(0,0,0);
    Vector orig = Vector(0,0,0);
    Vector L = Vector(-100, 20, 50);
    Light* li = new Light(*(new Color(1,1,1)), *(new Color(1,1,1)), *(new Color(1,1,1)), 1.5);

  for(int i=0;i<imageWidth;i++)
  {
	  for(int j=0;j<imageHeight;j++)
	  {
	      Vector point = Vector(imageToViewPlane(i, imageWidth, viewPlaneWidth), imageToViewPlane(j, imageHeight, viewPlaneHeight), viewPlaneDist);
		  Line ray = Line(orig, point, true);
		  Intersection in = findFirstIntersection(ray, 0, 0);
		  if(in.valid())
          {
                Vector N = in.vec() - in.geometry()._cen;
                N.normalize();
                Vector T = L - in.vec();
                T.normalize();
                Vector E = viewPoint - in.vec();
                E.normalize();
                Color col = in.geometry().material().ambient()*li->ambient();
                Vector R = N*(N*T)*2 - T;
                R.normalize();
                if(N*T > 0)
                {
                    col += in.geometry().material().diffuse()*li->diffuse()*(N*T);
                }
                if(E*R > 0)
                {
                    col += in.geometry().material().specular()*li->specular()*pow(E*R, in.geometry().material().shininess());
                }
                col *= li->intensity();
                image.setPixel(i,j,col);
          }
          else
          {
                image.setPixel(i,j,*c);
          }
	  }
  }

  image.store("scene.ppm");

  for(int i=0; i<geometryCount; i++) {
    delete scene[i];
  }

  return 0;
}
