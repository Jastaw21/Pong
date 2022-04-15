
#include "Ball.h"
#include "CppUnitTest.h"
#include "Geometry.h"
#include "Location.h"
#include "Paddle.h"
#include "Specialisations.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting {
TEST_CLASS(LocationClassTests) {
 public:
  XY test{2, 2};
  XY test2{4, 4};
  TEST_METHOD(plusop) {
    auto testcase = test + test2;
    Assert::AreEqual(6, testcase.x());
    Assert::AreEqual(6, testcase.y());
  }
  TEST_METHOD(minop) {
    auto testcase = test2 - test;
    Assert::AreEqual(2, testcase.x());
    Assert::AreEqual(2, testcase.y());
  }
  TEST_METHOD(multop) {
    auto testcase = test * test2;
    Assert::AreEqual(8, testcase.x());
    Assert::AreEqual(8, testcase.y());
  }
  TEST_METHOD(divop) {
    auto testcase = test2 / test;
    Assert::AreEqual(2, testcase.x());
    Assert::AreEqual(2, testcase.y());
  }
  TEST_METHOD(assignop) {
    test = test2;
    Assert::AreEqual(test.x(), test2.x());
  }
};
TEST_CLASS(BallClassTests) {
 public:
  WindowGeom w;
  Ball ball{w};

  TEST_METHOD(intitialised) {
    Assert::AreEqual(static_cast<pix>((w.WIDTH / 2) - (ball.w / 2)),
                     ball.xPos());
    Assert::AreEqual(static_cast<pix>((w.HEIGHT / 2)), ball.yPos());
    Assert::AreEqual(static_cast<pix>(8), ball.size_get());
  }
  TEST_METHOD(setters) {
    // resize
    ball.resize(12);
    Assert::AreEqual(static_cast<pix>(12), ball.size_get());

    // move
    ball.move(XY(150, 153));
    Assert::AreEqual(static_cast<pix>(150), ball.xPos());
    Assert::AreEqual(static_cast<pix>(153), ball.yPos());
  }
};
TEST_CLASS(PaddleClassTests) {
  WindowGeom wg{500, 500};
  Player player{wg};
  Opponent opponent{wg};
  TEST_METHOD(MaxXy) {
    Assert::AreEqual(500, player.maxX());
    Assert::AreEqual(500 - player.length(), player.maxY());
    Assert::AreEqual(500 - opponent.width(), opponent.maxX());
    Assert::AreEqual(500 - opponent.length(), opponent.maxY());
  }
  TEST_METHOD(InitPos) {
    auto halfway = (500 / 2);
    auto adjustedforlength = halfway - (player.length() / 2);
    Assert::AreEqual(adjustedforlength, player.rectangle_m.y);
    Assert::AreEqual(10, player.x());
    Assert::AreEqual(485, opponent.x());
  }
  TEST_METHOD(DefaultColourInit) {
    Assert::AreEqual(255, player.b());

    Assert::AreEqual(255, opponent.b());
  }
  TEST_METHOD(setters) {
    // move by XY
    player.move(XY(134, 12));
    Assert::AreEqual(134, player.x());
    Assert::AreEqual(12, player.y());

    // move by individual params
    player.move(12, 99);
    Assert::AreEqual(12, player.x());
    Assert::AreEqual(99, player.y());

    // up
    player.up(12);
    Assert::AreEqual(99 - 12, player.y());
    Assert::AreEqual(12, player.x());
  }

  TEST_METHOD(enumtest) { Assert::AreEqual(1, static_cast<int>(Bounds::LEFT)); }
};

}  // namespace UnitTesting
