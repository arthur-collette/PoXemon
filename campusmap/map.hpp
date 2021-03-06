#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include "tilemap.hpp"
#include "npc.hpp"
#include "trainer.hpp"
#include "shop.hpp"
#include "interior.hpp"
#include "center.hpp"
#include "Backpack_map.hpp"
#include "fights/Backpack.h"
#include "box.hpp"

using namespace std;

//This is our class for our map

class Map
{
    public:
        Map(sf::RenderWindow &window, int poke_name);
        ~Map();
        void draw(sf::RenderWindow &window,sf::View &view, Trainer &trainer, sf::Clock& clock, sf::Event &event);
        void initialisation(sf::RenderWindow &window, Trainer &trainer, sf::View &view);
        void end(sf::RenderWindow &window, Trainer &trainer);
        static sf::FloatRect getViewBounds(const sf::View &view);
        void trainerDisplacement(sf::RenderWindow &window, Trainer &trainer, sf::Event &event, sf::Clock& clock, sf::View &view);
        void fillTree(sf::RenderWindow &window);
        void openDoorS(sf::RenderWindow &window);
        void closeDoorS(sf::RenderWindow &window);
        void tunnel(sf::RenderWindow &window, int x, int y);
        bool catched;
        bool water_catch;
        bool obtained_light;
        bool mr_fountain;
        bool foot_players;
        map<string, vector<Npc*> > npcs; //Map mapping each map_name to its associated vector of npcs

         //Checking opponent trainers
        void check_opponents(Backpack &bag);

        //Backpack
        BackpackMap backpack;
        
        //Box
        Box box;
    
        string map_name;

    private:
        TileMap background1_1;
        TileMap background1_2;
        TileMap background2_1;
        //TileMap background2_2;
        TileMap background3_1;
        TileMap background3_2;
        TileMap background4_1;
        TileMap background4_2;
        TileMap background7_1;
        TileMap background7_2;
        TileMap background8;
        Interior background9;
        Interior background10;
        TileMap background11;
        TileMap background11_2;
        Interior background12;

        map<string, const int*> collision_;
        int alpha;
        string state;
        int animationCounter;
        int animationDoor;
        sf::Clock animClock;
        sf::Texture texture_1; //tileset1
        sf::Texture texture_2; //tileset2
        sf::Texture texture_3; //tileset3
        sf::Texture pokeInterior;
        sf::Sprite pokeBuilding;
        Shop shop;
        Center center;

        //Places of Spawn of the Trainer
        int initialX;
        int initialY;

        map<string,vector<vector<int>>> spawn_dict;
        int door;//which spwaning position
        vector<string> map_list;
        map<string, vector<string>> scenario;
        bool enter;
        bool fight;
        int nNpc;

        //illusions
        void illuCenter(sf::RenderWindow &window);
        void illuShop(sf::RenderWindow &window);
        void illuTunnelR(sf::RenderWindow &window);
        void illuTunnelL(sf::RenderWindow &window);
        void illuGrandhall(sf::RenderWindow &window);
        void illuBat80(sf::RenderWindow &window);

        //Shader for the underground
        void light(sf::RenderWindow &window, sf::View &view);

        //Flower animation
        void movingFlower(sf::RenderWindow &window, int x, int y);
        void flowerList(sf::RenderWindow &window);


        //Fish
        void fish(sf::RenderWindow &window, sf::View &view, Trainer &trainer);

};
