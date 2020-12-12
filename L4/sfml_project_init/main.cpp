#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <vector>
class Graphical_objects : public sf::Sprite
{
private:
    sf::Texture texture_;

public:
    Graphical_objects(std::string texture_path,
                      float scale,
                      sf::IntRect rect,
                      int x,
                      int y,
                      bool isRepeated = false)
    {
        if (texture_.loadFromFile(texture_path)) {
            setTexture(texture_);
            setScale(scale, scale);
            setTextureRect(rect);
            setPosition(x, y);
            texture_.setRepeated(isRepeated);
        }
    }
};

class Labirynth
{
    std::vector<sf::Sprite *> objects_;
    Graphical_objects *guy_;

public:
    Labirynth()
    {
        Graphical_objects *grass
            = new Graphical_objects("../tex/grass.png", 1, sf::IntRect(0, 0, 800, 600), 0, 0, true);
        objects_.emplace_back(grass);
        guy_ = new Graphical_objects("../tex/guy.png", 1, sf::IntRect(0, 0, 43, 63), 0, 0);
        objects_.emplace_back(guy_);
        Graphical_objects *wall = new Graphical_objects("../tex/wall.png",
                                                        1,
                                                        sf::IntRect(0, 0, 40, 400),
                                                        100,
                                                        100,
                                                        true);
        objects_.emplace_back(wall);
        objects_.emplace_back(
            new Graphical_objects("../tex/wall.png", 1, sf::IntRect(0, 0, 40, 400), 300, 200, true));
    }
    void draw(sf::RenderWindow *window)
    {
        for (auto &el : objects_) {
            window->draw(*el);
        }
    }
    void move_player(int x, int y) { guy_->move(x, y); }
    ~Labirynth()
    {
        for (auto &el : objects_)
            delete el;
    }
};

class Scene
{
private:
    sf::RenderWindow window_;
    Labirynth *labirynth_;

public:
    Scene(int w, int h) : window_(sf::VideoMode(w, h), "My window") {}
    void set_labirynt(Labirynth *ptr) { labirynth_ = ptr; }
    void draw()
    {
        window_.clear(sf::Color::Black);
        // draw everything here...

        labirynth_->draw(&window_);

        // end the current frame
        window_.display();
    }
    void events(sf::Event &event)
    {
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window_.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                //                guy.move(-2, 0);
                labirynth_->move_player(-2, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                labirynth_->move_player(2, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                labirynth_->move_player(0, 2);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                labirynth_->move_player(0, -2);
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window_);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y
                              << std::endl;
                }
            }
        }
    }
    void window_loop()
    {
        while (window_.isOpen()) {
            sf::Event event;
            while (window_.pollEvent(event)) {
                events(event);
                draw();
            }
        }
    }
};

int main()
{
    Scene scene(800, 600);
    Labirynth lab;
    scene.set_labirynt(&lab);
    scene.window_loop();

    return 0;
}
