/**
 ** Class Rocket
 **/

#include <iostream>
#include <algoviz/SVG.hpp>
using namespace std;

class Rocket {

        private:
        // Attribute
        Image figure;
        int xPosition;
        int yPosition;
        bool dead = true;
        
         /******************************
          **       Constructor        **
          ******************************/
        
        public:
        Rocket(SVG &playground) { 
            this->xPosition = 200;
            this->yPosition = 50;
            figure = Image("/user-redirect/algoviz/img/rocket_final.png", xPosition, yPosition, 40, 40, &playground);
        }
    
         /**************
          ** Methods **
          **************/
    
        // get Y-Coordinate
        int getYCoordinate(){
            return figure.getY();         
        }
    
        // rocket dies
        void rocketDead(){
            int r;
            while (dead == true){
                figure.moveTo(figure.getX(),figure.getY() + 2);
                figure.moveTo(figure.getX() + 1,figure.getY());
                figure.rotateTo(0 + r);
                r += 2;
                if (figure.getY() > 450){
                    dead = false;
                    figure.hide();
                }
            }
        }
    
        // move along y-axis. X-axis constantly 200!
        void move(int y){
            figure.moveTo(200, y);
        }
        
        // change rotation
        void rotate(int grad){
            figure.rotateTo(grad);
        }
};