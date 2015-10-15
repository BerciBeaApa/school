#include "Sphere.hpp"

using namespace rt;

Intersection Sphere::getIntersection(const Line& line,
                                     double minDist,
                                     double maxDist) {
  Intersection in;

  // ADD CODE HERE
    double X0 = line.x0().x();
    double Y0 = line.x0().y();
    double Z0 = line.x0().z();

    double Xd = line.dx().x();
    double Yd = line.dx().y();
    double Zd = line.dx().z();

    double Sr = radius();

    double Xc = center().x();
    double Yc = center().y();
    double Zc = center().z();

    double B = 2 * (Xd * (X0 - Xc) + Yd * (Y0 - Yc) + Zd * (Z0 - Zc));
    double C = (X0 - Xc) * (X0 - Xc) + (Y0 - Yc) * (Y0 - Yc) + (Z0 - Zc) * (Z0 - Zc) - (Sr * Sr);

    double delta = B*B - 4 * C;
    double t1 = 0;
    double t2 = 0;
    double t = 0;

    if(delta >= 0)
    {
        if(delta == 0)
        {
            t = -B / 2;
        }
        else
        {
            t1 = (-B + sqrt(delta)) / 2;
            t2 = (-B - sqrt(delta)) / 2;
            t = t1;
        }

        //Vector vec = new Vector((X0 + Xd * t), (Y0 + Yd * t), (Z0 + Zd * t));

        in = new Intersection(true, *this, line, t);
    }
    else
    {
        in = new Intersection(false, *this, line, t);
    }


  return in;
}

