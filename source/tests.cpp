#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include "shape.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

TEST_CASE ("Sphere Constructor and get methods ", "[Aufg. 5.2]")
{
  Sphere s {};
  REQUIRE (s.getCenter().x == 0.0f);
  REQUIRE (s.getCenter().y == 0.0f);
  REQUIRE (s.getCenter().z == 0.0f);
  REQUIRE (s.getRadius() == 1.0f);

  glm::vec3 g {2.0f};
  Color c {0.0f, 0.0f, 0.0f};
  std::string st = "name";
  Sphere s2 {g, 3.0f, c, st};
  REQUIRE (s2.getCenter().x == 2.0f);
  REQUIRE (s2.getCenter().y == 2.0f);
  REQUIRE (s2.getCenter().z == 2.0f);
  REQUIRE (s2.getRadius() == 3.0f);

  glm::vec3 g2 {2.0f, 4.0f, 3.0f};               //(x,y,z)
  Color c2 {0.0f, 0.0f, 0.0f};
  std::string st2 = "name";
  Sphere s3 {g2, 6.0f, c2, st2};
  REQUIRE (s3.getCenter().x == 2.0f);
  REQUIRE (s3.getCenter().y == 4.0f);
  REQUIRE (s3.getCenter().z == 3.0f);
  REQUIRE (s3.getRadius() == 6.0f);

}

TEST_CASE ("Sphere shape-functions ", "[Aufg. 5.2]")
{
  glm::vec3 g {2.0f};
  Color c {0.0f, 0.0f, 0.0f};
  std::string st = "name";
  Sphere s {g, 4.0f, c, st};
  REQUIRE (s.area() == 201.0619298f);
  REQUIRE (s.volume() == 268.0825731f);
}

TEST_CASE ("Box Constructor and get methods ", "[Aufg. 5.2]")
{
  Box b {};
  REQUIRE (b.getMin().x == -1.0f);
  REQUIRE (b.getMin().y == -1.0f);
  REQUIRE (b.getMin().z == -1.0f);
  REQUIRE (b.getMax().x == 1.0f);
  REQUIRE (b.getMax().y == 1.0f);
  REQUIRE (b.getMax().z == 1.0f);

  glm::vec3 g {3.0f};                   //min
  glm::vec3 g2 {4.0f};                  //max
  Color c {0.0f, 0.0f, 0.0f};
  std::string st = "name";
  Box b2 {g, g2, c, st};                       //(min, max) --> (min(x,y,z), max(x,y,z))
  REQUIRE (b2.getMin().x == 3.0f);
  REQUIRE (b2.getMin().y == 3.0f);
  REQUIRE (b2.getMin().z == 3.0f);
  REQUIRE (b2.getMax().x == 4.0f);
  REQUIRE (b2.getMax().y == 4.0f);
  REQUIRE (b2.getMax().z == 4.0f);
}


TEST_CASE ("Box shape-functions ", "[Aufg. 5.2]")
{
  glm::vec3 g {2.0f};
  glm::vec3 g2 {5.0f};
  Color c {0.0f, 0.0f, 0.0f};
  std::string st = "name";
  Box b {g, g2, c, st};
  REQUIRE (b.area() == 54.0f);
  REQUIRE (b.volume() == 27.0f);
}

TEST_CASE ("Sphere Color and Name ", "[Aufg. 5.3]")
{
  glm::vec3 g {2.0f};
  Color c {0.0f, 0.0f, 0.0f};       //rot, grün, blau
  std::string st = "name";
  Sphere s {g, 4.0f, c, st};
  REQUIRE (s.getName() == "name");
  REQUIRE (s.getColor().r == 0.0f);
  REQUIRE (s.getColor().g == 0.0f);
  REQUIRE (s.getColor().b == 0.0f);
}

TEST_CASE ("Box Color and Name ", "[Aufg. 5.3]")
{
  glm::vec3 g {2.0f};
  glm::vec3 g2 {5.0f};
  Color c {0.0f, 0.0f, 0.0f};
  std::string st = "name";
  Box b {g, g2, c, st};
  REQUIRE (b.getName() == "name");
  REQUIRE (b.getColor().r == 0.0f);
  REQUIRE (b.getColor().g == 0.0f);
  REQUIRE (b.getColor().b == 0.0f);
}

TEST_CASE ("Sphere print ", "[Aufg. 5.5]")
{
  glm::vec3 g {2.0f};
  Color c {0.0f, 0.0f, 0.0f};       //rot, grün, blau
  std::string st = "Sphere";
  Sphere s {g, 4.0f, c, st};
  std::cout << s;
}

TEST_CASE ("Box print ", "[Aufg. 5.5]")
{
  glm::vec3 g {2.0f};
  glm::vec3 g2 {5.0f};
  Color c {0.0f, 0.0f, 0.0f};
  std::string st = "Box";
  Box b {g, g2, c, st};
  std::cout << b;
}

TEST_CASE (" intersectRaySphere ", "[Aufg. 5.6]")
{
  //Ray
  glm::vec3 ray_origin {0.0 ,0.0 ,0.0};
  glm::vec3 ray_direction {0.0 ,0.0 ,1.0};

  //Sphere
  glm::vec3 sphere_center {0.0 ,0.0 ,5.0};
  float sphere_radius {1.0};
  float distance {0.0};

  auto result = glm::intersectRaySphere(
    ray_origin, ray_direction,
    sphere_center,
    sphere_radius * sphere_radius,    
    distance);
  REQUIRE (distance == Approx (4.0f));

  //Eigener Test

  //Nr. 1
  //Ray
  glm::vec3 origin {2.0};
  glm::vec3 direction {0.0, 0.0, 1.0};
  Ray r {origin, direction};

  //Sphere
  glm::vec3 g {2.0f};
  Color c {0.0f, 0.0f, 0.0f};       //rot, grün, blau
  std::string st = "Sphere";
  Sphere s {g, 4.0f, c, st}; 

  float dis {0.0};

  auto res = s.intersect(r,dis);

  REQUIRE( dis == 4.0f);

  //Nr. 2
  //Ray
  glm::vec3 orig {0.0, 3.0, 0.0};
  glm::vec3 direc {0.0, 0.0, 2.0};
  Ray r2 {orig, direc};

  //Sphere
  glm::vec3 h {0.0f};
  Color c2 {0.0f, 0.0f, 0.0f};       //rot, grün, blau
  std::string st2 = "Sphere";
  Sphere s2 {h, 2.0f, c2, st2}; 

  float dis2 {0.0};

  auto res2 = s2.intersect(r2,dis2);

  REQUIRE(dis2 == 0.0f);

}

TEST_CASE ("Destruktor Beispiel", "[Aufg. 5.8]")
{
  Color red (255,0,0);
  glm::vec3 position (0.0f, 0.0f, 0.0f);
  Sphere* s1 = new Sphere(position, 1.2, red, "sphere0");
  Shape* s2 = new Sphere(position, 1.2, red, "sphere1");
  s1 -> print (std::cout);
  s2 -> print (std::cout);
  delete s1;
  delete s2;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
