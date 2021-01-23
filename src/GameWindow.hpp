#pragma once

#include <Gosu/Gosu.hpp>

struct Point
{
    double x;
    double y;
};

class GameWindow : public Gosu::Window
{
public:
    GameWindow();

    void update() override;

    void draw() override;

    void button_down(Gosu::Button _button) override;
    void button_up(Gosu::Button _button) override;

    bool needs_cursor() const override;

    Gosu::Image checkerboard;
    Gosu::Image checkerboard_macro;

    Point corners[4];
    Point* dragging_corner = nullptr;

    bool draw_as_macro = true;
};
