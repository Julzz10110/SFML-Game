#include "Game.h"

// Static Functions

// Initialize Functions

void Game::initWindow()
{   
    std::ifstream ifs("config/window.ini");

    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if (ifs.is_open()) 
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

// Constructors/Destructors

Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

// Functions

void Game::updateDeltaTime() 
{   
    /* Updates the dT var with the item it takes to update and render one frame. */

    this->dt = this->dtClock.restart().asSeconds();

    system("cls");
    std::cout << this->dt << std::endl;
    
}

void Game::updateSFMLEvents() 
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
    
}

void Game::update() 
{
    this->updateSFMLEvents();
}

void Game::render() 
{
    this->window->clear();

    // Render Items

    this->window->display();

}

void Game::run() 
{
    while (this->window->isOpen())
    {  
       this->updateDeltaTime();
       this->update();
       this->render();
    }
    
}
