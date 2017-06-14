#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE ("Sphere Constructor and get methods ", "[Aufg. 5.2]")
{
  Sphere s {};
  REQUIRE (s.getCenter().x == 0.0f);
  REQUIRE (s.getCenter().y == 0.0f);
  REQUIRE (s.getCenter().z == 0.0f);
  REQUIRE (s.getRadius() == 1.0f);

  glm::vec3 g {2.0f};
  Sphere s2 {g, 3.0f};
  REQUIRE (s2.getCenter().x == 2.0f);
  REQUIRE (s2.getCenter().y == 2.0f);
  REQUIRE (s2.getCenter().z == 2.0f);
  REQUIRE (s2.getRadius() == 3.0f);

  glm::vec3 g2 {2.0f, 4.0f, 3.0f};            //  (x,y,z)
  Sphere s3 {g2, 6.0f};
  REQUIRE (s3.getCenter().x == 2.0f);
  REQUIRE (s3.getCenter().y == 4.0f);
  REQUIRE (s3.getCenter().z == 3.0f);
  REQUIRE (s3.getRadius() == 6.0f);

}

TEST_CASE ("Sphere shape-functions ", "[Aufg. 5.2]")
{
  glm::vec3 g {2.0f};
  Sphere s {g, 4.0f};
  REQUIRE (s.area() == 201.0619298f);
  //REQUIRE (s.volume() == 268.0825731f);
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
  Box b2 {g, g2};                       //(min, max) --> (min(x,y,z), max(x,y,z))
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
  Box b {g, g2};
  REQUIRE (b.area() == 54.0f);
  REQUIRE (b.volume() == 27.0f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
