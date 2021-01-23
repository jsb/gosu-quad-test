#include "GameWindow.hpp"

GameWindow::GameWindow() :
    Gosu::Window(640, 480),
    checkerboard("media/checkerboard512.png")
{
    corners[0] = {  60, 100 };
    corners[1] = { 280, 100 };
    corners[2] = {  60, 340 };
    corners[3] = { 280, 280 };

    checkerboard_macro = Gosu::Graphics::record(checkerboard.width(), checkerboard.height(), [&]
    {
        checkerboard.draw(0, 0);
    });
}

void GameWindow::update()
{
    if (dragging_corner)
    {
        dragging_corner->x = input().mouse_x();
        dragging_corner->y = input().mouse_y();
    }
}

void GameWindow::draw()
{
    if (draw_as_macro)
    {
        checkerboard_macro.data().draw(
                    corners[0].x, corners[0].y, Gosu::Color::WHITE,
                    corners[1].x, corners[1].y, Gosu::Color::WHITE,
                    corners[2].x, corners[2].y, Gosu::Color::WHITE,
                    corners[3].x, corners[3].y, Gosu::Color::WHITE,
                    0,
                    Gosu::AM_DEFAULT
        );
    }
    else
    {
        checkerboard.data().draw(
                    corners[0].x, corners[0].y, Gosu::Color::WHITE,
                    corners[1].x, corners[1].y, Gosu::Color::WHITE,
                    corners[2].x, corners[2].y, Gosu::Color::WHITE,
                    corners[3].x, corners[3].y, Gosu::Color::WHITE,
                    0,
                    Gosu::AM_DEFAULT
        );
    }
}

void GameWindow::button_down(Gosu::Button _button)
{
    if (_button == Gosu::KB_ESCAPE)
    {
        close();
    }

    if (_button == Gosu::MS_LEFT)
    {
        const auto m = Point{input().mouse_x(), input().mouse_y()};
        for (auto& c : corners)
        {
            if (Gosu::distance(m.x, m.y, c.x, c.y) < 20)
            {
                dragging_corner = &c;
                break;
            }
        }
    }

    if (_button == Gosu::KB_SPACE)
    {
        draw_as_macro = !draw_as_macro;
    }
}

void GameWindow::button_up(Gosu::Button _button)
{
    if (_button == Gosu::MS_LEFT)
    {
        dragging_corner = nullptr;
    }
}

bool GameWindow::needs_cursor() const
{
    return true;
}
