/**
 ** Class Layout
 **/

#include <iostream>
#include <algoviz/SVG.hpp>
using namespace std;

class Layout {

        private:
        // Attribute
        Rect backRed;
        Rect infoBack;
        Image backgroundLeft;
        Image backgroundRight;
        Image gameover;
        Image welcome;          
        
         /******************************
          **       Constructor        **
          ******************************/
        
        public:
        Layout(SVG &playground) {    //x = 1200, y = 600
            backgroundLeft = Image("/user-redirect/algoviz/img/backgroundspace_left.png", 100, 200, 1200, 700, &playground);
            backgroundRight = Image("/user-redirect/algoviz/img/backgroundspace_right.png", 974, 200, 1200, 700, &playground);
            gameover = Image("/user-redirect/algoviz/img/gameover.png", 400, 200, 900, 500, &playground);
            gameover.hide();
            backRed = Rect(0, 0, 800, 400, &playground);
            backRed.setFill("transparent");
            backRed.setColor(1, 1, 1, 0);
            infoBack = Rect(-5, -20, 80, 20, &playground);
            infoBack.setFill("white");
            infoBack.setColor("black");
            welcome = Image("/user-redirect/algoviz/img/welcome.png", 400, 200, 400, 300, &playground);
        }
        
         /**************
          ** Methods **
          **************/
        
        // show gameover screen
        void youLost(){
            gameover.show();
            infoBack.setFill("black");
            infoBack.setColor("black");
        }
        
        // hide welcome image
        void hideWelcome(){
            welcome.hide();
        }
        
        // flicker screen
        void flicker(){
            for (int i = 0; i < 2; i++) {
                backRed.setFill(255, 0, 0);
                AlgoViz::sleep(100);
                backRed.setFill("transparent");
                AlgoViz::sleep(40);
            }
        }
    
        void moveBackground(){
            backgroundLeft.moveTo((backgroundLeft.getX() - 1), backgroundLeft.getY());
            backgroundRight.moveTo((backgroundRight.getX() - 1), backgroundRight.getY());
        }

        // dynamic background
        void resetBackground(){
            if (backgroundLeft.getX() < -500){
                backgroundLeft.moveTo(backgroundRight.getX() + 874, 200);   
            } else if (backgroundRight.getX() < -500){
                backgroundRight.moveTo(backgroundLeft.getX() + 874, 200);
            }
         }
};